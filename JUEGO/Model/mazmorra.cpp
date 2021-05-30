#include "mazmorra.h"

Mazmorra::Mazmorra(nivel nivelMazmorra)
{
	int x, y;
	this->nivelMazmorra = nivelMazmorra;
	if (nivelMazmorra == nivel::principiante)
	{
		this->cantidadEnemigos = 10;
		tamano = 15;
	}
	else
	{
		this->cantidadEnemigos = 35;
		tamano = 25;
	}
	for(y = tamano - 1; y >= 0; --y)
	{
		for(x = 0; x < tamano; ++x)
		{
			Posicion* pPosicion = new Posicion(x, y, tipoElemento::vacio);
			matriz.push_back(pPosicion);
		}
	}
	generarLaberinto();
}

Posicion * Mazmorra::encontrarPosicion(int x, int y)
{
	for(list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		if((*it)->getX() == x && (*it)->getY() == y)
		{
			return *it;
		}
	}
	return NULL;
}

void Mazmorra::generarLaberinto()
{
	srand(time(NULL));
	Posicion* obstaculo;
	Posicion* obstaculoAnterior;
	float densidad = 0.3;
	int frecuenciaParedes = densidad * 8, aleatorioPuerta = rand() % ((tamano - 2) * 4);
	densidad = tamano * tamano * densidad / 4;
	int x, y, i = 0, j;
	for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		if ((*it)->getX() == 0 || (*it)->getY() == 0 || (*it)->getX() == tamano - 1 || (*it)->getY() == tamano - 1)
		{
			if(i == aleatorioPuerta && ((*it)->getX() != (*it)->getY()) && 
				((*it)->getX() + (*it)->getY() != tamano - 1))
			{
				(*it)->setElemento(tipoElemento::puerta);
			}
			else
			{
				(*it)->setElemento(tipoElemento::bloque);
			}
			++i;
		}
		else
		{
			(*it)->setElemento(tipoElemento::vacio);
		}
	}
	for (i = 0; i <= densidad; ++i)
	{
		int x = rand() % (tamano - 4) + 2;
		x = (x / 2) * 2; 
		int y = rand() % (tamano - 4) + 2;
		y = (y / 2) * 2;
		encontrarPosicion(x, y)->setElemento(tipoElemento::bloque);
		for (j = 0; j <= frecuenciaParedes; ++j)
		{
			int mx[4] = { x,  x,  x + 2, x - 2 };
			int my[4] = { y + 2,y - 2, y ,  y };
			int r = rand() % 4;
			obstaculo = encontrarPosicion(my[r], mx[r]);
			obstaculoAnterior = encontrarPosicion(my[r] + (y - my[r]) / 2, mx[r] + (x - mx[r]) / 2);
			if (obstaculo->getElemento() == tipoElemento::vacio)
			{
				obstaculo->setElemento(tipoElemento::bloque); 
				obstaculoAnterior->setElemento(tipoElemento::bloque);
			}
		}
	}
}

Posicion* Mazmorra::agregarEnemigo()
{
	srand(time(NULL));
	int numEnemigos = 0, numAleatorio;
	Posicion* pArriba, * pAbajo, * pIzq, * pDer;
	do
	{
		for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
		{
			numAleatorio = 1 + rand() % tamano;
			pArriba = encontrarPosicion((*it)->getX(), (*it)->getY() + 1);
			pAbajo = encontrarPosicion((*it)->getX(), (*it)->getY() - 1);
			pIzq = encontrarPosicion((*it)->getX() - 1, (*it)->getY());
			pDer = encontrarPosicion((*it)->getX() + 1, (*it)->getY());
			if ((*it)->getElemento() == tipoElemento::vacio && numAleatorio == 1 &&
				pArriba->getElemento() != tipoElemento::enemigo && pAbajo->getElemento() != tipoElemento::enemigo &&
				pIzq->getElemento() != tipoElemento::enemigo && pDer->getElemento() != tipoElemento::enemigo)
			{
				(*it)->setElemento(tipoElemento::enemigo);
				++numEnemigos;
				return *it;
				break;
			}
		}
	} while(1);
}

void Mazmorra::pintar()
{
	char a;
	int i = 0;
	for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		++i;
		switch((*it)->getElemento())
		{
		case(tipoElemento::vacio):
			a = ' ';
			break;
		case(tipoElemento::bloque):
			a = 178;
			break;
		case(tipoElemento::heroe):
			a = 211;
			break;
		case(tipoElemento::enemigo):
			a = 184;
			break;
		case(tipoElemento::pocion):
			a = 169;
			break;
		case(tipoElemento::arma):
			a = 158;
			break;
		case(tipoElemento::puerta):
			a = 206;
			break;
		case(tipoElemento::artefacto):
			a = 199;
			break;
		}
		cout << a << a;
		if(i == tamano)
		{
			cout << endl;
			i = 0;
		}
	}
}

Posicion* Mazmorra::agregarArma()
{
	srand(time(NULL));
	Posicion * pPosicion;
	int x, y;
	do
	{
		x = rand() % tamano;
		y = rand() % tamano;
		pPosicion = encontrarPosicion(x, y);
	} while (pPosicion->getElemento() != tipoElemento::vacio);
	pPosicion->setElemento(tipoElemento::arma);
	pPosicion->setTurnosSpawn(3);
	return pPosicion;
}

Posicion* Mazmorra::agregarPocion()
{
	srand(time(NULL));
	Posicion * pPosicion;
	int x, y;
	do
	{
		x = rand() % tamano;
		y = rand() % tamano;
		pPosicion = encontrarPosicion(x, y);
	} while (pPosicion->getElemento() != tipoElemento::vacio);
	pPosicion->setElemento(tipoElemento::pocion);
	pPosicion->setTurnosSpawn(3);
	return pPosicion;
}

Posicion * Mazmorra::agregarObjeto(tipoElemento elemento)
{
	srand(time(NULL));
	Posicion* pPosicion;
	do
	{
		pPosicion = encontrarPosicion(rand() % tamano, rand() % tamano);
	} while (pPosicion->getElemento() != tipoElemento::vacio);
	pPosicion->setElemento(elemento);
	return pPosicion;
}

int Mazmorra::getCantidadEnemigos()
{
	return this->cantidadEnemigos;
}

// mmmmmmmmm
// <o>   <o>
//     U
//  _______