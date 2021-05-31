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

class Ataque	// Clase abstracta
{
protected:
	std::string nombre;
	tipoAtaque tipo;
public:
	virtual int aplicarEfecto() = 0;	// Retorna la cantidad de daño o efecto que hace el ataque
	std::string getNombre();
	tipoAtaque getTipoAtaque();
};

#endif
