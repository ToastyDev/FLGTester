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

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* sphereCollider;

	UPROPERTY(BlueprintReadWrite)
	float sphereRadius;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class AChaser> chaserClass;

	UPROPERTY(VisibleAnywhere)
	int32 timesPressed;

	UPROPERTY(VisibleAnywhere)
	class UTextRenderComponent* textRender;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void SpawnChaser();

	UPROPERTY(VisibleAnywhere)
	bool bIsOverlapped;

	UFUNCTION()
	bool GetIsOverlapped();

};
