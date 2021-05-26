#include "controllerInicializador.h"

ControllerInicializador::ControllerInicializador(nivel nivelMazmorra) : mazmorra(nivelMazmorra)
{

}

Arma* ControllerInicializador::crearBaston(int resistencia, int puntosAtaque)
{
	Arma* baston = new Arma(resistencia, puntosAtaque);
	return baston;
}

Arma* ControllerInicializador::crearEspada(int resistencia, int puntosAtaque)
{
	Arma* espada = new Arma(resistencia, puntosAtaque);
	return espada;
}

Character* ControllerInicializador::crearGuerrero(Arma arma, int puntosVida, list<Ataque*>listaAtaques, int ataqueBase)
{
	Enemigo* guerrero = new Enemigo(arma, puntosVida, listaAtaques, ataqueBase);
	return guerrero;
}

Character* ControllerInicializador::crearGuerreroBoss(Arma arma, int puntosVida, list<Ataque*>listaAtaques, int ataqueBase)
{
	Enemigo* guerreroBoss = new Enemigo(arma, puntosVida, listaAtaques, ataqueBase);
	return guerreroBoss;
}

Character* ControllerInicializador::crearMago(Arma arma, int puntosVida, list<Ataque*>listaAtaques, int ataqueBase)
{
	Enemigo* mago = new Enemigo(arma, puntosVida, listaAtaques, ataqueBase);
	return mago;
}

Character* ControllerInicializador::crearMagoBoss(Arma arma, int puntosVida, list<Ataque*>listaAtaques, int ataqueBase)
{
	Enemigo* magoBoss = new Enemigo(arma, puntosVida, listaAtaques, ataqueBase);
	return magoBoss;
}

Mazmorra& ControllerInicializador::getMazmorra()
{
	return this->mazmorra;
}