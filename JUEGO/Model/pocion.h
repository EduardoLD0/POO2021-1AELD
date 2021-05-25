#ifndef POCION_H
#define POCION_H

#include "item.h"
#include "character.h"

enum tipoEfecto
{
	curacion = 1,
	dano = 2,
	ataque = 3,
	resistencia = 4
};

class Pocion : public Item
{
protected:
	tipoEfecto tipo;
public:
	~Pocion();
	virtual void aplicarEfecto(Character) = 0;
};

#endif