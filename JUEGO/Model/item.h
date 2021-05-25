#ifndef ITEM_H
#define ITEM_H

#include <iostream>


enum tipoItem
{ 
	arma = 0,
	pocion = 1
};

class Item
{
protected:
	tipoItem tipo;
public:
	~Item();
	virtual tipoItem getTipo() = 0;
	virtual void setTipo(tipoItem) = 0;
};

#endif