#include "pocionDebilitadora.h"

PocionDebilitadora::PocionDebilitadora()
{
	this->nombre = "Pocion de debilidad";
	this->tipo = tipoEfecto::dano;
}

int PocionDebilitadora::aplicarEfecto()
{
	return 4;
}