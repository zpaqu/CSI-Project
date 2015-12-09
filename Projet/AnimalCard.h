#pragma once
#include <string>
#include <iostream>

enum Orientation { Up, Down };
enum EvenOdd { Even, Odd };

class AnimalCard
{
public:
	int animalNumber;
	char* animals= new char[4];
	Orientation orient = Up;
	EvenOdd row = Odd;

	AnimalCard(char,char,char,char);
	~AnimalCard();
	void print();
	void changeOrientation();
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
private:

};

