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
		this->cantidadEnemigos = 25;
		tamano = 15;
	}
	for(x = 0; x < tamano; x++)
	{
		for(y = 0; y < tamano; y++)
		{
			Posicion* pPosicion = new Posicion(x, y, tipoElemento::vacio);
			matriz.push_back(pPosicion);
		}
	}
	generarLaberinto();
	agregarEnemigos();
	agregarObjeto(tipoElemento::heroe);
	agregarObjeto(tipoElemento::artefacto);
	agregarObjeto(tipoElemento::puerta);
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
	int fParedes = densidad * 8;
	densidad = tamano * tamano * densidad / 4;

	int x, y, i, j;
	for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		if ((*it)->getX() == 0 || (*it)->getY() == 0 || (*it)->getX() == tamano - 1 || (*it)->getY() == tamano - 1)
		{
			(*it)->setElemento(tipoElemento::bloque);
		}
		else
		{
			(*it)->setElemento(tipoElemento::vacio);
		}
	}
	for (i = 0; i <= densidad; ++i)
	{
		int x = rand() % (tamano - 4) + 2; // 2 18 
		x = (x / 2) * 2; 
		int y = rand()% (tamano - 4) + 2;
		y = (y / 2) * 2;
		encontrarPosicion(x, y)->setElemento(tipoElemento::bloque);
		for (j = 0; j <= fParedes; ++j)
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

void Mazmorra::agregarEnemigos()
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
			}
			if (numEnemigos >= cantidadEnemigos)
			{
				break;
			}
		}
	}  while (numEnemigos < cantidadEnemigos);
}

void Mazmorra::pintar()
{
	char a;
	int i = 0;
	for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		++i;
		if((*it)->getElemento() == tipoElemento::bloque)
		{
			a = 178;
			cout << a << a;
		}
		else if((*it)->getElemento() == tipoElemento::vacio)
		{
			cout << "  ";
		}
		else if((*it)->getElemento() == tipoElemento::enemigo)
		{
			a = 184;
			cout << a << a;
		}
		else if((*it)->getElemento() == tipoElemento::pocion)
		{
			a = 157;
			cout << a << a;
		}
		else if ((*it)->getElemento() == tipoElemento::arma)
		{
			a = 158;
			cout << a << a;
		}
		if(i == tamano)
		{
			cout << endl;
			i = 0;
		}
	}
}

Posicion * Mazmorra::agregarItem(tipoItem item)
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
	if(item == tipoItem::pocion)
	{
		pPosicion->setElemento(tipoElemento::pocion);
	}
	else if(item == tipoItem::arma)
	{
		pPosicion->setElemento(tipoElemento::arma);
	}
	return pPosicion;
}

void Mazmorra::agregarObjeto(tipoElemento elemento)
{
	srand(time(NULL));
	Posicion* pPosicion;
	do
	{
		pPosicion = encontrarPosicion(rand() % tamano, rand() % tamano);
	} while (pPosicion->getElemento() != tipoElemento::vacio);
	pPosicion->setElemento(elemento);
}

