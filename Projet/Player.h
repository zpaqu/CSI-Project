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
	 
	Player();
	~Player();
	Hand getHand();
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	void print();
private:
	std::string name;
	std::string sAnimal;
	Hand playerHand;
};
