#include "pocionAtaque.h"

PocionAtaque::PocionAtaque()
{
	this->nombre = "Pocion de ataque";
}

void PocionAtaque::aplicarEfecto(Character *dummy)
{
	int cambioAtaque = dummy->getAtaqueBase() + 5; // Valor temporal
	dummy->setAtaqueBase(cambioAtaque);
}