// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ChaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLGTEST_API AChaseHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AChaseHUD();

	void ShowHUD();
	void HideHUD();

	UFUNCTION()
	void ShowGameOver();

	UFUNCTION()
	void HideGameOver();

	UPROPERTY(VisibleAnywhere)
	int32 score;

protected:

	TSharedPtr<class SSpawnPromptWidget> spawnWidget;
	TSharedPtr<class SWidget> widgetContainer;

	TSharedPtr<class SGameOverWidget> gameOverWidget;
	TSharedPtr<class SWidget> gameOverWidgetContainer;

	virtual void BeginPlay() override;
};
