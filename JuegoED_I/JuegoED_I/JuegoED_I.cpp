#include <iostream>
#include "Controller.h"

using namespace std;

Controller gestor = Controller();

void iniciarJuego() {
	gestor.llenarBaraja();
	gestor.mezclarBaraja();
	gestor.repartirBaraja();
}

void jugarTurno() {
	cout << "\n-----Turno Jugador " << gestor.getTurno() <<"-----\n";

	Carta cartaActual = gestor.getCartaActual();

	if (cartaActual.getNombre() == "") {
		cout << "Saque una carta para definir el palo\n" << endl;
	}
	else {
		cout << "Tope del maso: " << cartaActual.getNombre() << " de " << cartaActual.getPalo() << endl;
	}

	cout << gestor.mostrarMasoTurno();

	bool salir = false;

	while (!salir) {
		cout << "\nElija una carta de su mano" << endl;
		string nombre;
		string palo;
		cout << "Digite el nombre de la carta" << endl;
		cin >> nombre;
		cout << "Digite el palo de la carta" << endl;
		cin >> palo;
		
		if (gestor.jugarTurno(palo, nombre)) {
			cout << "\nJugo el " << nombre << " de " << palo << endl;
			salir = true;
		}
		else {
			cout << "\nCarta incorrecta! Solo puede sacar una carta de su maso y que sea del mismo palo que la carta en el tope del maso." << endl;
		}
	}

	gestor.sigTurno();
	salir = false;
	while (!salir) {
		if (gestor.getContadorPalo() != 12) {
			cout << "\n-----Turno Jugador " << gestor.getTurno() << "-----\n";
			string palo = gestor.getCartaActual().getPalo();

			Carta nextCarta = gestor.getNextCarta(palo);
			if (nextCarta.getNombre() != "") {
				cout << "\nJugo el " << nextCarta.getNombre() << " de " << palo << endl;
			}
			else {
				cout << "\nPasa el turno" << endl;
			}
			gestor.sigTurno();
		}
		else {
			gestor.resetCartaActual();
			salir = true;
		}
	}
	
}

int main()
{
	iniciarJuego();

	while (!gestor.gameOver()) {
		jugarTurno();
	}

	cout << "\n***** GANADOR: Jugador " << gestor.getTurno() <<" *****"<< endl;
	return 0;
}



