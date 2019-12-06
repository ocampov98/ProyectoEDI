#include "NodoJugador.h"
#include "Jugador.h"

NodoJugador::NodoJugador() {
	data = Jugador();
	pointer = 0;
}

NodoJugador::NodoJugador(Jugador pData) {
	data = pData;
	pointer = 0;
}

Jugador NodoJugador::getData() {
	return data;
}

void NodoJugador::setData(Jugador pData) {
	data = pData;
}

NodoJugador* NodoJugador::getPtr() {
	return pointer;
}

void NodoJugador::setPtr(NodoJugador* pNext) {
	pointer = pNext;
}