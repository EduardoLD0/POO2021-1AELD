#include "ataqueComun.h"

AtaqueComun::AtaqueComun()
{
	this->nombre = "Embestida";
	this->tipo = tipoAtaque::dano;
}

int AtaqueComun::aplicarEfecto()
{
	return 3;
}