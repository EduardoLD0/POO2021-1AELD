#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <iostream>
#include "posicion.h"
#include "pocionVida.h"
#include "pocionDebilitadora.h"
#include "pocionAtaque.h"
#include "pocionDefensa.h"
#include "enemigo.h"
#include <list>
#include <ctime>
#include <map>

using namespace std;

enum class nivel
{
	principiante = 1,
	normal = 2
};

class Mazmorra
{
private:
	int tamano, cantidadEnemigos;
	list<Posicion*> matriz;	// Mapa del laberinto
	nivel nivelMazmorra;
public:
	Mazmorra(nivel);
	Posicion * encontrarPosicion(int, int);	// Encuentra la posicion con las coordenadas X y Y
	void generarLaberinto();				// Genera el laberinto de forma aleatoria
	Posicion* agregarEnemigo();				// Elige una posicion al azar y pone un enemigo
	Posicion* agregarPocion();				// "" pocion
	Posicion* agregarArma();				// "" arma
	Posicion * agregarObjeto(tipoElemento);	
	int getCantidadEnemigos();
	list<Posicion*> getMatriz();
	int getTamano();
};
#endif