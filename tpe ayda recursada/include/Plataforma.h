#ifndef PLATAFORMA_H_INCLUDED
#define PLATAFORMA_H_INCLUDED
#include <iostream>
#include "Lista.h"

using namespace std;

class Plataforma
{
private:
    unsigned int nroCancion;
    string interprete;
    string nombreCancion;
    unsigned int duracion;
    string anio;
    Lista<string> listaGeneros;
    unsigned int reproducciones;

public:
    Plataforma();
    Plataforma(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, Lista<string> listaGeneros, unsigned int reproducciones);
    virtual ~Plataforma();

    unsigned int consultarNumeroCancion() const;
    string consultarInterprete() const;
    string consultarNombreCancion() const;
    string consultarAnio() const;
    unsigned int consultarDuracion() const;
    unsigned int consultarReproducciones() const;

    bool perteneceGenero(string generoBuscado);
    void mostrarDatos();
};

#endif //PLATAFORMA_H_INCLUDED
