// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectiveUE4/Item/ItemBase.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	//For proper physics and saving mesh should be the root
	RootComponent = ItemMeshComponent;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AItemBase::CanBePickedUp_Implementation()
{
	if(HoldingActor){return false;}
	return true;
}

void AItemBase::OnMeshHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(ItemMeshComponent->IsSimulatingPhysics() && HitSound && GetWorld())
	{
		if(GetVelocity().Size()*ItemMeshComponent->GetMass() >= MinHitPowerToPlaySound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(),HitSound,GetActorLocation(),GetActorRotation());
		}
	}
}

void AItemBase::BePickedUp_Implementation(AActor*Holder)
{
	if(Holder)
	{
		ItemMeshComponent->SetSimulatePhysics(false);
		ItemMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SetOwner(Holder);
		HoldingActor = Holder;
	}
}

void AItemBase::BeDropped_Implementation()
{
	ItemMeshComponent->SetSimulatePhysics(true);
	ItemMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetOwner(nullptr);
	HoldingActor = nullptr;
}

