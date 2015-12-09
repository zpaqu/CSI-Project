#include "Hand.h"
#include <list>


template<class C, class Allocator = std::allocator<C>>
Hand::Hand()
{
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
	myHand.insert(param);
	cardNumber++;
}

template<class C, class Allocator = std::allocator<C>>
Hand& Hand::operator-=(std::shared_ptr<AnimalCard> param)
{
	myHand.remove(param);
	cardNumber--;
}

template<class C, class Allocator = std::allocator<C>>
std::shared_ptr<AnimalCard> Hand::operator[] (int param)
{
	std::list<std::shared_ptr<AnimalCard>>::iterator it = std::next(myHand.begin(), param);
	return it;
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