#ifndef VIEW_H
#define VIEW_H

#include "controllerJuego.h"
#include "controllerInicializador.h"
#include "controllerCombate.h"

class View
{
    private:
        ControllerInicializador* controllerI;
        ControllerJuego* controllerJ;
        ControllerCombate* controllerC;
    public:
        void pantallaPrincipal();
        void inventario();
        void juego();
        void entrada(char);
        void evento(int);
};

#endif