#include "controllerCombate.h"

bool ControllerCombate::combatir(Heroe hertz, Enemigo enemigo)
{
	int opcion;
	// Turno Hertz
	cout << "¿Que ataque desea usar?" << endl;
	cout << "1. Atacar" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		if (hertz.getArma().getResistencia() == 0)
		{
			enemigo.setVida(enemigo.getVida() - (hertz.getAtaqueBase()));
		}
		enemigo.setVida(enemigo.getVida() - (hertz.getAtaqueBase() + hertz.getArma().getPuntosAtaque()));
		hertz.getArma().setResistencia(hertz.getArma().getResistencia() - 1);
		if (hertz.getArma().getResistencia() == 0)
		{
			Item* pItem = &hertz.getArma();
			hertz.eliminarItemLista(pItem);
		}
	default:
		cout << "Opcion incorrecta, ingrese una opcion valida" << endl;
	}
	// Turno Enemigo
	enemigo.seleccionarAtaque()->aplicarEfecto(hertz);
	if (hertz.getVida() <= 0)
	{
		return 0;
	}
	if (enemigo.getVida() <= 0)
	{
		return 1;
	}
}