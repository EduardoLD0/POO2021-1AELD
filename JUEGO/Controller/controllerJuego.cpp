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

Posicion* ControllerJuego::verPosicionSiguiente(direccion dir)
{
	Posicion* pPosicion;
	int x = this->heroe->getPosicion()->getX(), y = this->heroe->getPosicion()->getY();
	switch(dir)
	{
		case(direccion::arriba):
			pPosicion = mazmorra->encontrarPosicion(x, y + 1);
			break;
		case(direccion::abajo):
			pPosicion = mazmorra->encontrarPosicion(x, y - 1);
			break;
		case(direccion::izquierda):
			pPosicion = mazmorra->encontrarPosicion(x - 1, y);
			break;
		case(direccion::derecha):
			pPosicion = mazmorra->encontrarPosicion(x + 1, y);
			break;
	}
	return pPosicion;
}

int ControllerJuego::moverPersonaje(direccion dir)
{
	int salida, opcion;
	Posicion* pPosicion = verPosicionSiguiente(dir);
	switch(pPosicion->getElemento())
	{
		case(tipoElemento::enemigo):
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 1;
			heroe->setPosicion(pPosicion);
			break;
		case(tipoElemento::pocion):
			cout << "Desea recoger la pocion?" << endl;
			cout << "1. Si" << endl;
			cout << "2. No" << endl;
			cin >> opcion;
			if(opcion == 1)
			{
				heroe->getPosicion()->setElemento(tipoElemento::vacio);
				heroe->setPosicion(pPosicion);
				salida = 2;
			}
			else
			{
				salida = 0;
			}
			break;
		case(tipoElemento::arma):
			cout << "Desea recoger el arma?" << endl;
			cout << "1. Si" << endl;
			cout << "2. No" << endl;
			cin >> opcion;
			if(opcion == 1)
			{
				heroe->getPosicion()->setElemento(tipoElemento::vacio);
				heroe->setPosicion(pPosicion);
				salida = 3;
			}
			else
			{
				salida = 0;
			}
			break;
		case(tipoElemento::puerta):
			if(artefactoEncontrado == 1)
			{
				salida = 4;
			}
			else
			{
				salida = 0;
			}
			break;
		case(tipoElemento::vacio):
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 0;
			heroe->setPosicion(pPosicion);
			break;
		case(tipoElemento::artefacto):
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 0;
			heroe->setPosicion(pPosicion);
			this->artefactoEncontrado = 1;
			break;
	}
	return salida;
}

int ControllerJuego::getContadorCombate()
{
	return this->contadorCombate;
}

void ControllerJuego::setContadorCombate(int num)
{
	this->contadorCombate = num;
}

Pocion* ControllerJuego::getPocion(Posicion* pPosicion)
{
	return listaPocionesSuelo.find(pPosicion)->second;
}

Arma* ControllerJuego::getArma(Posicion* pPosicion)
{
	return listaArmasSuelo.find(pPosicion)->second;
}

Enemigo* ControllerJuego::getEnemigo(Posicion* pPosicion)
{
	return listaEnemigosSuelo.find(pPosicion)->second;
}

Heroe* ControllerJuego::getHeroe()
{
	return this->heroe;
}

Posicion* ControllerJuego::getPosHeroe()
{
	return this->heroe->getPosicion();
}