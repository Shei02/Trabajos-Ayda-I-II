#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <class L>

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregarlista(L datoagregar);
        bool vacia() const;
        L devolverelem() const;
        void avanzarsig();
        void volveralprincipio();
        int lenght() const;
        bool pertenece(L datobuscado) const;
        void insertar(L nuevo, int pos);
        L devolverpos (int pos);

    protected:

    private:
        struct nodo {
           L elem;
           nodo * sig;
        };
        nodo * primero;
        nodo * ult;
        nodo * cursorpublico;
        int longitud;
};

#endif // LISTA_H_INCLUDED
