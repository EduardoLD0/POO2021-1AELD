#include <iostream>
#include <math.h>

class Rectangulo
{
private:
    float largo, ancho;

public:
    Rectangulo();
    void setLargo(float);
    void setAncho(float);
    float getLargo();
    float getAncho();
    void calcularPerimetro();
    void calcularArea();
};

Rectangulo::Rectangulo()
{
    this->largo = 0;
    this->ancho = 0;
}

void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}

void Rectangulo::setAncho(float ancho)
{
    this->ancho = ancho;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

float Rectangulo::getAncho()
{
    return this->ancho;
}

void Rectangulo::calcularPerimetro()
{
    float perimetro;
    perimetro = (2 * largo) + (2 * ancho);
    std::cout << "El perimetro es: " << perimetro << std::endl;
}

void Rectangulo::calcularArea()
{
    float area;
    area = ((largo * ancho));
    std::cout << "El area es: " << area << std::endl;
}

class Circulo
{
private:
    float radio, pi;

public:
    Circulo();
    Circulo(float);
    float getRadio();
    void setRadio(float);
    void calcularArea();
    void calcularPerimetro();
};

Circulo::Circulo()
{
    radio = 0;
    pi = 3.14159265359;
}

Circulo::Circulo(float radio)
{
    this->radio = radio;
    this->pi = 3.14159265359;
}

float Circulo::getRadio()
{
    return this->radio;
}

void Circulo::setRadio(float radio)
{
    this->radio = radio;
}

void Circulo::calcularArea()
{
    float area, piPorRadio;
    piPorRadio = pi * radio;
    area = piPorRadio * piPorRadio; //Potencia 2
    std::cout << "El area es: " << area << std::endl;
}

void Circulo::calcularPerimetro()
{
    float perimetro;
    perimetro = 2 * pi * radio;
    std::cout << "El perimetro es: " << perimetro << std::endl;
}

class Triangulo
{
private:
    float base, altura;

public:
    Triangulo();
    void setBase(float);
    void setAltura(float);
    float getBase();
    float getAltura();
    void calcularArea();
    void calcularPerimetro();
};

Triangulo::Triangulo()
{
    this->altura = 0;
    this->base = 0;
}

void Triangulo::setBase(float base)
{
    this->base = base;
}

void Triangulo::setAltura(float altura)
{
    this->altura = altura;
}

float Triangulo::getBase()
{
    return this->base;
}

float Triangulo::getAltura()
{
    return this->altura;
}

void Triangulo::calcularArea()
{
    float area;
    area = (base * altura) / 2;
    std::cout << "El area del Triangulo es: " << area << std::endl;
}

void Triangulo::calcularPerimetro()
{
    float perimetro, temp;
    temp = base / 2;
    perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
    std::cout << "El perimetro del Triangulo es: " << perimetro << std::endl;
}

int menu()
{
    int opcion;
    std::cout << "Menu\n"
              << std::endl;
    std::cout << "1. Rectangulos" << std::endl;
    std::cout << "2. Mostrar Rectangulos" << std::endl;
    std::cout << "3. Circulos" << std::endl;
    std::cout << "4. Mostrar Circulos" << std::endl;
    std::cout << "5. Triangulos" << std::endl;
    std::cout << "6. Mostrar Triangulos" << std::endl;
    std::cout << "0. Salir\n"
              << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int main()
{
    const int SIZE = 10;
    Rectangulo listaRectangulo[SIZE];
    Circulo listaCirculo[SIZE];
    Triangulo listaTriangulo[SIZE];
    int cantidadCirculos = 0, cantidadRectangulos = 0, cantidadTriangulos = 0, cuantosCirculos, cuantosRectangulos, cuantosTriangulos, opcion, i;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 0:
            break;
        case 1: //Rectangulos
            float largo, ancho;
            std::cout << "\nCuantos Rectangulos deseas agregar?: ";
            std::cin >> cuantosRectangulos;
            if (cantidadRectangulos <= SIZE)
            {
                std::cout << "Digita el largo del rectangulo " << cantidadRectangulos + 1 << ": ";
                std::cin >> largo;
                std::cout << "Digita el ancho del rectangulo " << cantidadRectangulos + 1 << ": ";
                std::cin >> ancho;
                listaRectangulo[cantidadRectangulos].setAncho(ancho);
                listaRectangulo[cantidadRectangulos].setLargo(largo);
            }
            else
            {
                std::cout << "\nSe sobrepasa el limite\n"
                          << std::endl;
            }
            break;
        case 2: //Mostrar Rectangulos
            std::cout << "\n";
            for (i = 0; i < cantidadRectangulos; i++)
            {
                std::cout << "Rectangulo " << i + 1 << ":" << std::endl;
                std::cout << " El largo es: " << listaRectangulo[i].getLargo() << std::endl;
                std::cout << " El Ancho es: " << listaRectangulo[i].getAncho() << std::endl;
            }
            std::cout << "\n";
            break;
        case 3: //Circulos
            float radio;
            if (cantidadCirculos <= SIZE)
            {
                std::cout << "Digita el radio del circulo " << cantidadRectangulos + 1 << ": ";
                std::cin >> radio;
                listaCirculo[cantidadCirculos].setRadio(radio);
            }
            else
            {
                std::cout << "\nSe sobrepasa el limite\n"
                          << std::endl;
            }
            break;
        case 4: //Mostrar Circulos
            std::cout << "\n";
            for (i = 0; i < cantidadCirculos; i++)
            {
                std::cout << "Circulo " << i + 1 << ":" << std::endl;
                std::cout << " El Radio es: " << listaCirculo[i].getRadio() << std::endl;
            }
            std::cout << "\n";
            break;
        case 5: //Triangulos
            float altura, base;
            if (cantidadTriangulos <= SIZE)
            {
                std::cout << "Digita la base del triangulo " << cantidadTriangulos + 1 << ": ";
                std::cin >> altura;
                std::cout << "Digita la altura del triangulo" << cantidadTriangulos + 1 << ": ";
                std::cin >> base;
                listaTriangulo[cantidadTriangulos].setAltura(altura);
                listaTriangulo[cantidadTriangulos].setBase(base);
            }
            else
            {
                std::cout << "\nSe sobrepasa el limite\n"
                          << std::endl;
            }
            break;
        case 6: //Mostrar Triangulos
            std::cout << "\n";
            for (i = 0; i < cantidadTriangulos; i++)
            {
                std::cout << "Triangulo " << i + 1 << ":" << std::endl;
                std::cout << " La altura es: " << listaTriangulo[i].getAltura() << std::endl;
                std::cout << " La base es: " << listaTriangulo[i].getBase() << std::endl;
            }
            std::cout << "\n";
            break;
        default:
            std::cout << "\nNumero invalido\n"
                      << std::endl;
            break;
        }
    } while (opcion != 0);
    return 0;
}