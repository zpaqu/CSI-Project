#pragma once
#include "Deck.h"
#include "AnimalCard.h"
#include "NoSplit.h"
#include "SplitFour.h"
#include "SplitThree.h"
#include "SplitTwo.h"

<<<<<<< HEAD
template <class T>
class Deck : public std::vector<T>
{
public:
	T draw();
	void add(T c);

private:

};
=======
//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015
>>>>>>> origin/master

class AnimalCardFactory
{
public:
	Deck<AnimalCard> myDeck;
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard> getDeck();
	~AnimalCardFactory();
};

