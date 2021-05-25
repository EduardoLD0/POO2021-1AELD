#include "ataqueResistencia.h"

void AtaqueResistencia::aplicarEfecto(Character* dummy)
{
	Arma * armaDummy = &dummy->getArma();
	int cambioResistencia = armaDummy->getResistencia() - 5; // Valor temporal
	armaDummy->setResistencia(cambioResistencia);
}