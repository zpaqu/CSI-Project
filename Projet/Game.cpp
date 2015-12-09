#include <iostream>
#include "Player.h"
#include "AnimalCardFactory.h"
#include "ActionCard.h"
#include "Table.h"
#include "Deck.h"
#include "Hand.h"

int main() {
	//option to load from file

	Table t();
	Hand * activeHand;
	AnimalCardFactory factory;
	Deck<std::shared_ptr<AnimalCard>> myDeck=factory.getDeck();
	int numJ=0;
	while (numJ < 2 || numJ>5) {

		std::cout << "entrer le nombre de joueurs" << std::endl;
		std::cin >> numJ;
	}
	Player* play[numJ - 1];
	Player p1(1);
	play[0] = p1;
	activeHand = &play[0].getHand();
	activeHand += myDeck.draw();
	activeHand += myDeck.draw();
	activeHand += myDeck.draw();

	Player p2(2);
	play[1] = p2;
	activeHand = &play[1].getHand();
	activeHand += myDeck.draw();
	activeHand += myDeck.draw();
	activeHand += myDeck.draw();
	if (numJ >= 3) {
		Player p3(3);
		play[2] = p3;
		activeHand = &play[2].getHand();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
	}

	if (numJ >= 4) {
		Player p4(4);
		play[3] = p4;
		activeHand = &play[3].getHand();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
	}

	if (numJ >= 5) {
		Player p5(5);
		play[4] = p5;
		activeHand = &play[4].getHand();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
		activeHand += myDeck.draw();
	}




	while (!winner()) {
		//can save the game here
		for (int i = 0; i < numJ; i++) {
			bool cardPlacedLegaly = false;
			t.print();
			activeHand = &(play[i].getHand());//not sure if that makes sence (the & placement)
			activeHand += myDeck.draw();
			play[i].print;
			while (!cardPlacedLegaly)
			{
				int cardNumber = -1;
				while (cardNumber<0 || cardNumber> activeHand.size()) {
					std::cout << "quel carte voulez vous selectionner (entre 0 et " << activeHand.size() << ")" << endl;
					std::cin >> cardNumber;
				}
				std::shared_ptr<AnimalCard> activeCard = activeHand[cardNumber];
				if (activeCard.isActionCard) {
					//do whatever action cards do
					cardPlacedLegaly = true;
				}
				else {
					int option = 0;
					while (option != 1 && option!=3) {
						activeCard.print();
						std::cout << "choisir un option (1-3)" << endl << "option1: placer la carte sur la table" << endl;
						std::cout << "Option2: tournez la carte de 180 degre" << endl << "option3: passer votre tour" << endl;
						if (option == 2) {
							activeCard.changeOrientation();
						}
					}
					if (option == 1) {
					
						int x = -1;
						while (x < 0 || x>103) {
							std::cout << "veuillez entrer la position x ou vous voulez placer la carte" << endl;
							std::cin >> x;
						}
						int y = -1;
						while (y < 0 || y>103) {
							std::cout << "veuillez entrer la position x ou vous voulez placer la carte" << endl;
							std::cin >> y;
						}
						try() {
							t.addAt(activeCard, x, y);
							activeHand -= activeCard;
							cardPlacedLegaly = true;

						}
						catch(){
							std::cout << "le placement na pas fonctionner" << endl;
						}

					}
					else {
						//le joueur a decider de passer son tour
						cardPlacedLegaly = true;
					}
					
					//should check for winner here i think
				}

			}
			



		}

	}

}

bool winner() {
	return false;
}