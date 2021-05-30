#include "pocionVida.h"

PocionVida::PocionVida()
{
	this->nombre = "Pocion de vida";
}

void PocionVida::aplicarEfecto(Character *dummy)
{
	int cambioVida = dummy->getVida() + 5; // Valor temporal
	dummy->setVida(cambioVida);
}