// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tools_TestGameMode.h"
#include "Tools_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATools_TestGameMode::ATools_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
