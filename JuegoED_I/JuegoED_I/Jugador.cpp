#include "Jugador.h"
#include <string>
using namespace std;

Jugador::Jugador() {
	nombre = "";
	puntaje = 0;
	mano = Lista();
}

Jugador::Jugador(string pNombre) {
	nombre = pNombre;
	puntaje = 0;
	mano = Lista();
}

string Jugador::getNombre() {
	return nombre;
}

void Jugador::setNombre(string pNombre) {
	nombre = pNombre;
}

int Jugador::getPuntaje() {
	return puntaje;
}

void Jugador::setPuntaje(int pPuntaje) {
	puntaje = pPuntaje;
}

void Jugador::sumarPuntaje() {
	puntaje++;
}

void Jugador::addCarta(Carta pCarta) {
	mano.add(pCarta);
}

void Jugador::mostrarMano() {
	mano.mostrarLista();
}