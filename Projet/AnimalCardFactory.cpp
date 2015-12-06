#include "AnimalCardFactory.h"
#include "DeerAction.h"
#include "BearAction.h"
#include "WolfAction.h"
#include "HareAction.h"
#include "MooseAction.h"
#include "Joker.h"
#include <algorithm>
#include <random>


AnimalCardFactory::AnimalCardFactory()
{
	char bear='b';
	char moose='m';
	char dear='d';
	char wolf='w';
	char hare = 'h';
	char* animals = new char[5];
	animals[0] = bear;
	animals[1] = moose;
	animals[2] = dear;
	animals[3] = wolf;
	animals[4] = hare;


	//5 nosplit

	myDeck.add(NoSplit(animals[0]));
	myDeck.add(NoSplit(animals[1]));
	myDeck.add(NoSplit(animals[2]));
	myDeck.add(NoSplit(animals[3]));
	myDeck.add(NoSplit(animals[4]));


	//10 splittwo
	myDeck.add(SplitTwo(animals[0], animals[1]));
	myDeck.add(SplitTwo(animals[1], animals[2]));
	myDeck.add(SplitTwo(animals[2], animals[3]));
	myDeck.add(SplitTwo(animals[3], animals[4]));
	myDeck.add(SplitTwo(animals[4], animals[0]));
	myDeck.add(SplitTwo(animals[0], animals[2]));
	myDeck.add(SplitTwo(animals[1], animals[3]));
	myDeck.add(SplitTwo(animals[2], animals[4]));
	myDeck.add(SplitTwo(animals[3], animals[0]));
	myDeck.add(SplitTwo(animals[4], animals[1]));

	//20 splitTree
	myDeck.add(SplitThree(animals[0], animals[1], animals[2]));
	myDeck.add(SplitThree(animals[0], animals[1], animals[3]));
	myDeck.add(SplitThree(animals[0], animals[2], animals[4]));
	myDeck.add(SplitThree(animals[0], animals[2], animals[1]));
	myDeck.add(SplitThree(animals[1], animals[3], animals[4]));
	myDeck.add(SplitThree(animals[1], animals[3], animals[0]));
	myDeck.add(SplitThree(animals[1], animals[4], animals[2]));
	myDeck.add(SplitThree(animals[1], animals[4], animals[3]));
	myDeck.add(SplitThree(animals[2], animals[0], animals[1]));
	myDeck.add(SplitThree(animals[2], animals[0], animals[3]));
	myDeck.add(SplitThree(animals[2], animals[3], animals[4]));
	myDeck.add(SplitThree(animals[2], animals[3], animals[0]));
	myDeck.add(SplitThree(animals[3], animals[4], animals[0]));
	myDeck.add(SplitThree(animals[3], animals[4], animals[1]));
	myDeck.add(SplitThree(animals[3], animals[0], animals[2]));
	myDeck.add(SplitThree(animals[3], animals[0], animals[4]));
	myDeck.add(SplitThree(animals[4], animals[1], animals[0]));
	myDeck.add(SplitThree(animals[4], animals[1], animals[2]));
	myDeck.add(SplitThree(animals[4], animals[2], animals[1]));
	myDeck.add(SplitThree(animals[4], animals[2], animals[3]));


			//15 splitFour
	myDeck.add(SplitFour(animals[0], animals[1], animals[2], animals[3]));	
	myDeck.add(SplitFour(animals[0], animals[2], animals[3], animals[4]));	
	myDeck.add(SplitFour(animals[0], animals[3], animals[4], animals[1]));
	myDeck.add(SplitFour(animals[1], animals[4], animals[0], animals[2]));
	myDeck.add(SplitFour(animals[1], animals[0], animals[2], animals[3]));
	myDeck.add(SplitFour(animals[1], animals[2], animals[3], animals[4]));
	myDeck.add(SplitFour(animals[2], animals[3], animals[4], animals[1]));
	myDeck.add(SplitFour(animals[2], animals[4], animals[1], animals[0]));
	myDeck.add(SplitFour(animals[2], animals[1], animals[0], animals[3]));
	myDeck.add(SplitFour(animals[3], animals[0], animals[1], animals[4]));
	myDeck.add(SplitFour(animals[3], animals[2], animals[4], animals[0]));
	myDeck.add(SplitFour(animals[3], animals[4], animals[1], animals[0]));
	myDeck.add(SplitFour(animals[4], animals[1], animals[0], animals[2]));
	myDeck.add(SplitFour(animals[4], animals[0], animals[3], animals[2]));
	myDeck.add(SplitFour(animals[4], animals[3], animals[2], animals[1]));

	//15 actioncard
	myDeck.add(DeerAction());
	myDeck.add(BearAction());
	myDeck.add(WolfAction());
	myDeck.add(HareAction());
	myDeck.add(MooseAction());
	myDeck.add(DeerAction());
	myDeck.add(BearAction());
	myDeck.add(WolfAction());
	myDeck.add(HareAction());
	myDeck.add(MooseAction());
	myDeck.add(DeerAction());
	myDeck.add(BearAction());
	myDeck.add(WolfAction());
	myDeck.add(HareAction());
	myDeck.add(MooseAction());

	//joker
	myDeck.add(Joker());

	delete animals;

}

AnimalCardFactory * AnimalCardFactory::getFactory()
{
	return nullptr;
}

Deck<std::shared_ptr<AnimalCard>> AnimalCardFactory::getDeck()
{
	std::random_shuffle(std::begin(myDeck), std::end(myDeck));
	return myDeck;
}


AnimalCardFactory::~AnimalCardFactory()
{
	
}
