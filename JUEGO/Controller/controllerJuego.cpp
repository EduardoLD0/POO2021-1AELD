#include "controllerJuego.h"

ControllerJuego::ControllerJuego(nivel nivelMazmorra)
{
	int i;
	controllerI = new ControllerInicializador();
	mazmorra = controllerI->crearMazmorra(nivelMazmorra);
	heroe = controllerI->crearHeroe();
	heroe->setPosicion(mazmorra->agregarObjeto(tipoElemento::heroe));
	mazmorra->agregarObjeto(tipoElemento::artefacto);
	list<Arma*>::iterator itArma;
	list<Ataque*>::iterator itAtaque1, itAtaque2, itAtaque3;
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::curacion));
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::dano));
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::ataque));
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::resistencia));
	
	listaArmas.push_back(controllerI->crearBaston());
	listaArmas.push_back(controllerI->crearEspada());
	listaArmas.push_back(controllerI->crearExcalibur());	
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::dano));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::ataque));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::curacion));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::resistencia));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::turno));
	listaEnemigos.push_back(controllerI->crearGuerrero());
	listaEnemigos.push_back(controllerI->crearMago());
	listaEnemigos.push_back(controllerI->crearGuerreroBoss());
	listaEnemigos.push_back(controllerI->crearMagoBoss());
	
	for(i = 0; i < mazmorra->getCantidadEnemigos(); ++i)
	{
		generarEnemigo();
	}
	for(i = 0; i < mazmorra->getCantidadEnemigos() / 10; ++i)
	{
		generarBoss();
	}
	this->contadorCombate = 0;
}

void ControllerJuego::generarPocion()
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarPocion();
	list<Pocion*>::iterator it = listaPociones.begin();
	int aleatorio = rand() % listaPociones.size();
	it = std::next(listaPociones.begin(), aleatorio);
	listaPocionesSuelo.insert(pair<Posicion*, Pocion*>(pPosicion, *it));
}

void ControllerJuego::generarArma()
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarArma();
	list<Arma*>::iterator it = listaArmas.begin();
	int aleatorio = rand() % listaArmas.size();
	it = std::next(listaArmas.begin(), aleatorio);
	listaArmasSuelo.insert(pair<Posicion*, Arma*>(pPosicion, *it));
}

void ControllerJuego::generarEnemigo()
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarEnemigo();
	list<Enemigo*>::iterator it;
	int aleatorio;
	do
	{
		aleatorio = rand() % listaEnemigos.size();
		it = std::next(listaEnemigos.begin(), aleatorio);
	} while((*it)->getTipoEnemigo() != tipoEnemigo::guerrero && (*it)->getTipoEnemigo() != tipoEnemigo::mago);
	listaEnemigosSuelo.insert(pair<Posicion*, Enemigo>(pPosicion, **it));
}

void ControllerJuego::generarBoss()
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarEnemigo();
	list<Enemigo*>::iterator it;
	int aleatorio;
	do
	{
		aleatorio = rand() % listaEnemigos.size();
		it = std::next(listaEnemigos.begin(), aleatorio);
	} while((*it)->getTipoEnemigo() != tipoEnemigo::guerreroBoss && (*it)->getTipoEnemigo() != tipoEnemigo::magoBoss);
	listaEnemigosSuelo.insert(pair<Posicion*, Enemigo>(pPosicion, **it));
}

void ControllerJuego::actualizarItem()
{
	Posicion* pPosicion, *pPosicion2;

	for (map<Posicion*, Pocion*>::iterator it = listaPocionesSuelo.begin(); it != listaPocionesSuelo.end(); )
	{
		pPosicion = it->first;
		if (pPosicion->getTurnosSpawn() == 1)
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
	int salida = 0, opcion;
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
				if(heroe->revisarItem(tipoItem::arma) + heroe->revisarItem(tipoItem::pocion) >= 10)
				{
					cout << "No tienes espacio" << endl;
				}
				else
				{
					heroe->getPosicion()->setElemento(tipoElemento::vacio);
					heroe->setPosicion(pPosicion);
					salida = 2;
				}
			}
			else
			{
				salida = 0;
			}
			break;
		case(tipoElemento::arma):
			cout << "Desea recoger el arma?" << endl;
			cout << "1. Si." << endl;
			cout << "2. No." << endl;
			cin >> opcion;
			if(opcion == 1)
			{
				if(heroe->revisarItem(tipoItem::arma) + heroe->revisarItem(tipoItem::pocion) >= 10)
				{
					cout << "No tienes espacio" << endl;
				}
				else
				{
					heroe->getPosicion()->setElemento(tipoElemento::vacio);
					heroe->setPosicion(pPosicion);
					salida = 3;
				}
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
			cout << "Haz encontrado la esmeralda, ahora podras salvar la farmacia" << endl;
			this->artefactoEncontrado = 1;
			break;
	}
	heroe->getPosicion()->setElemento(tipoElemento::heroe);
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

Enemigo ControllerJuego::getEnemigo(Posicion* pPosicion)
{
	return (listaEnemigosSuelo.find(pPosicion)->second);
}

Heroe* ControllerJuego::getHeroe()
{
	return this->heroe;
}

Posicion* ControllerJuego::getPosHeroe()
{
	return this->heroe->getPosicion();
}

void ControllerJuego::mostrarMazmorra()
{
	char a;
	list<Posicion*> matriz = mazmorra->getMatriz();
	Enemigo* pEnemigo = new Enemigo();
	int tamano = mazmorra->getTamano();
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
			*pEnemigo = getEnemigo(*it);
			switch(pEnemigo->getTipoEnemigo())
			{
			case(tipoEnemigo::guerrero):
				a = 251;
				break;
			case(tipoEnemigo::mago):
				a = 253;
				break;
			case(tipoEnemigo::guerreroBoss):
				a = 190;
				break;
			case(tipoEnemigo::magoBoss):
				a = 245;
				break;
			}
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

void ControllerJuego::setGameOver(bool estado)
{
	this->gameOver = estado;
}

bool ControllerJuego::getGameOver()
{
	return this->gameOver;
}