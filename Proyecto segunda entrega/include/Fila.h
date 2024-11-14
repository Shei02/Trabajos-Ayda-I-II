#ifndef FILA_H
#define FILA_H
#include <iostream>
#include "lista.h"

using namespace std;

template<typename L>
class Fila
{
    public:
        Fila(); //constructor de la clase
        ~Fila(); //destructor
        void agregar(const L & elem);
        void sacarelemento();
        L valorsigaretirar();
        int cantidadelementos();
        bool filavacia() const;
        void imprimirfila();
        L ultimoDato();
        string getoperacion();
        bool getcliente();
        L devolverelemento();
        bool getcolaabierta();
        void abrir();
        void cerrar();
        void criterio(const string & op);
        void criterioCl(const bool & cl);

    protected:

    private:
        lista<L> primero;
};

#endif // FILA_H
