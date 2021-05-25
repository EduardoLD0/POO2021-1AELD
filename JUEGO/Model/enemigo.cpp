#include "enemigo.h"


Enemigo::Enemigo(int vida, int ataqueBase) 
{
	this->vida = vida;
	this->ataqueBase = ataqueBase;
}

void Enemigo::agregarAtaque(Ataque *ataque)
{
	this->listaAtaqueEnemigos.push_back(ataque);
}