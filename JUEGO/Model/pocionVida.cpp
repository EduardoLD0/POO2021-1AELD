#include "pocionVida.h"

PocionVida::~PocionVida()
{

}

void PocionVida::aplicarEfecto(Character dummy)
{
	int cambioVida = dummy.getVida() + 5; // Valor temporal
	dummy.setVida(cambioVida);
	~PocionVida();
}