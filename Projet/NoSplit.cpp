#include "NoSplit.h"


NoSplit::NoSplit(char a) : AnimalCard(a,a,a,a)
{
	animalNumber = 1;
}

NoSplit::~NoSplit()
{
	delete[] animals;
}