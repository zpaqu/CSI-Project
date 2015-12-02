#pragma once
enum Orientation { Up, Down };
enum EvenOdd { Even, Odd };

class AnimalCard
{
public:
	AnimalCard();
	~AnimalCard();
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
private:

};

