#pragma once
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "Jugador.h"

class Controller
{
private:
	Lista baraja;
	Cola barajaMezclada;
	Pila maso;

	Jugador j1;
	Jugador j2;

public:
	Controller();
	void llenarBaraja();
	void mezclarBaraja();
	void repartirBaraja();

};

