#include "pocionVida.h"

PocionVida::PocionVida()
{
	this->nombre = "Pocion de vida";
	this->tipo = tipoEfecto::curacion;
}

int PocionVida::aplicarEfecto()
{
	return 10;
}