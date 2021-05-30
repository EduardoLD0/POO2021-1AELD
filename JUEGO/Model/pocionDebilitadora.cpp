#include "pocionDebilitadora.h"

PocionDebilitadora::PocionDebilitadora()
{
	this->nombre = "Pocion de debilidad";
}

void PocionDebilitadora::aplicarEfecto(Character * dummy)
{
	int cambioVida = dummy->getVida() - 5; // Valor temporal
	dummy->setVida(cambioVida);
}