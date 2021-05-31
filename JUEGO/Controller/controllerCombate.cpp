#include "controllerCombate.h"

ControllerCombate::ControllerCombate(ControllerJuego* controllerJ)
{
	this->controllerJ = controllerJ;
}

bool ControllerCombate::combatir(Heroe* hertz, Enemigo* enemigo)
{
	int opcion, turnosPerdidos = 0;	// Turnos Perdidos son los turnos en los que un personaje esta paralizado
	Ataque* pAtaque;
	this->turno = 1;		// Se inicializa el turno en 1 (hertz siempre ataca primero)
	do
	{
		cout << "Hertz: " << hertz->getVida() << endl;	// Mostras vidas 
		cout << enemigo->getNombre() << ": " << enemigo->getVida() << endl;
		if(turnosPerdidos == 0)	// Si no hay turnos perdidos sigue el otro contrincante
		{
			this->turno = !this->turno;
		}
		else
		{
			--turnosPerdidos;	// De lo contrario seguira el mismo hasta que se desparalice
		}
		if(!this->turno)	// Turno heroe
		{
			cout << "Que ataque desea usar?" << endl;
			hertz->mostrarListaAtaques();
			cin >> opcion;
			pAtaque = hertz->seleccionarAtaque(opcion);
			cout << "Heroe uso: " << pAtaque->getNombre() << endl;
			atacar(hertz, enemigo, pAtaque);						// Hertz ataca
			if(pAtaque->getTipoAtaque() == tipoAtaque::dano)
			{
				hertz->getArma()->setResistencia(hertz->getArma()->getResistencia() - 1);
			}
		}
		else	// Turno enemigo
		{
			pAtaque = enemigo->seleccionarAtaque();
			cout << enemigo->getNombre() << " uso: " << pAtaque->getNombre() << endl;
			atacar(enemigo, hertz, pAtaque);						// El enemigo ataca
		}	// Si tiene arma y se le acaba la resistencia se rompe y se quita del inventario
		if (hertz->getArma()->getResistencia() < 1 && hertz->getArma()->getNombre() != "Sin arma")
		{
			hertz->eliminarArmaLista(hertz->getArma());
			cout << "Tu arma se ha roto!" << endl;
			hertz->setArma(Arma("Sin arma", -1, 0));
		}
		if(pAtaque->getTipoAtaque() == tipoAtaque::turno)
		{
			turnosPerdidos = pAtaque->aplicarEfecto();	// Si el ataque es el ataque paralizador, el que lo recibio pierde turnos
		}
	} while(hertz->getVida() > 0 && enemigo->getVida() > 0);	// La pelea continuara hasta que uno de los dos se muera
	if(hertz->getVida() <= 0)	// Si hertz pierde toda su vida se acaba el juego
	{
		cout << "Haz muerto. Buen intento vaquero." << endl;
		return 1;
	}
	cout << "Haz matado al enemigo!" << endl;
	if(enemigo->getTipoEnemigo() == tipoEnemigo::guerreroBoss)	// Si el enemigo vencido es un jefe se le otorgara una recompensa
	{
		cout << "Tu recompensa es: 10 de vida" << endl;
		hertz->setVida(hertz->getVida() + 10);
	}
	else if(enemigo->getTipoEnemigo() == tipoEnemigo::magoBoss)
	{
		cout << "Tu recompensa es: 5 de ataque" << endl;
		hertz->setAtaqueBase(hertz->getAtaqueBase() + 5);
	}
	return 0;
}

void ControllerCombate::atacar(Character* atacante, Character* atacado, Ataque* ataque)
{
	switch(ataque->getTipoAtaque())	// Dependiendo del tipo de ataque el efecto sera diferente
	{
		case(tipoAtaque::dano):	// Quita vida al enemigo
			atacado->setVida(atacado->getVida() - (atacante->getAtaqueBase() + atacante->getArma()->getPuntosAtaque()));
			cout << "El ataque hizo " << atacante->getAtaqueBase() + atacante->getArma()->getPuntosAtaque() << " de dano." << endl;
			break;
		case(tipoAtaque::curacion):	// Se cura a si mismo
			atacante->setVida(atacante->getVida() + ataque->aplicarEfecto());
			cout << "Se ha curado " << ataque->aplicarEfecto() << "HP." << endl;
			break;
		case(tipoAtaque::ataque):	// Le baja el ataque base al enemigo
			if(ataque->aplicarEfecto() >= atacado->getAtaqueBase())	// Si su ataque corre el riesgo de bajar de 1 no se bajara
			{
				cout << "El ataque no puede bajar mas" << endl;
			}
			else
			{
				atacado->setAtaqueBase(atacado->getAtaqueBase() - ataque->aplicarEfecto());
				cout << "Ha rebajado los puntos de ataque en " << ataque->aplicarEfecto() << "." << endl;
			}
			break;
		case(tipoAtaque::resistencia):	// Le baja los puntos de resistencia al arma del enemigo
			atacado->getArma()->setResistencia(atacado->getArma()->getResistencia() - ataque->aplicarEfecto());
			cout << "Ha roto el arma en 1 punto" << endl;;
			break;
		case(tipoAtaque::turno):		// Paraliza al enemigo (no puede atacar durante algunos turnos)
			cout << "Lo ha paralizado en " << ataque->aplicarEfecto() << " turnos." << endl;
			break;
	}
	if(!this->turno)
	{
		controllerJ->actualizarItem(); // Cada vez que hertz ataca, un turno pasa
	}
}