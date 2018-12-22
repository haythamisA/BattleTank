// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))//, hideCategories = ("Collision"))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	
	UTankTrack();

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void ApplySidewaysForce();


	void DriveTrack();

	float CurrentThrottle = 0;

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000.f;


protected:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
