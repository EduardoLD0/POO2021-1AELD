#include "pocionDebilitadora.h"

PocionDebilitadora::~PocionDebilitadora()
{

}

void PocionDebilitadora::aplicarEfecto(Character dummy)
{
	int cambioVida = dummy.getVida() - 5; // Valor temporal
	dummy.setVida(cambioVida);
	~PocionDebilitadora();
}