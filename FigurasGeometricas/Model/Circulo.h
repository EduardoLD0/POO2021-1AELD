//#ifndef CIRCULO_H
// Guardas
//#define CIRCULO_H

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

//CLASE CIRCULO

class Circulo
{
private: //atributos
    float radio;
    const static float PI;

public:
    Circulo(); //NO OLVIDAR
    Circulo(float);
    void mostrarFigura() const;
    void calcularArea();
    void calcularPerimetro();
    float getRadio();
    void setRadio(float);
};

//#endif /* !CIRCULO_H */