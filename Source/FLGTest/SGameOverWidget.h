// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class  SGameOverWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameOverWidget) {}
	SLATE_ARGUMENT(TWeakObjectPtr<class AChaseHUD>, OwningHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AChaseHUD> OwningHUD;

	FReply OnPlayAgainClicked() const;

	FReply OnQuitClicked() const;
};
