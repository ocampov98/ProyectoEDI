#include "Controller.h"
#include "Lista.h"
#include "Carta.h"
#include "Pila.h"
#include<sstream>;
#include <iostream>
using namespace std;

#ifndef CONTROLLER_H
#define CONTROLLER_H

Controller::Controller() {
	baraja = Lista();
	barajaMezclada = Cola();
	maso = Pila();
	turno = 2;
	contadorPalo = 0;
	cartaActual = Carta();
	j1 = Jugador();
	j2 = Jugador();
}

int Controller::getTurno() {
	return turno;
}

int Controller::getContadorPalo() {
	return contadorPalo;
}

Carta Controller::getCartaActual() {
	return cartaActual;
}

bool Controller::gameOver() {
	switch (turno)
	{
	case 1:
		if (j1.mostrarMano() == "Lista vacia") {
			turno++;
			return true;
		}
		turno++;
		break;
	case 2:
		if (j2.mostrarMano() == "Lista vacia") {
			turno--;
			return true;
		}
		turno--;
		break;
	default:
		break;
	}
	return false;
}

void Controller::sigTurno() {
	switch (turno)
	{
	case 1:
		turno++;
		break;
	case 2:
		turno--;
		break;
	default:
		break;
	}
}

void Controller::resetCartaActual() {
	cartaActual = Carta();
}

void Controller::llenarBaraja() {
	
	//Corazones
	baraja.add(Carta("Corazones", "A"));
	for (int i = 2; i < 10; i++) {
		stringstream ss;
		ss << i;
		string s;
		ss >> s;

		baraja.add(Carta("Corazones", s));
	}
	baraja.add(Carta("Corazones", "J"));
	baraja.add(Carta("Corazones", "Q"));
	baraja.add(Carta("Corazones", "K"));

	//Diamantes
	baraja.add(Carta("Diamantes", "A"));
	for (int i = 2; i < 10; i++) {
		stringstream ss;
		ss << i;
		string s;
		ss >> s;

		baraja.add(Carta("Diamantes", s));
	}
	baraja.add(Carta("Diamantes", "J"));
	baraja.add(Carta("Diamantes", "Q"));
	baraja.add(Carta("Diamantes", "K"));

	//Picas
	baraja.add(Carta("Picas", "A"));
	for (int i = 2; i < 10; i++) {
		stringstream ss;
		ss << i;
		string s;
		ss >> s;

		baraja.add(Carta("Picas", s));
	}
	baraja.add(Carta("Picas", "J"));
	baraja.add(Carta("Picas", "Q"));
	baraja.add(Carta("Picas", "K"));

	//Treboles
	baraja.add(Carta("Treboles", "A"));
	for (int i = 2; i < 10; i++) {
		stringstream ss;
		ss << i;
		string s;
		ss >> s;

		baraja.add(Carta("Treboles", s));
	}
	baraja.add(Carta("Treboles", "J"));
	baraja.add(Carta("Treboles", "Q"));
	baraja.add(Carta("Treboles", "K"));

}

void Controller::mezclarBaraja() {
	baraja.mezclar();
	
	Carta mCarta = baraja.popFirst();
	while (mCarta.getNombre() != "")
	{
		barajaMezclada.push(mCarta);
		mCarta = baraja.popFirst();
	}	
}

void Controller::repartirBaraja() {

	int opc = 0;
	Carta mCarta = barajaMezclada.pop();
	while (mCarta.getNombre() != "")
	{
		switch (opc)
		{
		case 0:
			j1.addCarta(mCarta);
			opc++;
			break;
		case 1:
			j2.addCarta(mCarta);
			opc--;
			break;
		default:
			break;
		}
		mCarta = barajaMezclada.pop();
	}
}

bool Controller::jugarTurno(string palo, string nombre) {
	contadorPalo = 0;
	Carta mCarta;
	switch (turno)
	{
	case 1:
		mCarta = j1.sacarCarta(palo, nombre);
		break;
	case 2:
		mCarta = j2.sacarCarta(palo, nombre);
		break;
	default:
		break;
	}

	if (mCarta.getNombre() != "") {
		if (cartaActual.getNombre() == "") {
			maso.push(mCarta);
			cartaActual = mCarta;
			contadorPalo++;
			return true;
		}
		else {
			if (mCarta.mismoPalo(cartaActual)) {
				maso.push(mCarta);
				cartaActual = mCarta;
				contadorPalo++;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

string Controller::mostrarMasoTurno() {
	switch (turno)
	{
	case 1:
		return j1.mostrarMano();
	case 2:
		return j2.mostrarMano();
	default:
		return "";
		break;
	}
}

Carta Controller::getNextCarta(string pPalo) {
	Carta mCarta;
	switch (turno)
	{
	case 1:
		mCarta = j1.getNextCarta(pPalo);
		if (mCarta.getNombre() != "") {
			contadorPalo++;
		}
		return mCarta;
		break;
	case 2:
		mCarta = j2.getNextCarta(pPalo);
		if (mCarta.getNombre() != "") {
			contadorPalo++;
		}
		return mCarta;
		break;
	default:
		return Carta();
		break;
	}
}

#endif 
