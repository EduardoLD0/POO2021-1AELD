#include "ataqueResistencia.h"

AtaqueResistencia::AtaqueResistencia()
{
	this->nombre = "Rompe armas";
	this->tipo = tipoAtaque::resistencia;
}

int AtaqueResistencia::aplicarEfecto()
{
	return 1;
}