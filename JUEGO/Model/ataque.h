#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>
#include "character.h"

class Ataque
{
public:
	virtual void aplicarEfecto(int*) = 0;
	virtual void aplicarEfecto(Character*, Character*) = 0;
};

#endif
