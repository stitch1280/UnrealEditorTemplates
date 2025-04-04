// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleCustomAssetToolkit.h"

#include "Assets/ExampleCustomAsset.h"

static FName LayoutName = "ExampleCustomAssetEditorLayout";
static FName DetailsTabName = "ExampleCustomAssetDetailsTab";

void FExampleCustomAssetToolkit::InitEditor(const TArray<UObject*>& InObjects)
{
	Asset = Cast<UExampleCustomAsset>(InObjects[0]);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout(LayoutName)
	->AddArea
	(
	FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
	->Split
	(
		FTabManager::NewSplitter()
		->SetSizeCoefficient(0.6f)
		->SetOrientation(Orient_Horizontal)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.2f)
			->AddTab(DetailsTabName, ETabState::OpenedTab)
		)
	)
	->Split
	(
		FTabManager::NewStack()
		->SetSizeCoefficient(0.4f)
		->AddTab("OutputLog", ETabState::OpenedTab)
	)
	);
	FAssetEditorToolkit::InitAssetEditor(EToolkitMode::Standalone, {}, "ExampleCustomAssetEditor", Layout, true, true, InObjects);
}

void FExampleCustomAssetToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
 
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("ExampleCustomAsset Editor"));
 	
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bAllowSearch = true;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
 	
	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->SetObjects(TArray<UObject*>{ Asset });
	InTabManager->RegisterTabSpawner(DetailsTabName, FOnSpawnTab::CreateLambda([DetailsView](const FSpawnTabArgs&)
	{
		return SNew(SDockTab)
		[
			DetailsView
		];
	}))
	.SetDisplayName(INVTEXT("Details"))
	.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FExampleCustomAssetToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
 
	InTabManager->UnregisterTabSpawner(DetailsTabName);
}
