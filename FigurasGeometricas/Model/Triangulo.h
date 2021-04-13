//#ifndef TRINANGULO_H
// Guardas
//#define TRIANGULO_H

//CLASE TRIANGULO

#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class Triangulo
{
private:
    float base, altura;

public:
    Triangulo();
    Triangulo(float base, float altura);
    void mostrarFigura() const;
    void calcularArea();
    void calcularPerimetro();
};

//#endif /* !TRIANGULO_H */