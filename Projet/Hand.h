#pragma once
#include <list>
#include <memory>
#include "AnimalCard.h"


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
