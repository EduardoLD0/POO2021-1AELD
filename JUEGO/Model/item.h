#ifndef ITEM_H
#define ITEM_H

#include <iostream>


enum class tipoItem
{ 
	arma = 0,
	pocion = 1
};

class Item
{
protected:
	tipoItem tipoI;
public:
	~Item();
	tipoItem getTipo();
	void setTipo(tipoItem);
};

#endif