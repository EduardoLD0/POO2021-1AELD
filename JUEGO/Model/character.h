#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <list>
#include "arma.h"
#include "posicion.h"

using namespace std;

class Character 
{
protected:
	int vida;	
	int ataqueBase;
	Posicion posicion;
	Arma* arma;
	bool turno;
public:
	Character();
	void setVida(int);
	int getVida();
	void setAtaqueBase(int);
	int  getAtaqueBase();
	void setPosicion(Posicion);
	Posicion getPosicion();
};
#endif 
