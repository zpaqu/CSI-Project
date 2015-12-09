#pragma once
#include <memory> 
#include <string>
#include <iostream>
#include "AnimalCard.h"
#include "NoSplit.h"
#include "StartCard.h"


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

