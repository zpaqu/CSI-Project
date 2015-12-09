#include "AnimalCard.h"
	
AnimalCard::AnimalCard(char a, char b, char c, char d)
{
	animals[0] = a;
	animals[1] = b;
	animals[2] = c;
	animals[3] = d;
}
	
AnimalCard::~AnimalCard()
{
<<<<<<< HEAD
	delete[] animals;
=======

	delete[] animals;
}

void AnimalCard::print()
{
	printRow(Odd);
	printRow(Even);
}

void AnimalCard::changeOrientation()
{
	if (orient == Up) {
		orient = Down;
	}
	else if (orient == Down) {
		orient = Up;
	}
>>>>>>> origin/master
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

