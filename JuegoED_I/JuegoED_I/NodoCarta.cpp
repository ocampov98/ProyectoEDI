#include "NodoCarta.h"
#include "Carta.h"

NodoCarta::NodoCarta() {
	data = Carta();
	pointer = 0;
}

NodoCarta::NodoCarta(Carta pData) {
	data = pData;
	pointer = 0;
}

Carta NodoCarta::getData() {
	return data;
}

void NodoCarta::setData(Carta pData) {
	data = pData;
}

NodoCarta* NodoCarta::getPtr() {
	return pointer;
}

void NodoCarta::setPtr(NodoCarta* pNext) {
	pointer = pNext;
}