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
	std::shared_ptr<AnimalCard> ** tableau;
	Table();
	~Table();
	int addAt(std::shared_ptr<AnimalCard>, int, int);
	std::shared_ptr<AnimalCard> pickAt(int, int);
	std::shared_ptr<AnimalCard> get(int, int);
	bool win(std::string&);
	bool validPosition(std::shared_ptr<AnimalCard>, int, int);
	bool compare(std::shared_ptr<AnimalCard>, char);

private:

};

