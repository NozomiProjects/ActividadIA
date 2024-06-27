// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::MoveForward(float value)
{
    AddMovementInput(GetActorForwardVector() * value);
}

void AMyCharacter::MoveRight(float value)
{
    AddMovementInput(GetActorRightVector() * value);
}

void AMyCharacter::Jump()
{
    Super::Jump();
}

void AMyCharacter::StopJumping()
{
    Super::StopJumping();
}

// Definición de funciones para saltar



// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Acciones para el movimiento
    // Sintaxis: &nombre-clase: NombreFuncion
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

    // Acciones para el salto
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);
}