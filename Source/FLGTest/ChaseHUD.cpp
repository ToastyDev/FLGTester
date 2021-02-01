// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseHUD.h"
#include "SSpawnPromptWidget.h"
#include "SGameOverWidget.h"
#include "SpawnButton.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

AChaseHUD::AChaseHUD()
{
}

void AChaseHUD::BeginPlay()
{
	Super::BeginPlay();
	HideHUD();
}

void AChaseHUD::ShowHUD()
{
	if (GEngine && GEngine->GameViewport)
	{
		spawnWidget = SNew(SSpawnPromptWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(widgetContainer, SWeakWidget).PossiblyNullContent(spawnWidget.ToSharedRef()));
	}
}

void AChaseHUD::HideHUD()
{
	if (GEngine && GEngine->GameViewport && widgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(widgetContainer.ToSharedRef());
	}
}

void AChaseHUD::ShowGameOver()
{
	if (GEngine && GEngine->GameViewport)
	{
		gameOverWidget = SNew(SGameOverWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(gameOverWidgetContainer, SWeakWidget).PossiblyNullContent(gameOverWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AChaseHUD::HideGameOver()
{
	if (GEngine && GEngine->GameViewport && gameOverWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(gameOverWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}