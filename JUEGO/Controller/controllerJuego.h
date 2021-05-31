#ifndef CONTROLLERJUEGO_H
#define CONTROLLERJUEGO_H	

#include <cstring>

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
	ControllerInicializador* controllerI;
	Mazmorra* mazmorra;
	Heroe* heroe;
	list<Arma*> listaArmas;
	list<Pocion*> listaPociones;
	list<Enemigo*> listaEnemigos;
	list<Ataque*> listaAtaques;
	map<Posicion*, Pocion*> listaPocionesSuelo;
	map<Posicion*, Arma*> listaArmasSuelo;
	map<Posicion*, Enemigo> listaEnemigosSuelo;
	bool artefactoEncontrado, gameOver;
	int contadorCombate;
public:
	ControllerJuego(nivel);
	void generarPocion();	// Genera en el piso
	void generarArma();
	void generarEnemigo();
	void generarBoss();
	void actualizarItem();	// Cada 3 turnos un arma o pocion desaparecen del piso
	Posicion* verPosicionSiguiente(direccion);	// Devuelve la posicion a la que el jugador va a moverse
	int moverPersonaje(direccion);	// Mueve al jugador e indica que hacer despues
	int getContadorCombate();
	void setContadorCombate(int);
	Pocion* getPocion(Posicion*);	// Busca por la posicion en el map
	Arma* getArma(Posicion*);
	Enemigo getEnemigo(Posicion*);
	Heroe* getHeroe();
	Posicion* getPosHeroe();
	void mostrarMazmorra();
	bool getGameOver();
	void setGameOver(bool);
};

#endif