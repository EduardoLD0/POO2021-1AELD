#include "ataqueDebilitador.h"

AtaqueDebilitador::AtaqueDebilitador()
{
	this->nombre = "Ataque debilitador";
	this->tipo = tipoAtaque::ataque;
}

int AtaqueDebilitador::aplicarEfecto()	// Le baja los puntos de ataque base al enemigo
{
	return 2;
}