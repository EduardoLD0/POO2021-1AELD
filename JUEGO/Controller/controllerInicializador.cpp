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
	return crearArma("Baston", 10, 3);
}

Arma* ControllerInicializador::crearEspada()
{
	return crearArma("Espada", 8, 4);
}

Arma* ControllerInicializador::crearExcalibur()
{
	return crearArma("Excalibur", 12, 9);
}

Enemigo* ControllerInicializador::crearEnemigo(std::string nombre, Arma arma, int vida, list<Ataque*>listaAtaques, int ataqueBase, tipoEnemigo tipo)
{
	Enemigo* pEnemigo = new Enemigo(nombre, arma, vida, listaAtaques, ataqueBase, tipo);
	return pEnemigo;
}

Enemigo* ControllerInicializador::crearGuerrero()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueResistencia();
	return crearEnemigo("Guerrero", Arma("Espada", 8, 4), 10, {pAtaque1, pAtaque2}, 3, tipoEnemigo::guerrero);
}

Enemigo* ControllerInicializador::crearMago()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueCuracion();
	return crearEnemigo("Mago", Arma("Baston", 10, 3), 8, {pAtaque1, pAtaque2}, 2, tipoEnemigo::mago);
}

Enemigo* ControllerInicializador::crearGuerreroBoss()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueParalizador();
	Ataque* pAtaque3 = new AtaqueResistencia();
	return crearEnemigo("Guerrero Boss", Arma("Espada Legendaria", 20, 10), 20, {pAtaque1, pAtaque2, pAtaque3}, 5, tipoEnemigo::guerreroBoss);
}

Enemigo* ControllerInicializador::crearMagoBoss()
{
	Ataque* pAtaque1 = new AtaqueComun();
	Ataque* pAtaque2 = new AtaqueCuracion();
	Ataque* pAtaque3 = new AtaqueParalizador();
	return crearEnemigo("Mago Boss", Arma("Baston de Gandalf", 25, 11), 18, {pAtaque1, pAtaque2, pAtaque3}, 2, tipoEnemigo::magoBoss);
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