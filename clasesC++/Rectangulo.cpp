#include "Rectangulo.h"

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
}

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
	float area;		   // variable local
	area = largo * ancho; // son variables de instancia
	cout << "El area es: " << area << endl;
}
