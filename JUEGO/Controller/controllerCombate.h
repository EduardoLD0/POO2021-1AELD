#ifndef CONTROLLERCOMBAT_H
#define CONTROLLERCOMBAT_H

#include <iostream>
#include "../Model/heroe.h"
#include "../Model/enemigo.h"
#include "controllerJuego.h"

class ControllerCombate
{
private:
	ControllerJuego* controllerJ;
	bool turno; // 0 = Turno Hertz, 1 = Turno Enemigo
	int contadorTurno;
public:
	ControllerCombate(ControllerJuego*);
	bool combatir(Heroe*, Enemigo*); // 1 = Perdio el combate, 0 = Gano el combate
	void atacar(Character*, Character*, Ataque*);
};

#endif