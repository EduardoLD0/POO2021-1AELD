#ifndef FIGURASCONTROLLER_H
#define FIGURASCONTROLLER_H

#include "../Model/FiguraGeometrica.h"
#include "../Model/Circulo.h"
#include "../Model/Triangulo.h"
#include "../Model/Rectangulo.h"
#include "../Model/Cuadrado.h"

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class FigurasController
{
private:
    //constante y estático para declararla constante para todos los objetos.
    const static int MAX_ITEMS;
    list<Rectangulo> listaRectangulo;
    list<Circulo> listaCirculo;
    list<Triangulo> listaTriangulo;
    list<Cuadrado> listaCuadrado;
    list<FiguraGeometrica *> pListaFiguras; // Debe ser de apuntadores pq las clases abstractas no se pueden instanciar

public:
    // Retorna referencia a la lista de rectangulos
    list<Rectangulo> &getListaRectangulo();
    // Retorna referencia a la lista de circulos
    list<Circulo> &getListaCirculo();
    // Retorna referencia a la lista de triangulos
    list<Triangulo> &getListaTriangulo();
    // Retorna referencia a la lista de cuadrados
    list<Cuadrado> &getListaCuadrado();
    void agregarRectangulo(float largo, float ancho);

    /**
       * Retorna la referencia al rectangulo que tenga el mayor ancho       
       *
    */
    Rectangulo &encontrarMayorAncho();

    // TO-DO

    void agregarTriangulo(float base, float altura);
    void agregarCirculo(float radio);
    void agregarCuadrado(float lado);

    list<FiguraGeometrica *> &getListaFiguras();
    void llenarListaTodosDummy();
};
//#define FIGURAS_CONTROLLER_H
#endif // FIGURASCONTROLLER_H