#include "View.h"

//FUNCIONES DEL PROGRAMA
void View::pedirDatosRectangulo()
{
    // Se piden los datos y se valida para asegurar que estan bn
    float largo, ancho;
    do
    {
        cout << "Digite el valor del largo " << endl;
        cin >> largo;
        cout << "Digite el valor del ancho " << endl;
        cin >> ancho;
    } while (largo <= 0 || ancho <= 0);

    // Se llama al metodo del controller
    controller.agregarRectangulo(largo, ancho);
}

void View::pedirDatosCirculo()
{
    // Se piden los datos y se valida para asegurar que estan bn
    float radio;
    do
    {
        cout << "Digite el valor del radio " << endl;
        cin >> radio;
    } while (radio <= 0);

    // Se llama al metodo del controller
    controller.agregarCirculo(radio);
}

void View::pedirDatosTriangulo()
{
    // Se piden los datos y se valida para asegurar que estan bn
    float base, altura;
    do
    {
        cout << "Digite el valor de la base " << endl;
        cin >> base;
        cout << "Digite el valor de la altura " << endl;
        cin >> altura;
    } while (base <= 0 || altura <= 0);

    // Se llama al metodo del controller
    controller.agregarTriangulo(base, altura);
}

void View::mostrarRectangulos()
{
    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;
    int cont = 0;
    list<Rectangulo> &refListaRectangulo = controller.getListaRectangulo();
    for (list<Rectangulo>::iterator it = refListaRectangulo.begin(); it != refListaRectangulo.end(); ++it)
    {
        std::cout << "Rectangulo " << ++cont << ":" << std::endl;
        it->mostrarFigura();
    }
}

void View::mostrarTriangulos()
{
    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;
    int cont = 0;
    list<Triangulo> &refListaTriangulo = controller.getListaTriangulo();
    for (list<Triangulo>::iterator it = refListaTriangulo.begin(); it != refListaTriangulo.end(); ++it)
    {
        std::cout << "Triangulo " << ++cont << ":" << std::endl;
        it->mostrarFigura();
    }
}

void View::mostrarCirculos()
{
    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;
    int cont = 0;
    list<Circulo> &refListaCirculo = controller.getListaCirculo();
    for (list<Circulo>::iterator it = refListaCirculo.begin(); it != refListaCirculo.end(); ++it)
    {
        std::cout << "Circulo " << ++cont << ":" << std::endl;
        it->mostrarFigura();
    }
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n"
         << std::endl;
    cout << "1. Agregar Rectangulos" << std::endl;
    cout << "2. Mostrar Rectangulos" << std::endl;
    cout << "3. [Rectangulo] Calcular area y perimetro" << std::endl;
    cout << "4. Agregar Circulos" << std::endl;
    cout << "5. Mostrar Circulos" << std::endl;
    cout << "6. [Circulo] Calcular area y perimetro" << std::endl;
    cout << "7. Agregar Triangulos" << std::endl;
    cout << "8. Mostrar Triangulos" << std::endl;
    cout << "9. [Triangulo] Calcular area y perimetro" << std::endl;
    cout << "10. Caso para pruebas" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
        case 1: //Rectangulos
            pedirDatosRectangulo();
            break;
        case 2: //Mostrar Rectangulos
            mostrarRectangulos();
            break;
	   case 3: // Calcular area y perimetro
	       break; // Pendiente
        case 4: // Circulos
	       pedirDatosCirculo();
            break;
	   case 5: // Mostrar circulos
	       mostrarCirculos();
		  break;
	   case 6: // Calcular area y perimetro
	       break; // Pendiente
	   case 7: // Triangulos
	       pedirDatosTriangulo();
            break;
	   case 8: // Mostrar Triangulos
	       mostrarTriangulos();
		  break;
	   case 9: // Calcular area y perimetro
	       break; // Pendiente
        case 10:
        {
            Rectangulo &rectangulo = controller.encontrarMayorAncho();
            rectangulo.mostrarFigura();
        }
        break;
        }
    } while (opcion != 0);
}