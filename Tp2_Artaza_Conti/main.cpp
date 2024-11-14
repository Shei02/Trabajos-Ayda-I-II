#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <list>
#include <climits>
#include <utility>

#include "conio.h"
#include "iostream"

const int CANT_ARBITROS=8;

using namespace std;


void cargarEquipos();

void backMaxArbitros (pair<int,int> jornada [] , int cant_partidos , int num_partido , int puntajes_arbitros [][8] ,
int puntaje_actual , int&puntaje_maximo , list<int> arbitros_actuales , list<int>& arbitros);
bool arbitroElegido(list<int> arbitros_actuales , int arbitro);//Poda

void cargarPartidos (pair<int,int> jornada [] , int cant_equipos);
void cargarPuntajesArbitros(int puntajes_arbitros [][8], int cant_equipos );

void mostrarPartidos ( pair<int,int>jornada[] , int cant_equipos);
void mostrarPuntajes (int puntajes_arbitros [][8] , int cant_equipos);
void mostrarArbitros (list<int> arbitros);

int main() {


        cargarEquipos();

    return 0;
}

void cargarEquipos(){

        int cant_equipos;
        cout << "INGRESE LA CANTIDAD DE EQUIPOS PAR:  " << endl;
        cin >> cant_equipos;
        pair<int,int> jornada [cant_equipos/2];
        cargarPartidos(jornada,cant_equipos);
        mostrarPartidos ( jornada ,cant_equipos);

        int puntajes_arbitros [cant_equipos] [8];

        cargarPuntajesArbitros(puntajes_arbitros , cant_equipos);
        mostrarPuntajes(puntajes_arbitros,cant_equipos);

        int puntaje_maximo = INT_MIN;

        list<int> arbitros;
        list<int> arbitros_actuales;
        int cant_partidos = cant_equipos/2;

        backMaxArbitros(jornada , cant_partidos , 0 , puntajes_arbitros , 0 , puntaje_maximo , arbitros , arbitros);

        cout << "Los arbitros elegidos para la jornada dada son : " << endl;

        mostrarArbitros(arbitros );
        cout << "puntaje maximo: " << puntaje_maximo << endl;

}


void backMaxArbitros (pair<int,int> jornada [] , int cant_partidos , int num_partido , int puntajes_arbitros [][8] ,
int puntaje_actual , int&puntaje_maximo , list<int> arbitros_actuales , list<int> &arbitros){

    if( arbitros_actuales.size() == cant_partidos ){//Estado hoja
        if(puntaje_actual > puntaje_maximo){//Consulta sobre maximización
            puntaje_maximo = puntaje_actual;
            arbitros = arbitros_actuales;
            mostrarArbitros(arbitros);
            cout<< "puntaje maximo"<<puntaje_maximo<<endl;
        }
    }
    else {

        for (int i = 0; i < CANT_ARBITROS ; i++) //Vario cada arbitro
            if(!arbitroElegido(arbitros_actuales, i ) ) { //Poda por arbitro no elegido

                arbitros_actuales.push_back(i);
                //cout << "puntaje actual" <<puntaje_actual << endl;
                puntaje_actual += puntajes_arbitros[ jornada[num_partido].first][i] + puntajes_arbitros[jornada[num_partido].second][i];
                backMaxArbitros (jornada , cant_partidos , num_partido+1 , puntajes_arbitros , puntaje_actual , puntaje_maximo , arbitros_actuales , arbitros);
                arbitros_actuales.pop_back();
                puntaje_actual -= puntajes_arbitros[ jornada[num_partido].first][i] + puntajes_arbitros[jornada[num_partido].second][i];
            }
    }
}

bool arbitroElegido(list<int> arbitros_actuales , int arbitro){

    list<int>::const_iterator it_arbitros;

    for (it_arbitros = arbitros_actuales.begin() ; it_arbitros != arbitros_actuales.end();it_arbitros++)
        if(*it_arbitros == arbitro)
            return true;

    return false;

}

void cargarPartidos (pair<int,int> jornada [] , int cant_equipos){

    for(int i = 0 ; i < cant_equipos/2 ; i++) {
        jornada[i].first = i;
        jornada[i].second = (cant_equipos - 1) -i;
    }
}

void cargarPuntajesArbitros(int puntajes_arbitros [][8] , int cant_equipos ){

    for (int i = 0 ; i < cant_equipos ; i++)
        for (int j = 0 ; j < CANT_ARBITROS; j++)
            puntajes_arbitros[i][j] = rand()%11 ;

}
void mostrarPartidos ( pair<int,int>jornada[] , int cant_equipos){
    for (int i = 1 ; i <= cant_equipos/2 ; i++)
        cout << "(" << jornada[i].first << ","<< jornada[i].second  << ")" ;
    cout << endl;
}

void mostrarPuntajes (int puntajes_arbitros [][8] , int cant_equipos ){
    cout<<"los puntajes son: "<< endl;
     for (int i = 0 ; i < cant_equipos ; i++) {
        for (int j = 0 ; j < CANT_ARBITROS ; j++)
            cout << puntajes_arbitros[i][j] << " ";
        cout << endl;
     }
}

void mostrarArbitros (list<int> arbitros ){

    list<int>::const_iterator it_arbitros;
    for (it_arbitros = arbitros.begin() ; it_arbitros != arbitros.end();it_arbitros++)
        cout << *it_arbitros << " ";

}

