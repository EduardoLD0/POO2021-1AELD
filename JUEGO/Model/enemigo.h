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
	Enemigo();
	Enemigo(std::string, Arma, int, list<Ataque*>, int, tipoEnemigo);
	Ataque *seleccionarAtaque(int);	// Hereda de clase abstracta, tiene que declararse
	Ataque *seleccionarAtaque();	// Elige un ataque al azar de su lista de ataques **Sobrecarga**
	tipoEnemigo getTipoEnemigo();
};

#endif
