// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetDefinition_ExampleCustomAsset.h"
#include "Toolkit/ExampleCustomAssetToolkit.h"


UThumbnailInfo* UAssetDefinition_ExampleCustomAsset::LoadThumbnailInfo(const FAssetData& InAssetData) const
{
	return Super::LoadThumbnailInfo(InAssetData);
}

EAssetCommandResult UAssetDefinition_ExampleCustomAsset::OpenAssets(const FAssetOpenArgs& OpenArgs) const
{
	MakeShared<FExampleCustomAssetToolkit>()->InitEditor(OpenArgs.LoadObjects<UObject>());
	return EAssetCommandResult::Handled;
}
