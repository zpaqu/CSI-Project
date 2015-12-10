#include "Player.h"

Player::Player(int pn)
{
	num = pn; 
	//Player number!!!
	std::cout << "Quel est le nom du joueur";
	std::cin >> name;

	playerHand = Hand();

	bool flag = true;
	while (flag) {
		int x = rand() % 5;
		if (x = 0 && bearSecret) {
			sAnimal = "Bear";
			bearSecret = false;
			flag = false;
		}
		if (x = 1 && dearSecret) {
			sAnimal = "Deer";
			dearSecret = false;
			flag = false;

		}
		if (x = 2 && wolfSecret) {
			sAnimal = "Wolf";
			wolfSecret = false;
			flag = false;

		}
		if (x = 3 && mooseSecret) {
			sAnimal = "Moose";
			mooseSecret = false;
			flag = false;

		}
		if (x = 4 && hareSecret) {
			sAnimal = "Hare";
			hareSecret = false;
			flag = false;

		}
	}
	
}

Player::~Player()
{

}

int Player::getNum()
{
	return num;
}

Hand Player::getHand()
{
	return playerHand;
}

void Player::setHand(Hand h)
{
	playerHand = h;
}

std::string Player::swapSecretAnimal(std::string& a)
{
	std::string temp = a;
	a = sAnimal;
	sAnimal = temp;
	return sAnimal;
}

std::string Player::getSecretAnimal()
{
	return sAnimal;

}


void Player::print()
{
	std::cout << "nom:" << name << "animal secret" << sAnimal << "main:";
	playerHand.print();
}
