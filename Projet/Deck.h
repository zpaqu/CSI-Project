#include <vector>
#include <iostream>
#include <memory>
#include "AnimalCard.h"

using namespace std;

template <class C>
class Deck : public vector<C>
{
public:
	Deck();
	~Deck();
	std::shared_ptr<C> draw();
	void add(AnimalCard c);

private:

};
