// Fill out your copyright notice in the Description page of Project Settings.


#include "SSpawnPromptWidget.h"

void SSpawnPromptWidget::Construct(const FArguments& InArgs)
{
	const FText text = FText::FromString("Press E to spawn a chaser");

	const FMargin padding = FMargin(500.f, 300.f);

	FSlateFontInfo textStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	textStyle.Size = 25.f;

	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.VAlign(VAlign_Bottom)
		.Padding(padding)
		[
			SNew(STextBlock)
			.Font(textStyle)
			.Text(text)
			.ColorAndOpacity(FColor::Silver)
			.Justification(ETextJustify::Center)
		]
	];
}
