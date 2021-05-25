#include "ataqueCuracion.h"

void ataqueCuracion::aplicarEfecto(Character dummy)
{
	int cambioVida = dummy.getVida() + 5; // Valor temporal
	dummy.setVida(cambioVida);
}