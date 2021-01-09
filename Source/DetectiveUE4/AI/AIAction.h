// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "AIAction.generated.h"

UENUM()
enum EAIAction
{
	/*Use this when no response to anim is needed*/
	EAIA_None UMETA(DisplayName = "None"),
	EAIA_OpenDoor UMETA(DisplayName = "OpenDoor")
};
