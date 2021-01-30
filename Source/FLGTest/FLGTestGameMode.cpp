// Copyright Epic Games, Inc. All Rights Reserved.

#include "FLGTestGameMode.h"
#include "FLGTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFLGTestGameMode::AFLGTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
