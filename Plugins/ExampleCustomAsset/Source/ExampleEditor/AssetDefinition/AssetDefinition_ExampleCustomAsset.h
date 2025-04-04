// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Assets/ExampleCustomAsset.h"
#include "AssetDefinition_ExampleCustomAsset.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEEDITOR_API UAssetDefinition_ExampleCustomAsset : public UAssetDefinitionDefault
{
	GENERATED_BODY()

	// UAssetDefinition Begin
	virtual FText GetAssetDisplayName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_ExampleCustomAsset", "ExampleCustomAsset"); }
	virtual FLinearColor GetAssetColor() const override { return FColor::Turquoise; }
	virtual TSoftClassPtr<UObject> GetAssetClass() const override { return UExampleCustomAsset::StaticClass(); }
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override
	{
		static const auto Categories = { EAssetCategoryPaths::Misc };
		return Categories;
	}
	virtual UThumbnailInfo* LoadThumbnailInfo(const FAssetData& InAssetData) const override;
	virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& OpenArgs) const override;
	// UAssetDefinition End
};
