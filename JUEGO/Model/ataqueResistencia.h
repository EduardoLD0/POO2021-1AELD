#ifndef ATAQUERESISTENCIA_H
#define ATAQUERESISTENCIA_H

#include "ataque.h"
#include "arma.h"

class AtaqueResistencia : public Ataque
{
public:
	AtaqueResistencia();
	int aplicarEfecto();
};

#endif