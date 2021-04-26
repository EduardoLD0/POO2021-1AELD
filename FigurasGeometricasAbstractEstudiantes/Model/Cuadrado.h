//#ifndef CUADRADO_H
// Guardas
//#define CUADRADO_H

//CLASE CUADRADO

#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica
{
private:
    float lado;

public:
    Cuadrado();
    Cuadrado(float lado);
    virtual void calcularArea() override;
    virtual void calcularPerimetro() override;
    virtual void mostrarFigura();
};

//#endif /* !CUADRADO_H */