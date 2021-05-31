#include "view.h"

void View::pantallaPrincipal()
{
    int opcion = -1, dificultad;
    do
    {
        cout << "Bienvenido a Hertz el heroe" << endl;
        cout << "1. Jugar" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            cout << "Ingrese la dificultad" << endl;
            cout << "1. Principiante" << endl;
            cout << "2. Normal" << endl;
            cin >> dificultad;
            this->juego(dificultad);
            break;
        case 0:
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
        }
    } while(opcion != 0);
}

bool View::inventario()
{
    int opcion;
    bool salida = 0;
    Heroe* pHeroe = controllerJ->getHeroe();
    try
    {
        cout << "Que desea hacer?" << endl;
        cout << "1. Usar pocion" << endl;
        cout << "2. Seleccionar arma" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            if(!pHeroe->revisarItem(tipoItem::pocion))
            {
                throw domain_error("Usted no tiene pociones");
            }
            cout << "Escoja una pocion:" << endl;
            pHeroe->mostrarListaPociones();
            cin >> opcion;
            salida = pHeroe->usarPocion(opcion);
            controllerJ->actualizarItem();
            break;
        case 2:
        if(pHeroe->getArma()->getNombre() != "Sin arma")
        {
            throw domain_error("Usted ya tiene un arma equipada");
        }
        if(!pHeroe->revisarItem(tipoItem::arma))
        {
            throw domain_error("Usted no tiene armas");
        }
            cout << "Escoje un arma:" << endl;
            pHeroe->mostrarListaArmas();
            cin >> opcion;
            pHeroe->seleccionarArma(opcion);
            controllerJ->actualizarItem();
            break;
        }
    }
    catch(const domain_error& e)
    {
        cout << e.what() << '\n';
    }
    return salida;
}

void View::evento(int evento)
{   // Un evento ocurrira dependiendo de la casilla en donde esta el jugador
    int opcion, arrojarPocion = 0;
    Heroe * pHeroe = controllerJ->getHeroe();
    Enemigo * pEnemigo = new Enemigo();
    Pocion * pPocion = new PocionVida();
    Arma * pArma = new Arma();
    switch(evento)
    {
    case 1: // Se encuentra con un enemigo
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
                arrojarPocion = inventario();   // Abrir inventario
                break;
            case 2:
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
            }
        } while(opcion < 1 || opcion > 2);
        *pEnemigo = controllerJ->getEnemigo(controllerJ->getPosHeroe());
        if(arrojarPocion)   // Si eligio la pocion de daño le hara daño al enemigo antes de combatir
        {
            pEnemigo->setVida(pEnemigo->getVida() - 5);
        }
        controllerJ->setGameOver(controllerC->combatir(pHeroe, pEnemigo));  // Dependiendo del resultado del combate el juego sigue o termina
        controllerJ->setContadorCombate(controllerJ->getContadorCombate() + 1); // Aumenta en 1 el contador de combate
        if(controllerJ->getContadorCombate() % 3 == 0)
        {
            controllerJ->generarPocion();   // Cada 3 combates se genera una pocion
        }
        if(controllerJ->getContadorCombate() % 2 == 0)
        {
            controllerJ->generarArma();     // Cada 2 combates se genera un arma
        }
        break;
    case 2: // Se encuentra una pocion, ha decidido recogerla y tiene espacio
        pHeroe->recogerPocion(controllerJ->getPocion(controllerJ->getPosHeroe()));
        controllerJ->actualizarItem();  // Recoger una pocion gasta un turno
        break;
    case 3: // Se encontro un arma, ha decidido recogerla y tiene espacio
        pHeroe->recogerArma(controllerJ->getArma(controllerJ->getPosHeroe()));
        controllerJ->actualizarItem(); // Recoger un arma gasta un turno
        break;
    case 4: // Salio por la puerta abierta
        cout << "Felicidades, haz ganado el juego" << endl;
        controllerJ->setGameOver(1);    // Juego terminado
        break;
    }
}

void View::estado()
{   // Stats del jugador
    cout << "Hertz:" << endl;
    cout << "Vida: " << controllerJ->getHeroe()->getVida() << endl;
    cout << "Puntos de ataque: " << controllerJ->getHeroe()->getAtaqueBase() << endl;
    cout << "Arma: " << controllerJ->getHeroe()->getArma()->getNombre() << endl;
    cout << "Resistencia arma: " << controllerJ->getHeroe()->getArma()->getResistencia() << endl;
    cout << "Puntos de ataque arma: " << controllerJ->getHeroe()->getArma()->getPuntosAtaque() << endl;
}

void View::entrada(char letra)
{   // Letra escrita en consola
    int evento = 0;
    switch(letra)
    { // WASD = moverse, I = abrir inventario, E = ver estado del jugador
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
        break;
    case 'E':
        estado();
        break;
    }
    this->evento(evento);   // Un evento se ejecutara si el usuario se mueve
}

void View::juego(int dificultad)
{   // Se crea la mazmorra con el nivel de dificultad escogido
    switch(dificultad)
    {
    case 1:
        controllerJ = new ControllerJuego(nivel::principiante);
        break;
    case 2:
        controllerJ = new ControllerJuego(nivel::normal);
        break;
    }
    controllerC = new ControllerCombate(controllerJ);
    char letra;
    do
    {
        controllerJ->mostrarMazmorra();
        cin >> letra;
        entrada(letra);
    } while(controllerJ->getGameOver() == 0);
}