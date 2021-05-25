#include "enemigo.h"


Enemigo::Enemigo(Arma* arma, int vida, list<Ataque*>listaAtaques, int ataqueBase) 
{
	this->arma = arma;
	this->vida = vida;
	this->ataqueBase = ataqueBase;
	this->listaAtaqueEnemigos = listaAtaques;
}

void Enemigo::agregarAtaque(Ataque *ataque)
{
	this->listaAtaqueEnemigos.push_back(ataque);
}

Ataque *Enemigo::seleccionarAtaque()
{
	int aleatorio = rand() % listaAtaqueEnemigos.size(), i;
	list<Ataque*>::iterator it = listaAtaqueEnemigos.begin();
	for (i = 0; i <= aleatorio; ++i)
	{
		++it;
	}
	return *it;
}

	/*\o/
	   |
	  / \*/