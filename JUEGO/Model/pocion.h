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
	std::string nombre;
	tipoEfecto tipo;
public:
	tipoEfecto getTipoEfecto();
	virtual int aplicarEfecto() = 0;
	std::string getNombre();
};

#endif