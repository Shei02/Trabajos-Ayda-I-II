#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template<class L>

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregarlista(L & datoagregar);
        bool vacia() const;
        L * devolverelem() const;
        void avanzarsig();
        void volveralprincipio();
        int lenght() const;
        nodo * cursorpublico;

    protected:

    private:
        struct nodo {
           L * elem;
           nodo * sig = NULL;
        };
        nodo * primero;
        nodo * final;

        int longitud;
};

#endif // LISTA_H_INCLUDED
