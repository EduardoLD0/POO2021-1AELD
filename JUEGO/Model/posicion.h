#ifndef POSICION_H
#define POSICION_H

#include <iostream>

enum class tipoElemento
{
	vacio = 0,
	bloque = 1,
	enemigo = 2,
	boss = 3,
	pocion = 4,
	arma = 5,
	artefacto = 6,
	heroe = 7,
	puerta = 8
};

class Posicion
{
private:	
	int x, y;
	tipoElemento elemento;
	int turnosSpawn; // Turnos para que desaparezca del mapa (aplica para pociones y armas)
public:
	Posicion();
	Posicion(int, int, tipoElemento);
	int getX();
	int getY();
	int getTurnosSpawn();	
	tipoElemento getElemento();
	void setElemento(tipoElemento);
	void setTurnosSpawn(int);

};
#endif
