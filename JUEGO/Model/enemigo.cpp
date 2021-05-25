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