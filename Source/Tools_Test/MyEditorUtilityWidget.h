// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "MyEditorUtilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOOLS_TEST_API UMyEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	void RenameSelectedAssets(const FString& Prefix, const FString& Suffix);
};
