#include "Circulo.h"

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
