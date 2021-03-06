#ifndef VIEW_H
#define VIEW_H

#include "../Controller/controllerJuego.h"
#include "../Controller/controllerInicializador.h"
#include "../Controller/controllerCombate.h"

class View
{
    private:
        ControllerJuego* controllerJ;
        ControllerCombate* controllerC;
    public:
        void pantallaPrincipal();
        bool inventario();
        void juego(int);
        void entrada(char);
        void evento(int);
        void estado();
};

#endif