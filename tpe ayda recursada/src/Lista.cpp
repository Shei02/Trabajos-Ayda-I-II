#include <iostream>
#include "Lista.h"
#include "plataforma.h"

using namespace std;

template <typename L>
Lista<L> :: Lista()
{
    this->primero = NULL;
    this->final = NULL;
    this->cursorPublico = NULL;
    this->longitud = 0;
}

template <typename L>
Lista<L> :: ~Lista()
{
    nodo * aux;
    while (primero != NULL) {
        aux = primero->sig;
        primero = aux;
        delete aux;
    }
    primero = NULL;
}

template <typename L>
void Lista<L> :: agregarlista(L & datoagregar)
{
    nodo * nuevo = new nodo;
    nuevo->elemento = &datoagregar;
    nuevo->sig = primero;
    primero = nuevo;

    longitud++;
}

template <typename L>
bool Lista<L> :: vacia() const
{
    return (longitud == 0);
}

template <typename L>
int Lista<L> :: lenght() const {
    return longitud;
}

template <typename L>
void Lista<L> :: avanzarsig()
{
    this->cursorpublico = this->cursopublico->sig;
}

template <typename L>
void Lista<L> :: volveralprincipio()
{
    this->cursorpublico = this->primero;
}

template class Lista<string>;
template class Lista<Plataforma>;
