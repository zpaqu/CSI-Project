#pragma once
#include <list>
#include <memory>
#include "AnimalCard.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


class Hand
{
public:
	Hand();
	~Hand();
	std::list<std::shared_ptr<AnimalCard>> cards;
	int cardNumber;
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[] (int);
	int noCards();
	void print();

private:

};
