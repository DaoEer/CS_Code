#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterFollowRole.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2019-10-30
*/

/**
* �������
*/
class CHUANGSHI_API MonsterFollowRole : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterFollowRole();
	~MonsterFollowRole();

	FVector getNextPosition() { return nextPosition; }
	FVector getNextDirection() { return nextDirection; }

	void set_enemyID(const int32& newEnemyID, const int32& oldEnemyID);
	void set_curPosition(const FVector &newKbePos, const FVector& oldKbePos);
	void set_curDirection(const FVector &newKbeDir, const FVector& oldKbeDir);

private:
	void OnSetPosition(const FVector &unrealPos);
	void OnSetDirection(const FVector &unrealDir);
	void UpdateVolatileDataToServer(const FVector& pos, const FVector& dir);

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
	// ���Է�������ǿ��λ�øı�
	void OnPositionSet(const FVector &unrealPos);

	// ���Է�������ǿ�Ƴ���ı�
	void OnDirectionSet(const FVector &unrealDir);
private:
	FVector nextPosition;
	FVector nextDirection;
};
