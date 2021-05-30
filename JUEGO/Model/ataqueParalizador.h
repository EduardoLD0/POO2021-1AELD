#ifndef ATAQUEPARALIZADOR_H
#define ATAQUEPARALIZADOR_H

#include "ataque.h"

class AtaqueParalizador : public Ataque
{
public:
	AtaqueParalizador();
	int aplicarEfecto();
};

#endif