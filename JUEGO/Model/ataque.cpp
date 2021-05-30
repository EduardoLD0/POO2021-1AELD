#include "ataque.h"

std::string Ataque::getNombre()
{
    return this->nombre;
}

tipoAtaque Ataque::getTipoAtaque()
{
    return this->tipo;
}