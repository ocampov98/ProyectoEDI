#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Lista.h"
using namespace std;

class Jugador
{
private:
	string nombre;
	int puntaje;
	Lista mano;
public:
	Jugador();
	Jugador(string);
	string getNombre();
	void setNombre(string);
	int getPuntaje();
	void setPuntaje(int);
	void sumarPuntaje();
	void addCarta(Carta);
	void mostrarMano();
};

#endif 


