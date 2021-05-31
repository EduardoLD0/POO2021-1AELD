#include "ataqueCuracion.h"

AtaqueCuracion::AtaqueCuracion()
{
	this->nombre = "Restauracion";
	this->tipo = tipoAtaque::curacion;
}

int AtaqueCuracion::aplicarEfecto()	// El ataque curacion le da vida al personaje que lo use
{
	return 2;
}