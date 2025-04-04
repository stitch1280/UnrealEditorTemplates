// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ExampleCustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEEDITOR_API UExampleCustomAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UExampleCustomAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

	virtual bool DoesSupportClass(UClass* Class) override;
};
