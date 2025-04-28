# -*- coding: utf-8 -*-

"""
"""
import functools

import KBEngine
from KBEDebug import *

import MysqlUtility
from .utils.query_utils import Q

class QuerySet(object):
	"""
	"""
	def __init__(self, model_class = None):
		"""
		"""
		self.model = None
		self.meta = None
		self.filters = []
		self.limit_opt = tuple()  # 查询上限 -> (min, max)
		self.order_by_opt = tuple()

		if model_class:
			self.set_model(model_class)

	def set_model(self, model_class):
		"""
		@param model_class: EntityModel
		"""
		self.model = model_class
		self.meta = model_class._meta

	def clone(self):
		"""
		复制一份自己出来。
		注意：所有内容均只是浅拷贝，复制的实例对某些变量的修改有可能会影响源实例。
		
		@return QuerySet
		"""
		obj = self.__class__()
		obj.model = self.model
		obj.meta = self.meta
		obj.filters = list( self.filters )
		obj.limit_opt = self.limit_opt
		obj.order_by_opt = self.order_by_opt
		return obj

	def build_where_clauses(self, *args, **kwargs):
		"""
		@return bytes; where sql
		"""
		vs = list(args) + list(kwargs.items())
		r = []
		for v in vs:
			if isinstance(v, Q):
				r.append( v.as_sql(self.meta) )
			else:
				q = Q(v)
				r.append( q.as_sql(self.meta) )
		where = b" AND ".join(r)
		return where and b" WHERE " + where

	def build_order_by_clauses(self):
		"""
		@return bytes; mysql order by clauses
		"""
		if not self.order_by_opt:
			return b""

		metaField = self.meta.fields
		orderby = []
		for k in self.order_by_opt:
			o = " ASC"
			c = k[0]
			if c in "-+":
				k = k[1:]
				if c == "-":
					o = " DESC"
			orderby.append(metaField[k].db_column + o)
		return (" ORDER BY " + ", ".join(orderby)).encode()

	def filter(self, *args, **kwargs):
		"""
		设置过滤器
		@return QuerySet
		"""
		obj = self.clone()
		obj.filters.extend( list(args) + list(kwargs.items()) )
		return obj

	def limit(self, min, max):
		"""
		"""
		assert isinstance(min, int) and isinstance(max, int) and min <= max
		obj = self.clone()
		obj.limit_opt = (min, max)
		return obj

	def order_by(self, *args):
		"""
		@param args: 字段列表，例如：order_by("id", "-name")。减号开头表示降序排序
		"""
		obj = self.clone()
		obj.order_by_opt = tuple(args)
		return obj

	def select(self, callback, *args, **kwargs):
		"""
		def callback(success, models):
			pass
		"""
		assert self.model is not None
		arg = self.filters + list(args) + list(kwargs.items())
		where = self.build_where_clauses(*arg)

		attrs = list( self.meta.fields )
		fields = [ self.meta.fields[e].db_column for e in attrs ]
		queryField = ", ".join( fields )
		select = "SELECT {} FROM {}".format( queryField, self.meta.db_table )
		cmd = b"".join([
			MysqlUtility.makeSafeSql( select ),
			where,
			self.build_order_by_clauses(),
			self.limit_opt and (" LIMIT %d, %d" % self.limit_opt).encode() or b"",
		])
		
		
		#DEBUG_MSG( "%s::select(), %s" % (self.__class__.__name__, cmd) )
		KBEngine.executeRawDatabaseCommand( cmd, functools.partial( self._select_callback, cmd, attrs, callback ) )

	def _select_callback( self, cmd, fields, callback, result, rows, insertid, error ):
		"""
		select命令回调
		"""
		if error is not None:
			ERROR_MSG( "%s::_select_callback(), execute raw sql '%s' fault!!!; error: %s" % ( self.__class__.__name__, cmd, error ) )
			if callable( callback ):
				callback( False, None )
			return
		
		#DEBUG_MSG( "%s::_select_callback(), cmd: |%s|, result: |%s|" % ( self.__class__.__name__, cmd, result ) )
		models = []
		for row in result:
			m = self.model()
			for i, key in enumerate( fields ):
				setattr( m, key, self.meta.fields[key].to_python(  row[i] ) )
			models.append( m )
		
		if callable( callback ):
			callback( True, models )

	def delete(self, callback, *args, **kwargs):
		"""
		def callback(success, rows):
			pass
		"""
		assert self.model is not None
		arg = self.filters + list(args) + list(kwargs.items())
		where = self.build_where_clauses(*arg)
		
		cmd = "DELETE FROM {}".format( self.meta.db_table )
		cmd = MysqlUtility.makeSafeSql( cmd ) + where
		#DEBUG_MSG( "%s::delete(), %s" % (self.__class__.__name__, cmd) )
		KBEngine.executeRawDatabaseCommand( cmd, functools.partial( self._delete_callback, cmd, callback ) )

	def _delete_callback( self, cmd, callback, result, rows, insertid, error ):
		"""
		delete命令回调
		"""
		if error is None:
			if callable( callback ):
				callback( True, rows )
		else:
			ERROR_MSG( "%s::_delete_callback(), execute raw sql '%s' fault!!!; error: %s" % ( self.__class__.__name__, cmd, error ) )
			if callable( callback ):
				callback( False, 0 )

	def update( self, callback, *args, **kwargs):
		"""
		例子：更新字段id = 123的条目的数据
		xxx.filter(id = 123).update( cb, (field2, value1), (field2, value2), fieldN = valueN )
		
		回调格式：
		def callback(success, rows):
			pass
		"""
		assert self.model is not None
		where = self.build_where_clauses(*self.filters)

		paramsKey = []
		paramsVal = []
		kw = list(args) + list(kwargs.items())
		for k, v in kw:
			if hasattr(v, "resolve_expression"):
				paramsKey.append( "{} = {}".format( self.meta.fields[k].db_column, v.resolve_expression(self.meta) ) )
			else:
				paramsKey.append( "{} = %s".format( self.meta.fields[k].db_column ) )
				paramsVal.append( v )
		
		cmd = "UPDATE {} SET {}".format( self.meta.db_table, ", ".join( paramsKey ) )
		cmd = MysqlUtility.makeSafeSql( cmd, paramsVal ) + where
		#DEBUG_MSG( "%s::update(), %s" % (self.__class__.__name__, cmd) )
		KBEngine.executeRawDatabaseCommand( cmd, functools.partial( self._update_callback, cmd, callback ) )

	def _update_callback( self, cmd, callback, result, rows, insertid, error ):
		"""
		update命令回调
		"""
		if error is None:
			if callable( callback ):
				callback( True, rows )
		else:
			ERROR_MSG( "%s::_update_callback(), execute raw sql '%s' fault!!!; error: %s" % ( self.__class__.__name__, cmd, error ) )
			if callable( callback ):
				callback( False, rows )

	def insert( self, callback, *args, **kwargs ):
		"""
		向数据库插入一条记录。
		def callback(success, insertid):
			pass
		"""
		kw = list(args) + list(kwargs.items())
		fieldNames = []
		fieldValues = []
		fieldValuesP = []
		for k, v in kw:
			fieldNames.append( self.meta.fields[k].db_column )
			fieldValues.append( v )
			fieldValuesP.append( "%s" )
		
		cmd = "INSERT INTO {} ( {} ) VALUES ( {} )".format( self.meta.db_table, ", ".join( fieldNames ), ", ".join( fieldValuesP ) )
		cmd = MysqlUtility.makeSafeSql( cmd, fieldValues )
		#DEBUG_MSG( "%s::insert(), %s" % (self.__class__.__name__, cmd) )
		KBEngine.executeRawDatabaseCommand( cmd, functools.partial( self._insert_callback, cmd, callback ) );

	def _insert_callback( self, cmd, callback, result, rows, insertid, error ):
		"""
		insert命令回调
		"""
		if error is not None:
			ERROR_MSG( "%s::_insertToDBCallback(), execute raw sql '%s' fault!!!; error: %s" % ( self.__class__.__name__, cmd, error ) )
			if callable( callback ):
				callback( False, insertid )
			return
		
		if insertid <= 0:
			# 如果primary_key所代表的字段与auto_incr所代表的字段不是同一字段时，这个情况就会发生，
			# 所以严格来说，这个问题不一定是个错误，也许是使用者就想这么干的^_^
			ERROR_MSG( "%s::_insertToDBCallback(), execute raw sql '%s' success, but last insert id not big than 0. result = '%s'" % ( self.__class__.__name__, cmd, insertid ) )
		
		if callable( callback ):
			callback( True, insertid )




