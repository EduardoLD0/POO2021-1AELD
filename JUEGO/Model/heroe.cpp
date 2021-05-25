#include "heroe.h"

void Heroe::usarPocion(Pocion* pocion)
{
	//pocion->aplicarEfecto(); // Hay que hacer correccion
}

void Heroe::seleccionarArma(Arma* arma)
{
	this->arma = arma;
}

void Heroe::recogerItem(Item* item)
{
	listaItemInv.push_back(item);
}

bool Heroe::revisarItem(tipoItem tipo)
{
	for (list<Item*>::iterator it = listaItemInv.begin(); it != listaItemInv.end(); ++it)
	{
		if ((*it)->getTipo() == tipo)
		{
			return 1;
		}
	}
	return 0;
}

 void Heroe::eliminarItemLista(Item* item)
 {
	 listaItemInv.remove(item);
 }