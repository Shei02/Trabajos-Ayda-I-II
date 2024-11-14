#include <iostream>
#include "BibliotecaUnicen.h"
#include "Lista.h"

using namespace std;

BibliotecaUnicen :: BibliotecaUnicen()
{
    // constructora
}

BibliotecaUnicen :: ~BibliotecaUnicen()
{
    //dtor
}

void BibliotecaUnicen :: AggBibliotecaUnicen(string IDLibro, string tituloLibro, string Autor, string Editorial, int anio, int Edicion, Lista<string> listaGeneros, int nroPag, int CantEjV, float Precio)
{
    cout << "agrego el libro " << tituloLibro << endl;
    this->IDLibro = IDLibro;
    this->tituloLibro = tituloLibro;
    this->Autor = Autor;
    this->Editorial = Editorial;
    this->Edicion = Edicion;
    listaGeneros.volveralprincipio();
    //while ( != NULL) {
    this->listaGeneros = listaGeneros;
      //  listaGeneros.avanzarsig();
    //}
    this->anio= anio;
    this->nroPag = nroPag;
    this->CantEjV = CantEjV;
    this->Precio = Precio;
}

string BibliotecaUnicen :: consultarIDLibro() const
{
    return IDLibro;
}

string BibliotecaUnicen :: consultartitulodelibro() const
{
    return tituloLibro;
}

string BibliotecaUnicen :: consultarautor() const
{
    return Autor;
}

string BibliotecaUnicen :: consultareditorial() const
{
    return Editorial;
}

int BibliotecaUnicen :: consultaranio() const
{
    return anio;
}

int BibliotecaUnicen :: consultaredicion() const
{
    return Edicion;
}

int BibliotecaUnicen :: consultarnropaginas() const
{
    return nroPag;
}

int BibliotecaUnicen :: consultarcantejemplaresvendidos() const
{
    return CantEjV;
}

int BibliotecaUnicen :: consultarprecio() const
{
    return Precio;
}

Lista<string> BibliotecaUnicen :: consultarGenero() const
{
    return listaGeneros;

}

bool BibliotecaUnicen::operator==(BibliotecaUnicen libro)
{
    return IDLibro == libro.consultarIDLibro();
}

void BibliotecaUnicen :: mostrarDatos()
{
    cout << "El Id del libro es: " << this->IDLibro << endl;
    cout << "El titulo del libro es: " << this->tituloLibro << endl;
    cout << "El autor es: " << this->Autor << endl;
    cout << "La editorial es: " << this->Editorial << endl;
    cout << "El año de edición: " << this->anio << endl;
    cout << "El volumen del libro es: " << this->Edicion << endl;
    cout << "Generos: " << endl;
    listaGeneros.volveralprincipio();
    int longitud = 1;
    while (longitud <= listaGeneros.lenght()){
        listaGeneros.devolverpos(longitud);
        longitud++;
    }
    cout << "Tiene " << this->nroPag << " páginas" << endl;
    cout << "Tiene " << this->CantEjV << " ejemplares vendidos" << endl;
    cout << "$" << this->Precio << endl;
    cout << "-------------------------------------------------" << endl;
}
