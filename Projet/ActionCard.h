#pragma once
#include "NoSplit.h"
#include "Table.h"
#include "Player.h"

//Dont know what to do with wuery result yet...
class QueryResult
{
public:
	QueryResult();
	~QueryResult();

private:

};


class ActionCard : public NoSplit
{
public:
	ActionCard();
	~ActionCard();
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
private:

};

