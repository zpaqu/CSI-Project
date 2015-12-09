#pragma once
#include "Deck.h"
#include "AnimalCard.h"
#include "NoSplit.h"
#include "SplitFour.h"
#include "SplitThree.h"
#include "SplitTwo.h"

class AnimalCardFactory
{
public:
	Deck<AnimalCard> myDeck;
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard> getDeck();
	~AnimalCardFactory();
};

