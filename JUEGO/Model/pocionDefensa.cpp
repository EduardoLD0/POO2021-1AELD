#include "pocionDefensa.h"

PocionDefensa::PocionDefensa()
{
	this->nombre = "Pocion reparadora";
}

void PocionDefensa::aplicarEfecto(Character * dummy)
{
	int cambioResistencia = dummy->getArma().getResistencia() + 5; // Valor temporal
	dummy->getArma().setResistencia(cambioResistencia);
}