#include "mazmorra.h"

Mazmorra::Mazmorra(nivel nivelMazmorra)
{
	int x, y;
	this->nivelMazmorra = nivelMazmorra;
	if (nivelMazmorra == nivel::principiante)	// Dependiendo del nivel varia el tamaño y la cantidad de enemigos
	{
		this->cantidadEnemigos = 12;
		tamano = 15;
	}
	else
	{
		this->cantidadEnemigos = 35;
		tamano = 25;
	}
	for(y = tamano - 1; y >= 0; --y)			// Llena la matriz de posiciones vacias
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
	srand(time(NULL));				// Inicializar semilla aleatoria
	Posicion* obstaculo;			// Posicion en la que nos paramos
	Posicion* obstaculoAnterior;	// Posicion anterior
	float densidad = 0.3;			// Expresa que tan lleno de bloques esta el laberinto
	int frecuenciaParedes = densidad * 8, aleatorioPuerta = rand() % ((tamano - 2) * 4);	// Genera una posicion aleatoria para la puerta
	densidad = tamano * tamano * densidad / 4;
	int x, y, i = 0, j;
	for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)
	{
		if ((*it)->getX() == 0 || (*it)->getY() == 0 || (*it)->getX() == tamano - 1 || (*it)->getY() == tamano - 1) // Bordes del mapa
		{
			if(i == aleatorioPuerta && ((*it)->getX() != (*it)->getY()) && 
				((*it)->getX() + (*it)->getY() != tamano - 1)) // La puerta no se puede generar en las esquinas, solo en los bordes
			{
				(*it)->setElemento(tipoElemento::puerta); // Genera una sola puerta aleatoriamente
			}
			else
			{
				(*it)->setElemento(tipoElemento::bloque);	// Llena los bordes de bloques
			}
			++i;
		}
		else
		{
			(*it)->setElemento(tipoElemento::vacio);	// El centro de la mazmorra esta vacio
		}
	}
	for (i = 0; i <= densidad; ++i)
	{
		int x = rand() % (tamano - 4) + 2;	// Elige una posicion aleatoria
		x = (x / 2) * 2; 					// Tiene que ser par la posicion
		int y = rand() % (tamano - 4) + 2;
		y = (y / 2) * 2;
		encontrarPosicion(x, y)->setElemento(tipoElemento::bloque);
		for (j = 0; j <= frecuenciaParedes; ++j)
		{
			int mx[4] = { x,  x,  x + 2, x - 2 }; // Cada posicion tiene 4 posiciones adyacentes
			int my[4] = { y + 2,y - 2, y ,  y };
			int r = rand() % 4;					  // Elige una posicion adyacente al azar
			obstaculo = encontrarPosicion(my[r], mx[r]);
			obstaculoAnterior = encontrarPosicion(my[r] + (y - my[r]) / 2, mx[r] + (x - mx[r]) / 2);
			if (obstaculo->getElemento() == tipoElemento::vacio)
			{
				obstaculo->setElemento(tipoElemento::bloque); // Si la posicion esta vacia, la llena y a la que esta atras tambien
				obstaculoAnterior->setElemento(tipoElemento::bloque);
			}
		}
	}
}

Posicion* Mazmorra::agregarEnemigo()
{
	srand(time(NULL));
	int numAleatorio;	// Se generara un enemigo en una posicion aleatoria
	Posicion* pArriba, * pAbajo, * pIzq, * pDer;	// Un enemigo no puede aparecer al lado de otro
	do
	{
		for (list<Posicion*>::iterator it = matriz.begin(); it != matriz.end(); ++it)	// Se recorren todas las posiciones
		{
			numAleatorio = 1 + rand() % tamano;
			pArriba = encontrarPosicion((*it)->getX(), (*it)->getY() + 1);	// Si alguna de las coordenadas adyacentes tiene un enemigo
			pAbajo = encontrarPosicion((*it)->getX(), (*it)->getY() - 1);	// se buscara otra posicion
			pIzq = encontrarPosicion((*it)->getX() - 1, (*it)->getY());
			pDer = encontrarPosicion((*it)->getX() + 1, (*it)->getY());
			if ((*it)->getElemento() == tipoElemento::vacio && numAleatorio == 1 &&		// Solo se pondra si el numero aleatorio coincide
				pArriba->getElemento() != tipoElemento::enemigo && pAbajo->getElemento() != tipoElemento::enemigo &&
				pIzq->getElemento() != tipoElemento::enemigo && pDer->getElemento() != tipoElemento::enemigo)
			{
				(*it)->setElemento(tipoElemento::enemigo);
				return *it;	// Retorna la posicion en la que se ubico el enemigo
				break;
			}
		}
	} while(1);	// Nos aseguramos de que el enemigo se ponga
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
	} while (pPosicion->getElemento() != tipoElemento::vacio);	// Se busca una posicion al azar que este vacia
	pPosicion->setElemento(tipoElemento::arma);	// Se pone el arma
	pPosicion->setTurnosSpawn(3);		// Se ajustan los turnos para que desaparezca
	return pPosicion;	// Retorna la posicion
}

Posicion* Mazmorra::agregarPocion()	// Misma estrategia que con las armas
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

Posicion * Mazmorra::agregarObjeto(tipoElemento elemento)	// Agrega un objeto especifico de forma aleatoria
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

list<Posicion*> Mazmorra::getMatriz()
{
	return this->matriz;
}

int Mazmorra::getTamano()
{
	return this->tamano;
}