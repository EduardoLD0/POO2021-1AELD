#include "pocionDefensa.h"

PocionDefensa::~PocionDefensa()
{

}

void PocionDefensa::aplicarEfecto(Character dummy)
{
	int cambioResistencia = dummy.getResistencia() + 5; // Valor temporal
	dummy.setResistencia(cambioResistencia);
	~PocionDefensa();
}