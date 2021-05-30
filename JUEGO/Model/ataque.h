#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>

class Ataque
{
protected:
	std::string nombre;
public:
	virtual int aplicarEfecto() = 0;
};

#endif
