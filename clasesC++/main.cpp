#include <iostream>

using namespace std;

class Rectangulo
{
private:
    // Pepito es una variable que estoy usando de ejemplo para demostrar que puedo tener
    // tantas variables como necesite como parte de las varibles de instancia
    float largo, ancho, pepito; // variables de instancia o atributos de instancia

public:
    Rectangulo(float, float); //Constructor
    Rectangulo(float, float, float);
    void calcularPerimetro();
    void calcularArea();
    float getLargo();     // Me permite ver el largo de un rectangulo
    void setLargo(float); // Me permite cambiar el valor del largo.
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

// Versión favorita :), usa el operador this para diferenciar las
// variables de instancia de las variables locales que tienen el mismo nombre
Rectangulo::Rectangulo(float largo, float ancho)
{
    // Inicializar las varibles de instancia.
    //Todo lo que tenga que inicializar
    this->largo = largo;
    this->ancho = ancho;
    cout << "Entre y me cree" << endl;
}

// Ejemplo de constructor con tres arametros. Busca ilustrar qe puedo tener varios contructores
// si cambio el número de parametros o el tipo de datos entre los parametros
Rectangulo::Rectangulo(float largo, float ancho, float pepito)
{
    // Inicializar las varibles de instancia.
    //Todo lo que tenga que inicializar
    this->largo = largo;
    this->ancho = ancho;
    this->pepito = pepito;
    cout << "Entre y me cree" << endl
              << "el valor de pepito es " << pepito;
}

// TO-DO pedir los datos al usuario.

void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

void Rectangulo::calcularPerimetro()
{
    float perimetro; // variable local
    perimetro = (2 * largo) + (2 * ancho);
    pepito++;
    cout << "El perimetro es: " << perimetro << endl;
}

void Rectangulo::calcularArea()
{
    float area;           // variable local
    area = largo * ancho; // son variables de instancia
    cout << "El area es: " << area << endl;
}

class Circulo{
   private:
      float radio;
      const float PI = 3.14159265;
   public:
      Circulo(float); // constructor
      void calcularArea(); // PI*r^2
      void calcularPerimetro(); // 2*PI*r
      float getRadio();
};

Circulo::Circulo( float radio ){
   this->radio = radio;
   cout << "Circulo de radio " << radio << " creado" << endl;
}

void Circulo::calcularArea(){
   float area = PI * radio * radio;
   cout << "El area es: " << area << endl;
}

void Circulo::calcularPerimetro(){
   float perimetro = 2 * PI * radio;
   cout << "El perimetro es: " << perimetro << endl;
}

float Circulo::getRadio(){
   return this->radio;
}

int main()
{
   /*//Instanciar --> crear objetos de una clase
   int valor;

   ///Mi primer objeto
   Rectangulo miRectangulo(2, 2); // sobrecarga....
   //calculo el area
   miRectangulo.calcularArea();

   // Cambio el largo a otro valor
   miRectangulo.setLargo(50);

   // Calculo el área
   miRectangulo.calcularArea();

   std::cout << "El largo es " << miRectangulo.getLargo();

   // std::cout << "Con el nuevo objeto, miren pues cambian los valores" <<std::endl;
   Rectangulo miRectanguloNuevo(1, 5);
   miRectanguloNuevo.calcularArea();
   //calcular el perimetro
   //miRectangulo.calcularPerimetro();

   // Mi segundo objeto
   Rectangulo miRectangulo1(3, 3, 3); */
    
   Circulo circuloChiquito( 3 );
   circuloChiquito.calcularArea();
   circuloChiquito.calcularPerimetro();
    
   Circulo circuloGrande( 12 );
   circuloGrande.calcularArea();
   circuloGrande.calcularPerimetro();
   
   return 0;
}