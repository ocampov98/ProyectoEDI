#ifndef LISTA
#define LISTA
#include "NodoCarta.h"

class Lista
{
public:
	Lista();
	void add(Carta);
	void mezclar();
	void ordenar();
	Carta pop(string, string);
	Carta popFirst();
	Carta popNextPalo(string);
	string mostrarLista();

private:
	NodoCarta* cabeza;
};

#endif