// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleCustomAssetFactory.h"
#include "Assets/ExampleCustomAsset.h"


UExampleCustomAssetFactory::UExampleCustomAssetFactory()
{
	SupportedClass = UExampleCustomAsset::StaticClass();
	bCreateNew = true;
}

UObject* UExampleCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UExampleCustomAsset>(InParent, InClass, InName, Flags, Context);
}

bool UExampleCustomAssetFactory::DoesSupportClass(UClass* Class)
{
	return Class->IsChildOf(UExampleCustomAsset::StaticClass());
}
