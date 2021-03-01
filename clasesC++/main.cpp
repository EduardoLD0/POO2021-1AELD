#include <iostream>

using namespace std;

const int CAP = 10;

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

Rectangulo::Rectangulo(){
	
}

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

void Rectangulo::setAncho( float ancho ){
   this->ancho = ancho;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

float Rectangulo::getAncho(){
   return this->ancho;
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
	 Circulo();
      void calcularArea(); // PI*r^2
      void calcularPerimetro(); // 2*PI*r
      float getRadio();
      void setRadio(float);
};

Circulo::Circulo(){
	
}

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

void Circulo::setRadio( float radio ){
   this->radio = radio;
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
    
   /*Circulo circuloChiquito( 3 );
   circuloChiquito.calcularArea();
   circuloChiquito.calcularPerimetro();
    
   Circulo circuloGrande( 12 );
   circuloGrande.calcularArea();
   circuloGrande.calcularPerimetro();*/
   int opcion = 1, posRectangulos = 0, posCirculos = 0, i;
   float radioTemp = 0, largoTemp = 0, anchoTemp = 0;
   Rectangulo arregloRectangulos[CAP];
   Circulo arregloCirculos[CAP];
   while( opcion != 0 ){
      cout << "Menu de creacion de figuras" << endl;
      cout << "1. Crear figura" << endl;
      cout << "2. Ver figuras" << endl;
      cout << "0. Salir" << endl;
      cin >> opcion;
      switch( opcion ){
         case 0:
            break;
         case 1:
            cout << "1. Crear rectangulo" << endl;
            cout << "2. Crear circulo" << endl;
            cin >> opcion;
            if( opcion == 1 && posRectangulos == 10 ){
               cout << "Error. El arreglo de rectangulos esta lleno." << endl;
            }
            else if( opcion == 1 ){
               cout << "Ingrese el ancho" << endl;
               cin >> anchoTemp;
               arregloRectangulos[posRectangulos].setAncho(anchoTemp);
               cout << "Ingrese el largo" << endl;
               cin >> largoTemp;
               arregloRectangulos[posRectangulos].setLargo(largoTemp);
               posRectangulos++;
            }
            else if( opcion == 2 && posCirculos == 10 ){
               cout << "Error. El arreglo de circulos esta lleno." << endl;
            }
            else if( opcion == 2 ){
               cout << "Ingrese el radio" << endl;
               cin >> radioTemp;
               arregloCirculos[posCirculos].setRadio(radioTemp);
               posCirculos++;
            }
            else{
               cout << "Error. Opcion no disponible." << endl;
            }
		  break;
         case 2:
            cout << "Lista de rectangulos: " << endl << endl;
            for( i = 0; i < posRectangulos; i++ ){
               cout << "Rectangulo #" << i << endl;
               cout << "Largo: " << arregloRectangulos[i].getLargo() << endl;
               cout << "Ancho: " << arregloRectangulos[i].getAncho() << endl << endl;
            }
            cout << "Lista de circulos: " << endl << endl;
            for( i = 0; i < posCirculos; i++ ){
               cout << "Circulo #" << i << endl;
               cout << "Radio: " << arregloCirculos[i].getRadio() << endl << endl;
            }
		  break;
	    default:
	       cout << "Error. Opcion no disponible" << endl;
      }
   }
   return 0;
}