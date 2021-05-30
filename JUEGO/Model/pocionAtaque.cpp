#include "pocionAtaque.h"

PocionAtaque::PocionAtaque()
{
	this->nombre = "Pocion de ataque";
	this->tipo = tipoEfecto::ataque;
}

int PocionAtaque::aplicarEfecto()
{
	return 2;
}