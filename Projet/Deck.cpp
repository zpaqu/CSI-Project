#include "Deck.h"

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
