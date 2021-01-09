// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class DETECTIVEUE4_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent*ItemMeshComponent;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Owner)
	AActor*HoldingActor = nullptr;

	//Instead of each item being thrown with the same power and some of them flying to space and others being too heavy - it's set per item
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Throwing)
	float ThrowingPower = 3000.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Physics)
	float MinHitPowerToPlaySound = 3000.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Physics)
	bool bPlayHitSound = true;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Physics)
	USoundBase*HitSound;
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void BeDropped();

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
    void BePickedUp(AActor*Holder);

	UFUNCTION(BlueprintPure)
	UStaticMeshComponent* GetItemMesh(){return ItemMeshComponent;}

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	bool CanBePickedUp();

	UFUNCTION(BlueprintNativeEvent)
	void OnMeshHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
