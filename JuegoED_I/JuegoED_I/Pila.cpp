#include "Pila.h"
#include "NodoCarta.h"
#include <iostream>
using namespace std;

Pila::Pila() {
	cabeza = NULL;
	length = 0;
}

void Pila::push(Carta data) {
	NodoCarta* nuevoNodo = new NodoCarta;
	nuevoNodo->setData(data);
	nuevoNodo->setPtr(NULL);

	if (cabeza == NULL) {
		cabeza = nuevoNodo;
		nuevoNodo = NULL;
		length++;
	}
	else {
		nuevoNodo->setPtr(cabeza);
		cabeza = nuevoNodo;
		length++;
	}
}

Carta Pila::pop() {

	if (cabeza == NULL) {
		return Carta();
	}
	else {
		Carta data = cabeza->getData();
		cabeza = cabeza->getPtr();
		length--;
		return data;
	}
}

int Pila::getLength() {
	return length;
}