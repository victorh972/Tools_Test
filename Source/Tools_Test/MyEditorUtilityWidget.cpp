// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditorUtilityWidget.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Editor.h"

void UMyEditorUtilityWidget::RenameSelectedAssets(const FString& Prefix, const FString& Suffix)
{
    // Get the currently selected assets in the Content Browser
    TArray<FAssetData> SelectedAssets;
    GEditor->GetContentBrowserSelections(SelectedAssets);

    if (SelectedAssets.Num() <= 0)
    {
        GLog->Log("No assets selected.");
        return;
    }

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

    for (const FAssetData& Asset : SelectedAssets)
    {
        FString NewName = Prefix + Asset.AssetName.ToString() + Suffix;
        FString NewObjectPath = Asset.PackagePath.ToString() + "/" + NewName;

        // Check if the asset with the new name already exists
        if (AssetRegistryModule.Get().GetAssetByObjectPath(*NewObjectPath).IsValid())
        {
            GLog->Log("An asset with the name " + NewName + " already exists.");
            continue;
        }

        // Rename the asset
        TArray<FAssetRenameData> AssetsToRename;
        AssetsToRename.Add(FAssetRenameData(Asset.GetAsset(), Asset.PackagePath, NewName));
        AssetTools.RenameAssets(AssetsToRename);
    }
}