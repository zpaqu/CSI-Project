#include <list>
#include <memory>
#include "AnimalCard.h"

template<class C, class Allocator = std::allocator<C>> 
class Hand
{
public:
	Hand();
	~Hand();
	std::list<std::shared_ptr<AnimalCard>> myHand;
	int cardNumber;
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[] (int);
	int noCards();
	void print();

private:

};
