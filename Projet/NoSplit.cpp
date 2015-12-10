#include "NoSplit.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


NoSplit::NoSplit(char a) : AnimalCard(a,a,a,a)
{
	animalNumber = 1;
}

NoSplit::~NoSplit()
{
	delete[] animals;
}