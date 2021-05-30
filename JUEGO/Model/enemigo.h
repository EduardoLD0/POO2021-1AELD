#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include "character.h"
#include "ataque.h"

enum tipoEnemigo
{
	guerrero = 1,
	mago = 2,
	guerreroBoss = 3,
	magoBoss = 4
};

class Enemigo : public Character
{
private:
	tipoEnemigo tipoE;
public:
	Enemigo(std::string, Arma, int, list<Ataque*>, int);
	Ataque *seleccionarAtaque(int);
	tipoEnemigo getTipoEnemigo();
};

#endif
