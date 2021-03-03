#include <iostream>

using namespace std;

class Triangulo{
	private:
		float base, altura, ladoIzq, ladoDer;
	public:
		Triangulo();
		Triangulo(float, float, float, float);
		void calcularArea();
		void calcularPerimetro();
		float getBase();
		float getAltura();
		float getLadoIzq();
		float getLadoDer();
		void setBase(float);
		void setAltura(float);
		void setLadoIzq(float);
		void setLadoDer(float);
};