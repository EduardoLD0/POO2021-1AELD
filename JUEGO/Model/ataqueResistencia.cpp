#include "ataqueResistencia.h"

AtaqueResistencia::AtaqueResistencia()
{
	this->nombre = "Rompe armas";
	this->tipo = tipoAtaque::resistencia;
}

int AtaqueResistencia::aplicarEfecto()	// Le baja la resistencia al arma del enemigo
{
	return 1;
}