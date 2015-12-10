#pragma once
#include "AnimalCard.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"
#include "QueryResult.h"
#include <iostream>

//Dont know what to do with wuery result yet...
enum action { Bear, Deer, Hare, Moose, Wolf };

class ActionCard : public NoSplit
{
public:
	action act;
	ActionCard(char);
	~ActionCard();
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
private:

};






