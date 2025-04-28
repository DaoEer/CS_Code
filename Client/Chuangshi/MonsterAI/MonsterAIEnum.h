#pragma once
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class MONSTER_AI_EVENT : uint8
{
	///����ҽ��뵱ǰ�ͻ���
	ROLE_ENTER_WORLD = 0 UMETA(DisplayName = "ROLE_ENTER_WORLD"),
	///�й�����뵱ǰ�ͻ���
	MONSTER_ENTER_WORLD = 1 UMETA(DisplayName = "MONSTER_ENTER_WORLD"),
};

UENUM(BlueprintType)
enum class MONSTER_AI_COMMAND : uint8
{
	///ָ��
	NONE = 0 UMETA(DisplayName = "NONE"),
	///����ָ��
	FOLLOW = 1 UMETA(DisplayName = "FOLLOW"),
	///���� 
	FORMATION = 2 UMETA(DisplayName = "FORMATION"),
	///����ָ��
	ATTACK = 3 UMETA(DisplayName = "ATTACK"),
	///����ָ��
	CLIMB = 4 UMETA(DisplayName = "CLIMB"),
	
};

enum class MONSTER_AI_COMMAND_PROCESS : uint8
{
	///ָ��
	READY = 0 UMETA(DisplayName = "READY"),
	///����ָ��
	PROCESS = 1 UMETA(DisplayName = "PROCESS"),
	///����ָ��
	OVER = 2 UMETA(DisplayName = "OVER"),
};

UENUM(BlueprintType)
enum class MONSTER_AI_STATE : uint8
{
	///����״̬
	DEAD = 0 UMETA(DisplayName = "DEAD"),
	///��ͨ״̬
	NORMAL = 1 UMETA(DisplayName = "NORMAL"),

	ESCAPE = 2 UMETA(DisplayName = "ESCAPE"),
};

UENUM(BlueprintType)
enum class MONSTER_AI_MOVETYPE : uint8
{
	Stop			= 0 UMETA(DisplayName = "Stop"),
	MoveToPos		= 1 UMETA(DisplayName = "MoveToPos"),
	MoveChaseActor	= 2 UMETA(DisplayName = "MoveChaseActor"),
	MoveCharge		= 3 UMETA(DisplayName = "MoveCharge"),
	MoveMarch		= 4 UMETA(DisplayName = "MoveMarch"),
	MoveFollow		= 5 UMETA(DisplayName = "MoveFollow"),
	MoveRect		= 6	UMETA(DisplayName = "MoveRect"),
	MoveCircle      = 7	UMETA(DisplayName = "MoveCircle"),

};

///����
UENUM(BlueprintType)
enum class MONSTER_AI_FORMATION : uint8
{
	///����
	Rectangle = 1 UMETA(DisplayName = "Rectangle"),

	///Բ��
	Circle = 2 UMETA(DisplayName = "Circle"),
};
