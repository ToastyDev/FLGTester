// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Chaser.generated.h"

UENUM()
enum class Mode : uint8
{
	WANDER,
	CHASE,
	RETREAT
};

UCLASS()
class FLGTEST_API AChaser : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChaser();

	UPROPERTY(EditAnywhere)
	class UPawnSensingComponent* pawnSensingComponent;

	UPROPERTY()
	Mode currentMode = Mode::WANDER;

	UPROPERTY(EditAnywhere, Category = "AI Variables")
	float sightRange;

	UPROPERTY(EditAnywhere, Category = "AI Variables")
	float peripheralVisionAngle;

	UPROPERTY(EditAnywhere, Category = "AI Variables")
	float nextMoveDelay;

	UPROPERTY(EditAnywhere, Category = "AI Variables")
	float chaseSpeed;

	UPROPERTY(EditAnywhere, Category = "AI Variables")
	float wanderSpeed;

	UPROPERTY(VisibleAnywhere)
	bool bIsAtDestination;

	UPROPERTY(VisibleAnywhere)
	class AChaseAIController* chaseAIController;

	UPROPERTY()
	FVector savedLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnSeePlayer(APawn* pawn);

	UFUNCTION()
	void WalkToPoint(FVector location);

	UFUNCTION()
	void SetChaseState();

	UFUNCTION()
	void SetRetreatState();

	UFUNCTION()
	void SetWanderState();
};
