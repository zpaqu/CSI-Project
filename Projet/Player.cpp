#include "Player.h"

Player::Player()
{
	std::cout << "Quel est le nom du joueur";
	std::cin >> name;
	playerHand();
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

std::string Player::swapSecretAnimal(std::string& a)
{
	std::string temp = a;
	a = sAnimal;
	sAnimal = temp;
}

std::string Player::getSecretAnimal()
{

}