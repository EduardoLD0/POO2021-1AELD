#include "pocionDefensa.h"

PocionDefensa::PocionDefensa()
{
	this->nombre = "Pocion reparadora";
	this->tipo = tipoEfecto::resistencia;
}

int PocionDefensa::aplicarEfecto()
{
	return 10;
}