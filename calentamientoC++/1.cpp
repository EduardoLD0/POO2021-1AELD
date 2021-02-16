#include <iostream>

const float IVA = 0.19;

void calcularIVA( float precio ){
   std::cout << "El precio con iva es: " << precio * IVA + precio << std::endl;
}

int main(){
   float precio;
   std::cout << "Ingrese el precio a calcular con el iva" << std::endl;
   std::cin >> precio;
   calcularIVA( precio );
   return 0;
}