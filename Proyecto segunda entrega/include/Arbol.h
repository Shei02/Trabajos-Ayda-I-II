#ifndef ARBOL_H
#define ARBOL_H
#include "lista.h"

template<typename A>
class Arbol
{
    public:
        Arbol(); //constructor de la clase
        ~Arbol(); //destructor
        void agregarElemento(const A & elem);
        lista<A>listadefrontera;
        bool perteneceelem(const A & elem);
        int cantelementos();
        bool arbolvacio();
        int profundidadarbol();
        void listarfrontera() ;
        void listararbol() ;

    //protected:

    private:
        struct nodo {
            A elem;
            nodo * menor;
            nodo * mayor;
        };
    nodo * raiz;
    void insertarenarbol(nodo*&raiz,const A & elem);
    bool estaenarbol(const A & elem, nodo*raiz);
    int cantidad(nodo*raiz);
    int profundidad(nodo*raiz);
    void frontera(nodo*raiz);
    void enorden(nodo*raiz);
    void vaciararbol() const;
};

#endif // ARBOL_H
