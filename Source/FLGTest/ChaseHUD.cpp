// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseHUD.h"
#include "SSpawnPromptWidget.h"
#include "SpawnButton.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

AChaseHUD::AChaseHUD()
{
	//ConstructorHelpers::FObjectFinder<ASpawnButton> spawnObj(TEXT("Blueprint'/Game/MySpawnButton.MySpawnButton'"));
	//spawnButton = spawnObj.Object;
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

void AChaseHUD::IsOverlapped()
{
	if ((spawnButton != nullptr) && (spawnButton->GetIsOverlapped() == true))
	{
		ShowHUD();
	}
}

void AChaseHUD::IsNotOverlapped()
{
	if ((spawnButton != nullptr) && (spawnButton->GetIsOverlapped() == false))
	{
		HideHUD();
	}
}