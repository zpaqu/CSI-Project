#pragma once
#include <string>
#include <iostream>

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

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

