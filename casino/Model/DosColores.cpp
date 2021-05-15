//
// Created by lufe0 on 8/05/2021.
//

#include "DosColores.h"

float DosColores::jugar(float gonzosApostar) {
    float gonzosResultado;
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1+rand()%14;// numeros de 1 a 13
    numeroCasino = 1+rand()%14;// numeros de 1 a 13

    colorJugador = rand()%2; // Numero entre 0 y 1
    colorCasino = rand()%2; // Numero entre 0 y 1
    cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n" << "Tu color: " <<colorJugador << "\n";
    cout << "Numero casino: "<< numeroCasino <<"\n" << "Color casino: " <<colorCasino << "\n";
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float DosColores::calcularResultado(float gonzosApostar) {
    // Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado
    if(numeroJugador == numeroCasino && colorJugador == colorCasino)
    {
        return 4 * gonzosApostar;
    }
    // coincide sólo con el valor del dado ganará 0.5 veces lo apostado
    else if(numeroJugador == numeroCasino)
    {
        return 1.5 * gonzosApostar;
    }
    // no gana ni pierde
    else if(colorJugador == colorCasino)
    {
        return gonzosApostar;
    }
     // pierde todo lo apostado
    else
    {
        return 0;
    }
}

DosColores::~DosColores() {

}
