// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DetectiveUE4HUD.generated.h"

UCLASS()
class ADetectiveUE4HUD : public AHUD
{
	GENERATED_BODY()

public:
	ADetectiveUE4HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

