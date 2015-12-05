#include "NoSplit.h"


NoSplit::NoSplit(char a)
{
	animalNumber = 1;
	animals[0] = a;
	animals[1] = a;
	animals[2] = a;
	animals[3] = a;


}

NoSplit::~NoSplit()
{
	animals.delete[];
}