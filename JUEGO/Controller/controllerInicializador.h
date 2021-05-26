#ifndef CONTROLLERINIC_H
#define CONTROLLERINIC_H

#include <iostream>
#include "../Model/mazmorra.h"
#include "../Model/arma.h"
#include "../Model/ataque.h"
#include "../Model/enemigo.h"

class ControllerInicializador
{
private:
	Mazmorra mazmorra;
public:
	ControllerInicializador(nivel);
	Arma* crearBaston(int, int);
	Arma* crearEspada(int, int);
	Character* crearGuerrero(Arma, int, list<Ataque*>, int);
	Character* crearGuerreroBoss(Arma, int, list<Ataque*>, int);
	Character* crearMago(Arma, int, list<Ataque*>, int);
	Character* crearMagoBoss(Arma, int, list<Ataque*>, int);
	Mazmorra& getMazmorra();
	// Crear funcion crearEnemigo y llamar por medio de las otras funciones
};

#endif