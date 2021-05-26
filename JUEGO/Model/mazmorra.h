#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <iostream>
#include "posicion.h"
#include "item.h"
#include <list>
#include <ctime>

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
	void agregarEnemigos();
	Posicion * agregarItem(tipoItem);
	void pintar();
	void agregarObjeto(tipoElemento);
};
#endif