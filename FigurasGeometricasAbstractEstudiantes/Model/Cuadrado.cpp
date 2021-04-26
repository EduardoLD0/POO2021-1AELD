#include "cuadrado.h"

//CONSTRUCTORES CUADRADO

Cuadrado::Cuadrado() {}

Cuadrado::Cuadrado(float lado)
{

    this->lado = lado;
}

//METODOS CUADRADO

void Cuadrado::calcularArea()
{
    this->area = this->lado * this->lado;
}

void Cuadrado::calcularPerimetro()
{
    this->perimetro = 4 * this->lado;
}

void Cuadrado::mostrarFigura()
{
    cout << "El lado: " << lado << endl;
    if (this->area == 0)
    {
        this->calcularArea();
    }
    if (this->perimetro == 0)
    {
        this->calcularPerimetro();
    }

    cout << "El area del cuadrado es: " << this->area << endl;
    cout << "El perimetro del cuadrado es: " << this->perimetro << endl;
    // LLamo al mostrarFigura delegado
    FiguraGeometrica::mostrarFigura();
}