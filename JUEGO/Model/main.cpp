#include "../Controller/controllerCombate.h"
#include "../Controller/controllerInicializador.h"
#include "../Controller/controllerJuego.h"

using std::cout;
using std::endl;

int main()
{
	ControllerInicializador controllerInicializador(nivel::normal);
	Mazmorra* mazmorra = &controllerInicializador.getMazmorra();
	ControllerJuego controllerJuego(mazmorra);
	mazmorra->pintar();
}