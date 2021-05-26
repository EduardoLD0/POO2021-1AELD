#include "ataqueComun.h"

void AtaqueComun::aplicarEfecto(Character* dummy, Character* dummy2)
{
	dummy2->setVida(dummy2->getVida() - (dummy->getAtaqueBase() + dummy->getArma().getPuntosAtaque()));
	dummy->getArma().setResistencia(dummy->getArma().getResistencia() - 1);
}