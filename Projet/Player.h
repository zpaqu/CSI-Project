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
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	//Methode d'affiche d'etat aussi...

private:
	std::string name;
	std::string sAnimal;
	Hand playerHand;
};
