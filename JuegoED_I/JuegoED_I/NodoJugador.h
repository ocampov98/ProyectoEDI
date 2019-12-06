#include "Jugador.h";

#ifndef NODOJUGADOR_H
#define NODOJUGADOR_H
class NodoJugador
{
private:
	Jugador data;
	NodoJugador* pointer;
public:
	NodoJugador();
	NodoJugador(Jugador);
	Jugador getData();
	void setData(Jugador);
	NodoJugador* getPtr();
	void setPtr(NodoJugador*);
};

#endif