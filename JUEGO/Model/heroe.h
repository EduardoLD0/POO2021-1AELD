#ifndef HEROE_H
#define HEROE_H

#include "character.h"
#include "pocion.h"
#include "item.h"
#include "arma.h"
#include <list>


class Heroe : public Character 
{
private:
	list<Item> listaItemInv;
public:
	void usarPocion(Pocion);
	void seleccionarArma(Arma);
	void recogerItem(Item);
	void botarItem(Item);

	
};
#endif
