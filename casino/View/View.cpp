//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}

void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}

void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opcion, resultado;
    float cantGonzos;
    int idJuego;
        try {
            do {
                cout << "Cuantos gonzos desea apostar \n";
                cin >> cantGonzos;
            } while (cantGonzos <= 0);

            // Agregue el esto de la logica para el juego 1. Juego mayor a 13, 2 juego de dos colores.
            cout << "Elija el juego: " << endl;
            cout << "1. Mayor a 13." << endl;
            cout << "2. Dos colores." << endl;
            cout << "3. Slots." << endl;
            cout << "Opcion: ";
            cin >> opcion;
        } catch (std::domain_error ex){
            cout << ex.what();
        }
    resultado = controller.jugar(opcion, idJugador, cantGonzos);
    if(resultado)
    {
        cout << "Haz ganado!" << endl;
    }
    else
    {
        cout << "Haz perdido :C" << std::endl;
    }
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador - pendiente " << std::endl;
    cout << "4. Vender gonzos - pendiente " << std::endl;
    cout << "5. Retirar jugador " << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 1: agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                recargarGonzos();
                break;
            case 5:
                retirarJugador();
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);
    } catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::retirarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);
        controller.retirarJugador(idJugador);
        cout << "Jugador retirado con exito." << std::endl;
    } catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::recargarGonzos()
{
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        controller.recargarGonzos(idJugador);
        cout << "Recarga realizada con exito." << std::endl;
    } catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}