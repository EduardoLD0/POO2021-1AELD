#include "character.h"

Character::Character()
{

}

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
void Character::setPosicion(Posicion* posicion)
{
	this->posicion = posicion;
}

Posicion* Character::getPosicion()
{
	return this->posicion;
}

Arma* Character::getArma()
{
	Arma* pArma = &this->arma;
	return pArma;
}

void Character::setArma(Arma arma)
{
	this->arma = arma;
}

void Character::agregarAtaque(Ataque* pAtaque)	// Agrega el ataque a la lista de ataques
{
	listaAtaques.push_back(pAtaque);
}

std::string Character::getNombre()
{
	return this->nombre;
}