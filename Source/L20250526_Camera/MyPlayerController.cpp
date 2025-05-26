// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "MyCharacter.h"

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UE_LOG(LogTemp, Warning, TEXT("OnPossess"));

	AMyCharacter* MyPawn = Cast<AMyCharacter>(InPawn);

	if (IsValid(MyPawn))
	{
		if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (MyPawn->IMC_Default)
				{
					UE_LOG(LogTemp, Warning, TEXT("Test"));
					InputSystem->AddMappingContext(MyPawn->IMC_Default, 0);
				}
			}
		}
	}
}


void AMyPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}