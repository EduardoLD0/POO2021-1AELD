#ifndef POCIONDEFENSA_H
#define POCIONDEFENSA_H

#include "pocion.h"

class PocionDefensa : public Pocion
{
public:
	void aplicarEfecto(Character) override;
}

#endif 