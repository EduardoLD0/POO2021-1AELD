#include "controllerCombate.h"

bool ControllerCombate::combatir(Heroe* hertz, Enemigo* enemigo)
{
	int opcion;
	// Turno Hertz
	cout << "Que ataque desea usar?" << endl;
	if (hertz->getArma().getResistencia() == 0)
	{
		cout << "1. Atacar a puno" << "\n";
	}
	else
	{
		cout << "1. Atacar con el arma" << "\n";
	}
	cout << "2. ";
	cin >> opcion;
	hertz->seleccionarAtaque(opcion)->aplicarEfecto(hertz, enemigo);
	
	if (hertz->getArma().getResistencia() == 0)
	{
		Item* pItem = &hertz->getArma();
		hertz->eliminarItemLista(pItem);
	}
	// Turno Enemigo
	enemigo->seleccionarAtaque()->aplicarEfecto(hertz);
	if (hertz->getVida() <= 0)
	{
		return 0;
	}
	if (enemigo->getVida() <= 0)
	{
		return 1;
	}
}