#include "ataqueDebilitador.h"

void ataqueDebilitador::aplicarEfecto(Character dummy)
{
	int cambioAtaque = dummy.getAtaque() - 5; // Valor temporal
	dummy.setAtaque(cambioAtaque);
}