#ifndef HEROE_H
#define HEROE_H

#include "character.h"
#include "pocion.h"
#include "item.h"
#include "arma.h"
#include "ataque.h"
#include <list>


class Heroe : public Character 
{
private:
	list<Item*> listaItemInv;
public:
	Heroe();
	void usarPocion(Pocion*);
	void setArma(Arma);
	void recogerItem(Item*);
	bool revisarItem(tipoItem);
	void eliminarItemLista(Item*);
	Ataque* seleccionarAtaque(int);
};
#endif
