#include "ataqueDebilitador.h"

void AtaqueDebilitador::aplicarEfecto(Character* dummy)
{
	int cambioAtaque = dummy->getAtaqueBase() - 5; // Valor temporal
	dummy->setAtaqueBase(cambioAtaque);
}