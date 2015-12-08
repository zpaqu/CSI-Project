#include "AnimalCard.h"
	
AnimalCard::AnimalCard()
{

}
	
AnimalCard::~AnimalCard()
{
	delete[] animals;
}

void AnimalCard::setOrientation(Orientation o)
{
	if (orient != o) {
		char temp0 = animals[0];
		char temp1 = animals[1];
		animals[0] = animals[3];
		animals[1] = animals[2];
		animals[3] = temp0;
		animals[4] = temp1;
		orient = o;
	}
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

