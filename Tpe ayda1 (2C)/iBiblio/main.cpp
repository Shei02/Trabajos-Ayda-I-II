#include <iostream>
#include <fstream>
#include <clocale>
#include "ServiciosBiblioteca.h"
#include "BibliotecaUnicen.h"
#include "Lista.h"
#include "stdlib.h"

using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen, Lista<BibliotecaUnicen> & libreria)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            //int idLibro = 1;

            //Informacion entre pos_inicial y pos_final
            string idLibro = linea.substr(pos_inicial, pos_final);

             //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string editorial = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int anio = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int nro_edicion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Septima posición del separador ;
             //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Octava posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int nro_paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Novena posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int ejemplares_vendidos = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

             //Decima posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << "LIBRO Nro "<< nroLibro<< ": " << endl;
            cout << "   ISBN: " << idLibro << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   EDITORIAL: " << editorial<<endl;
            cout << "   AñO EDICION: " << anio<< endl;
            cout << "   NÚMERO EDICION: " << nro_edicion<< endl;
            cout << "   GENEROS: " << lst_generos<<endl;
            cout << "   PAGINAS: " << nro_paginas <<endl;
            cout << "   EJEMPLARES VENDIDOS: " << ejemplares_vendidos <<endl;
            cout << "   PRECIO: " << precio <<endl<<endl;

            //TO DO: Completar la lectura de los generos de la cancion

            //Desde esta posición hasta el final se encuentra un número variable de géneros de cada canción.
            //no tomo en cuenta los corchetes
            string generos = lst_generos.substr(1, lst_generos.size()-2);

            //el siguiente código de prueba separa los diferentes géneros en un arreglo de 10 posiciones
            Lista<string> listaGeneros;

            int pos_inicial_generos = 0, pos_final_generos = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                string genero = generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos);
                listaGeneros.agregarlista(genero);
                pos_inicial_generos = pos_final_generos + 1;
            }
            BibliotecaUnicen libro;
            cout << "Agregando " << titulo << endl;
            libro.AggBibliotecaUnicen(idLibro,titulo,autor,editorial,anio,nro_edicion,listaGeneros,nro_paginas,ejemplares_vendidos,precio);
            cout << "creo el libro " << endl;
            libreria.agregarlista(libro);
            nroLibro++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    Lista<BibliotecaUnicen> libreria;
    //procesar_archivo_entrada("libros.csv", libreria);
    Lista<string> listaGeneros;
    string titulo,autor,editorial,id,terror,suspenso;
    //listaGeneros.agregarlista("feliz");
    listaGeneros.agregarlista("suspenso");
    BibliotecaUnicen libro;
    BibliotecaUnicen libro2;
    BibliotecaUnicen libro3;
    BibliotecaUnicen libro4;
    BibliotecaUnicen libro5;
    BibliotecaUnicen libro6;
    libro.AggBibliotecaUnicen(id,"hola",autor,editorial,2000,2002,listaGeneros,100,1050,1000);
    libro2.AggBibliotecaUnicen(id,"holauno",autor,editorial,2002,2003,listaGeneros,100,1000,1000);
    libro3.AggBibliotecaUnicen(id,"holados",autor,editorial,2020,2021,listaGeneros,100,15000,1000);
    libro4.AggBibliotecaUnicen(id,"holatres",autor,editorial,2019,2020,listaGeneros,100,25,1000);
    libro5.AggBibliotecaUnicen(id,"Codigo limpio",autor,editorial,2005,2004,listaGeneros,100,25,1000);
    libro6.AggBibliotecaUnicen(id,"Sheila",autor,editorial,1973,1974,listaGeneros,100,45,1000);
    libreria.agregarlista(libro);
    libreria.agregarlista(libro2);
    libreria.agregarlista(libro3);
    libreria.agregarlista(libro4);
    libreria.agregarlista(libro5);
    libreria.agregarlista(libro6);
    system("cls");
    menu(libreria);
    return 0;
}
