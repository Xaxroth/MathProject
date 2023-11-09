// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefaultActor.generated.h"

UENUM(BlueprintType)
enum class MovementState : uint8
{
	Interpolate,
	Curve,
	Default,
};

UCLASS()
class NANO_API ADefaultActor : public AActor
{
	GENERATED_BODY()

	MovementState State;

public:
	ADefaultActor();

	UFUNCTION(BlueprintCallable, Category = "Interpolation")
	void Interpolate(float DeltaTime, bool ExitAtFullCharge);

	bool Interpolating = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	float InterpolationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	float ChargeSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	float ChargeRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	AActor* TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	FTransform StartTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	FTransform TargetTransform;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
