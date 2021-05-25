#ifndef ATAQUEPARALIZADOR_H
#define ATAQUEPARALIZADOR_H

#include <iostream>

class AtaqueInvocarMagos : public Ataque
{
	public:
	void aplicarEfecto(Character*);
}

#endif