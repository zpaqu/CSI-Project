#include "AnimalCardFactory.h"
#include "DeerAction.h"
#include "BearAction.h"
#include "WolfAction.h"
#include "HareAction.h"
#include "MooseAction.h"
#include "Joker.h"
#include <algorithm>
#include <random>

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

<<<<<<< HEAD
template <class T>
T Deck<T>::draw()
{
	return pop_back();
}

template<class T>
void Deck<T>::add(T t)
{
	push_back(t);
}


=======

//Lorssqu'une AnimalCardFactory est cree, on ajoute toute les possibilites de carte dans un Deck de type AnimalCard
>>>>>>> origin/master
AnimalCardFactory::AnimalCardFactory()
{
	
	char* animals = new char[5];
	animals[0] = 'b';
	animals[1] = 'm';
	animals[2] = 'd';
	animals[3] = 'w';
	animals[4] = 'h';


	//5 nosplit

	myDeck.add(NoSplit(animals[0]));
	myDeck.add(NoSplit(animals[1]));
	myDeck.add(NoSplit(animals[2]));
	myDeck.add(NoSplit(animals[3]));
	myDeck.add(NoSplit(animals[4]));


	//10 splittwo
	myDeck.add(SplitTwo(animals[0], animals[0], animals[1], animals[1]));
	myDeck.add(SplitTwo(animals[1], animals[1], animals[2], animals[2]));
	myDeck.add(SplitTwo(animals[2], animals[2], animals[3], animals[3]));
	myDeck.add(SplitTwo(animals[3], animals[3], animals[4], animals[4]));
	myDeck.add(SplitTwo(animals[4], animals[4], animals[0], animals[0]));
	myDeck.add(SplitTwo(animals[0], animals[2], animals[0], animals[2]));
	myDeck.add(SplitTwo(animals[1], animals[3], animals[1], animals[3]));
	myDeck.add(SplitTwo(animals[2], animals[4], animals[2], animals[4]));
	myDeck.add(SplitTwo(animals[3], animals[0], animals[3], animals[0]));
	myDeck.add(SplitTwo(animals[4], animals[1], animals[4], animals[1]));

	//20 splitTree
	myDeck.add(SplitThree(animals[0], animals[0], animals[1], animals[2]));
	myDeck.add(SplitThree(animals[0], animals[1], animals[0], animals[3]));
	myDeck.add(SplitThree(animals[0], animals[2], animals[4], animals[2]));
	myDeck.add(SplitThree(animals[0], animals[2], animals[1], animals[1]));
	myDeck.add(SplitThree(animals[1], animals[1], animals[3], animals[4]));
	myDeck.add(SplitThree(animals[1], animals[3], animals[1], animals[0]));
	myDeck.add(SplitThree(animals[1], animals[4], animals[2], animals[4]));
	myDeck.add(SplitThree(animals[1], animals[4], animals[3], animals[3]));
	myDeck.add(SplitThree(animals[2], animals[2], animals[0], animals[1]));
	myDeck.add(SplitThree(animals[2], animals[0], animals[2], animals[3]));
	myDeck.add(SplitThree(animals[2], animals[3], animals[4], animals[3]));
	myDeck.add(SplitThree(animals[2], animals[3], animals[0], animals[0]));
	myDeck.add(SplitThree(animals[3], animals[3], animals[4], animals[0]));
	myDeck.add(SplitThree(animals[3], animals[4], animals[3], animals[1]));
	myDeck.add(SplitThree(animals[3], animals[0], animals[2], animals[0]));
	myDeck.add(SplitThree(animals[3], animals[0], animals[4], animals[4]));
	myDeck.add(SplitThree(animals[4], animals[4], animals[1], animals[0]));
	myDeck.add(SplitThree(animals[4], animals[1], animals[4], animals[2]));
	myDeck.add(SplitThree(animals[4], animals[2], animals[1], animals[2]));
	myDeck.add(SplitThree(animals[4], animals[2], animals[3], animals[3]));


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

//Retourne un pointeur a une nouvelle AnimalCardFactory
AnimalCardFactory * AnimalCardFactory::getFactory()
{
	AnimalCardFactory * fact = new AnimalCardFactory();
	return fact;
}

//Retourne le Deck brasser
Deck<AnimalCard> AnimalCardFactory::getDeck()
{
	std::random_shuffle(std::begin(myDeck), std::end(myDeck));
	return myDeck;
}


AnimalCardFactory::~AnimalCardFactory()
{
	
}
