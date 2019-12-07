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
	Carta cartaActual;

	Jugador j1;
	Jugador j2;

	int turno;
	int contadorPalo;

public:
	Controller();
	int getTurno();
	int getContadorPalo();
	Carta getCartaActual();
	bool gameOver();
	void sigTurno();
	void resetCartaActual();

	void llenarBaraja();
	void mezclarBaraja();
	void repartirBaraja();
	bool jugarTurno(string, string);
	string mostrarMasoTurno();
	Carta getNextCarta(string);

};

