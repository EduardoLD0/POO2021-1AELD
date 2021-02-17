#include <iostream>
#include <fstream>
using namespace std;
/*Escriba un programa pra guardar numeros telefonicos que muestre un menu con las siguientes opciones. Investigue como usar archivos de texto de tal manera que los contactos queden creados en un archivo de texto: 

1. Crear el directorio  con algunos contactos ( el archivo no existe y se crea (nombre,apellidos,telefono) 

2. Agregar más contactos. Se agregan al archivo ya creado. Es decir se agrega el nuevo contacto al archivo ya existente.  

3. Visualizar contactos 

*/
struct contacto{
   string nombre1;
   string nombre2;
   string apellido1;
   string apellido2;
   string telefono;
};

void mostrarContacto( contacto x ){
   std::cout << "Nombre: ";
   std::cout << x.nombre1 << " ";
   std::cout << x.nombre2 << " ";
   std::cout << x.apellido1 << " ";
   std::cout << x.apellido2 << " " << std::endl;
   std::cout << "Telefono: " << x.telefono << std::endl << std::endl;
}

void crearContacto( contacto *x ){
   std::cout << "Ingresa el primer nombre" << std::endl;
   std::cin >> x->nombre1;
   std::cout << "Ingresa el segundo nombre. Si no tiene escriba no" << std::endl;
   std::cin >> x->nombre2;
   if( x->nombre2 == "no" ){
      x->nombre2 = "";
   }
   std::cout << "Ingresa el primer apellido" << std::endl;
   std::cin >> x->apellido1;
   std::cout << "Ingresa el segundo apellido. Si no tiene escriba no" << std::endl;
   std::cin >> x->apellido2;
   if( x->apellido2 == "no" ){
      x->apellido2 = "";
   }
   std::cout << "Ingresa el numero de telefono" << std::endl;
   std::cin >> x->telefono;
}

int main(){
   contacto listaContactos[100];
   contacto temporal;
   int pos = 0, opcion = 5, i;
   ifstream infile;
   ofstream outfile;
   while( opcion != 0 ){
      std::cout << "Menu de contactos" << std::endl;
      std::cout << "1. Crear directorio (si no existe)" << std::endl;
      std::cout << "2. Agregar contactos" << std::endl;
      std::cout << "3. Ver contactos" << std::endl;
      std::cout << "4. Cargar contactos de un directorio existente" << std::endl;
      std::cout << "5. Guardar contactos" << std::endl;
      std::cout << "0. Salir" << std::endl;
      std::cout << "Opcion: " << std::endl;
      std::cin >> opcion;
      switch( opcion ){
         case 1:
         if( pos == 0 ){
            listaContactos[0] = { "Juan", "Pablo", "Rojas", "Morales", "3104201337" };
            listaContactos[1] = { "Maria", "Alejandra", "Torres", "Ruiz", "0312771234" };
            listaContactos[2] = { "Luigi", "Stuart", "Ferrari", "Turing", "5557777" };
            pos = 3;
            std::cout << "Directorio creado con exito" << std::endl << std::endl;
         }
         else{
            std::cout << "Error. Ya existe un directorio" << std::endl << std::endl;
         }
            break;
         case 2:
            crearContacto( &listaContactos[pos] );
            pos++;
            std::cout << pos << std::endl;
            break;
         case 3:
            std::cout << "Directorio" << std::endl << std::endl;
            for( i = 0; i < pos; i++ ){
               mostrarContacto( listaContactos[i] );
            }
            break;
         case 4:
            infile.open( "directorio.dat", ios::binary | ios::in );
            if( !infile ){
               std::cout << "Error. No se pudo abrir el archivo" << std::endl << std::endl;
            }
            else{
               infile.read( (char *)&listaContactos, 100 * sizeof( contacto ) );
               infile.read( (char *)&pos, sizeof( int ) );
               infile.close();
               std::cout << "Directorio cargado con exito" << std::endl << std::endl;
            }
            break;
         case 5:
            outfile.open( "directorio.dat", ios::binary | ios::out );
            if( !outfile ){
               std::cout << "Error. No se pudo abrir el archivo" << std::endl << std::endl;
            }
            else{
               outfile.write( (char *)&listaContactos, 100 * sizeof( contacto ) );
               outfile.write( (char *)&pos, sizeof( int ) );
               outfile.close();
               std::cout << "Directorio guardado con exito" << std::endl << std::endl;
            }
         case 0:
            break;
         default:
            std::cout << "Error. Opcion no disponible" << std::endl << std::endl;
      }
   }
   return 0;
}