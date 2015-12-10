#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "AnimalCard.h"

using namespace std;

template <class T>
class Deck : public vector<T>
{
public:
	T draw();
	void add(T c);

private:

};
