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
	bool artefactoEncontrado;
	list<Posicion*> matriz;
	nivel nivelMazmorra;
public:
	Mazmorra(nivel);
	Posicion * encontrarPosicion(int, int);
	void generarLaberinto();
	pair<Posicion*, Enemigo*> agregarEnemigo();
	pair<Posicion*, Pocion*> agregarPocion();
	pair<Posicion*, Arma*> agregarArma();
	void pintar();
	Posicion * agregarObjeto(tipoElemento);
	int getCantidadEnemigos();
};
#endif