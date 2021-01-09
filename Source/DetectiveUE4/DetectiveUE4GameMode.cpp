// Copyright Epic Games, Inc. All Rights Reserved.

#include "DetectiveUE4GameMode.h"
#include "DetectiveUE4HUD.h"
#include "DetectiveUE4Character.h"
#include "UObject/ConstructorHelpers.h"

ADetectiveUE4GameMode::ADetectiveUE4GameMode()
	: Super()
{
	// use our custom HUD class
	HUDClass = ADetectiveUE4HUD::StaticClass();
}
