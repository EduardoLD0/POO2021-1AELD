#include "ataqueComun.h"

AtaqueComun::AtaqueComun()
{
	this->nombre = "Embestida";
	this->tipo = tipoAtaque::dano;
}

int AtaqueComun::aplicarEfecto()	// El ataque comun depende unicamente del ataque base y el arma
{
	return 0;
}