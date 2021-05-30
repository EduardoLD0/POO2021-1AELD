#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>

enum class tipoAtaque
{
	dano = 1,
	curacion = 2,
	turno = 3,
	resistencia = 4,
	ataque = 5
};

class Ataque
{
protected:
	std::string nombre;
	tipoAtaque tipo;
public:
	virtual int aplicarEfecto() = 0;
	std::string getNombre();
};

#endif
