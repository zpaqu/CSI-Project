#include "Deck.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

template <class T>
T Deck<T>::draw()
{
	return pop_back();
}

template<class T>
void Deck<T>::add(T t)
{
	push_back(t);
}
