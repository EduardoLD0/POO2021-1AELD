#include "ataqueCuracion.h"

AtaqueCuracion::AtaqueCuracion()
{
	this->nombre = "Restauracion";
	this->tipo = tipoAtaque::curacion;
}

int AtaqueCuracion::aplicarEfecto()
{
	return 2;
}