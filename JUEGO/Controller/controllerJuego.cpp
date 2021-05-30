#include "controllerJuego.h"

ControllerJuego::ControllerJuego(Mazmorra* mazmorra)
{
	this->mazmorra = mazmorra;
	contadorCombate = 0;
	Pocion* pocion, *pocion2;
	Arma* arma, * arma2;
	listaPociones.push_back(pocion);
	listaPociones.push_back(pocion2);
	listaArmas.push_back(arma);
	listaArmas.push_back(arma2);
}

void ControllerJuego::generarPocion()
{
	map<Posicion*, Pocion*> pocionTemp = mazmorra->agregarPocion();
	map<Posicion*, Pocion*>::iterator it = pocionTemp.begin();
	list<Pocion*>::iterator it2 = listaPociones.begin();
	int aleatorio = rand() % listaPociones.size();
	it2 = std::next(listaPociones.begin(), aleatorio);
	it->second = *it2;
	listaPocionesSuelo.insert(pocionTemp.begin(), pocionTemp.end());
}

void ControllerJuego::generarArma()
{
	map<Posicion*, Arma*> armaTemp = mazmorra->agregarArma();
	map<Posicion*, Arma*>::iterator it = armaTemp.begin();
	list<Arma*>::iterator it2 = listaArmas.begin();
	int aleatorio = rand() % listaArmas.size();
	it2 = std::next(listaArmas.begin(), aleatorio);
	it->second = *it2;
	listaArmasSuelo.insert(armaTemp.begin(), armaTemp.end());
}

void ControllerJuego::generarEnemigo()
{
	map<Posicion*, Enemigo*> enemigoTemp = mazmorra->agregarEnemigo();
	map<Posicion*, Enemigo*>::iterator it = enemigoTemp.begin();
	list<Enemigo*>::iterator it2 = listaEnemigos.begin();
	int aleatorio = rand() % listaArmas.size();
	it2 = std::next(listaEnemigos.begin(), aleatorio);
	*it->second = **it2;
	listaEnemigosSuelo.insert(enemigoTemp.begin(), enemigoTemp.end());
}

void ControllerJuego::actualizarItem()
{
	Posicion* pPosicion, *pPosicion2;

	for (map<Posicion*, Pocion*>::iterator it = listaPocionesSuelo.begin(); it != listaPocionesSuelo.end(); )
	{
		pPosicion = it->first;
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

	for (map<Posicion*, Arma*>::iterator it = listaArmasSuelo.begin(); it != listaArmasSuelo.end(); )
	{
		pPosicion2 = it->first;
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
}