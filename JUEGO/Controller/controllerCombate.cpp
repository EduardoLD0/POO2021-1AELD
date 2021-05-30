#include "controllerCombate.h"

bool ControllerCombate::combatir(Heroe* hertz, Enemigo* enemigo)
{
	int opcion, turnosPerdidos = 0;
	Ataque* pAtaque;
	this->turno = 1;
	do
	{
		if(turnosPerdidos = 0)
		{
			this->turno = !this->turno;
		}
		else
		{
			--turnosPerdidos;
		}
		if(!this->turno)
		{
			cout << "Que ataque desea usar?" << endl;
			hertz->mostrarListaAtaques();
			cin >> opcion;
			pAtaque = hertz->seleccionarAtaque(opcion);
			atacar(hertz, enemigo, pAtaque);
			if(pAtaque->getTipoAtaque() == tipoAtaque::dano)
			{
				hertz->getArma()->setResistencia(hertz->getArma()->getResistencia() - 1);
			}
		}
		else
		{
			pAtaque = enemigo->seleccionarAtaque(1);
			atacar(enemigo, hertz, pAtaque);
		}
		if (hertz->getArma()->getResistencia() < 1 && hertz->getArma()->getNombre() != "Sin arma")
		{
			hertz->eliminarArmaLista(hertz->getArma());
			cout << "Tu arma se ha roto!" << endl;
			hertz->setArma(Arma("Sin arma", -1, 0));
		}
		if(pAtaque->getTipoAtaque() == tipoAtaque::turno)
		{
			turnosPerdidos = 3;
		}
	} while(hertz->getVida() > 0 && enemigo->getVida() > 0);
	if(enemigo->getTipoEnemigo() == tipoEnemigo::guerreroBoss)
	{
		cout << "Tu recompensa es: 10 de vida";
		hertz->setVida(hertz->getVida() + 10);
	}
	if(hertz->getVida() <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void ControllerCombate::atacar(Character* atacante, Character* atacado, Ataque* ataque)
{
	switch(ataque->getTipoAtaque())
	{
		case(tipoAtaque::dano):
			atacado->setVida(atacado->getVida() - atacante->getAtaqueBase() + atacante->getArma()->getPuntosAtaque());
			break;
		case(tipoAtaque::curacion):
			atacante->setVida(atacante->getVida() + ataque->aplicarEfecto());
			break;
		case(tipoAtaque::ataque):
			atacado->setAtaqueBase(atacado->getAtaqueBase() - ataque->aplicarEfecto());
			break;
		case(tipoAtaque::resistencia):
			atacado->getArma()->setResistencia(atacado->getArma()->getResistencia() - ataque->aplicarEfecto());
			break;
		case(tipoAtaque::turno):
			break;
	}
}