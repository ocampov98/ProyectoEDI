#include <string>
using namespace std;

#ifndef CARTA_H
#define CARTA_H

class Carta
{
private:
	string palo;
	string nombre;
public:
	Carta();
	Carta(string, string);
	string getPalo();
	void setPalo(string);
	string getNombre();
	void setNombre(string);
	bool isEqual(Carta);
	bool mismoPalo(Carta);
};

#endif 


