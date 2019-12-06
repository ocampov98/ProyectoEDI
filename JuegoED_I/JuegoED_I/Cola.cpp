#include "Cola.h"
#include "NodoCarta.h"
#include <iostream>
using namespace std;

Cola::Cola() {
	frente = NULL;
	final = NULL;
	length = 0;
}

void Cola::push(Carta dato) {
	NodoCarta* nuevoNodo = new NodoCarta;
	nuevoNodo->setData(dato);
	nuevoNodo->setPtr(NULL);

	if (frente == NULL) {
		frente = nuevoNodo;
		final = nuevoNodo;
		nuevoNodo = NULL;
		length++;
	}
	else {
		final->setPtr(nuevoNodo);
		final = nuevoNodo;
		length++;
	}
}

Carta Cola::pop() {

	if (frente == NULL) {
		return Carta();
	}
	else {
		Carta data = frente->getData();
		frente = frente->getPtr();
		length--;
		return data;
	}
}

int Cola::getLength() {
	return length;
}