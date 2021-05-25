#ifndef CONTROLLERINIC_H
#define CONTROLLERINIC_H

#include <iostream>
#include "../Model/mazmorra.h"
#include "../Model/arma.h"
#include "../Model/ataque.h"
#include "../Model/enemigo.h"

class ControllerInicializador
{
public:
	Mazmorra* crearMazmorra(nivel nivel);
	Arma* crearBaston(int, int);
	Arma* crearEspada(int, int);
	Character* crearGuerrero(Arma*, int, list<Ataque*>, int);
	Character* crearGuerreroBoss(Arma*, int, list<Ataque*>, int);
	Character* crearMago(Arma*, int, list<Ataque*>, int);
	Character* crearMagoBoss(Arma*, int, list<Ataque*>, int);
};

#endif