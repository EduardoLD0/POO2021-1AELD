#ifndef CONTROLLERINIC_H
#define CONTROLLERINIC_H

#include <iostream>
#include "../Model/arma.h"
#include "../Model/heroe.h"
#include "../Model/enemigo.h"
#include "../Model/pocionVida.h"
#include "../Model/pocionAtaque.h"
#include "../Model/pocionDefensa.h"
#include "../Model/pocionDebilitadora.h"
#include "../Model/ataqueComun.h"
#include "../Model/ataqueResistencia.h"
#include "../Model/ataqueDebilitador.h"
#include "../Model/ataqueParalizador.h"
#include "../Model/ataqueCuracion.h"
#include "../Model/mazmorra.h"

class ControllerInicializador
{
public:
	ControllerInicializador();
	Arma* crearArma(std::string, int, int);
	Arma* crearBaston();
	Arma* crearEspada();
	Arma* crearExcalibur();
	Enemigo* crearGuerrero();
	Enemigo* crearMago();
	Enemigo* crearGuerreroBoss();
	Enemigo* crearMagoBoss();
	Enemigo* crearEnemigo(std::string, Arma, int, list<Ataque*>, int);	
	Pocion* crearPocion(tipoEfecto);
	Ataque* crearAtaque(tipoAtaque);
	Mazmorra* crearMazmorra(nivel);
	Heroe* crearHeroe();
	// Crear funcion crearEnemigo y llamar por medio de las otras funciones
};

#endif