#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Cliente.h"

using namespace std;

template <typename L>
class lista
{
    public:
        lista(); //constructor de la clase
        ~lista(); //destructor
        void agregaralprincipio(const L &);
        void agregaralfinal(const L &);
        void agregararbitrario(const L &,const int);
        int cantelem();
        bool pertenece(const L &) const;
        bool listavacia() const;
        void eliminarelem(const L & elem);
        void eliminaralinicio();
        L mostrarelultimo();
        L getDato() const;
        L ultimoDato() const;
        L iterarEnlista();
        void imprimirlista(int mmin, int mmax);
        void abrircolanueva();
        void cerrarcolanueva();
        bool devuelvecolaabierta();
        string devuelveoperacion();
        bool devuelvecliente();
        void cambiarcriterio(const string & opnueva);
        void cambiarcriteriocl(const bool & clnuevo);

    protected:

    private: //mis argumentos

        struct nodo {
            L elem;
            nodo * sig;
        };
        nodo*primero;
        nodo*aux;
        nodo*ultimo;
        string operacion;
        bool abierto;
        bool esCliente;
        void vaciarlista();
};

#endif // LISTA_H
