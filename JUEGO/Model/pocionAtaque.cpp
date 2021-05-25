#include "pocionAtaque.h"

PocionAtaque::~PocionAtaque()
{

}

void PocionAtaque::aplicarEfecto(Character dummy)
{
	int cambioAtaque = dummy.getAtaque() + 5; // Valor temporal
	dummy.setAtaque(cambioAtaque);
	~PocionAtaque();
}