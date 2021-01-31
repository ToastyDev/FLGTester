// Fill out your copyright notice in the Description page of Project Settings.


#include "SSpawnPromptWidget.h"

void SSpawnPromptWidget::Construct(const FArguments& InArgs)
{
	const FText text = FText::FromString("Press E to spawn a chaser");

	FSlateFontInfo textStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	textStyle.Size = 50.f;

	ChildSlot
	[
		SNew(STextBlock)
		.Font(textStyle)
		.Text(text)
		.Justification(ETextJustify::Center)
	];
}
