#include "pocionDebilitadora.h"

PocionDebilitadora::PocionDebilitadora()
{
	this->nombre = "Pocion de debilidad";
	this->tipo = tipoEfecto::dano;
}

int PocionDebilitadora::aplicarEfecto()	// El efecto se aplica sobre el enemigo, no sobre el jugador
{
	return 0;
}