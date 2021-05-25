#include "arma.h"

Arma::Arma(int resistencia, int puntosAtaque)
{
	this->resistencia = resistencia;
	this->puntosAtaque = puntosAtaque;
}

int Arma::getResistencia()
{
	return this->resistencia;
}

int Arma::getPuntosAtaque()
{
	return this->puntosAtaque;
}

void Arma::setResistencia(int resistencia)
{
	this->resistencia = resistencia;
}

void Arma::setPuntosAtaque(int puntosAtaque)
{
	this->puntosAtaque = puntosAtaque;
}