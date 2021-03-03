#include <iostream>

using namespace std;

class Rectangulo
{
private:
    // Pepito es una variable que estoy usando de ejemplo para demostrar que puedo tener
    // tantas variables como necesite como parte de las varibles de instancia
    float largo, ancho, pepito; // variables de instancia o atributos de instancia

public:
    Rectangulo();
    Rectangulo(float, float); //Constructor
    Rectangulo(float, float, float);
    void calcularPerimetro();
    void calcularArea();
    float getLargo();     // Me permite ver el largo de un rectangulo
    void setLargo(float); // Me permite cambiar el valor del largo.
    float getAncho();
    void setAncho(float);
};

/*
// Asi se usa cuando cambio el nombre e las variables en los parámetros
Rectangulo::Rectangulo(float largo1, float ancho1)
{
    // Inicializar las varibles de instancia.
    //Todo lo que tenga que inicializar
    largo = largo1;
    ancho = ancho1;
    std::cout << "Entre y me cree" << std::endl;
}*/
