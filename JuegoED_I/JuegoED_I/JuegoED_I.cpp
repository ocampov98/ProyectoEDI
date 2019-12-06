#include <iostream>
#include "Controller.h"

using namespace std;

Controller gestor = Controller();

void iniciarJuego() {
	gestor.llenarBaraja();
	gestor.mezclarBaraja();
	gestor.repartirBaraja();
}

int main()
{
	iniciarJuego();
}

