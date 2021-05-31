#include "ataqueParalizador.h"

AtaqueParalizador::AtaqueParalizador()
{
    this->nombre = "Rayo laser";
    this->tipo = tipoAtaque::turno;
}

int AtaqueParalizador::aplicarEfecto()  // Paraliza al enemigo por ciertos turnos (no puede atacar)
{
    return 2;
}