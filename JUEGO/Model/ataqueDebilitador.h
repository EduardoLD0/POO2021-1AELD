#ifndef ATAQUEDEBILITADOR_H
#define ATAQUEDEBILITADOR_H

#include "ataque.h"

class AtaqueDebilitador : public Ataque
{
public:
	AtaqueDebilitador();
	int aplicarEfecto();
};

#endif