#include "controllerJuego.h"

ControllerJuego::ControllerJuego(nivel nivelMazmorra)
{
	int i;
	controllerI = new ControllerInicializador();
	mazmorra = controllerI->crearMazmorra(nivelMazmorra);	// Crea la mazmorra con el nivel elegido
	heroe = controllerI->crearHeroe();
	heroe->setPosicion(mazmorra->agregarObjeto(tipoElemento::heroe));

	mazmorra->agregarObjeto(tipoElemento::artefacto);

	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::curacion));	// Inicializar pociones
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::dano));
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::ataque));
	listaPociones.push_back(controllerI->crearPocion(tipoEfecto::resistencia));
	
	listaArmas.push_back(controllerI->crearBaston());							// Inicializar armas
	listaArmas.push_back(controllerI->crearEspada());
	listaArmas.push_back(controllerI->crearExcalibur());	
	
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::dano));			// Inicializar ataques
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::ataque));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::curacion));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::resistencia));
	listaAtaques.push_back(controllerI->crearAtaque(tipoAtaque::turno));

	listaEnemigos.push_back(controllerI->crearGuerrero());						// Inicializar enemigos
	listaEnemigos.push_back(controllerI->crearMago());
	listaEnemigos.push_back(controllerI->crearGuerreroBoss());
	listaEnemigos.push_back(controllerI->crearMagoBoss());
	
	for(i = 0; i < mazmorra->getCantidadEnemigos(); ++i)
	{
		generarEnemigo();	// Genera tantos enemigos como se indica en los niveles
	}
	for(i = 0; i < mazmorra->getCantidadEnemigos() / 10; ++i)
	{
		generarBoss();		// Por cada 10 enemigos normales se genera un boss
	}
	this->contadorCombate = 0;
}

void ControllerJuego::generarPocion()
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarPocion();	// Genera una posicion con una pocion
	list<Pocion*>::iterator it = listaPociones.begin();	// Elige una pocion al azar de la lista
	int aleatorio = rand() % listaPociones.size();
	it = std::next(listaPociones.begin(), aleatorio);
	listaPocionesSuelo.insert(pair<Posicion*, Pocion*>(pPosicion, *it));	// Se crea un par con la pocion y su posicion y se agrega al map
}

void ControllerJuego::generarArma()	// Igual que con las pociones
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarArma();
	list<Arma*>::iterator it = listaArmas.begin();
	int aleatorio = rand() % listaArmas.size();
	it = std::next(listaArmas.begin(), aleatorio);
	listaArmasSuelo.insert(pair<Posicion*, Arma*>(pPosicion, *it));
}

void ControllerJuego::generarEnemigo()	// Igual que con las pociones
{
	srand(time(NULL));
	Posicion* pPosicion = mazmorra->agregarEnemigo();
	list<Enemigo*>::iterator it;
	int aleatorio;
	do	// Solo se generan enemigos comunes
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
	do	// Solo se generan jefes
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
	{	// Se busca en el map una pocion que ya tenga que desaparecer
		pPosicion = it->first;
		if (pPosicion->getTurnosSpawn() == 1)
		{
			pPosicion->setElemento(tipoElemento::vacio);
			it = listaPocionesSuelo.erase(it);	// Quita la pocion del suelo
		}
		else
		{	// A las pociones que aun no desaparecen se les quita un turno
			pPosicion->setTurnosSpawn(pPosicion->getTurnosSpawn() - 1);
			++it;
		}
	}

	for (map<Posicion*, Arma*>::iterator it = listaArmasSuelo.begin(); it != listaArmasSuelo.end(); )
	{	// Mismo mecanismo que con las pociones
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
	int x = this->heroe->getPosicion()->getX(), y = this->heroe->getPosicion()->getY();	// Coordenadas del jugador
	switch(dir)	// Direccion a la que va a moverse el jugador
	{			// Dependiendo de la direccion, halla la posicion de enfrente
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
	Posicion* pPosicion = verPosicionSiguiente(dir);	// Posicion siguiente
	switch(pPosicion->getElemento())					// Dependiendo del elemento, se movera o no, y dara indicacion para un evento
	{
		case(tipoElemento::enemigo):	// Si es un enemigo, el heroe se mueve y empieza un combate
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 1;
			heroe->setPosicion(pPosicion);
			break;
		case(tipoElemento::pocion):		// Si es una pocion le pregunta si desea cogerla
			cout << "Desea recoger la pocion?" << endl;
			cout << "1. Si" << endl;
			cout << "2. No" << endl;
			cin >> opcion;
			if(opcion == 1)
			{	// Revisar que tenga espacio en el inventario
				if(heroe->revisarItem(tipoItem::arma) + heroe->revisarItem(tipoItem::pocion) >= 10)
				{
					cout << "No tienes espacio" << endl;
				}
				else
				{	// Si tiene espacio, el jugador recoge la pocion y se mueve
					heroe->getPosicion()->setElemento(tipoElemento::vacio);
					heroe->setPosicion(pPosicion);
					salida = 2;
				}
			}
			else
			{	// Si no quiere recogerla ni se mueve ni la recoge
				salida = 0;
			}
			break;
		case(tipoElemento::arma):	// Igual que con las pociones
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
		case(tipoElemento::puerta):	// Si ya encontro el artefacto la puerta estara abierta y ganara el juego
			if(artefactoEncontrado == 1)
			{
				salida = 4;
			}
			else	// Si no la puerta estara cerrada
			{
				salida = 0;
			}
			break;
		case(tipoElemento::vacio):	// Si esta vacia el heroe puede seguir
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 0;
			heroe->setPosicion(pPosicion);
			break;
		case(tipoElemento::artefacto):	// Si es el artefacto lo recogera y avanzara
			heroe->getPosicion()->setElemento(tipoElemento::vacio);
			salida = 0;
			heroe->setPosicion(pPosicion);
			cout << "Haz encontrado la esmeralda, ahora podras salvar la farmacia" << endl;
			this->artefactoEncontrado = 1;
			break;
	}
	heroe->getPosicion()->setElemento(tipoElemento::heroe);	// Actualiza posicion del heroe
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
	{	// Dependiendo del elemento en la posicion mostrata un caracter distinto en pantalla
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
			{	// Dependiendo del enemigo mostrara un caracter distinto
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
		if(i == tamano)	// Indica el salto de linea
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