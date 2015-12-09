#include "stdafx.h"
#include <iostream>
#include "Player.h"

int main() {
	//option to load from file


	int numJ=0;
	while (numJ < 2 || numJ>5) {

		std::cout << "entrer le nombre de joueurs" << std::endl;
		std::cin >> numJ;
	}
	Player p1();
	Player p2();
	if (numJ >= 3)
		Player p3();
	if (numJ >= 4)
		Player p4();
	if (numJ >= 5)
		Player p5();




	while (!winner()) {

	}

}

bool winner() {
	return false;
}