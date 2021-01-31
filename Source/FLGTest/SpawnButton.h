// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnButton.generated.h"

UCLASS()
class FLGTEST_API ASpawnButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnButton();

	UPROPERTY(VisibleAnywhere)
	bool bCanBePressed;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
	class USphereComponent* sphereCollider;

	UPROPERTY(EditAnywhere)
	float sphereRadius;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AChaser> chaserClass;

	UPROPERTY(VisibleAnywhere)
	int32 timesPressed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void SpawnChaser();

	UPROPERTY()
	bool bIsOverlapped;

	UFUNCTION()
	bool GetIsOverlapped();

};
