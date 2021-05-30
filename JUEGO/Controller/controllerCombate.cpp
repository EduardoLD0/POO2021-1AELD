#include "controllerCombate.h"

bool ControllerCombate::combatir(Heroe* hertz, Enemigo* enemigo)
{
	int opcion, turnosPerdidos = 0;
	Ataque* pAtaque;
	this->turno = 1;
	do
	{
		cout << "Hertz: " << hertz->getVida() << endl;
		cout << enemigo->getNombre() << ": " << enemigo->getVida() << endl;
		if(turnosPerdidos == 0)
		{
			this->turno = !this->turno;
		}
		else
		{
			--turnosPerdidos;
		}
		cout << "x";
		if(!this->turno)
		{
			cout << "Que ataque desea usar?" << endl;
			hertz->mostrarListaAtaques();
			cin >> opcion;
			pAtaque = hertz->seleccionarAtaque(opcion);
			cout << "Heroe uso: " << pAtaque->getNombre() << endl;
			atacar(hertz, enemigo, pAtaque);
			if(pAtaque->getTipoAtaque() == tipoAtaque::dano)
			{
				hertz->getArma()->setResistencia(hertz->getArma()->getResistencia() - 1);
			}
		}
		else
		{
			pAtaque = enemigo->seleccionarAtaque(1);
			cout << enemigo->getNombre() << " uso: " << pAtaque->getNombre() << endl;
			atacar(enemigo, hertz, pAtaque);
		}
		cout << "x";
		if (hertz->getArma()->getResistencia() < 1 && hertz->getArma()->getNombre() != "Sin arma")
		{
			hertz->eliminarArmaLista(hertz->getArma());
			cout << "Tu arma se ha roto!" << endl;
			hertz->setArma(Arma("Sin arma", -1, 0));
		}
		if(pAtaque->getTipoAtaque() == tipoAtaque::turno)
		{
			turnosPerdidos = pAtaque->aplicarEfecto();
		}
	} while(hertz->getVida() > 0 && enemigo->getVida() > 0);
	if(enemigo->getTipoEnemigo() == tipoEnemigo::guerreroBoss)
	{
		cout << "Tu recompensa es: 10 de vida";
		hertz->setVida(hertz->getVida() + 10);
	}
	if(hertz->getVida() <= 0)
	{
		cout << "Haz muerto. Buen intento vaquero." << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

void ControllerCombate::atacar(Character* atacante, Character* atacado, Ataque* ataque)
{
	switch(ataque->getTipoAtaque())
	{
		case(tipoAtaque::dano):
			atacado->setVida(atacado->getVida() - (atacante->getAtaqueBase() + atacante->getArma()->getPuntosAtaque()));
			cout << "El ataque hizo " << atacante->getAtaqueBase() + atacante->getArma()->getPuntosAtaque() << " de dano." << endl;
			break;
		case(tipoAtaque::curacion):
			atacante->setVida(atacante->getVida() + ataque->aplicarEfecto());
			cout << "Se ha curado " << ataque->aplicarEfecto() << "HP." << endl;
			break;
		case(tipoAtaque::ataque):
			atacado->setAtaqueBase(atacado->getAtaqueBase() - ataque->aplicarEfecto());
			cout << "Ha rebajado los puntos de ataque en " << ataque->aplicarEfecto() << "." << endl;
			break;
		case(tipoAtaque::resistencia):
			atacado->getArma()->setResistencia(atacado->getArma()->getResistencia() - ataque->aplicarEfecto());
			cout << "Ha roto el arma en 1 punto" << endl;;
			break;
		case(tipoAtaque::turno):
			cout << "Lo ha paralizado en " << ataque->aplicarEfecto() << " turnos." << endl;
			break;
	}
}