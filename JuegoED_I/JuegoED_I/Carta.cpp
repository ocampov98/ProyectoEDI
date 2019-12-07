#include "Carta.h"
#include <string>
using namespace std;

Carta::Carta() {
	palo = "";
	nombre = "";
}

Carta::Carta(string pPalo, string pNombre) {
	palo = pPalo;
	nombre = pNombre;
}

string Carta::getPalo() {
	return palo;
}

void Carta::setPalo(string pPalo) {
	palo = pPalo;
}

string Carta::getNombre() {
	return nombre;
}

void Carta::setNombre(string pNombre) {
	nombre = pNombre;
}

bool Carta::isEqual(Carta pCarta) {
	if (pCarta.getPalo() == palo && pCarta.getNombre() == nombre) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Carta::mismoPalo(Carta pCarta) {
	if (pCarta.getPalo() == palo) {
		return true;
	}
	else
	{
		return false;
	}
}
