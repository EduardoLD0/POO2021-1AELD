#include "controllerInicializador.h"

ControllerInicializador::ControllerInicializador()
{

}

Arma* ControllerInicializador::crearArma(std::string nombre, int resistencia, int dano)
{
	Arma* pArma = new Arma(nombre, resistencia, dano);
	return pArma;
}

Arma* ControllerInicializador::crearBaston()
{
	return crearArma("Baston", 10, 5);
}

Arma* ControllerInicializador::crearEspada()
{
	return crearArma("Espada", 8, 7);
}

Arma* ControllerInicializador::crearExcalibur()
{
	return crearArma("Excalibur", 12, 9);
}

Enemigo* ControllerInicializador::crearEnemigo(std::string nombre, Arma arma, int vida, list<Ataque*>listaAtaques, int ataqueBase)
{
	Enemigo* pEnemigo = new Enemigo(nombre, arma, vida, listaAtaques, ataqueBase);
	return pEnemigo;
}

Enemigo* ControllerInicializador::crearGuerrero()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueResistencia();
	return crearEnemigo("Guerrero", Arma("Espada", 10, 7), 5, {pAtaque1, pAtaque2}, 3);
}

Enemigo* ControllerInicializador::crearMago()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueCuracion();
	return crearEnemigo("Guerrero", Arma("Baston", 8, 10), 5, {pAtaque1, pAtaque2}, 3);
}

Pocion* ControllerInicializador::crearPocion(tipoEfecto tipo)
{
	Pocion* pPocion;
	switch(tipo)
	{
		case(tipoEfecto::ataque):
			pPocion = new PocionAtaque();
			break;
		case(tipoEfecto::curacion):
			pPocion = new PocionVida();
			break;
		case(tipoEfecto::dano):
			pPocion = new PocionDebilitadora();
			break;
		case(tipoEfecto::resistencia):
			pPocion = new PocionDefensa();
			break;
	}
	return pPocion;
}

Ataque* ControllerInicializador::crearAtaque(tipoAtaque tipo)
{
	Ataque* pAtaque;
	switch(tipo)
	{
		case(tipoAtaque::ataque):
			pAtaque = new AtaqueDebilitador();
			break;
		case(tipoAtaque::curacion):
			pAtaque = new AtaqueCuracion();
			break;
		case(tipoAtaque::dano):
			pAtaque = new AtaqueComun();
			break;
		case(tipoAtaque::resistencia):
			pAtaque = new AtaqueResistencia();
			break;
		case(tipoAtaque::turno):
			pAtaque = new AtaqueParalizador();
			break;
	}
	return pAtaque;
}
Mazmorra* ControllerInicializador::crearMazmorra(nivel nivelMazmorra)
{
	Mazmorra * pMazmorra = new Mazmorra(nivelMazmorra);
	return pMazmorra;
}

Heroe* ControllerInicializador::crearHeroe()
{
	Heroe * pHeroe = new Heroe();
	Ataque* pAtaque = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueDebilitador();
	pHeroe->agregarAtaque(pAtaque);
	pHeroe->agregarAtaque(pAtaque2);
return pHeroe;
}