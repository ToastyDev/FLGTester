// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameOverWidget.h"
#include "ChaseHUD.h"
#include "GameFramework/PlayerController.h"

void SGameOverWidget::Construct(const FArguments & InArgs)
{
	OwningHUD = InArgs._OwningHUD;

	const FText text = FText::FromString("Press E to spawn a chaser");
	const FText gameOverText = FText::FromString("Game Over");
	const FText playAgainText = FText::FromString("Play Again");
	const FText quitText = FText::FromString("Quit");

	const FMargin contentPadding = FMargin(500.f, 300.f);
	const FMargin buttonPadding = FMargin(10.f);

	FSlateFontInfo textStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	textStyle.Size = 50.f;

	FSlateFontInfo buttonStyle = textStyle;
	buttonStyle.Size = 45.f;

	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Silver)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(contentPadding)
		[
			SNew(SVerticalBox)
			//game over text
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(textStyle)
				.Text(gameOverText)
				.Justification(ETextJustify::Center)
			]
			//play again button
			+SVerticalBox::Slot()
			.Padding(buttonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SGameOverWidget::OnPlayAgainClicked)
				[
					SNew(STextBlock)
					.Font(buttonStyle)
					.Text(playAgainText)
					.Justification(ETextJustify::Center)
				]
			]
			//quit button
			+ SVerticalBox::Slot()
			.Padding(buttonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SGameOverWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(buttonStyle)
					.Text(quitText)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}

FReply SGameOverWidget::OnPlayAgainClicked() const
{
	if (OwningHUD.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("play again clicked"));
		OwningHUD->HideGameOver();
	}
	
	return FReply::Handled();
}

FReply SGameOverWidget::OnQuitClicked() const
{
	if (OwningHUD.IsValid())
	{
		if (APlayerController* playerController = OwningHUD->PlayerOwner)
		{
			playerController->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}