#include "heroe.h"

Heroe::Heroe()
{
	this->nombre = "Hertz";
	this->vida = 30;
	this->ataqueBase = 5;
	this->arma = Arma("Sin Arma", -1, 0);
}

int Heroe::usarPocion(int numPocion)
{
	list<Pocion*>::iterator it = std::next(listaPociones.begin(), numPocion - 1);
	switch((*it)->getTipoEfecto())
	{
		case(tipoEfecto::ataque):
			this->ataqueBase += (*it)->aplicarEfecto();
			break;
		case(tipoEfecto::curacion):
			this->vida += (*it)->aplicarEfecto();
			break;
		case(tipoEfecto::resistencia):
			this->arma.setResistencia(this->arma.getResistencia() + (*it)->aplicarEfecto());
			break;
		case(tipoEfecto::dano):
			return 1;
			break;
	}
	listaPociones.erase(it);
	return 0;
}

void Heroe::seleccionarArma(int numArma)
{
	list<Arma*>::iterator it = std::next(listaArmas.begin(), numArma - 1);
	this->arma = **it;
}

void Heroe::recogerPocion(Pocion* pocion)
{
	listaPociones.push_back(pocion);
}

void Heroe::recogerArma(Arma* arma)
{
	listaArmas.push_back(arma);
}

bool Heroe::revisarItem(tipoItem tipo)
{
	if(tipo == tipoItem::pocion)
	{
		return listaPociones.size();
	}
	else
	{
		return listaArmas.size();
	}
}

void Heroe::eliminarArmaLista(Arma* arma)
{
	listaArmas.remove(arma);
}

Ataque* Heroe::seleccionarAtaque(int id)
{
	list<Ataque*>::iterator it;
	it = std::next(listaAtaques.begin(), id - 1);
	return *it;
}
