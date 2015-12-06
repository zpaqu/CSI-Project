#pragma once
#include "NoSplit.h"
#include "Table.h"
#include "Player.h"
#include <iostream>

//Dont know what to do with wuery result yet...
enum action { Bear,Deer,Hare,Moose,Wolf};

class QueryResult
{
public:
	Player* play;
	//variable de position de la carte a prendre
	//variable de la position ou mettre la carte
	
	QueryResult();
	~QueryResult();

private:

};


class ActionCard : public NoSplit
{
public:
	action act;
	ActionCard(char a);
	~ActionCard();
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
private:

};

