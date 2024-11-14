#include "DatosServidor.h"
#include "Plataforma.h"
#include <iostream>

Datos_Servidor::Datos_Servidor()
{
    //ctor
}

Datos_Servidor::Datos_Servidor(Plataforma *cancion)
{
    this->cancion = cancion;
}

Plataforma Datos_Servidor::consultar_plataforma()
{
    return *cancion;
}


Datos_Servidor::~Datos_Servidor()
{
    //dtor
}
