#pragma once
#include <memory> 
#include <string>
#include <iostream>
#include "AnimalCard.h"
#include "NoSplit.h"
#include "StartCard.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

class Table
{
public:
	int numPlayers;
	std::shared_ptr<AnimalCard> ** tableau;
	Table(int a);
	~Table();
	int addAt(std::shared_ptr<AnimalCard>, int, int);
	std::shared_ptr<AnimalCard> pickAt(int, int);
	std::shared_ptr<AnimalCard> get(int, int);
	bool win(std::string&);
	bool validPosition(std::shared_ptr<AnimalCard>, int, int);
	int compare(std::shared_ptr<AnimalCard>, char);
	void print();

private:

};

