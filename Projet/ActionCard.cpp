#include "ActionCard.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

ActionCard::ActionCard(char c) : NoSplit(c)
{
	if (c == 'B')
	{
		act = Bear;
	}
	else if (c == 'D')
	{
		act = Deer;
	}
	else if (c == 'H')
	{
		act = Hare;
	}
	else if (c == 'M')
	{
		act = Moose;
	}
	else if (c == 'W')
	{
		act = Wolf;
	}
	else
	{
		// nothing
	}

}

ActionCard::~ActionCard()
{
}

QueryResult ActionCard::query()
{
	QueryResult q = QueryResult();

	if (act == Bear) 
	{
		std::cout << "Vous avez joué une carte d'action de type Ours!" << std::endl;
		std::cout << "Avec quel joueur voulez vous echanger votre main?";
		std::cin >> q.playerNum;
	}

	else if (act == Deer) 
	{
		std::cout << "Vous avez joué une carte d'action de type Cerf!" << std::endl;
		std::cout << "Quel est le numero du joueur avec qui vous voulez echanger votre carte objectif?";
		std::cin >> q.playerNum;
	}

	else if (act == Hare)
	{
		std::cout << "Vous avez joué une carte d'action de type Lievre!" << std::endl;

		std::cout << "Quel carte voulez vous deplacer? (Coordonnees X,Y)" << std::endl;
		std::cin >> q.cX;
		std::cin >> q.cY;

		std::cout << "A quel emplacement voulez vous placer cette carte? (Coordonnees X,Y)" << std::endl;
		std::cin >> q.rX;
		std::cin >> q.rY;
	}

	else if (act == Moose) 
	{
		std::cout << "Vous avez joué une carte d'action de type Original!" << std::endl;
		std::cout << "Changement des cartes d'objectifs..." << std::endl;
	}

	else if (act == Wolf) 
	{
		std::cout << "Vous avez joué une carte d'action de type Loup!" << std::endl;
		std::cout << "Quel carte voulez vous prendre? (Coordonnees X, Y)" << std::endl;
		std::cin >> q.rX;
		std::cin >> q.rY;
	}

	else
	{
		//nothing
	}
	return q;
}

void ActionCard::perform(Table& t, Player* p , QueryResult q)
{
	if (act == Bear) {
		Player* oP = p+(q.playerNum - p->getNum());
		Hand tH = p->getHand();
		p->setHand(oP->getHand());
		oP->setHand(tH);
	}

	else if (act == Deer) {
		Player* oP = p + (q.playerNum - p->getNum());
		std::string tS = p->getSecretAnimal();
		p->swapSecretAnimal(oP->getSecretAnimal());
		oP->swapSecretAnimal(tS);
	}

	else if (act == Hare) {
		std::shared_ptr<AnimalCard> sP1 = t.pickAt(q.cX, q.cY);
		if (sP1 != nullptr)
		{
			t.addAt(sP1, q.rX, q.rY);
		}
	}

	else if (act == Moose) {
		Player* lP = p + (t.numPlayers - p->getNum());

		std::string tA = lP->getSecretAnimal();

		for (int i = t.numPlayers; i >1 ; i--)
		{
			lP->swapSecretAnimal((--lP)->getSecretAnimal());
		}
		lP->swapSecretAnimal(tA);
	}

	else if (act == Wolf) {
		std::shared_ptr<AnimalCard> sP = t.pickAt(q.cX, q.cY);
		p->getHand() += sP;
	}

	else
	{
		//do nothing
	}

}
