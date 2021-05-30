#include "view.h"

void View::pantallaPrincipal()
{
    int opcion = -1;
    do
    {
        cout << "Bienvenido a Hertz el heroe" << endl;
        cout << "1. Jugar" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            juego();
            break;
        case 0:
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
        }
    } while(opcion != 0);
}

void View::inventario()
{
    int opcion;
    Heroe* pHeroe = controllerJ->getHeroe();
    cout << "Que desea hacer?" << endl;
    cout << "1. Usar pocion" << endl;
    cout << "2. Seleccionar arma" << endl;
    cin >> opcion;
    switch(opcion)
    {
    case 1:
        cout << "Escoja una pocion:" << endl;
        pHeroe->mostrarListaPociones();
        cin >> opcion;
        pHeroe->usarPocion(opcion);
        break;
    case 2:
        cout << "Escoje un arma:" << endl;
        pHeroe->mostrarListaArmas();
        cin >> opcion;
        pHeroe->seleccionarArma(opcion);
        break;
    }
}

void View::evento(int evento)
{
    int opcion;
    Heroe * pHeroe = controllerJ->getHeroe();
    Enemigo * pEnemigo;
    switch(evento)
    {
    case 1:
        do{
            cout << "Una batalla esta por empezar." << endl;
            cout << "Desea equipar un arma / usar una pocion?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cin >> opcion;
            switch(opcion)
            {
            case 0:
                break;
            case 1:
                inventario();
                break;
            case 2:
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
            }
        } while(opcion < 1 || opcion > 2);
        pEnemigo = controllerJ->getEnemigo(controllerJ->getPosHeroe());
        controllerC->combatir(pHeroe, pEnemigo);
        break;
    case 2:
        pHeroe->recogerPocion(controllerJ->getPocion(controllerJ->getPosHeroe()));
        break;
    case 3:
        pHeroe->recogerPocion(controllerJ->getPocion(controllerJ->getPosHeroe()));
        break;
    case 4:
        cout << "Felicidades, haz ganado el juego" << endl;
        break;
    }
}

void View::entrada(char letra)
{
    int evento;
    switch(letra)
    {
    case 'W':
        evento = controllerJ->moverPersonaje(direccion::arriba);
        break;
    case 'A':
        evento = controllerJ->moverPersonaje(direccion::izquierda);
        break;
    case 'S':
        evento = controllerJ->moverPersonaje(direccion::abajo);
        break;
    case 'D':
        evento = controllerJ->moverPersonaje(direccion::derecha);
        break;
    case 'I':
        inventario();
        evento = 0;
        break;
    }
    this->evento(evento);
}