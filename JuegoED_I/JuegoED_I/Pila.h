#ifndef PILA
#define PILA
#include "NodoCarta.h"

class Pila
{
public:
	Pila();
	void push(Carta);
	Carta pop();
	int getLength();

private:
	NodoCarta* cabeza;
	int length;
};

#endif