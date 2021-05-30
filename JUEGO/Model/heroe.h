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
	list<Pocion*> listaPociones;
	list<Arma*> listaArmas;
public:
	Heroe();
	int usarPocion(int);
	void seleccionarArma(int);
	void recogerPocion(Pocion*);
	void recogerArma(Arma*);
	int revisarItem(tipoItem);
	void eliminarArmaLista(Arma*);
	Ataque* seleccionarAtaque(int);
	void mostrarListaPociones();
	void mostrarListaArmas();
	void mostrarListaAtaques();
};
#endif
