#pragma once
#include "ActionCard.h"
#include "Hand.h"

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
		Hand a = p->getHand();
		Hand b = p[q.playerNum];
		//Switch pointers of hands
	}
	if (act == Deer) {
		std::string s = p->getSecretAnimal();
		p->swapSecretAnimal(p[q.playerNum].getSecretAnimal());
		p[q.playerNum].swapSecretAnimal(s); 
	}
	if (act == Hare) {
		std::shared_ptr<AnimalCard> sP1 = t.pickAt(q.cX, q.cY);
		if (sP1 != nullptr)
		{
			t.addAt(sP1, q.rX, q.rY);
		}
	}
	if (act == Moose) {
		std::string temp1;
		int i = 0;
		while (p[i])
		{

		}
	}
	if (act == Wolf) {
		std::shared_ptr<AnimalCard> sP = t.pickAt(q.cX, q.cY);
		Hand<std::shared_ptr<AnimalCard>> temp = p->getHand();
		//Add pointer to hand
	}

}

QueryResult::QueryResult(){ }

QueryResult::~QueryResult(){ }
