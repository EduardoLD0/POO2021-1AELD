#ifndef ATAQUECOMUN_H
#define ATAQUECOMUN_H

#include "ataque.h"

class AtaqueComun : public Ataque
{
public:
	void aplicarEfecto(Character*);
};

#endif