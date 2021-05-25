#ifndef ATAQUECURACION_H
#define ATAQUECURACION_H

#include "ataque.h"

class AtaqueCuracion : public Ataque
{
public:
	void aplicarEfecto(Character);
};

#endif