#ifndef CONTROLLERCOMBAT_H
#define CONTROLLERCOMBAT_H

#include <iostream>
#include "../Model/heroe.h"
#include "../Model/enemigo.h"

class ControllerCombate
{
private:
	bool turno; // 0 = Turno Hertz, 1 = Turno Enemigo
	int contadorTurno;
public:
	bool combatir(Heroe*, Enemigo*); // 0 = Perdi� el combate, 1 = Gan� el combate
	void atacar(Character*, Character*, Ataque*);
};

#endif