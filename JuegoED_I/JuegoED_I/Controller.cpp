#include "Controller.h"
#include "Lista.h"
#include "Carta.h"
#include<sstream>;
#include <iostream>
using namespace std;

#ifndef CONTROLLER_H
#define CONTROLLER_H

Controller::Controller() {
	baraja = Lista();
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

	cout << "-----Jugador 1-----" << endl;
	j1.mostrarMano();
	cout << "\n-----Jugador 2-----" << endl;
	j2.mostrarMano();

}

#endif 
