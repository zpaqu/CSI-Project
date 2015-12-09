#pragma once
#include "NoSplit.h"
#include "Table.h"
#include "Player.h"
#include <iostream>

//Dont know what to do with wuery result yet...
enum action {Bear,Deer,Hare,Moose,Wolf};

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

class QueryResult
{
public:
	int playerNum; 
	int cX, cY, rX, rY; //Coordonnee X, Y et Resultat X, Y

	QueryResult();
	~QueryResult();

private:

};




