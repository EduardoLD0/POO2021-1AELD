#include "ataqueComun.h"

void AtaqueComun::aplicarEfecto(Character* dummy)
{
	int cambioVida = dummy->getVida() - 5; // Valor temporal
	dummy->setVida(cambioVida);
}