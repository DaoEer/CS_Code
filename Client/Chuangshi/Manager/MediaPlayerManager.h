// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "../MediaAssets/Public/MediaPlayer.h"
#include "GameData/MediaPlayerData.h"
#include "MediaPlayerManager.generated.h"

DECLARE_MULTICAST_DELEGATE(FLoadMediaOverDelegate);
DECLARE_MULTICAST_DELEGATE(FOnMediaEndReachedDelegate);
DECLARE_MULTICAST_DELEGATE(FOnMediaOpenedDelegate);

/*
* �ļ����ƣ�MediaPlayerManager.h
* ����˵����ý�������
* �ļ����ߣ�huting
* Ŀǰά����huting
* ����ʱ�䣺2018-9-18
*/
UCLASS()
class CHUANGSHI_API UMediaPlayerManager : public UCS3Object
{
	GENERATED_BODY()
public:
	static UMediaPlayerManager* GetInstance();

	UFUNCTION(BlueprintNativeEvent, Category = "Media|MediaPlayer")
		void OnInitMediaPlayer();///<BlueprintNativeEvent,��ʼ��MediaPlayer
	/**
	* Close the currently open media, if any.
	*
	* @see OnMediaClosed, OpenPlaylist, OpenPlaylistIndex, OpenSource, OpenUrl, Pause, Play
	*/
	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		void Close(bool bIsForcedClose = false);
	/**
	* Pauses media playback.
	*
	* This is the same as setting the playback rate to 0.0.
	*
	* @return true if playback is being paused, false otherwise.
	* @see CanPause, Close, Next, Play, Previous, Rewind, Seek
	*/
	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		bool Pause();

	/**
	* Starts media playback.����
	*
	* This is the same as setting the playback rate to 1.0.
	*
	* @return true if playback is starting, false otherwise.
	* @see CanPlay, GetRate, Next, Pause, Previous, SetRate
	*/
	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		bool Play();

	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		bool Rewind();///<���ع��ܻ��˵���ʼλ��
	/**
	 * Changes the media's playback rate.�����+�����ˣ�-��
	 *
	 * @param Rate The playback rate to set.
	 * @return true on success, false otherwise.
	 * @see GetRate, SupportsRate
	 */
	UFUNCTION(BlueprintCallable, Category="Media|MediaPlayer")
	bool SetRate(float Rate);
	/**
	* Open the specified media source.��ǰý���Ǵ򿪾Ͳ���
	*
	* A return value of true indicates that the player will attempt to open
	* the media, but it may fail to do so later for other reasons, i.e. if
	* a connection to the media server timed out. Use the OnMediaOpened and
	* OnMediaOpenFailed delegates to detect if and when the media is ready!
	*
	* @param MediaSource The media source to open.
	* @return true if the source will be opened, false otherwise.
	* @see Close, OpenFile, OpenPlaylist, OpenPlaylistIndex, OpenUrl, Reopen
	*/
	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		bool OpenSource(UMediaSource* MediaSource);

	///<����ý�����һЩ������رս��桢�������롢������� ��Ϸ����һ�㲥��ý��Ľӿ� Play()����ֻ�ǲ��Ų����ж��������ͣ��֮���ڲ���ʹ��Play()
	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		void PlayMedia(FString MediaPlayerId);

	UFUNCTION()
		void OnEndReached();///<ý�岥������¼��ص�����	
	UFUNCTION()
		void OnMediaClosed();///<ý��ر��¼��ص�����	
	UFUNCTION()
		void OnMediaOpened(FString OpenedUrl);///<ý����¼��ص�����
	UFUNCTION()
		void OnMediaOpenFailed(FString FailedUrl);///<ý���ʧ���¼��ص�����

	int PreLoadMediaAsset(const FLoadMediaOverDelegate& InLoadMediaOverDelegate = FLoadMediaOverDelegate());
	void PreLoadMediaAssetByGameStatus();///<����һ�û�н�������֮ǰ����ý����Դ�����ڵ�¼����ʱ��ҪԤ����CG����ѡ���ɫ����Ԥ����CG��
	void PreLoadAllMediaAsset();///<Ԥ�������е�ý����Դ
	void ClearMediaAsset();///<�л��ؿ�ʱ���Ԥ���ص�ý����Դ

	bool IsNeedHideUI();///<��ý�岥��ʱ�Ƿ���Ҫ���ؽ���

	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		void GetSkipTimeData(float& HoldTime, float& CurTime, float& SkipTime,bool& bIsCanSkip,bool& bIsShowUI);///<��ȡ��ǰ��������ʱ��

	UFUNCTION(BlueprintImplementableEvent, Category = "Media|MediaPlayer")
	void OnShowMediaSkipTime_BP();

	bool IsStopLoadingLevel();
	bool IsStopInWorldOver();

	bool IsCanStopByMinimumTime() { return bIsCanStopByMinimumTime; };

	UFUNCTION(BlueprintCallable, Category = "Media|MediaPlayer")
		bool IsPlaying();///<��ǰ�Ƿ����ڲ�����

private:
	void DelayRemoveCGWindow();///<�ر�CG����
	void OnEnableInput(bool bIsEnable);///<�����������ô���
	/**
	*��ȡý���������
	*
	*@param MediaPlayerId ý��ID
	*
	*@return FSTORY_DATA* ý������
	*/
	const FMEDIA_PLAYER_DATA* GetMediaPlayerData(const FString& MediaPlayerId);

	void OnMediaStoped();///<ý��������߹ر��¼�����Ҫ������߼�
	void StartPlayMedia(TSoftObjectPtr<UMediaSource> MediaAss, const FString& MediaId);///<��ȡ����Դ��ʼ����ý��
	void GetMediaSource(TSoftObjectPtr<UMediaSource> MediaAss, const FString& MediaId);///<��ȡҪ���ŵ�ý����Դ

	void LoadMediaAssetEnd(TSoftObjectPtr<UMediaSource> MediaAss = nullptr);///<���ص�����Դ����
	void LoadMediaAsset(FString MediaID, TSoftObjectPtr<UMediaSource> MediaAss);///<���ص�����Դ

	void ClearMediaEvent();///<���ý���¼�
	void ResetMediaData();///<����ý������ ����Դ֮��

	UFUNCTION()
		void InWorldLoadingOverEvent(); 

	void onNotifyServerEvent(FString Params);
public:
	UPROPERTY(BlueprintReadWrite)
		UMediaPlayer*  MediaPlayer;///<ý�岥����
	UPROPERTY(BlueprintReadWrite)
		FString  CurMediaPlayerId = TEXT("");///<��ǰý�岥��ID
	UPROPERTY(BlueprintReadOnly)
		TMap<FString, UMediaSource*>MediaAssList;///<�ؿ�ý����Դ�б�
	UPROPERTY(BlueprintReadOnly)
		TMap<FString, TSoftObjectPtr<UMediaSource>>MediaAss;///<ý�������Դ
	UPROPERTY(BlueprintReadOnly)
		TMap<FString, TSoftObjectPtr<UMediaSource>>AllMediaAss;///<��ǰ��ͼ������ҪԤ����ý����Դ
	FOnMediaOpenedDelegate OnMediaOpenedDelegate;///<ý��򿪳ɹ������¼�
	FOnMediaEndReachedDelegate  OnMediaEndReachedDelegate;///<ý�岥������¼�
private:
	FLoadMediaOverDelegate LoadMediaOverDelegate;///<ý������¼�ί��
	FTimerHandle DelayLoadAllMediaHandle;///<��������ý����Դ��ʱ��
	FTimerHandle MinimumTimeHandle;///<��Сʱ�䶨ʱ��
	bool bIsCanStopByMinimumTime = true;///<�Ƿ�ﵽ��Сʱ��ֹͣ����
	bool bIsStopByLoadingOver = true; ///<��Ϸ״̬��Ϊ����״̬���ؽ���
};
