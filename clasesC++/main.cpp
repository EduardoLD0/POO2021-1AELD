#include<iostream>
#include"Rectangulo.h"
#include"Circulo.h"
#include"Triangulo.h"

const int  CAP  =  10;

int  main(){
	//Instanciar-->crearobjetosdeunaclase
	int opcion = 1, posRectangulos = 0, posCirculos = 0, posTriangulos = 0, i;
	float radioTemp = 0, largoTemp = 0, anchoTemp = 0, baseTemp, alturaTemp, 
	ladoIzqTemp, ladoDerTemp;
	Rectangulo arregloRectangulos[CAP];
	Circulo arregloCirculos[CAP];
	Triangulo arregloTriangulos[CAP];
	while(opcion != 0){
		cout << "Menu de creacion de figuras." << endl;
		cout << "1. Crear figura." << endl;
		cout << "2. Ver figuras." << endl;
		cout << "0. Salir." << endl;
		cin >> opcion;
		switch(opcion){
			case0:
				break;
			case1:
				cout << "1. Crear rectangulo" << endl;
				cout << "2. Crear circulo" << endl;
				cout << "3. Crear triangulo" << endl;
				cin >> opcion;
				if(opcion == 1 && posRectangulos == 10){
					cout << "Error.El arreglo de rectangulos esta lleno." << endl;
				}
				else if(opcion == 1){
					cout << "Ingrese el ancho:" << endl;
					cin >> anchoTemp;
					arregloRectangulos[posRectangulos].setAncho(anchoTemp);
					cout << "Ingrese el largo:" << endl;
					cin >> largoTemp;
					arregloRectangulos[posRectangulos].setLargo(largoTemp);
					posRectangulos++;
				}
				else if(opcion == 2 && posCirculos == 10){
					cout << "Error. El arreglo de circulos esta lleno." << endl;
				}
				else if(opcion == 2){
					cout << "Ingrese el radio:" << endl;
					cin >> radioTemp;
					arregloCirculos[posCirculos].setRadio(radioTemp);
					posCirculos++;
				}
				else if(opcion == 3 && posTriangulos == 10){
					cout << "Error. El arreglo de triangulos esta lleno." << endl;
				}
				else if(opcion == 3){
					cout << "Ingrese la base:" << endl;
					cin >> baseTemp;
					arregloTriangulos[posTriangulos].setBase(baseTemp);
					cout << "Ingrese la altura:" << endl;
					cin >> alturaTemp;
					arregloTriangulos[posTriangulos].setAltura(alturaTemp);
					cout << "Ingrese el lado izquierdo:" << endl;
					cin >> ladoIzqTemp;
					arregloTriangulos[posTriangulos].setLadoIzq(ladoIzqTemp);
					cout << "Ingrese el lado derecho:" << endl;
					cin >> ladoDerTemp;
					arregloTriangulos[posTriangulos].setLadoDer(ladoDerTemp);
					posTriangulos++;
				}
				else{
					cout << "Error. Opcion no disponible." << endl;
				}
				break;
			case2:
				cout << "Lista de rectangulos:" << endl << endl;
				for(i = 0; i < posRectangulos; i++){
					cout << "Rectangulo #" << i << endl;
					cout << "Largo: " << arregloRectangulos[i].getLargo() << endl;
					cout << "Ancho: " << arregloRectangulos[i].getAncho() << endl;
					arregloRectangulos[i].calcularPerimetro();
					arregloRectangulos[i].calcularArea();
					cout << endl;
				}
				cout << "Lista de circulos:" << endl << endl;
				for(i = 0; i < posCirculos; i++){
					cout << "Circulo #" << i << endl;
					cout << "Radio: " << arregloCirculos[i].getRadio() << endl;
					arregloCirculos[i].calcularPerimetro();
					arregloCirculos[i].calcularArea();
					cout << endl;
				}
				cout << "Lista de triangulos:" << endl << endl;
				for(i = 0; i < posTriangulos; i++){
					cout << "Triangulo #" << i << endl;
					cout << "Base: " << arregloTriangulos[i].getBase() << endl;
					cout << "Altura: " << arregloTriangulos[i].getAltura() << endl;
					cout << "Lado Izquierdo: " << arregloTriangulos[i].getLadoIzq() << endl;
					cout << "Lado Derecho: " << arregloTriangulos[i].getLadoDer() << endl;
					arregloTriangulos[i].calcularPerimetro();
					arregloTriangulos[i].calcularArea();
					cout << endl;
				}
				break;
			default:
				cout << "Error. Opcion no disponible." << endl;
		}
	}
	return 0;
}