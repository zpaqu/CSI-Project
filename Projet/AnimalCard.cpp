#include "AnimalCard.h"
	
AnimalCard::AnimalCard()
{

}
	
AnimalCard::~AnimalCard()
{

}

void AnimalCard::setOrientation(Orientation o)
{
	orient = o;
	return;
}

void AnimalCard::setRow(EvenOdd e)
{
	row = e;
	return;

}

void AnimalCard::printRow(EvenOdd e)
{
	setRow(e);
	if (row == Odd) {
		std::cout << animals[0] << animals[1]<<" ";

	}
	if (row == Even) {
		std::cout << animals[3] << animals[4]<<" ";
	}
	return;
}

//Methodes Virtuelles : Classe Abstraite

