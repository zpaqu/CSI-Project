#include "Table.h"

Table::Table()
{
	tableau = new std::shared_ptr<AnimalCard>[103][103];
	NoSplit *startStack = new NoSplit("*");
	addAt(startStack, 52, 52);
}

Table::~Table()
{
	tableau.delete[][];
}

int Table::addAt(std::shared_ptr<AnimalCard> card, int x, int y)
{
	if(/*tableau[x][y]==goodplacement*/)
		tableau[x][y] = card;
	else {
		throw IllegalPlacement;
	}

	return *card.animalNumber;



}

std::shared_ptr<AnimalCard> Table::pickAt(int x, int y)
{
	if (tableau[x][y] == nullptr) {
		return null;
	}
	else {
		std::shared_ptr<AnimalCard> temp = tableau[x][y];
		tableau[x][y] = nullptr;
		return temp;
	}
}

std::shared_ptr<AnimalCard> Table::get(int x, int y)
{
	if (tableau[x][y] == nullptr) {
		return null;
	}
	else {
		return tableau[x][y];
	}
}

bool Table::win(std::string& animal)
{
	int count = 0;
	for (int x = 0; x < 103; x++) {
		for (int y = 0; y < 103; y++) {
			if (tableau[x][y].compare(animal)) {
				count++;
			}
		}
	}
	if (count >= 12) {
		return true;
	}
	else
		return false;

}