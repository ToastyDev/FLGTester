// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnButton.h"
#include "Chaser.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASpawnButton::ASpawnButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereRadius = 200.f;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = mesh;
	
	sphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	sphereCollider -> InitSphereRadius(sphereRadius);
	sphereCollider -> SetCollisionProfileName("Trigger");
	sphereCollider -> SetupAttachment(mesh);
	
	textRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Render"));
	textRender->SetTextRenderColor(FColor::Red);
	textRender->SetRelativeLocation(FVector(0.f, 55.f, 40.f));
	textRender->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
	textRender->Text = FText::AsNumber(timesPressed);
	textRender->SetupAttachment(mesh);
}

// Called when the game starts or when spawned
void ASpawnButton::BeginPlay()
{
	Super::BeginPlay();
	
	bCanBePressed = true;
	bIsOverlapped = false;
}

// Called every frame
void ASpawnButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//DrawDebugSphere(GetWorld(), GetActorLocation(), sphereRadius, 20, FColor::Purple, false, -1, 0, 1);

}

void ASpawnButton::SpawnChaser()
{
	if (bCanBePressed && bIsOverlapped && (chaserClass != nullptr))
	{
		UWorld* const world = GetWorld();
		FVector const spawnLocation = FVector(-1030.f, -1240.f, 220.f);
		FRotator const spawnRotation = FRotator(0.f, 90.f, 0.f);
		FActorSpawnParameters spawnParams;
		world->SpawnActor<AChaser>(chaserClass, spawnLocation, spawnRotation, spawnParams);
		bCanBePressed = false;
		timesPressed += 1;
		textRender->SetText(FText::AsNumber(timesPressed));
	}
}

bool ASpawnButton::GetIsOverlapped()
{
	return bIsOverlapped;
}