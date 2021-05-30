#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include "character.h"
#include "ataque.h"

class Enemigo : public Character
{
public:
	Enemigo(std::string, Arma, int, list<Ataque*>, int);
	void agregarAtaque(Ataque *);
	Ataque *seleccionarAtaque(int);
};

#endif
