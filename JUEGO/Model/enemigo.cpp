#include "enemigo.h"

Enemigo::Enemigo()
{

}

Enemigo::Enemigo(std::string nombre, Arma arma, int vida, list<Ataque*>listaAtaques, int ataqueBase, tipoEnemigo tipo) 
{
	this->nombre = nombre;
	this->arma = arma;
	this->vida = vida;
	this->ataqueBase = ataqueBase;
	this->listaAtaques = listaAtaques;
	this->tipoE = tipo;
}

Ataque* Enemigo::seleccionarAtaque(int a)
{
	return NULL;
}

Ataque* Enemigo::seleccionarAtaque()
{
	int aleatorio = rand() % listaAtaques.size(), i;	// Genera un numero aleatorio para elegir un ataque al azar
	list<Ataque*>::iterator it;
	it = std::next(listaAtaques.begin(), aleatorio);	// Avanza hasta la posicion del ataque elegido al azar
	return *it;											// Retorna el ataque
}

tipoEnemigo Enemigo::getTipoEnemigo()
{
	return this->tipoE;
}