#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>
#include "character.h"

class Ataque
{
public:
	virtual void aplicarEfecto(Character) = 0;
};

#endif
