#include <iostream>

using namespace std;

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
