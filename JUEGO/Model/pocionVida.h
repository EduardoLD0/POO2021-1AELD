#ifndef POCIONVIDA_H
#define POCIONVIDA_H

#include "pocion.h"


class PocionVida : public Pocion
{
public:
	PocionVida();
	int aplicarEfecto() override;
};

#endif