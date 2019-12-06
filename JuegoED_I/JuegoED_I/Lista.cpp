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
		cout << "lista vacia";
	}
	else {
		Carta data = Carta(palo,nombre);
		NodoCarta* ant;
		NodoCarta* act;
		ant = cabeza;
		act = cabeza->getPtr();
		bool ciclo = true;
		if (data.isEqual(cabeza->getData())) {
			data = cabeza->getData();
			cabeza = cabeza->getPtr();
			delete act;
			return data;
		}
		else {
			while (ciclo != false && act != NULL) {
				if (data.isEqual(act->getData())) {
					data = act->getData();
					ant->setPtr(act->getPtr());
					delete act;
					ciclo = false;
					return data;
				}
				else
				{
					ant = act;
					act = ant->getPtr();
				}
			}
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

void Lista::mostrarLista() {
	NodoCarta* aux;
	aux = cabeza;

	if (aux == NULL) {
		cout << "Lista vacia";
	}
	else {
		while (aux != NULL)
		{
			cout << aux->getData().getNombre() << " de " << aux->getData().getPalo() << endl;
			aux = aux->getPtr();
		}
	}
}


/*
void Lista::mezclar() {

	NodoCarta* aux;
	aux = cabeza;

	if (aux == NULL) {
		cout << "Lista vacia";
	}
	else {
		int r;
		Pila auxStack1 = Pila();
		Pila auxStack2 = Pila();

		while (aux != NULL)
		{
			string palo = aux->getData().getPalo();
			string nombre = aux->getData().getNombre();

			srand((int)time(0));
			r = (rand() % 2) + 1;
			switch (r)
			{
			case 1:
				auxStack1.push(pop(palo, nombre));
				break;
			case 2:
				auxStack2.push(pop(palo, nombre));
				break;
			default:
				break;
			}

			aux = aux->getPtr();
		}

		Carta auxCard;
		auxCard = auxStack1.pop();
		while (auxCard.getNombre() != "") {
			add(auxCard);
			auxCard = auxStack1.pop();
		}

		auxCard = auxStack2.pop();
		while (auxCard.getNombre() != "") {
			add(auxCard);
			auxCard = auxStack2.pop();
		}
	}

}

*/