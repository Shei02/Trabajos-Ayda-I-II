#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
#include "lista.h"
#include "Fila.h"
#include <string.h>
#include <conio.h>
using namespace std;

template<typename B>

class Banco
{
    public:
    Banco();
    ~Banco();
    void ingresarCliente();
    void atenderCliente();
    void abrirColaEsp();
    void criterios(Fila<Cliente> & cola);
    void acomodarclientes();
    void cerrarColaEsp();
    void listaDeOp();
    void Menu();

    private:
        Fila<Cliente>  colaGeneral;
        Fila<Cliente>  colaespecial_1;
        Fila<Cliente>  colaespecial_2;
        lista<Cliente>  lista_de_atendidos;
};

#endif // BANCO_H
