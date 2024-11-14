#include <iostream>
#include <conio.h>
#include "Banco.h"
#include "Cliente.h"
#include "lista.h"
#include "Fila.h"
using namespace std;

void Menu() {
    int opcion;
    Cliente nuevo_usuario;
    bool Salir = false;
    Banco<Cliente> Banco;
    while (Salir == false) {
        cout << "Usted ingreso a Banco" << endl;
        cout << endl;
        cout << "Ingrese una opcion:" << endl;
        cout << "1-Mesa de entrada" << endl;
        cout << "2-Atender proximo cliente" << endl;
        cout << "3-Abrir cola especial" << endl;
        cout << "4-Cerra cola especial" << endl;
        cout << "5-Lista de operaciones" << endl;
        cout << "6-Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1: system("CLS");
                    Banco.ingresarCliente();
                    break;
            case 2: system("CLS");
                    Banco.atenderCliente();
                    break;
            case 3: system("CLS");
                    Banco.abrirColaEsp();
                    break;
            case 4: system("CLS");
                    Banco.cerrarColaEsp();
                    break;
            case 5: system ("CLS");
                    Banco.listaDeOp();
                    break;
            case 6: Salir = true;
                    break;
            default: system("CLS");
                    break;
        }
    }
}

int main()
{
    Menu();
    return 0;
}
