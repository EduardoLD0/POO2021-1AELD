#include "controllerJuego.h"

ControllerJuego::ControllerJuego(): mazmorra(nivel::normal)
{
	contadorCombate = 0;
	mazmorra.generarLaberinto();
	mazmorra.agregarEnemigos();
	Pocion* pocion, *pocion2;
	Arma* arma, * arma2;
	listaPociones.push_back(pocion);
	listaPociones.push_back(pocion2);
	listaArmas.push_back(arma);
	listaArmas.push_back(arma2);
}

void ControllerJuego::generarPocion()
{
	
	srand(time(NULL));
	int i, numAleatorio = rand() % listaPociones.size();
	cout << numAleatorio;
	list<Pocion*>::iterator it = listaPociones.begin(); 
	for (i = 0; i <= numAleatorio; ++i)
	{
		++it;
	}
	Posicion* pPocion = mazmorra.agregarItem(tipoItem::pocion);
	listaPocionesSuelo.insert(pair<Pocion*, Posicion*>((*it), pPocion));
	pPocion->setTurnosSpawn(3);
}

void ControllerJuego::generarArma()
{
	srand(time(NULL));
	int i, numAleatorio = rand() % listaArmas.size();
	list<Arma*>::iterator it = listaArmas.begin();
	for (i = 0; i <= numAleatorio; ++i)
	{
		++it;
	}
	Posicion* pArma = mazmorra.agregarItem(tipoItem::arma);
	listaArmasSuelo.insert(pair<Arma*, Posicion*>((*it), pArma));
	pArma->setTurnosSpawn(3);
}

void ControllerJuego::actualizarItem()
{
	Posicion* pPosicion, *pPosicion2;

	for (map<Pocion*, Posicion*>::iterator it = listaPocionesSuelo.begin(); it != listaPocionesSuelo.end(); )
	{
		pPosicion = it->second;
		if (pPosicion->getTurnosSpawn() == 0)
		{
			pPosicion->setElemento(tipoElemento::vacio);
			it = listaPocionesSuelo.erase(it);
		}
		else
		{
			pPosicion->setTurnosSpawn(pPosicion->getTurnosSpawn() - 1);
			++it;
		}
	}

	for (map<Arma*, Posicion*>::iterator it = listaArmasSuelo.begin(); it != listaArmasSuelo.end(); )
	{
		pPosicion2 = it->second;
		if (pPosicion2->getTurnosSpawn() == 0) 
		{
			pPosicion2->setElemento(tipoElemento::vacio);
			it = listaArmasSuelo.erase(it);
		}
		else
		{
			pPosicion2->setTurnosSpawn(pPosicion2->getTurnosSpawn() - 1);
			++it;
		}
	}
	mazmorra.pintar();
}

int main()
{
	ControllerJuego controller;
	controller.generarPocion();
	controller.actualizarItem();
	controller.actualizarItem();
	controller.actualizarItem();
	return 0;
}