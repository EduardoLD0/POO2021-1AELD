#include "ataqueDebilitador.h"

AtaqueDebilitador::AtaqueDebilitador()
{
	this->nombre = "Ataque debilitador";
	this->tipo = tipoAtaque::ataque;
}

int AtaqueDebilitador::aplicarEfecto()
{
	return 2;
}