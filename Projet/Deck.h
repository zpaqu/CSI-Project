#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "AnimalCard.h"

//using namespace std;
//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015



template <class T>
class Deck : public std::vector<T>
{
public:
	T draw();
	void add(T c);

private:

};


//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


//Retourne le dernier element dans le Deck. Dans ce cas ce sera un objet de type AnimalCard
template <class T>
T Deck<T>::draw()
{
	T temp = back();
	pop_back();

	return temp;
}

template<class T>
void Deck<T>::add(T t) // Ajoute un objet dans le Deck. Dans ce cas ce sera un objet de type AnimalCard
{
	push_back(t);
}

