#include "ataqueComun.h"

void ataqueComun::aplicarEfecto(Character dummy)
{
	int cambioVida = dummy.getVida() - 5; // Valor temporal
	dummy.setVida(cambioVida);
}