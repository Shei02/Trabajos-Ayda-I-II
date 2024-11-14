#include "Plataforma.h"

Plataforma::Plataforma()
{
    // ctr
}

Plataforma::Plataforma(unsigned int nroCancion,string interprete, string nombreCancion, unsigned int duracion, string anio, Lista<string> listaGeneros, unsigned int reproducciones)
{
    this->nroCancion = nroCancion;
    this->interprete = interprete;
    this->nombreCancion = nombreCancion;
    this->duracion = duracion;
    this->anio = anio;
    listaGeneros.volverAPrimero();
    while (listaGeneros.cursorPublico != NULL) {
        this->listaGeneros = listaGeneros;
        listaGeneros.avanzarASig();
    }
    this->reproducciones = reproducciones;
}

Plataforma::~Plataforma()
{
    //dtcr
}

unsigned int Plataforma::consultarNumeroCancion() const
{
    return nroCancion;
}

string Plataforma::consultarInterprete() const
{
    return interprete;
}

string Plataforma::consultarNombreCancion() const
{
    return nombreCancion;
}

string Plataforma::consultarAnio() const
{
    return anio;
}
unsigned int Plataforma::consultarDuracion() const
{
    return duracion;
}

unsigned int Plataforma::consultarReproducciones() const
{
    return reproducciones;
}

bool Plataforma::perteneceGenero(string generoBuscado)
{
    listaGeneros.volverAPrimero();
    cout << "ELEMENTO " << listaGeneros.cursorPublico->elemento << endl;
    while ((listaGeneros.cursorPublico != NULL)) //&& (listaGeneros.cursorPublico->elemento != generoBuscado))
    {
        listaGeneros.avanzarASig();
    }
    if (listaGeneros.cursorPublico != NULL) {
        return true;
    }
    else {
        return false;
    }
}

void Plataforma::mostrarDatos()
{
    cout << "El nombre de cancion es: " << this->nombreCancion << endl;
    cout << "El interprete es: " << this->interprete << endl;
    cout << "El anio es: " << this->anio << endl;
    cout << "La duracion es: " << this->duracion << endl;
    cout << "Tiene " << this->reproducciones << " reproducciones"<<endl;
    cout << "Generos: " << endl;
    listaGeneros.volverAPrimero();
    while ((listaGeneros.cursorPublico != NULL))
    {
        this-> listaGeneros.cursorPublico->elemento;
        listaGeneros.avanzarASig();
    }
    cout << "-------------------------------------------------" << endl;
}
