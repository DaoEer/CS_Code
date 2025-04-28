// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestQiYuan.h"
#include "Util/ConvertUtil.h"
#include "JsonFieldData.h"

void UQuestQiYuan::InitDatas(const FString JsonStr)
{
	Super::InitDatas(JsonStr);

	//��̬���ݴӷ�����������JsonStr�����ȡ
	auto JsonData = UJsonFieldData::Create(this)->FromString(JsonStr)->GetObject(TEXT("ROOT"));

	//���춴�����������⴦��һ�£���Ҫ��ʾ����ʱ
	mCountDown = JsonData->GetString(TEXT("countDown"));
	isShowTime = FSTRING_TO_INT(JsonData->GetString(TEXT("isShowTime")));
}