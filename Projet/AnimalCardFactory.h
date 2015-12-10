#pragma once
#include "Deck.h"
#include "AnimalCard.h"
#include "NoSplit.h"
#include "SplitFour.h"
#include "SplitThree.h"
#include "SplitTwo.h"


//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

class AnimalCardFactory
{
public:
	Deck<AnimalCard> myDeck;
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard> getDeck();
	~AnimalCardFactory();
};

