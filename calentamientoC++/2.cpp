#include <iostream>
/*Realice un programa que lea los siguientes datos de una persona: Edad: dato de tipo entero. Sexo: dato de tipo caracter.  Altura en metros: dato de tipo flotante. Muestre los datos leidos.  Desarrolle su programa usando funciones.  */
void mostrarDatos( int edad, char sexo[1], float altura ){
   std::cout << "Su edad es: " << edad << std::endl;
   std::cout << "Su sexo es: " << sexo << std::endl;
   std::cout << "Su altura es: " << altura << std::endl;
}

int main(){
   int edad;
   char sexo[1];
   float altura;
   std::cout << "Ingrese su edad" << std::endl;
   std::cin >> edad;
   std::cout << "Ingrese su sexo" << std::endl;
   std::cin >> sexo;
   std::cout << "Ingrese su altura en metros" << std::endl;
   std::cin >> altura;
   mostrarDatos( edad, sexo, altura );
   return 0;
}