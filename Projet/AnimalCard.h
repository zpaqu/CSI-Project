#pragma once
#include <string>

enum Orientation { Up, Down };
enum EvenOdd { Even, Odd };

class AnimalCard
{
public:
	int animalNumber;
	char* animals= new char[4];
	AnimalCard();
	~AnimalCard();
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
private:

};

