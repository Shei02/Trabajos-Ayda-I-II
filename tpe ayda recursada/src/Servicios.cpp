#include <iostream>
#include <fstream>
#include <string>
#include "Servicios.h"
#include "Lista.h"

//Servicios.cpp tiene todas las funciones y sus correspondientes desarrollos para poder cumplir con los 3 servicios planteados en el ejercicio

using namespace std;

Plataforma * procesar_archivo_entrada(string origen,unsigned int & tamanio_arreglo)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_canciones = atoi(linea.c_str());
        tamanio_arreglo = cantidad_canciones;
        Plataforma * arreglo = new Plataforma[cantidad_canciones];
        int posicion = 0;
        cout << "Se cargaron " << cantidad_canciones << " canciones." << endl;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posicion del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            unsigned int nroCancion = 1;

            //Informacion entre pos_inicial y pos_final
            string interprete = linea.substr(pos_inicial, pos_final);

            //Segunda posicion del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nombreCancion = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posicion del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            unsigned int duracion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Cuarta posicion del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string anio = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posicion del separador ;
            //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);
            //Desde esta posicion hasta el final se encuentra un n�mero variable de g�neros de cada canci�n.
            //no tomo en cuenta los corchetes
            string generos = lst_generos.substr(1, lst_generos.size()-2);
            // el siguiente c�digo de prueba separa los diferentes g�neros en un arreglo de 10 posiciones
            Lista<string> listaGeneros;
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                string nuevoGenero = generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos);
                listaGeneros.lista_agregar(nuevoGenero);
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }

            //Sexta posicion del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            unsigned int reproducciones = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            Plataforma cancion(nroCancion,interprete,nombreCancion,duracion,anio,listaGeneros,reproducciones);
            //se crea un objeto de la clase Plataforma en memoria, que contendrá la información de una cancion en particular
            arreglo[posicion] = cancion;

            posicion++;
            nroCancion++;
        }
        return arreglo;
    }
    return NULL;
}

/* ---------------------- COMIENZO SERVICIO N°1 ----------------------------------- */
void buscarCancion(Plataforma arreglo[], unsigned int tamanio_arreglo, string tituloIngresado)
// Si no usa comodin, entra aca y retorna si existe o no la cancion buscada
{
    bool existe = false;
    unsigned int i = 0;
    while ((i < tamanio_arreglo) && (existe == false))
    {
        if (arreglo[i].consultarNombreCancion() == tituloIngresado)
            existe = true;
        i= i + 1;
    }
    if (existe == true)
    {
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "El titulo " << tituloIngresado << ". Existe en el registro" << " y se encuentra en la posicion " << i << endl;
    }
    else {
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "El titulo ingresado no existe en el registro" << endl;
    }
}

bool usaComodin(string tituloIngresado)
// retorna si usa comodin o no
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
}

bool comparaCanciones(Plataforma arreglo[], string tituloIngresado,unsigned int pos) // dada dos canciones las compara
// compara una cancion del arreglo con el titulo ingresado y retorna si es una posible cancion
{
    unsigned int k = 0; // indice buscado
    unsigned int indice = 0; // indice de las canciones
    bool posible = true;
    string tituloAcomparar = arreglo[pos].consultarNombreCancion(); // VER -> SI ME TOMA LA PALABRA COMPLETA O SOLO LA PRIMERA
    while  ((indice < tituloAcomparar.size()) && (k < tituloIngresado.size()) && (posible == true)) // mientras que esten en rango ambos titulos
    {
        if ((tituloIngresado[k] == tituloAcomparar[indice]) || ((tituloIngresado[k] == '?') && (tituloAcomparar[indice] != ' '))) { // compara hasta que no haya igualdad
            k= k + 1;
            indice = indice + 1;
        }
        else {
            if (((tituloIngresado[k] != '*') && (tituloIngresado[k] != ' ')) && (tituloAcomparar[indice] != ' ')) { // |er caso, no coincidan
                posible = false;
            }
            if ((tituloIngresado[k] == '*') && (tituloAcomparar[indice] != ' ') && (posible == true)) { // 2do caso, hay una palabra de incognita
                while ((tituloAcomparar[indice] != ' ') && ( indice < tituloAcomparar.size())) {
                    indice = indice + 1;
                }

                k= k+1; // le sumo  1 porque me di cuenta que si se pone un * te cuenta como dos posiciones
                if ((k == tituloIngresado.size()) && (indice < tituloAcomparar.size())) {
                    posible= false;
                }
                else {
                    posible= true;
                }
            }
        }
    }
    return posible;
}

void posiblesCanciones(Plataforma arreglo[],unsigned int tamanio_arreglo, string tituloIngresado, Lista<Plataforma> & listaCanciones) // recorre todo el arreglo y llama un void q compara, si son iguales lo guarda para imprimir
// recorre todo el arreglo y dependiendo del comparaCanciones los agrego a la lista
{
    unsigned int pos = 0;
    bool posible = false;
    while (pos < tamanio_arreglo)
    {
        posible = comparaCanciones(arreglo,tituloIngresado, pos);
        if (posible == true)
        {
            listaCanciones.lista_agregar(arreglo[pos]);
            pos = pos + 1;
        }
        else {
            pos = pos + 1;
        }
    }
}
/* ---------------------- FIN SERVICIO N°1 ----------------------------------- */

/* -------------------- COMIENDO SERVICIO  N°2 --------------------- */
void Devolver_Lista_Rango(Plataforma arreglo[], unsigned int tamanio_arreglo, string Limite_Inferior, string Limite_Superior, Lista<Plataforma> & Listado) //funci�n encargada de resolver el servicio 3
{
    unsigned int posicion = 0;
    while (posicion < tamanio_arreglo){
        if (arreglo[posicion].consultarAnio() >= Limite_Inferior && arreglo[posicion].consultarAnio() <= Limite_Superior) //si la cancion cuenta con un anio en el rango indicado, se agrega al listado pedido
            Listado.lista_agregar(arreglo[posicion]);
        posicion++;//se incrementa en 1 la posici�n para seguir con la b�squeda secuencial sobre el arreglo
    }
}

void es_menor(string primero,string & segundo) // funcion para el servicio 2, obliga al usuario a poner el anio superior mas grande que el inferior
// comprueba que el anio minimo sea mayor al segundo
{
    while(primero > segundo) {
        cout << " Incorrecto, el anio ingresado debe ser superior a " << primero << endl;
        cin>>segundo;
    }
}
/* -------------------- FIN SERVICIO  N°2 --------------------- */

/* -------------------- COMIENZO SERVICIO  N°3 --------------------- */

void Devolver_Lista_Genero(Plataforma arreglo[],unsigned int tamanio_arreglo,string generoBuscado,Lista<Plataforma> & ListaTop)
{
    unsigned int pos = 0;
    bool pertenece = false;
    while (pos < tamanio_arreglo)
    {
        while (ListaTop.lenght() < 10) {
            pertenece = arreglo[pos].perteneceGenero(generoBuscado);
            if (pertenece == true) {
                ListaTop.lista_agregar(arreglo[pos]);
            }
            pos = pos + 1;
        }
    }
}
/* -------------------- FIN SERVICIO  N°3 --------------------- */


void menu(Plataforma arreglo[], unsigned int tamanio_arreglo) //módulo encargado de solicitar una opción al usuario y de acuerdo a la misma llevar a cabo la operación que corresponda según el caso
{
    int opcion = 1; //inicializado en 1 para que pueda entrar al while, cuyas instrucciones se llevan a cabo hasta que la opción sea igual 0, y allí finaliza el programa
    while (opcion != 0) {
        cout << endl;
        cout << "                                                   Menu                                                   " << endl;
        cout << "Servicio 1: Buscar cancion por titulo ( '*' para una palabra y '?' para un caracter )" << endl;
        cout << "Servicio 2: Listado de canciones entre rangos de anios" << endl;
        cout << "Servicio 3: Top 10 de las canciones mas escuchadas de un genero" << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "A continuacion ingrese el numero de servicio que desea ejecutar, o en caso de querer salir ingrese un 0: ";
        cin >> opcion;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        if (opcion < 0 || opcion > 3) {
            cout << "-------------------------------------------------" << endl;
            cout << "Ingreso un numero de operacion no valido" << endl;
            cout << "-------------------------------------------------" << endl;
        }
        switch (opcion)
        {
            case 1:
            {
                string tituloIngresado;
                bool comodin;
                string resultado;

                cout << "-------------------------------------------------" << endl;
                cout<< "Ingrese el titulo de la cancion que desea buscar: " << endl;
                cin.ignore();
                getline(cin, tituloIngresado);
                cout << "-------------------------------------------------" << endl;
                comodin = usaComodin(tituloIngresado);
                if (comodin == false)
                {
                    buscarCancion(arreglo,tamanio_arreglo,tituloIngresado);
                }
                else {
                    cout << "-------------------------------------------------" << endl;
                    cout << "Las posibles canciones buscadas son las siguientes: " << endl;
                    cout << "-------------------------------------------------" << endl;
                    Lista<Plataforma> listaCanciones;
                    posiblesCanciones(arreglo,tamanio_arreglo,tituloIngresado,listaCanciones);
                    cout << "-------------------------------------------------" << endl;
                    if (listaCanciones.es_vacia())
                        cout << "No hay coincidencias" << endl;
                    else {
                        cout << "El listado de la busqueda:" << endl;
                        listaCanciones.volverAPrimero();
                        while (listaCanciones.cursorPublico != NULL) {
                            listaCanciones.cursorPublico->elemento->mostrarDatos();
                            listaCanciones.avanzarASig();
                        }
                    }
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            case 2:
            {
                cout << "-------------------------------------------------" << endl;
                cout << "Anio minimo" << endl;
                cout << endl;
                string Anio_Min; //se pasa como mínimo el 1 debido a que no tiene sentido que una cancion sea del anio 0
                cin>> Anio_Min;
                cout << endl;
                cout << "Anio maximo" << endl;
                cout << endl;
                string Anio_Max;
                cin>> Anio_Max;
                es_menor(Anio_Min,Anio_Max);
                cout << "-------------------------------------------------" << endl;
                cout << endl;
                Lista<Plataforma> Listado;
                Devolver_Lista_Rango(arreglo, tamanio_arreglo, Anio_Min, Anio_Max, Listado);

                cout << "-------------------------------------------------" << endl;
                if (Listado.es_vacia())
                    cout << "No hay ninguna cancion cuyo anio pertenece al rango " << Anio_Min << "-" << Anio_Max << endl;
                else {
                    cout << "El listado de canciones cuya anio pertenece al rango " << Anio_Min << "-" << Anio_Max << " es el siguiente:" << endl;
                    cout << " " << endl;
                    Listado.volverAPrimero();
                    while (Listado.cursorPublico != NULL) {
                        Listado.cursorPublico->elemento->mostrarDatos();
                        Listado.avanzarASig();
                    }
                }
                cout << "-------------------------------------------------" << endl;

                break;
            }
            case 3:
            {
                string generoBuscado;
                cout << "-------------------------------------------------" << endl;
                cout<< "Ingrese el titulo de la cancion que desea buscar: " << endl;
                cin.ignore();
                getline(cin, generoBuscado);
                cout << "-------------------------------------------------" << endl;
                Lista<Plataforma> ListaTop;
                cout << "hasta aca " << endl;
                Devolver_Lista_Genero(arreglo, tamanio_arreglo, generoBuscado, ListaTop);
                if (ListaTop.es_vacia())
                    cout << "No hay ninguna cancion cuyo genero determinado este registrado " << endl;
                else {
                    cout << "El listado TOP 10 de canciones cuyo genero es: " << generoBuscado << " es el siguiente:" << endl;
                    cout << " " << endl;
                    ListaTop.volverAPrimero();
                    while (ListaTop.cursorPublico != NULL) {
                        ListaTop.cursorPublico->elemento->mostrarDatos();
                        ListaTop.avanzarASig();
                }
                break;
            }
        }
    }
}
}

