#include "enemigo.h"

Enemigo::Enemigo(std::string nombre, Arma arma, int vida, list<Ataque*>listaAtaques, int ataqueBase) 
{
	this->nombre = nombre;
	this->arma = arma;
	this->vida = vida;
	this->ataqueBase = ataqueBase;
	this->listaAtaques = listaAtaques;
}

void Enemigo::agregarAtaque(Ataque *ataque)
{
	this->listaAtaques.push_back(ataque);
}

Ataque *Enemigo::seleccionarAtaque(int num)
{
	int aleatorio = rand() % listaAtaques.size(), i;
	list<Ataque*>::iterator it;
	it = std::next(listaAtaques.begin(), aleatorio);
	return *it;
}

	/*\o/
	   |
	  / \*/