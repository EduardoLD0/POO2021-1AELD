#include "ataqueParalizador.h"

AtaqueParalizador::AtaqueParalizador()
{
    this->nombre = "Rayo laser";
    this->tipo = tipoAtaque::turno;
}

int AtaqueParalizador::aplicarEfecto()
{
    return 2;
}