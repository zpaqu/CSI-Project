#pragma once
#include "ActionCard.h"

ActionCard::ActionCard(char c) : NoSplit(c)
{
}

ActionCard::~ActionCard()
{
}

QueryResult ActionCard::query()
{
	QueryResult que();

	if (act == Bear) {
		int p=0;
		while (p<1 && p>5/*replace by the number of players*/ && p!=0/*replace by the player's number*/)
		{
			std::cout << "Avec quel joueur voulez vous echanger votre main?";
			std::cin >> p;
		}
		//que.play=*the player with that number*; (give the variable play a player)

		
	}
	if (act == Deer) {

		int p = 0;
		while (p<1 && p>5/*replace by the number of players*/ && p != 0/*replace by the player's number*/)
		{
			std::cout << "Avec quel joueur voulez vous echanger votre carte objectif?";
			std::cin >> p;
		}
		//que.play=*the player with that number*;

	}
	if (act == Hare) {
		std::cout << "Quel carte voulez vous deplacer?";
		//code
		std::cout << "A quel emplacement voulez vous placer cette carte?";
		//code

	}
	if (act == Moose) {
	//nothing here
	}
	if (act == Wolf) {
		std::cout << "Quel carte voulez vous prendre?";
		//code (same as first part of Hare)
	}
}

void ActionCard::perform(Table&, Player*, QueryResult)
{

	if (act == Bear) {
		//code
	}
	if (act == Deer) {
		//code
	}
	if (act == Hare) {
		//code
	}
	if (act == Moose) {
		//code
	}
	if (act == Wolf) {
		//code
	}

}

QueryResult::QueryResult()
{

}

QueryResult::~QueryResult()
{
	delete play;
}
