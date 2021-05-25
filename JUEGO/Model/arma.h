#ifndef ARMA_H
#define ARMA_H

#include "item.h"

class Arma : public Item
{
private:
	int resistencia, puntosAtaque;
public:
	Arma(int, int);
	int getResistencia();
	int getPuntosAtaque();
	void setResistencia(int);
	void setPuntosAtaque(int);
};

#endif