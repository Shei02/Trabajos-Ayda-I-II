#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "Plataforma.h"
#include "Lista.h"

//Servicios.h posee todas las declaraciones de funciones que se requieren para resolver los servicios indicados por el ejercicio

void menu (Plataforma * arreglo,unsigned int tamanio_arreglo);
Plataforma * procesar_archivo_entrada(string origen, unsigned int & tamanio_arreglo);
unsigned int devolver_Posicion(); //FALTA COMPLETAR, DADA UNA ESTRUCTURA Y EL NOMBRE DEVUELVE LA POSICION
Plataforma devolver_Plataforma(int posicion, Plataforma * arreglo);
void Devolver_Lista_Rango(Plataforma * arreglo, unsigned int tamanio_arreglo, string Anio_Min, string Anio_Max, Lista<Plataforma> & Listado);
void es_menor(string Anio_Min, string & Anio_Max);
bool usaComodin(string tituloIngresado);
void buscarCancion(Plataforma * arreglo, unsigned int tamanio_arreglo, string tituloIngresado);
void posiblesCanciones(Plataforma * arreglo,unsigned int tamanio_arreglo, string tituloIngresado, Lista<Plataforma> & listaCanciones);
void Devolver_Lista_Genero(Plataforma * arreglo, unsigned int tamanio_arreglo, string generoBuscado, Lista<Plataforma> & ListaTop);

#endif //SERVICIOS_H_INCLUDED
