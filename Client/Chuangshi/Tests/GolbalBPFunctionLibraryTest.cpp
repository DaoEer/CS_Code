// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include <iostream>
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Util/CS3Debug.h"
#include "UnrealMathUtility.h"
#include <string.h>

using namespace std;
DEFINE_LOG_CATEGORY_STATIC(LogBaseAutomationTests, Log, All);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUGolbalBPFunctionLibrary, "Game.Util.UGolbalBPFunctionLibrary", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FUGolbalBPFunctionLibrary::RunTest(const FString& Parameters)
{
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSplitString, "Game.Util.UGolbalBPFunctionLibrary.SplitString", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FSplitString::RunTest(const FString& Parameters)
{
	TArray<FString> TestArray = UGolbalBPFunctionLibrary::SplitString(FString(TEXT("1,2,3,3")), true, ",");

	FString JoinedStr;
	for (auto& Str : TestArray)
	{
		JoinedStr += Str;
	}
	if (TestArray.Num() != 3)
	{
		UE_LOG(LogBaseAutomationTests, Error, TEXT("TestArray Len: %d"), TestArray.Num());
		return false;
	}
	if (TestArray.Find(TEXT("1")) == INDEX_NONE)
	{
		return false;
	}
	if (TestArray.Find(TEXT("2")) == INDEX_NONE)
	{
		return false;
	}
	if (TestArray.Find(TEXT("3")) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FConvertFVector2DToFVector, "Game.Util.UGolbalBPFunctionLibrary.ConvertFVector2DToFVector", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FConvertFVector2DToFVector::RunTest(const FString& Parameters)
{
	TArray<FVector2D> TestTarget;
	TestTarget.Add(FVector2D(1, 1));
	TestTarget.Add(FVector2D(2, 2));
	TestTarget.Add(FVector2D(3, 3));
	TestTarget.Add(FVector2D(4, 4));
	TArray<FVector> TestResult = UGolbalBPFunctionLibrary::ConvertFVector2DToFVector(TestTarget);
	if (TestResult.Num() != 4)
	{
		UE_LOG(LogBaseAutomationTests, Error, TEXT("TestResult Len: %d"), TestResult.Num());
		return false;
	}
	if (TestResult.Find(FVector(1, 1, 0)) == INDEX_NONE) 
	{
		return false;
	}
	if (TestResult.Find(FVector(2, 2, 0)) == INDEX_NONE)
	{
		return false;
	}
	if (TestResult.Find(FVector(3, 3, 0)) == INDEX_NONE)
	{
		return false;
	}
	if (TestResult.Find(FVector(4, 4, 0)) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FIsContainStr, "Game.Util.UGolbalBPFunctionLibrary.IsContainStr", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FIsContainStr::RunTest(const FString& Parameters)
{
	///<�ж��ַ������Ƿ�����ַ���,��������True
	TArray<FString> TestStringArray;
	TestStringArray.Add(FString(TEXT("Hello world!")));
	TestStringArray.Add(FString(TEXT("Good world!")));
	TestStringArray.Add(FString(TEXT("Good morning!")));
	TestStringArray.Add(FString(TEXT("Good afternoon!")));
	if (!UGolbalBPFunctionLibrary::IsContainStr(FString(TEXT("Hello world!")), TestStringArray))
	{
		return false;
	}
	if (UGolbalBPFunctionLibrary::IsContainStr(FString(TEXT("Hello my boy!")), TestStringArray))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FIsPositionInSectorRange, "Game.Util.UGolbalBPFunctionLibrary.IsPositionInSectorRange", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FIsPositionInSectorRange::RunTest(const FString& Parameters)
{
	FVector Pos1 = FVector(1.0, 0.0, 0.0 );
	FVector Pos2 = FVector(-1.0, 0.0, 0.0 );
	FVector Pos3 = FVector(0.0, 1.0, 0.0 );
	FVector Pos4 = FVector(0.0, -1.0, 0.0 );

	FVector SectorPos = FVector(0.0, 0.0, 0.0 );
	FVector SectorForwadDir = FVector(1.0, 0.0, 0.0 );
	float SectorAngle = 90.0;
	float SectorDistance = 100;
	float SectorHeight = 100;

	if(!UGolbalBPFunctionLibrary::IsPositionInSectorRange(Pos1, SectorPos, SectorForwadDir, SectorAngle, SectorDistance, SectorHeight) )
	{	
		return false;
	}
	if( UGolbalBPFunctionLibrary::IsPositionInSectorRange(Pos2, SectorPos, SectorForwadDir, SectorAngle, SectorDistance, SectorHeight) )
	{	
		return false;
	}

	if( UGolbalBPFunctionLibrary::IsPositionInSectorRange(Pos3, SectorPos, SectorForwadDir, SectorAngle, SectorDistance, SectorHeight) )
	{	
		return false;
	}

	if( UGolbalBPFunctionLibrary::IsPositionInSectorRange(Pos4, SectorPos, SectorForwadDir, SectorAngle, SectorDistance, SectorHeight) )
	{	
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FConvertStringToVectors, "Game.Util.UGolbalBPFunctionLibrary.ConvertStringToVectors", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FConvertStringToVectors::RunTest(const FString& Parameters)
{
	TArray<FVector> TestVectors = UGolbalBPFunctionLibrary::ConvertStringToVectors(FString(TEXT("1,2,3,4,5,6,7,8,9")));
	if (TestVectors.Num() != 3)
	{
		return false;
	}
	if(TestVectors.Find(FVector(1,2,3)) == INDEX_NONE)
	{
		return false;
	}
	if (TestVectors.Find(FVector(4,5,6)) == INDEX_NONE)
	{
		return false;
	}
	if (TestVectors.Find(FVector(7,8,9)) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FIntListToStringList, "Game.Util.UGolbalBPFunctionLibrary.IntListToStringList", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FIntListToStringList::RunTest(const FString& Parameters)
{
	TArray<int32> TestInIntList;
	TestInIntList.Add(1);
	TestInIntList.Add(2);
	TestInIntList.Add(3);
	TestInIntList.Add(4);
	TArray<FString> TestOutStringList = UGolbalBPFunctionLibrary::IntListToStringList(TestInIntList);
	if (TestOutStringList.Find(FString(TEXT("1"))) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutStringList.Find(FString(TEXT("2"))) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutStringList.Find(FString(TEXT("3"))) == INDEX_NONE)
	{
		return false;
	}
	if (!(TestOutStringList.Find(FString(TEXT("5"))) == INDEX_NONE))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FStringListToIntList, "Game.Util.UGolbalBPFunctionLibrary.StringListToIntList", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FStringListToIntList::RunTest(const FString& Parameters)
{
	TArray<FString> TestInStringList;
	TestInStringList.Add(FString(TEXT("123")));
	TestInStringList.Add(FString(TEXT("456")));
	TestInStringList.Add(FString(TEXT("789")));
	TestInStringList.Add(FString(TEXT("111")));
	TArray<int32> TestOutIntList = UGolbalBPFunctionLibrary::StringListToIntList(TestInStringList);
	if (TestOutIntList.Find(123) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutIntList.Find(456) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutIntList.Find(789) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutIntList.Find(111) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FloatListToStringList, "Game.Util.UGolbalBPFunctionLibrary.FloatListToStringList", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FloatListToStringList::RunTest(const FString& Parameters)
{
	TArray<float> TestInFloatList;
	TestInFloatList.Add(2.3);
	TestInFloatList.Add(4.56);
	TestInFloatList.Add(0.123456);
	TestInFloatList.Add(10.1);
	TArray<FString> TestOutfloatList = UGolbalBPFunctionLibrary::FloatListToStringList(TestInFloatList);
	if (TestOutfloatList.Find(FString(TEXT("2.3"))) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutfloatList.Find(FString(TEXT("4.56"))) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutfloatList.Find(FString(TEXT("0.123456"))) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutfloatList.Find(FString(TEXT("10.1"))) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(SGreaterThan, "Game.Util.UGolbalBPFunctionLibrary.SGreaterThan", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool SGreaterThan::RunTest(const FString& Parameters)
{
	TArray<FString> TestStringGreaterThan ;
	
	
	TestStringGreaterThan.Add(FString("Hello"));
	TestStringGreaterThan.Add(FString(TEXT("World!")));
	TestStringGreaterThan.Add(FString(TEXT("Y")));
	TestStringGreaterThan.Add(FString(TEXT("A")));
	if (UGolbalBPFunctionLibrary::SGreaterThan(("Hello"), ("World!")))
	{
		CS3_Warning(TEXT("Hello>World��-no.H<W"));
		return false;
	}
	///���ܲ��ǱȽ��ַ����ĳ��ȣ����ǱȽ��ַ���������ĸ Y>W
	if (!(UGolbalBPFunctionLibrary::SGreaterThan(("Y"), ("World!"))))
	{
		return false;
	}
	if (!(UGolbalBPFunctionLibrary::SGreaterThan(("Y"), ("A"))))
	{
		CS3_Warning(TEXT("Y>A"));
		return false;
	}
	if (UGolbalBPFunctionLibrary::SGreaterThan(("A"), ("Y")))
	{
		CS3_Warning(TEXT("A>Y"));
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(SLessThan, "Game.Util.UGolbalBPFunctionLibrary.SLessThan", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool SLessThan::RunTest(const FString& Parameters)
{
	TArray<FString> TestStringLessThan;


	TestStringLessThan.Add(FString("Hello"));
	TestStringLessThan.Add(FString(TEXT("World!")));
	TestStringLessThan.Add(FString(TEXT("Y")));
	TestStringLessThan.Add(FString(TEXT("A")));
	if (!UGolbalBPFunctionLibrary::SLessThan(("Hello"), ("World!")))
	{
		CS3_Warning(TEXT("Hello<World��.H<W"));
		return false;
	}
	if ((UGolbalBPFunctionLibrary::SLessThan(("Y"), ("World!"))))
	{
		CS3_Warning(TEXT("Y>World��."));
		return false;
	}
	if ((UGolbalBPFunctionLibrary::SLessThan(("Y"), ("A"))))
	{
		CS3_Warning(TEXT("Y>A"));
		return false;
	}
	if (!UGolbalBPFunctionLibrary::SLessThan(("A"), ("Y")))
	{
		CS3_Warning(TEXT("A<Y"));
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetEllipsisString, "Game.Util.UGolbalBPFunctionLibrary.GetEllipsisString", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetEllipsisString::RunTest(const FString& Parameters)
{
	TArray<FString> TestInEllipsisString ;
	TestInEllipsisString.Add(FString(TEXT("goodmoring")));
	TestInEllipsisString.Add(FString(TEXT("good")));
	//ԭ�ַ���goodmoring�����ַ����ĳ���3 goo...
	FString TestOutEllipsisString = UGolbalBPFunctionLibrary::GetEllipsisString(FString(TEXT("goodmoring")),3);

	if (TestOutEllipsisString.Find(TEXT("goo...")) == INDEX_NONE)
	{ 
		return false;
	}
	if (TestOutEllipsisString.Find(TEXT("...")) == INDEX_NONE)
	{
		return false;
	}
	if (!(TestOutEllipsisString.Find(TEXT("d")) == INDEX_NONE))
	{
		return false;
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(StringContains, "Game.Util.UGolbalBPFunctionLibrary.StringContains", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool StringContains::RunTest(const FString& Parameters)
{
	//�ж�һ���ַ����Ƿ������һ���ַ��������е�����Ԫ��
	FString TestString1 = "hello";
	FString TestString2 = "hello world";
	if (UGolbalBPFunctionLibrary::StringContains(TestString1, TestString2))
	{
		CS3_Warning(TEXT("TestString1 Contains all TestString2"));
		return false;
	}
	if (!UGolbalBPFunctionLibrary::StringContains(FString(TEXT("abcd")), FString(TEXT("abd"))))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FStringToFVector, "Game.Util.UGolbalBPFunctionLibrary.FStringToFVector", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FStringToFVector::RunTest(const FString& Parameters)
{

	FVector TestStringToFVector = UGolbalBPFunctionLibrary::FStringToFVector(FString(TEXT("1.0 2 3.4")));
 	if (!(TestStringToFVector.X == 1.0000))
 	{
		return false;
 	}
	if (!(TestStringToFVector.Y == 2.0))
	{
		return false;
	}
// 	float i = TestStringToFVector.Z;
// 	cout << "TestStringToFVector.Z:" << i << endl;

	// float������==С�������λ̫�࣬-3.4�ľ���ֵС��0.0001
	if (FMath::Abs(TestStringToFVector.Z - 3.4) >= 0.0001)
	{
		return false;
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetReplaceString, "Game.Util.UGolbalBPFunctionLibrary.GetReplaceString", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetReplaceString::RunTest(const FString& Parameters)
{
	FString TestReplaceString = UGolbalBPFunctionLibrary::GetReplaceString(FString(TEXT("a{1},b{0}|cd")),TEXT("1,2"),",");
	//TestReplaceString�Ľ���� a2,b1|cd,����2�滻����1�е�{}
	
	//�����б�����û��1
	if (TestReplaceString.Find(TEXT("1")) == INDEX_NONE)
	{
		return false;
	}
	if (TestReplaceString.Find(TEXT("b")) == INDEX_NONE)
	{
		return false;
	}
	if (TestReplaceString.Find(TEXT("cd")) == INDEX_NONE)
	{
		return false;
	}
	if (TestReplaceString.Find(TEXT("a")) == INDEX_NONE)
	{
		return false;
	}
	if (TestReplaceString.Find(TEXT("2")) == INDEX_NONE)
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetValidInputTxt, "Game.Util.UGolbalBPFunctionLibrary.GetValidInputTxt", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetValidInputTxt::RunTest(const FString& Parameters)
{
	TArray<FString> TestInValidInputTxt;
	TestInValidInputTxt.Add(FString(TEXT("hello")));
	//TestInValidInputTxt.Add(FString(TEXT("good")));
	//�ַ������ƣ������Ǳ�һֱ���ǳ�ȥ���һλ��������ֵ�����ǹ̶���TempInputString.Len()-1
	
	FString TestOutValidInputTxt = UGolbalBPFunctionLibrary::GetValidInputTxt(FString(TEXT("hello")),2, true);

	if (TestOutValidInputTxt.Find(TEXT("hell")) == INDEX_NONE)
	{
		return false;
	}
	if (!(TestOutValidInputTxt.Find(TEXT("o")) == INDEX_NONE))
	{
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(ReplaceLineBreak, "Game.Util.UGolbalBPFunctionLibrary.ReplaceLineBreak", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool ReplaceLineBreak::RunTest(const FString& Parameters)
{
	//�滻���з������з�ɾ��
	TArray<FString> TestInReplaceLineBreak;
	TestInReplaceLineBreak.Add(FString(TEXT("goodmoring")));
	
	FString TestOutReplaceLineBreak = UGolbalBPFunctionLibrary::ReplaceLineBreak(FString(TEXT("good\r\n moring\r\n")));

	if (TestOutReplaceLineBreak.Find(TEXT("good moring")) == INDEX_NONE)
	{
		return false;
	}
	if (!(TestOutReplaceLineBreak.Find(TEXT("\r\n")) == INDEX_NONE))
	{
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetValidInputString, "Game.Util.UGolbalBPFunctionLibrary.GetValidInputString", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetValidInputString::RunTest(const FString& Parameters)
{
	
	//�����ֵΪ0-100֮�䣬������ֵ100������0����ֵ0���Ǵ����֣����ַ�����ȥ���һλ
	FString TestOutValidInputString1 = UGolbalBPFunctionLibrary::GetValidNumericInput(FString(TEXT("hello123")));
	FString TestOutValidInputString2 = UGolbalBPFunctionLibrary::GetValidNumericInput(FString(TEXT("456")));
	FString TestOutValidInputString3 = UGolbalBPFunctionLibrary::GetValidNumericInput(FString(TEXT("-1")));
	if (TestOutValidInputString1.Find(TEXT("hello12")) == INDEX_NONE)
	{
		return false;
	}
	if (!(TestOutValidInputString1.Find(TEXT("3")) == INDEX_NONE))
	{
		return false;
	}
	if (!(TestOutValidInputString2.Find(TEXT("456")) == INDEX_NONE))
	{
		return false;
	}
	if (TestOutValidInputString2.Find(TEXT("100")) == INDEX_NONE)
	{
		return false;
	}
	if (TestOutValidInputString3.Find(TEXT("0")) == INDEX_NONE)
	{
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetStringBytes, "Game.Util.UGolbalBPFunctionLibrary.GetStringBytes", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetStringBytes::RunTest(const FString& Parameters)
{
	//int�ַ������ֽ������ֽ���=�ַ�������=�ַ�������
	int32 TestStringBytes1, TestStringBytes2, TestStringBytes3;
	TestStringBytes1 = UGolbalBPFunctionLibrary::GetStringBytes("hello");
	TestStringBytes2 = UGolbalBPFunctionLibrary::GetStringBytes("1234567");
	TestStringBytes3 = UGolbalBPFunctionLibrary::GetStringBytes(TEXT("����"));
	if (!(TestStringBytes1 == 5))
	{
		CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	if (!(TestStringBytes2 == 7))
	{
		return false;
	}
	if (!(TestStringBytes3 == 2))
	{
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(IsPureAnsi, "Game.Util.UGolbalBPFunctionLibrary.IsPureAnsi", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool IsPureAnsi::RunTest(const FString& Parameters)
{
	//�ж��ַ����Ƿ�ֻ����ASCII��,ֻ����ASCII�뷵��True���������ķ���False
	TArray<FString> TestPureAnsi;
	TestPureAnsi.Add("0000000");
	TestPureAnsi.Add("0000x000");
	TestPureAnsi.Add(TEXT("����"));

	if (!(UGolbalBPFunctionLibrary::IsPureAnsi("000000")))
	{
		return false;
	}
	if (!(UGolbalBPFunctionLibrary::IsPureAnsi("0000x000")))
	{
		return false;
	}
	if (!(UGolbalBPFunctionLibrary::IsPureAnsi(TEXT("����"))))
	{
		CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	if (!UGolbalBPFunctionLibrary::IsPureAnsi(TEXT("sherthw")))
	{
		return false;
	}
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetLookAtRotator, "Game.Util.UGolbalBPFunctionLibrary.GetLookAtRotator", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetLookAtRotator::RunTest(const FString& Parameters)
{
	//������֮�������Ҳˮƽx��ļнǶ�����������ʵֻҪ�� x  y��ģ���ƽ���

	//TestResult = { Pitch = 0.000000000 Yaw = 44.9999962 Roll = 0.000000000 }
	//��1��1����2��2�����������߻���Ϊ45��
	FVector TestStartPosition = FVector(1.0, 1.0, 0.0);
	FVector TestTragetPosition = FVector(2.0, 2.0, 2.0);
	FRotator TestResult = UGolbalBPFunctionLibrary::GetLookAtRotator(TestStartPosition, TestTragetPosition);


	//TestResult2 = { Pitch = 0.000000000 Yaw = -135.000000 Roll = 0.000000000 }
	FVector TestStartPosition2 = FVector(3.0, 3.0, 10.0);
	FVector TestTragetPosition2 = FVector(2.0, 2.0, 5.0);
	FRotator TestResult2 = UGolbalBPFunctionLibrary::GetLookAtRotator(TestStartPosition2, TestTragetPosition2);

	//TestResult3 = { Pitch = 0.000000000 Yaw = 90.0000000 Roll = 0.000000000 }
	FVector TestStartPosition3 = FVector(0.0, 0.0, 1.0);
	FVector TestTragetPosition3 = FVector(0.0, 1.0, 0.0);
	FRotator TestResult3 = UGolbalBPFunctionLibrary::GetLookAtRotator(TestStartPosition3, TestTragetPosition3);

	//TestResult4 = { Pitch = 0.000000000 Yaw = 135.000000 Roll = 0.000000000 }
	FVector TestStartPosition4 = FVector(1.0, 0.0, 0.0);
	FVector TestTragetPosition4 = FVector(0.0, 1.0, 1.0);
	FRotator TestResult4 = UGolbalBPFunctionLibrary::GetLookAtRotator(TestStartPosition4, TestTragetPosition4);

	if (!(TestResult2 == FRotator(0.0, -135.0, 0.00)))
	{
		return false;
		
	}
	if (!(TestResult3 == FRotator(0.0, 90.0, 0.00)))
	{
		return false;
		
	}
	if (!(TestResult4 == FRotator(0.0, 135.0, 0.00)))
	{
		return false;
		
	}
	return true;
}



IMPLEMENT_SIMPLE_AUTOMATION_TEST(HandleLineFeeds, "Game.Util.UGolbalBPFunctionLibrary.HandleLineFeeds", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool HandleLineFeeds::RunTest(const FString& Parameters)
{
	FString TestHandleLineFeeds1, TestHandleLineFeeds2;
	FString TestHell0 = FString(TEXT("hello"));
	FString TestHell01 = FString(TEXT("hello\n"));

	TestHandleLineFeeds1 = UGolbalBPFunctionLibrary::HandleLineFeeds(TestHell0);
	TestHandleLineFeeds2 = UGolbalBPFunctionLibrary::HandleLineFeeds(TestHell01);
	if (!(TestHandleLineFeeds1 == TEXT("hello\n")))
	{
		return false;
	}
	if (!(TestHandleLineFeeds2 == TEXT("hello\n")))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(SetFontStyle, "Game.Util.UGolbalBPFunctionLibrary.SetFontStyle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool SetFontStyle::RunTest(const FString& Parameters)
{
	FString TestPath = "hello";
	FString TestType = "eye";
	FString TestSize = "one";
	FString TestColor = "blue";
	FString TestShadowColor = "two";
	FString TestShadowOffset = "red";
	FString TestFontStyle = UGolbalBPFunctionLibrary::SetFontStyle(TestPath, TestType, TestSize, TestColor, TestShadowColor, TestShadowOffset);

	if (!(TestFontStyle == TEXT("<text FontPath=hello FontType=eye FontSize=one Color=blue ShadowColor=two ShadowOffset=red>")))
	{
		return false;
	}

	return true;
}

/*
IMPLEMENT_SIMPLE_AUTOMATION_TEST(LessTmap, "Game.Util.UGolbalBPFunctionLibrary.LessTmap", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool LessTmap::RunTest(const FString& Parameters)
{
	//�ֵ��������ֵ��֪����ʲô����������ģ��ҿ���ͼ�Ǳ��Ǻ������ĸ��������������
	FString Test = "res";
	TMap<int32, AActor*> TestResult = UGolbalBPFunctionLibrary::LessTmap("weq");
	if ()
	{
	}
	return true;
}*/

/*
IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetFormatEmoteStr, "Game.Util.UGolbalBPFunctionLibrary.GetFormatEmoteStr", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetFormatEmoteStr::RunTest(const FString& Parameters)
{
	//�滻ԭ�ַ����������滻����ַ���������Ϸ���ԡ�
	FString Teststring = "afw[#:D]asdf";
	FString Teststring2 = "FFFFFFFF";
	FString TestFormatEmoteStr = UGolbalBPFunctionLibrary::GetFormatEmoteStr(Teststring, Teststring2);
	//û���滻���������ԭ�����ַ���[����ǲ���Ҫ���ⲿ�滻�ģ��ҿ������Ǳ�������ԴͼƬ��]
	if (TestFormatEmoteStr.IsEmpty())
	{
		CS3_Warning(TEXT("5 bytes"));
	}
	return true;
}*/

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetIntegerFieldByKey, "Game.Util.UGolbalBPFunctionLibrary.GetIntegerFieldByKey", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetIntegerFieldByKey::RunTest(const FString& Parameters)
{
	//�����ֵ��е�ֵ���оͷ���99��û�оͷ���-1���ֵ�ṹ�ַ�����ô����
	FString SrcString = TEXT("{\"money\":99,\"tongContribute\":100}");
	FString a = TEXT("money");
	
	int32 TestIntegerFieldByKey = UGolbalBPFunctionLibrary::GetIntegerFieldByKey(SrcString,a);
	if (!(TestIntegerFieldByKey == 99))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetFormatColorString, "Game.Util.UGolbalBPFunctionLibrary.GetFormatColorString", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetFormatColorString::RunTest(const FString& Parameters)
{
	//��Ϣ�ַ����滻���ı������˲��������ַ����޸�������ɫ,�������һ������ġ����� \"\"����
	FString FormatColorString = UGolbalBPFunctionLibrary::GetFormatColorString(FString(TEXT("a{1},b{0}|cd")));
	//FString TestResult = TEXT("\"<text color = \"#FFFFFFFF\">a</text >{1}<text color = \"#FFFFFFFF\">,b</text >{0}<text color = \"#FFFFFFFF\">|cd</text >\"");
	FString TestResult = TEXT("<text color=\"#FFFFFFFF\">a</text>{1}<text color=\"#FFFFFFFF\">,b</text>{0}<text color=\"#FFFFFFFF\">|cd</text>");

	if (!(FormatColorString.Equals(TestResult)))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetPercent, "Game.Util.UGolbalBPFunctionLibrary.GetPercent", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetPercent::RunTest(const FString& Parameters)
{
	int32 TestPercent1 = 100;
	int32 TestPercent2 = 200;
	FText TestPercent3;
	TestPercent3 = UGolbalBPFunctionLibrary::GetPercent(TestPercent1, TestPercent2);

	/*if (!(TestPercent3.ToString() == TEXT("50%")))
	{
		return false;
	}*/
	if (!(TestPercent3.ToString().Equals(TEXT("50%"))))
	{
		return false;
	}
	
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetWeekDayByDate, "Game.Util.UGolbalBPFunctionLibrary.GetWeekDayByDate", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetWeekDayByDate::RunTest(const FString& Parameters)
{
	//������ǲ���ûд�ԣ�FDateTime���壨�꣬�£��գ�
	FDateTime TestDate = FDateTime(2019,11,28);
	int32 Test = UGolbalBPFunctionLibrary::GetWeekDayByDate(TestDate);
	if (!(Test == 3))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetBloodStage, "Game.Util.UGolbalBPFunctionLibrary.GetBloodStage", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetBloodStage::RunTest(const FString& Parameters)
{
	//����1�Ƿ���ֵ������2��ǰѪ��������3���Ѫ��������4Ѫ�������������ǰѪ���ڵڼ���
	float TestBloodStage1;
	int32 TestBloodStage2 = 200;
	int32 TestBloodStage3;

	TestBloodStage3 = UGolbalBPFunctionLibrary::GetBloodStage(TestBloodStage1,60,200,4);

	if (!(TestBloodStage3 == 2))
	{
		return false;
	}
	return true;
}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetHoverTips, "Game.Util.UGolbalBPFunctionLibrary.GetHoverTips", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetHoverTips::RunTest(const FString& Parameters)
{

	//��ťtips����Ҫ���ݱ��ȡ���ǲ��ǵô��зֿ�,CSV_CONFIG_HOVER_TIPS_DATA���в���  TestResult = Empty
	FString Test = TEXT("xuanshi");
	FString TestResult = UGolbalBPFunctionLibrary::GetHoverTips(Test);
	if (!(TestResult.IsEmpty()))
	{
		return false;
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FromServerTimeToClientTime, "Game.Util.UGolbalBPFunctionLibrary.FromServerTimeToClientTime", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FromServerTimeToClientTime::RunTest(const FString& Parameters)
{


	FDateTime TestServerTimeToClientTime = UGolbalBPFunctionLibrary::FromServerTimeToClientTime(1);
	//��ȡ������е�����
	int a = TestServerTimeToClientTime.DaysInMonth(2016, 2);
	int b = TestServerTimeToClientTime.DaysInMonth(2018, 2);
	if (!(a==29))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	if (!(b==28))
	{
		return false;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetItemNameColorByQuality, "Game.Util.UGolbalBPFunctionLibrary.GetItemNameColorByQuality", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetItemNameColorByQuality::RunTest(const FString& Parameters)
{
	//������ɫ
	FLinearColor TestColorByQuality1 = UGolbalBPFunctionLibrary::GetItemNameColorByQuality(1);
	FLinearColor TestColorByQuality2 = UGolbalBPFunctionLibrary::GetItemNameColorByQuality(8);

	if (!(TestColorByQuality1.InitFromString(TEXT("R=1.00000000 G=1.00000000 B=1.00000000"))))
	{
		return false;
	}
	if (!(TestColorByQuality2.InitFromString(TEXT("R=1.00000000 G=1.00000000 B=1.00000000"))))
	{
		return false;
	}


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(GetItemNameByQuality, "Game.Util.UGolbalBPFunctionLibrary.GetItemNameByQuality", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool GetItemNameByQuality::RunTest(const FString& Parameters)
{
	FString TestNameByQuality = UGolbalBPFunctionLibrary::GetItemNameByQuality("white",1);
	FString TestNameByQuality2 = UGolbalBPFunctionLibrary::GetItemNameByQuality("blue",2);
	FString TestNameByQuality3 = UGolbalBPFunctionLibrary::GetItemNameByQuality("yellow",3);
	FString TestNameByQuality4 = UGolbalBPFunctionLibrary::GetItemNameByQuality("pink",4);
	FString TestNameByQuality7 = UGolbalBPFunctionLibrary::GetItemNameByQuality("green", 7);


	if (!(TestNameByQuality.Equals("<text color=\"#FFFFFFFF\">white</text>")))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
/*
	if (!(TestNameByQuality.Equals("<text color=\"#33CCFFFF\">��</text>")))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	if (!(TestNameByQuality7.Equals("<text color=\"#FFE036FF\">��</text>")))
	{

		return false;
	}
	if (!(TestNameByQuality7.Equals("<text color=\"#FF8080FF\">��</text>")))
	{

		return false;
	}
*/
	if (!(TestNameByQuality7.Equals("<text color=\"#64FF9FFF\">green</text>")))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	return true;
}



IMPLEMENT_SIMPLE_AUTOMATION_TEST(ConvertWorldLocationToMapPosition, "Game.Util.UGolbalBPFunctionLibrary.ConvertWorldLocationToMapPosition", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool ConvertWorldLocationToMapPosition::RunTest(const FString& Parameters)
{
	FVector2D position1 = FVector2D(10,10);
	FVector2D position2 = FVector2D(2, 2);
	FVector2D Test= UGolbalBPFunctionLibrary::ConvertWorldLocationToMapPosition(position1, position2,2.0);
	if (!(Test.Equals(FVector2D(4.0,4.0))))
	{
		//CS3_Warning(TEXT("5 bytes"));
		return false;
	}
	return true;
}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(ConvertWorldLocToSlotPos, "Game.Util.UGolbalBPFunctionLibrary.ConvertWorldLocToSlotPos", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool ConvertWorldLocToSlotPos::RunTest(const FString& Parameters)
{
	FVector2D a = FVector2D(2, 2);
	bool Test = UGolbalBPFunctionLibrary::ConvertWorldLocToSlotPos(FVector2D(10, 10),FVector2D(5, 5), FVector2D(2, 2),2.0,5.0, FVector2D(5, 5), FVector2D(10, 10), a);
	bool Test2 = UGolbalBPFunctionLibrary::ConvertWorldLocToSlotPos(FVector2D(20, 20), FVector2D(3, 3), FVector2D(10, 10), 2.0, 3.0, FVector2D(20, 20), FVector2D(10, 10), a);
	if (Test)
	{
		return false;
	}
	if (!(Test2))
	{
		return false;
	}
	return true;
}