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
	Deck<std::shared_ptr<AnimalCard>> myDeck;
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();
	~AnimalCardFactory();
};

