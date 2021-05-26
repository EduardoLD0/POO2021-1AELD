#include "pocionDefensa.h"

PocionDefensa::~PocionDefensa()
{

}

void PocionDefensa::aplicarEfecto(Character * dummy)
{
	int cambioResistencia = dummy->getArma().getResistencia() + 5; // Valor temporal
	dummy->getArma().setResistencia(cambioResistencia);
}