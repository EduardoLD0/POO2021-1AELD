#ifndef ARMA_H
#define ARMA_H

#include "item.h"

class Arma : public Item
{
private:
	std::string nombre;
	int resistencia, puntosAtaque;
public:
	Arma();
	Arma(std::string, int, int);
	int getResistencia();
	int getPuntosAtaque();
	void setResistencia(int);
	void setPuntosAtaque(int);
	std::string getNombre();
};

#endif