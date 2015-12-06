#include "Table.h"


Table::Table()
{
	tableau[103][103];
	std::shared_ptr<AnimalCard> start(new StartCard());
	addAt(start, 52, 52);
}

Table::~Table()
{
	delete[] tableau;
}

int Table::addAt(std::shared_ptr<AnimalCard> card, int x, int y)
{
	try
	{
		if (true)
		{
			tableau[x][y] = card;
		}
		else 
		{
			throw 1;
		}
	}
	catch (int e)
	{
		std::cout << "Illegal Argument" << std::endl; //Should be illegal placement FIX THIS!!!!!
	}

	return tableau[x][y].animalNumber;



}

std::shared_ptr<AnimalCard> Table::pickAt(int x, int y)
{
	if (tableau[x][y] == nullptr) {
		return nullptr;
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
		return nullptr;
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