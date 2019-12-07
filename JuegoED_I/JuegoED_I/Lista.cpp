#include "Lista.h"
#include "NodoCarta.h"
#include "Pila.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

Lista::Lista() {
	cabeza = NULL;
}

void Lista::add(Carta data) {
	NodoCarta* nuevoNodoCarta = new NodoCarta;
	nuevoNodoCarta->setData(data);
	nuevoNodoCarta->setPtr(NULL);

	if (cabeza == NULL) {
		cabeza = nuevoNodoCarta;
		nuevoNodoCarta = NULL;
	}
	else {
		nuevoNodoCarta->setPtr(cabeza);
		cabeza = nuevoNodoCarta;
	}
}

void Lista::mezclar() {

	if (cabeza == NULL) {
		cout << "Lista vacia";
	}
	else {
		int r;
		NodoCarta* ant;
		NodoCarta* act;
		NodoCarta* sig;
		srand((int)time(0));
		for (int i = 0; i < 104; i++)
		{	
			
			r = (rand() % 45) + 1;
			//cout << r << endl;
			ant = cabeza;
			act = ant->getPtr();
			sig = act->getPtr();
			for (int j = 0; j < r; j++) {
				act->setPtr(sig->getPtr());
				ant->setPtr(sig);
				sig->setPtr(act);

				ant = sig;
				sig = act->getPtr();
				//act = act->getPtr();
				
			}
		}
	}

}

void Lista::ordenar() {

}

Carta Lista::pop(string palo, string nombre) {

	if (cabeza == NULL) {
		return Carta();
	}
	else {
		Carta data = Carta(palo,nombre);
		NodoCarta* ant;
		NodoCarta* act;
		ant = cabeza;
		act = cabeza->getPtr();
		if (data.isEqual(cabeza->getData())) {
			data = cabeza->getData();
			cabeza = cabeza->getPtr();
			return data;
		}
		else {
			while (act != NULL) {
				if (data.isEqual(act->getData())) {
					data = act->getData();
					ant->setPtr(act->getPtr());
					return data;
				}
				else
				{
					ant = act;
					act = act->getPtr();
				}
			}
			return Carta();
		}
	}
}

Carta Lista::popFirst() {

	if (cabeza == NULL) {
		//cout << "Lista vacia";
		return Carta();
	}
	else {
		Carta data = cabeza->getData();
		cabeza = cabeza->getPtr();
		return data;
	}
}

Carta Lista::popNextPalo(string pPalo) {
	if (cabeza == NULL) {
		return Carta();
	}
	else {
		Carta data = Carta(pPalo, "");
		NodoCarta* ant;
		NodoCarta* act;
		ant = cabeza;
		act = cabeza->getPtr();
		if (data.mismoPalo(cabeza->getData())) {
			data = cabeza->getData();
			cabeza = cabeza->getPtr();
			return data;
		}
		else {
			while (act != NULL) {
				if (data.mismoPalo(act->getData())) {
					data = act->getData();
					ant->setPtr(act->getPtr());
					return data;
				}
				else
				{
					ant = act;
					act = act->getPtr();
				}
			}
			return Carta();
		}
	}
}

string Lista::mostrarLista() {
	NodoCarta* aux;
	aux = cabeza;

	if (aux == NULL) {
		return "Lista vacia";
	}
	else {
		string text;
		while (aux != NULL)
		{
			text += aux->getData().getNombre() + " de " + aux->getData().getPalo() + "\n";
			aux = aux->getPtr();
		}
		return text;
	}
}
