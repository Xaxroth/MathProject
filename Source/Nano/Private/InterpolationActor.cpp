// Fill out your copyright notice in the Description page of Project Settings.


#include "InterpolationActor.h"

// Sets default values
AInterpolationActor::AInterpolationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInterpolationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterpolationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

