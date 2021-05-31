#include "heroe.h"

Heroe::Heroe()
{
	this->nombre = "Hertz";
	this->vida = 30;
	this->ataqueBase = 5;
	this->arma = Arma("Sin arma", -1, 0);	// Hertz siempre empieza sin arma
}

int Heroe::usarPocion(int numPocion)
{
	if(numPocion > listaPociones.size() || numPocion <= 0)	// Si el usuario ingresa un ID invalido se le tira error
	{
		throw std::domain_error("ID incorrecto");
	}
	list<Pocion*>::iterator it = std::next(listaPociones.begin(), numPocion - 1);	// Avanza hasta la posicion de la pocion que indico el jugador
	switch((*it)->getTipoEfecto())	// Dependiendo del efecto le aumentara dicha caracteristica
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
		case(tipoEfecto::dano):	// La pocion de daño aplica efecto en el enemigo
			return 1;			// Indicador para hacerle daño al enemigo
			break;
	}
	listaPociones.erase(it);	// Se borra la pocion del inventario al usarse
	return 0;
}

void Heroe::seleccionarArma(int numArma)
{
	if(numArma > listaArmas.size() || numArma <= 0)	// Si el usuario ingresa un ID incorrecto le tira un error
	{
		throw std::domain_error("ID incorrecto");
	}
	list<Arma*>::iterator it = std::next(listaArmas.begin(), numArma - 1);	// Avanza hasta la pocision digitada por el usuario
	this->arma = **it;														// Le asigna el arma
	this->vida += (*it)->getResistencia();									// Le aumenta la vida segun la resistencia del arma
}

void Heroe::recogerPocion(Pocion* pocion)
{
	listaPociones.push_back(pocion);
}

void Heroe::recogerArma(Arma* arma)
{
	listaArmas.push_back(arma);
}

int Heroe::revisarItem(tipoItem tipo)
{
	if(tipo == tipoItem::pocion)	// Indica la lista a revisar
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
	it = std::next(listaAtaques.begin(), id - 1);	// Mueve el apuntador a la posicion indicada por el usuario
	return *it;
}

void Heroe::mostrarListaPociones()
{
	int i = 0;
	for(list<Pocion*>::iterator it = listaPociones.begin(); it != listaPociones.end(); ++it)
	{
		cout << ++i << ". " << (*it)->getNombre() << "." << endl;
	}
}

void Heroe::mostrarListaArmas()
{
	int i = 0;
	for(list<Arma*>::iterator it = listaArmas.begin(); it != listaArmas.end(); ++it)
	{
		cout << ++i << ". " << (*it)->getNombre() << "." << endl;
	}
}

void Heroe::mostrarListaAtaques()
{
	int i = 0;
	for(list<Ataque*>::iterator it = listaAtaques.begin(); it != listaAtaques.end(); ++it)
	{
		cout << ++i << ". " << (*it)->getNombre() << "." << endl;
	}
}