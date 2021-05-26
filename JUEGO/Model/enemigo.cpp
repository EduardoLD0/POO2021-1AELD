#include "enemigo.h"


Enemigo::Enemigo(Arma arma, int vida, list<Ataque*>listaAtaques, int ataqueBase) 
{
	this->arma = arma;
	this->vida = vida;
	this->ataqueBase = ataqueBase;
	this->listaAtaques = listaAtaques;
}

void Enemigo::agregarAtaque(Ataque *ataque)
{
	this->listaAtaques.push_back(ataque);
}

Ataque *Enemigo::seleccionarAtaque()
{
	int aleatorio = rand() % listaAtaques.size(), i;
	list<Ataque*>::iterator it = listaAtaques.begin();
	for (i = 0; i <= aleatorio; ++i)
	{
		++it;
	}
	return *it;
}

	/*\o/
	   |
	  / \*/