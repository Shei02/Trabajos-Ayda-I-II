#include <iostream>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;

const int CANT_EMPLEADOS = 8;

const string L1 = "Java";
const string L2 = "C++";
const string L3 = "Python";
const string L4 = "PHP";
const string L5 = "Prolog";
const string L6 = "Fortran";
const string L7 = "Perl";
const string L8 = "TypeScript";
const string L9 = "Ruby";
const string L10 = "Javascript";
const string L11 = "SmallTalk";
const string L12 = "Pascal";

void insertarLenguajes (set<string> & L){
    L.insert(L1);
    L.insert(L2);
    L.insert(L3);
    L.insert(L4);
    L.insert(L5);
    L.insert(L6);
    L.insert(L7);
    L.insert(L8);
    L.insert(L9);
    L.insert(L10);
    L.insert(L11);
    L.insert(L12);
}

void insertarEmpleados (set<string> CE []){

    int i = 0;
    set<string> E;
    E.insert(L1);
    E.insert(L2);
    E.insert(L5);
    E.insert(L6);
    CE[i++] = E;

    E.clear();
    E.insert(L5);
    E.insert(L6);
    E.insert(L7);
    E.insert(L8);
    CE[i++] = E;

    E.clear();
    E.insert(L2);
    E.insert(L3);
    E.insert(L4);
    CE[i++] = E;

    E.clear();
    E.insert(L9);
    E.insert(L10);
    E.insert(L11);
    CE[i++] = E;


    E.clear();
    E.insert(L3);
    E.insert(L4);
    E.insert(L7);
    E.insert(L8);
    E.insert(L11);
    E.insert(L12);
    CE[i++] = E;


    E.clear();
    E.insert(L6);
    E.insert(L7);
    E.insert(L8);
    E.insert(L10);
    E.insert(L11);
    E.insert(L12);
    CE[i++] = E;


    E.clear();
    E.insert(L5);
    E.insert(L9);
    CE[i++] = E;


    E.clear();
    E.insert(L4);
    E.insert(L8);
    E.insert(L12);
    CE[i++] = E;

}

void eliminarLenguajes (set<string> & L , set<string> empleado_elegido){

    set<string>::const_iterator it;
    for (it = empleado_elegido.begin() ; it!= empleado_elegido.end() ; it++)
        L.erase(*it);

}

void agregarLenguajes (set<string> & L , set<string> empleado_elegido){

    set<string>::const_iterator it;
    for (it = empleado_elegido.begin() ; it!= empleado_elegido.end() ; it++)
        L.insert(*it);
}

int cantLenguajesEmpleado (set<string> L , set<string> empleado){
    int cant = 0;
    set<string>::const_iterator it;
    for (it = empleado.begin() ; it!= empleado.end() ; it++)
        if( L.find(*it) != L.end() )
            cant++;
    return cant;
}

set<string> empleadoElegido (set<string> L , set<string> CE [] , set<int> & indices_elegidos){
    int cant_max = 0;
    set<string> empleado_elegido;
    for(int i = 0 ; i < CANT_EMPLEADOS ; i++){
        set<int>::const_iterator it_index = indices_elegidos.find(i);
        if( it_index == indices_elegidos.end() ) {
            int cant_lenguajes = cantLenguajesEmpleado(L , CE[i]);
            if(cant_lenguajes > cant_max){
                cant_max = cant_lenguajes;
                empleado_elegido = CE[i];
            }
        }
    }
    return empleado_elegido;
}

void aproxSetCover (set<string> EE [] , int & cant_EE , set<string> L , set<string> CE []){

    set<int> indices_elegidos;
    while (L.size() != 0){

        set<string> empleado_elegido = empleadoElegido(L,CE,indices_elegidos);
        eliminarLenguajes(L,empleado_elegido);
        EE[cant_EE++] = empleado_elegido;
    }
}

void mostrarEmpleados(set<string> empleados [] , int cant_empl ){

    for(int i = 0 ; i < cant_empl ; i++){
        set<string> empleado = empleados[i];
        set<string>::const_iterator it_empleado;
        for(it_empleado = empleado.begin() ; it_empleado != empleado.end() ; it_empleado++)
            cout << *it_empleado << "|";
        cout<<endl;
    }
}

void backSetCover (set<string> EE [] , set<string> EE_parciales [] , set<string> CE [] , set<string> L,
                   int indice , int & cant_minima_emp , int cant_actual ){

    if(L.size() == 0){
       cant_minima_emp = cant_actual;
       EE = EE_parciales;
    }
    else {

       for (int i = indice ; i < CANT_EMPLEADOS ; i++){
           if(cant_actual + 1 < cant_minima_emp ){
               EE_parciales[cant_actual] = CE[indice];
               eliminarLenguajes(L,CE[indice]);
               backSetCover(EE,EE_parciales,CE,L,i+1,cant_minima_emp,cant_actual+1);
               //EE_parciales[cant_actual].clear();
               agregarLenguajes(L,CE[indice]);
           }
       }
    }
}


int main() {
    set<string> L ;
    insertarLenguajes(L);
    set<string> CE[CANT_EMPLEADOS];
    insertarEmpleados(CE);
    set<string> empleados_elegidos[CANT_EMPLEADOS];

    int cant_empleados_elegidos = 0;
    aproxSetCover(empleados_elegidos, cant_empleados_elegidos,L,CE);
    cout <<"Cantidad minima de empleados que se pueden tomar : "<< cant_empleados_elegidos <<endl;
    mostrarEmpleados(empleados_elegidos,cant_empleados_elegidos);

    //set<string> empleados_elegidos_parciales[CANT_EMPLEADOS];
    //int cant_minima = CANT_EMPLEADOS;
    //backSetCover(empleados_elegidos,empleados_elegidos_parciales,CE,L,0,cant_minima,0);
    //cout <<"Cantidad minima de empleados que se pueden tomar : "<< cant_minima <<endl;
    //mostrarEmpleados(empleados_elegidos,cant_minima);


    return 0;
}
