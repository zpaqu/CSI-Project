#pragma once
#include <iostream>
#include "Player.h"
#include "AnimalCardFactory.h"
#include "ActionCard.h"
#include "Table.h"
#include "Deck.h"
#include "Hand.h"
#include "Exception.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

int main() {
	//option to load from file
	int numJ = 0;
	while (numJ < 2 || numJ>5) {

		std::cout << "entrer le nombre de joueurs" << std::endl;
		std::cin >> numJ;
	}

	Table t = Table(numJ);
	
	
	Hand * activeHand;
	AnimalCardFactory factory = AnimalCardFactory();
	
	Deck<AnimalCard> myDeck=factory.getDeck();
	
	Player* play[5];
	Player p1(1);
	
	play[0] = &p1;
	activeHand = (&(*play[0]).getHand());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	Player p2(2);
	play[1] = &p2;
	activeHand = (&(*play[1]).getHand());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	if (numJ >= 3) {
		Player p3(3);
		play[2] = &p3;
		activeHand = (&(*play[2]).getHand());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		
	}


	if (numJ >= 4) {
		Player p4(4);
		play[3] = &p4;
		activeHand = (&(*play[3]).getHand());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	}

	if (numJ >= 5) {
		Player p5(5);
		play[4] = &p5;
		activeHand = (&(*play[4]).getHand());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
		*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
	}

	
	bool won = false;
	std::cout << "going in the while" << std::endl;
	system("PAUSE");
	while (!won) {
		//can save the game here
		for (int i = 0; i < numJ; i++) {
			if(!won){
			bool cardPlacedLegaly = false;
			//t.print(); 
			//there is an error when calling t.print, unautorized access
			activeHand = (&(*play[i]).getHand());
			*activeHand += std::make_shared<AnimalCard>(myDeck.draw());
			(*play[i]).print();
			while (!cardPlacedLegaly)
			{
				int cardN = -1;
				while (cardN<0 || cardN> (*activeHand).cardNumber) {
					std::cout << "quel carte voulez vous selectionner (entre 0 et " << (*activeHand).cardNumber << ")" << endl;
					std::cin >> cardN;
				}
				//on a mis des pauses pour demontrer ou le probleme est dans le programme
				std::cout << "on a selectionner la carte" << std::endl;
				system("PAUSE");
				//c'est ici que le programme arrete de fonctionner, le proble est probablement avec l'operateur
				std::shared_ptr<AnimalCard> activeCard = (*activeHand)[cardN];
				std::cout << "la carte est active" << std::endl;
				system("PAUSE");
				if ((*activeCard).animals[0] >= 'A' && (*activeCard).animals[0] <= 'Z') {
					std::shared_ptr<ActionCard> act;
					//act =(ActionCard)activeCard;  //probleme avec cette 
					QueryResult q=(*act).query;
					(*act).perform(t,play[i],q);//the methode perform will do the action of the card
					
					cardPlacedLegaly = true;
					
				}
				else {
					int option = 0;
					while (option != 1 && option != 3) {
						(*activeCard).print();
						std::cout << "choisir un option (1-3)" << endl << "option1: placer la carte sur la table" << endl;
						std::cout << "Option2: tournez la carte de 180 degre" << endl << "option3: passer votre tour" << endl;
						if (option == 2) {
							(*activeCard).changeOrientation();
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
						try {
							t.addAt(activeCard, x, y);
							*activeHand -= activeCard;
							cardPlacedLegaly = true;

						}
						catch (Exception w) {
							w.report();
						}

					}
					else {
						//le joueur a decider de passer son tour
						cardPlacedLegaly = true;
					}

					for (int j = 0; j < numJ; j++) {
						//ici on verifie si il y a un gagnant
						won=t.win((*play[j]).getSecretAnimal());
						std::cout << "Bravo! le gagnant est: " << (*play[j]).name << endl;

					}

				}
			}

			}
			



		}

	}

}

