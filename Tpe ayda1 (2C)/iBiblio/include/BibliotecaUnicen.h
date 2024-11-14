#ifndef BIBLIOTECAUNICEN_H_INCLUDED
#define BIBLIOTECAUNICEN_H_INCLUDED
#include <iostream>
#include "Lista.h"

using namespace std;

class BibliotecaUnicen
{
    public:
        BibliotecaUnicen();
        virtual ~BibliotecaUnicen();
        void AggBibliotecaUnicen(string IDLibro, string tituloLibro, string Autor, string Editorial, int anio, int Edicion, Lista <string> listaGeneros, int nroPag, int CantEjV, float Precio);
        string consultarIDLibro() const;
        string consultartitulodelibro() const;
        string consultarautor() const;
        string consultareditorial() const;
        int consultaranio() const;
        int consultaredicion() const;
        int consultarnropaginas() const;
        int consultarcantejemplaresvendidos() const;
        int consultarprecio() const;
        Lista<string> consultarGenero() const;
        bool operator==(BibliotecaUnicen libro);
        void mostrarDatos();

    protected:

    private:
        string IDLibro;
        string tituloLibro;
        string Autor;
        string Editorial;
        int anio;
        int Edicion;
        Lista<string> listaGeneros;
        int nroPag;
        int CantEjV;
        float Precio;
};

#endif // BIBLIOTECAUNICEN_H_INCLUDED
