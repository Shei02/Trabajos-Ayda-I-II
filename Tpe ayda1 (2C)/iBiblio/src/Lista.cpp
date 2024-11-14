#include <iostream>
#include "Lista.h"
#include "BibliotecaUnicen.h"

using namespace std;

template <typename L>
Lista<L> :: Lista()
{
    this->primero = NULL;
    this->ult = NULL;
    this->cursorpublico = NULL;
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
void Lista<L> :: agregarlista(L datoagregar)
{
    nodo * nuevo = new nodo;
    nuevo->elem = datoagregar;
    nuevo->sig = NULL;
    if (primero == NULL){
        primero = nuevo;
        ult = primero;
    }
    else{
        nodo * aux;
        aux = primero;
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    longitud++;
}

template <typename L>
bool Lista<L> :: vacia() const
{
    if(longitud==0)
        return true;
    else
        return false;
}

template <typename L>
int Lista<L> :: lenght() const {
    return longitud;
}

template <typename L>
void Lista<L> :: avanzarsig()
{
    if (cursorpublico->sig != NULL){
        cursorpublico = cursorpublico->sig;
    }
}

template <typename L>
void Lista<L> :: volveralprincipio()
{
    cursorpublico = primero;
}

template <typename L>
L Lista<L> :: devolverelem() const
{
    if(cursorpublico != NULL){
        return cursorpublico->elem;
    }
}

template <typename L>
bool Lista<L> :: pertenece(L datobuscado) const
{
    nodo * aux;
    aux = primero;
    while (aux != NULL){
        if (aux->elem == datobuscado)
            return true;
        aux = aux->sig;
    }
    return false;
}

template <typename L>
void Lista<L> :: insertar(L nuevo, int pos)
{
    if ((pos <= longitud) && (pos>0)){
        nodo * ainsertar = new nodo;
        ainsertar->elem = nuevo;
        ainsertar->sig = NULL;
        nodo * cursor = primero;
        int contador = 1;
        while (contador<pos-1){
            contador++;
            cursor = cursor->sig;
        }
        if (pos == 1){
            ainsertar->sig = primero;
            primero = ainsertar;
        }
        else{

            ainsertar->sig = cursor->sig;
            cursor->sig = ainsertar;
        }
        longitud++;

    }
}

template <typename L>
L Lista<L> :: devolverpos(int pos)
{
    nodo * cursor;
    if ((pos<=longitud) && (pos>0)){
        int contador = 1;
        cursor = primero;
        while (contador < pos) {
            contador ++;
            cursor = cursor->sig;
        }
        return (cursor->elem);
    }
}

template class Lista <BibliotecaUnicen>;
template class Lista <string>;
