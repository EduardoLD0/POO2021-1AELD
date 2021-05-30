#ifndef CONTROLLERJUEGO_H
#define CONTROLLERJUEGO_H	

#include "controllerInicializador.h"

using namespace std;

class ControllerJuego
{
private:
	Mazmorra* mazmorra;
	Heroe* heroe;
	list<Arma*> listaArmas;
	list<Pocion*> listaPociones;
	list<Enemigo*> listaEnemigos;
	map<Posicion*, Pocion*> listaPocionesSuelo;
	map<Posicion*, Arma*> listaArmasSuelo;
	map<Posicion*, Enemigo*> listaEnemigosSuelo;
	int contadorCombate;
public:
	ControllerJuego(Mazmorra*);
	void generarPocion();
	void generarArma();
	void generarEnemigo();
	void actualizarItem();
	Posicion* verPosicionSiguiente();
	int moverPersonaje();
	int getContadorCombate();
	void setContadorCombate(int);
	Pocion* getPocion(Posicion*);
	Arma* getArma(Posicion*);
	Enemigo* getEnemigo(Posicion*);
	Heroe* getHeroe();
	Posicion* getPosHeroe();
};

#endif