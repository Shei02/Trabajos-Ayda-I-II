#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"
#include "BibliotecaUnicen.h"
#include "ServiciosBiblioteca.h"

using namespace std;

/*----------------------------------------Servicio 1-----------------------------------*/
/*bool usaComodin(string tituloIngresado)
//retorna si usa comodin o no
{
    bool usa = true;
    unsigned int i =0;
    while((i < tituloIngresado.size()) && (tituloIngresado[i] != '*' && tituloIngresado[i] != '?'))
    {
        i= i +1;
    }
    if (i == tituloIngresado.size())
        usa = false;
    return usa;
}*/

bool buscarTitulo(Lista<BibliotecaUnicen>& Libreria, string tituloIngresado)
// Si no usa comodin, entra aca y retorna si existe o no el libro buscado
{
    bool existe = false;
    int i = 1;
    while ((i <= Libreria.lenght()) && (existe == false))
    {
        if (Libreria.devolverpos(i).consultartitulodelibro() == tituloIngresado){
            existe = true;
        }
        else{
            i++;
        }
    }
    if (existe == true)
    {
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "El titulo " << tituloIngresado << ". Existe en la biblioteca" << " y se encuentra en la posicion: " << i << endl;
        return true;
    }
    else
        {
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "El titulo ingresado no esta disponible en la biblioteca" << endl;
        return false;
    }
}

/*-------------------------------------Servicio 2------------------------------------*/
Lista<BibliotecaUnicen> Devolver_Lista_Rango(Lista<BibliotecaUnicen> & libreria,int Anio1, int Anio2)
{
    int contador = 1;
    Lista<BibliotecaUnicen> ListadoLibros;
    libreria.volveralprincipio();
    BibliotecaUnicen libro;
    while (contador <= libreria.lenght()){
        libro = libreria.devolverpos(contador);
        if ((libro.consultaranio() >= Anio1) && (libro.consultaranio() <= Anio2)){ //si el libro cuenta con un año en el rango indicado, se agrega al listado pedido
            ListadoLibros.agregarlista(libro);
        }
        contador++;//se incrementa en 1 la posicion para seguir con la busqueda secuencial sobre el arreglo
    }
    return ListadoLibros;
}

void esmenor(int & Anio_1, int & Anio_2) // esta funcion obliga al usuario a poner el segundo año ingresado mas grande que el primer año
{
    while(Anio_1 > Anio_2) {
        cout << " Debe ingresar un año mayor al año1 " << Anio_1 << endl;
        cin>> Anio_2;
    }
}

/*----------------------------------Servicio 3----------------------------------------*/
Lista<BibliotecaUnicen> Devolver_Lista_Genero(Lista<BibliotecaUnicen> libreria, string generoBuscado)
{
    int contador = 1;
    bool pertenece = false;
    Lista<BibliotecaUnicen> lstGenero;
    libreria.volveralprincipio();
    BibliotecaUnicen libro;
    while (contador <= libreria.lenght()) {
        libro = libreria.devolverpos(contador);
        if (libro.consultarGenero().pertenece(generoBuscado)){
            lstGenero.agregarlista(libro);
        }
        contador++;
    }
    return lstGenero;
}

Lista<BibliotecaUnicen> agregarOrdenado(Lista<BibliotecaUnicen> & lstGenero)
{
    int longitud=1;
    int contador;
    Lista<BibliotecaUnicen> lstVendidos;
    lstGenero.volveralprincipio();
    while(longitud <= lstGenero.lenght()){
        lstVendidos.volveralprincipio();
        if (lstVendidos.vacia()){
            lstVendidos.agregarlista(lstGenero.devolverpos(1));
        }
        else{
            contador = 1;
            while((contador <= lstVendidos.lenght()) && (lstVendidos.devolverpos(contador).consultarcantejemplaresvendidos() > lstGenero.devolverelem().consultarcantejemplaresvendidos())){
                lstVendidos.avanzarsig();
                contador++;
            }
            if (contador > lstVendidos.lenght()){
                lstVendidos.agregarlista(lstGenero.devolverelem());
            }
            else{
                lstVendidos.insertar(lstGenero.devolverelem(),contador);
            }
        }
        lstGenero.avanzarsig();
        longitud++;
    }
    return lstVendidos;
}

/*----------------------------------------------Menu--------------------------------------------------*/
void menu(Lista<BibliotecaUnicen> & Libreria)
{
    int opcion = 1;
    while (opcion != 0) {
        cout << endl;
        cout << "Bienvenido a al menú de la Biblioteca" << endl;
        cout << "Servicio 1: Busque un libro por su titulo" << endl;
        cout << "Servicio 2: Listado de libros entre el rango de años que desee" << endl;
        cout << "Servicio 3: Primeras 10 ventas de un genero de su interes" << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Por favor ingrese el numero de servicio que desea ejecutar, o en caso de querer salir ingrese 0: ";
        cin >> opcion;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        if (opcion < 0 || opcion > 3) {
            cout << "-------------------------------------------------" << endl;
            cout << "Ingreso un numero valido, por favor" << endl;
            cout << "-------------------------------------------------" << endl;
        }
        switch (opcion)
        {
           case 1:
            {
                string tituloIngresado;
                bool resultado;
                cout << "-------------------------------------------------" << endl;
                cout<< "Ingrese el titulo del libro que desea buscar: " << endl;
                cin.ignore();
                getline(cin, tituloIngresado);
                cout << "-------------------------------------------------" << endl;
                resultado = buscarTitulo(Libreria,tituloIngresado);
                break;
            }
            case 2:
            {
                cout << "-------------------------------------------------" << endl;
                cout << "Año 1: " << endl;
                int Anio_1,Anio_2; //se pasa como mínimo el 1 debido a que no tiene sentido que un libro sea del año 0
                cin>> Anio_1;
                cout << "Año 2: " << endl;
                cin>> Anio_2;
                //esmenor(Anio_1,Anio_2);
                cout << "-------------------------------------------------" << endl;
                cout << endl;
                Lista<BibliotecaUnicen> ListadoLibros = Devolver_Lista_Rango(Libreria, Anio_1, Anio_2);
                cout << "-------------------------------------------------" << endl;
                if (ListadoLibros.vacia())
                    cout << "No hay ningun libro perteneciente al rango " << Anio_1 << "-" << Anio_2 << endl;
                else {
                    cout << "El listado de libros perteneciente al rango " << Anio_1 << "-" << Anio_2 << " es el siguiente:" << endl;
                    cout << " " << endl;
                    ListadoLibros.volveralprincipio();
                    int longitud = 1;
                    while (longitud <= ListadoLibros.lenght()){
                        ListadoLibros.devolverpos(longitud).mostrarDatos();
                        longitud++;
                    }
                }
                cout << "-------------------------------------------------" << endl;
                break;
            }
            case 3:
            {
                string generoBuscado;
                cout << "-------------------------------------------------" << endl;
                cout<< "Ingrese el genero del libro que desea buscar: " << endl;
                cin.ignore();
                getline(cin, generoBuscado);
                cout << "-------------------------------------------------" << endl;
                if (Libreria.vacia())
                    cout << "No hay ningun libro con el genero registrado " << endl;
                else {
                    cout << "El listado de 10 ventas de libros con dicho genero: " << generoBuscado << endl;
                    cout << " " << endl;
                    Libreria.volveralprincipio();
                    Lista<BibliotecaUnicen> lstgenero = Devolver_Lista_Genero(Libreria,generoBuscado);
                    cout<<lstgenero.lenght()<<endl;
                    Lista<BibliotecaUnicen> vendidos = agregarOrdenado(lstgenero);
                    int j = 1;
                    while (j <= vendidos.lenght()){
                        vendidos.devolverpos(j).mostrarDatos();
                        j++;
                    }
                break;
                }
            }
        }
    }
}
