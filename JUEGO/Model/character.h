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
	Posicion* posicion;	// Donde se encuentra el personaje en el mapa
	Arma arma;
	list<Ataque*> listaAtaques;
public:
	Character();	// Clase abstracta
	void setVida(int);
	int getVida();
	void setAtaqueBase(int);
	int  getAtaqueBase();
	void setPosicion(Posicion*);
	Arma* getArma();
	void setArma(Arma);
	Posicion* getPosicion();
	std::string getNombre();
	void agregarAtaque(Ataque *);
	virtual Ataque* seleccionarAtaque(int) = 0;
};
#endif 
