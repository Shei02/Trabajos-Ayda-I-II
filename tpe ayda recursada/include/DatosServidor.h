#ifndef DATOS_SERVIDOR_H_INCLUDED
#define DATOS_SERVIDOR_H_INCLUDED
#include "Plataforma.h"
#include <iostream>

using namespace std;

class Datos_Servidor
{
    public:
        Datos_Servidor();
        Datos_Servidor(Plataforma * cancion);
        Plataforma consultar_plataforma();
        virtual ~Datos_Servidor();

    private:
        Plataforma *cancion;
};


#endif // DATOS_SERVIDOR_H_INCLUDED
