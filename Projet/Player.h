#include <string>
#include "Hand.h"

static bool bearSecret=true;
static bool wolfSecret = true;
static bool mooseSecret = true;
static bool dearSecret = true;
static bool hareSecret = true;


class Player
	
{
public:
	 
	Player(int pn);
	~Player();
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	Hand getHand();
	int getNum();
	void print();
private:
	std::string name;
	int num;
	std::string sAnimal;
	Hand playerHand;
};
