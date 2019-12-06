#include "Carta.h";

#ifndef NODOCARTA_H
#define NODOCARTA_H
class NodoCarta
{
private:
	Carta data;
	NodoCarta* pointer;
public:
	NodoCarta();
	NodoCarta(Carta);
	Carta getData();
	void setData(Carta);
	NodoCarta* getPtr();
	void setPtr(NodoCarta*);
};

#endif
