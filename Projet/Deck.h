#include <vector>
#include <iostream>
#include <memory>

using namespace std;

template <class C>
class Deck : public vector<C>
{
public:
	Deck();
	~Deck();
	std::shared_ptr<C> draw();

private:

};
