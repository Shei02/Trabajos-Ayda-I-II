#include <iostream>
#include <clocale>
#include "Plataforma.h"
#include "Servicios.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    /* procesar_archivo_entrada("libros.csv"); */
    unsigned int tamanio_arreglo = 0;
    Plataforma * arreglo = procesar_archivo_entrada("libros.csv", tamanio_arreglo);
    menu(arreglo, tamanio_arreglo);
    delete[] arreglo; // libera la memoria ocupada por arreglo

    return 0;
}
