#pragma once
#include "AnimalCard.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"
#include "QueryResult.h"
#include <iostream>

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

//Enumeration qui aide a determiner le type d'action a executer
enum action { Bear, Deer, Hare, Moose, Wolf };

class ActionCard : public NoSplit
{
public:
	action act;
	ActionCard(char);
	~ActionCard();
	//Methodes virtuelles
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
private:

};






