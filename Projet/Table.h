#pragma once
#include <memory> 
#include <string>
#include "AnimalCard.h"

class Table
{
public:
	Table();
	~Table();
	int addAt(std::shared_ptr<AnimalCard>, int, int);
	std::shared_ptr<AnimalCard> pickAt(int, int);
	std::shared_ptr<AnimalCard> get(int, int);
	bool win(std::string&);

private:
	std::shared_ptr<AnimalCard> bob[];

};

