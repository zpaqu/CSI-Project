#include "Hand.h"
#include <list>
#include <iomanip>

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


Hand::Hand()
{
	cardNumber = 0;
}

Hand::~Hand()
{
	cards.clear();
}


Hand& Hand::operator+=(std::shared_ptr<AnimalCard> param)
{
	cards.push_back(param);
	cardNumber++;
	return *this;
}

Hand& Hand::operator-=(std::shared_ptr<AnimalCard> param)
{
	cards.remove(param);
	cardNumber--;
	return *this;
}


std::shared_ptr<AnimalCard> Hand::operator[] (int param)
{
	std::list<std::shared_ptr<AnimalCard>>::iterator it = std::next(cards.begin(), param);
	return *it;
}

int Hand::noCards()
{
	return cardNumber;
}


void Hand::print()
{
	int i = 1;
	std::list<std::shared_ptr<AnimalCard>>::iterator it;
	for (it = cards.begin(); it != cards.end(); ++it, i++){
		std::cout << std::setw(3) << std::left << i;
	}
	std::cout << std::endl;

	for (it = cards.begin(); it != cards.end(); ++it) {
		(*it)->printRow(Odd);

	}
	std::cout << std::endl;

	for (it = cards.begin(); it != cards.end(); ++it) {
		(*it)->printRow(Even);

	}
	std::cout << std::endl;
}