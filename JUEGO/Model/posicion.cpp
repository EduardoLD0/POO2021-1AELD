#include "posicion.h"

Posicion::Posicion()
{

}

Posicion::Posicion(int x, int y, tipoElemento elemento)
{
	this->x = x;
	this->y = y;
	this->elemento = elemento;
	this->turnosSpawn = -1;
}

int Posicion::getX()
{
	return this->x;
}

int Posicion::getY()
{
	return this->y;
}

tipoElemento Posicion::getElemento()
{
	return this->elemento;
}

void Posicion::setElemento(tipoElemento elemento)
{
	this->elemento = elemento;
}

void Posicion::setTurnosSpawn(int turnosSpawn)
{
	this->turnosSpawn = turnosSpawn;
}

int Posicion::getTurnosSpawn()
{
	return this->turnosSpawn;
}