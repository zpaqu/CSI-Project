#pragma once
#include "Deck.h"
#include "AnimalCard.h"
#include "NoSplit.h"
#include "SplitFour.h"
#include "SplitThree.h"
#include "SplitTwo.h"

template <class T>
class Deck : public std::vector<T>
{
public:
	T draw();
	void add(T c);

private:

};

class AnimalCardFactory
{
public:
	Deck<AnimalCard> myDeck;
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard> getDeck();
	~AnimalCardFactory();
};

