#ifndef COLA
#define COLA

#include "NodoCarta.h"

class Cola {

private:
	NodoCarta* frente;
	NodoCarta* final;
	int length;

public:

	Cola();
	void push(Carta data);
	Carta pop();
	int getLength();

	NodoCarta* getFrente();
	NodoCarta* getFinal();
};

#endif
