#include "Rectangulo.h"

//CONSTRUCTORES RECTANGULO

Rectangulo::Rectangulo() {}

Rectangulo::Rectangulo(float ancho, float largo)
{

    this->ancho = ancho;
    this->largo = largo;
}

//METODOS RECTANGULO

void Rectangulo::calcularArea()
{
    float area;
    area = largo * ancho;
    cout << "El area del rectangulo es: " << area << endl;
}

void Rectangulo::calcularPerimetro()
{
    float perimetro;
    perimetro = (2 * largo) + (2 * ancho);
    cout << "El perimetro del rectangulo es : " << perimetro << endl;
}

void Rectangulo::mostrarFigura() const
{
    cout << "El ancho: " << ancho << " -- "
         << "el largo: " << largo << endl;
}

float Rectangulo::getAncho()
{
    return this->ancho;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

void Rectangulo::setAncho(float ancho)
{
    this->ancho = ancho;
}
void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}
