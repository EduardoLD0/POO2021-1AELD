#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <list>
#include <ctime>
#include "arma.h"
#include "posicion.h"
#include "ataque.h"

using namespace std;

class Character 
{
protected:
	std::string nombre;
	int vida;	
	int ataqueBase;
	Posicion posicion;
	Arma arma;
	list<Ataque*> listaAtaques;
public:
	Character();
	void setVida(int);
	int getVida();
	void setAtaqueBase(int);
	int  getAtaqueBase();
	void setPosicion(Posicion);
	Arma& getArma();
	Posicion getPosicion();
	std::string getNombre();
	virtual Ataque* seleccionarAtaque(int) = 0;
};
#endif 
