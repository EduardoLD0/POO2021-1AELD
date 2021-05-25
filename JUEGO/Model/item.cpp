#include "item.h"

Item::~Item()
{

}

tipoItem Item::getTipo()
{
	return this->tipo;
}

void Item::setTipo(tipoItem tipo)
{
	this->tipo = tipo;
}