#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

using namespace std;

class Cliente
{
    public:
        Cliente(); //constructor
        virtual ~Cliente(); //destructor
        void ingresarcliente();
        void ingresaredad();
        void elegiroperacion();
        void elegirdestinatario();
        void montoOperacion();
        void esCliente();
        //devuelvo;
        string muestranom();
        int muestraedad();
        string muestradest();
        string muestraop();
        int muestramonto();
        bool muestraCl();
        bool operator== (const Cliente & otrocliente) const;
        bool operator!= (const Cliente & otrocliente) const;

    //protected:

    private:
        string nombre;
        int edad;
        string operacion;
        string destinatario;
        int montoOp;
        bool esClien;
};

#endif // CLIENTE_H
