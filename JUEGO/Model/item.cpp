#include "item.h"

Item::~Item()
{

}

tipoItem Item::getTipo()
{
	return this->tipoI;
}

void Item::setTipo(tipoItem tipo)
{
	this->tipoI = tipo;
}