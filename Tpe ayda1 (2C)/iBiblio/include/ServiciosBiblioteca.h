#ifndef SERVICIOSBIBLIOTECA_H
#define SERVICIOSBIBLIOTECA_H
#include "BibliotecaUnicen.h"
#include "Lista.h"

using namespace std;

//bool usaComodin(string tituloIngresado); //no implementado.
bool buscarTitulo(Lista<BibliotecaUnicen>& Libreria, string tituloIngresado);
void esmenor(int Anio_1,int & Anio_2);
Lista<BibliotecaUnicen> Devolver_Lista_Rango(Lista<BibliotecaUnicen> & Libreria,int Anio_Min,int Anio_Max);
Lista<BibliotecaUnicen> Devolver_Lista_Genero(Lista<BibliotecaUnicen> Libreria, string generoBuscado);
Lista<BibliotecaUnicen> Lista_vendidos(Lista<BibliotecaUnicen> & lstGenero);
void menu (Lista<BibliotecaUnicen> & libreria);

#endif // SERVICIOSBIBLIOTECA_H
