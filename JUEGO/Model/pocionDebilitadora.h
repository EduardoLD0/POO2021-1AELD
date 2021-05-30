#ifndef POCIONDEBIL_H
#define POCIONDEBIL_H

#include "pocion.h"

class PocionDebilitadora : public Pocion
{
public:
	PocionDebilitadora();
	int aplicarEfecto() override;
};

#endif