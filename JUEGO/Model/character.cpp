#include "character.h"

void Character::setVida(int vida)
{
	this->vida = vida;
}

int Character::getVida()
{
	return this->vida;
}
void Character::setAtaqueBase(int ataqueBase)
{
	this->ataqueBase = ataqueBase;
}

int Character::getAtaqueBase()
{
	return this->ataqueBase;
}
void Character::setPosicion(Posicion posicion)
{
	this->posicion = posicion;
}

Posicion Character::getPosicion()
{
	return this->posicion;
}

Arma& Character::getArma()
{
	return arma;
}

std::string Character::getNombre()
{
	return this->nombre;
}