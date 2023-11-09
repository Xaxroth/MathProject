// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultActor.h"

ADefaultActor::ADefaultActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADefaultActor::BeginPlay()
{
	Super::BeginPlay();

	FString DebugMessage = TEXT("DefaultActor in Scene");
	float TimeToDisplay = 5.0f;
	FColor DebugTextColor = FColor::Green;

	GEngine->AddOnScreenDebugMessage(-1, TimeToDisplay, DebugTextColor, DebugMessage);

	State = MovementState::Interpolate;
}

void ADefaultActor::Interpolate(float DeltaTime, bool ExitAtFullCharge)
{
	if (TargetActor != nullptr)
	{
		float InterpolationFactor = 0.5f + 0.5f * FMath::Sin(ChargeSpeed * GetWorld()->GetTimeSeconds());

		float InterpolatedFloat = FMath::Lerp(0.0f, ChargeRange, InterpolationFactor);

		FString DebugMessage = FString::Printf(TEXT("Interpolated Float Value: %.2f"), InterpolatedFloat);
		float TimeToDisplay = 5.0f;
		FColor DebugTextColor = FColor::Green;

		GEngine->AddOnScreenDebugMessage(-1, TimeToDisplay, DebugTextColor, DebugMessage);

		FVector NewScale = FVector::OneVector * InterpolatedFloat;
		SetActorScale3D(NewScale);

		if (InterpolatedFloat == ChargeRange && ExitAtFullCharge) {
			State = MovementState::Default;
		}
	}
}

void ADefaultActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (State) {
		case MovementState::Interpolate:
			Interpolate(DeltaTime, true);
			break;
		case MovementState::Default:
			break;
	}

}

