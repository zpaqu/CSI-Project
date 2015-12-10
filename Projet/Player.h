#pragma once
#ifndef Player_def
#define Player_def
#include <string>
#include "Hand.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

static bool bearSecret=true;
static bool wolfSecret = true;
static bool mooseSecret = true;
static bool dearSecret = true;
static bool hareSecret = true;
#endif

class Player{
public:
	Player(int pn);
	~Player();
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	Hand getHand();
	void setHand(Hand);
	int getNum();
	void print();
private:
	std::string name;
	int num;
	std::string sAnimal;
	Hand playerHand;
};
