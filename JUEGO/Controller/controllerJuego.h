#ifndef CONTROLLERJUEGO_H
#define CONTROLLERJUEGO_H	

#include "controllerInicializador.h"

using namespace std;

enum class direccion
{
	arriba = 1,
	abajo = 2,
	izquierda = 3,
	derecha = 4
};

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
	bool artefactoEncontrado;
	int contadorCombate;
public:
	ControllerJuego(Mazmorra*);
	void generarPocion();
	void generarArma();
	void generarEnemigo();
	void actualizarItem();
	Posicion* verPosicionSiguiente(direccion);
	int moverPersonaje(direccion);
	int getContadorCombate();
	void setContadorCombate(int);
	Pocion* getPocion(Posicion*);
	Arma* getArma(Posicion*);
	Enemigo* getEnemigo(Posicion*);
	Heroe* getHeroe();
	Posicion* getPosHeroe();
};

#endif