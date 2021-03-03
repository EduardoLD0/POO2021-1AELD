#include "Triangulo.h"

Triangulo::Triangulo(){
	
}

Triangulo::Triangulo(float base, float altura, float ladoIzq, float ladoDer){
	this->base = base;
	this->altura = altura;
	this->ladoIzq = ladoIzq;
	this->ladoDer = ladoDer;
}

void Triangulo::calcularArea(){
	float area = base * altura / 2;
	cout << "El area es: " << area << endl;
}

void Triangulo::calcularPerimetro(){
	float perimetro = base + ladoIzq + ladoDer;
	cout << "El perimetro es: " << perimetro << endl;
}

float Triangulo::getBase(){
	return this->base;
}

float Triangulo::getAltura(){
	return this->altura;
}

float Triangulo::getLadoIzq(){
	return this->ladoIzq;
}

float Triangulo::getLadoDer(){
	return this->ladoDer;
}

void Triangulo::setBase(float base){
	this->base = base;
}

void Triangulo::setAltura(float altura){
	this->altura = altura;
}

void Triangulo::setLadoIzq(float ladoIzq){
	this->ladoIzq = ladoIzq;
}

void Triangulo::setLadoDer(float ladoDer){
	this->ladoDer = ladoDer;
}
