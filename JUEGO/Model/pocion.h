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

class Pocion : public Item	// Clase abstracta
{
protected:
	std::string nombre;
	tipoEfecto tipo;
public:
	tipoEfecto getTipoEfecto();
	virtual int aplicarEfecto() = 0;	// En las clases hijas se hace sobreescritura
	std::string getNombre();
};

#endif