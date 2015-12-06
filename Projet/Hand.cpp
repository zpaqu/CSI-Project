#include "Hand.h"


template<class C, class Allocator = std::allocator<C>>
Hand::Hand()
{
	myHand= new std::shared_ptr<AnimalCard>[50];
	cardNumber = 0;
	
}

template<class C, class Allocator = std::allocator<C>>
Hand::~Hand()
{
	delete myHand;
}

template<class C, class Allocator = std::allocator<C>>
Hand& Hand::operator+=(std::shared_ptr<AnimalCard> param)
{
	myHand[cardNumber] = param;
	cardNumber++;
}

template<class C, class Allocator = std::allocator<C>>
Hand& Hand::operator-=(std::shared_ptr<AnimalCard> param)
{
	cardNumber--;
	myHand[cardNumber] = nullptr;
}

template<class C, class Allocator = std::allocator<C>>
std::shared_ptr<AnimalCard> Hand::operator[] (int param)
{
	return myHand[param];
}

template<class C, class Allocator = std::allocator<C>>
int Hand::noCards()
{
	return cardNumber;
}

template<class C, class Allocator = std::allocator<C>>
void Hand::print()
{
	for (int i = 0; i <= cardNumber; i++) {
		std::cout << i << " ";

	}
	std::cout << endl;
	for (int i = 0; i <= cardNumber; i++) {
		myHand[i].printRow(Odd);

	}
	for (int i = 0; i <= cardNumber; i++) {
		myHand[i].printRow(Even);

	}


}