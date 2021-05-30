#ifndef POCIONATAQUE_H
#define POCIONATAQUE_H

#include "pocion.h"

class PocionAtaque : public Pocion
{
public:
	PocionAtaque();
	int aplicarEfecto() override;
};

#endif 