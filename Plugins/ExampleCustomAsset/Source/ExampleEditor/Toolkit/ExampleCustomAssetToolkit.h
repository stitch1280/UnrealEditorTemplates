// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UExampleCustomAsset;
/**
 * 
 */
	class EXAMPLEEDITOR_API FExampleCustomAssetToolkit : public FAssetEditorToolkit
{
public:

	void InitEditor(const TArray<UObject*>& InObjects);
 
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
 
	virtual FName GetToolkitFName() const override { return "ExampleCustomAssetEditor"; }
	virtual FText GetBaseToolkitName() const override { return INVTEXT("ExampleCustomAsset Editor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return "ExampleCustomAsset"; }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return {}; }
 
private:
	UExampleCustomAsset* Asset = nullptr;
};
