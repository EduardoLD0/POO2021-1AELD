#ifndef CONTROLLERJUEGO_H
#define CONTROLLERJUEGO_H	

#include "../Model/enemigo.h"
#include "../Model/pocion.h"
#include "../Model/mazmorra.h"

#include <iostream>
#include <list>
#include <ctime>
#include <map>

using namespace std;

class ControllerJuego
{
private:
	Mazmorra mazmorra;
	list<Arma*> listaArmas;
	list<Pocion*> listaPociones;
	list<Enemigo*> listaEnemigos;
	map<Pocion*, Posicion*> listaPocionesSuelo;
	map<Arma*, Posicion*> listaArmasSuelo;
	int contadorCombate;
public:
	ControllerJuego();
	void generarPocion();
	void generarArma();
	void actualizarItem();
};

#endif