#include "Grafo.h"
#include "conio.h"
#include "iostream"
#include "stdlib.h"

using namespace std;

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<int> vertices;
	grafo.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}


void DFS (const Grafo<int> &g, char *Marca, int origen, int destino,bool &continuar, list<int>& Camino, string color, map<int,string> coloresVert)
{
	Marca[origen]='G';
    Camino.push_back(origen);
 	if(origen!= destino)
    {

        list<typename Grafo<int>::Arco> adyacentes;
        g.devolver_adyacentes(origen,adyacentes);
        list<typename Grafo<int>::Arco> ::const_iterator it= adyacentes.begin();
        while (continuar && (it!=adyacentes.end())){
            int vertice_ady = it->devolver_adyacente();
            if((Marca[vertice_ady] != 'G') && (coloresVert[vertice_ady] != color ))
                DFS(g,Marca,vertice_ady,destino,continuar,Camino,color,coloresVert);
            it++;
        }
        if (continuar){
            Marca[origen]='B';
            Camino.pop_back();
        }
    }
    else
        continuar=false;


}

void buscarCamino(const Grafo<int> &g, map<int,string> coloresVert){

    int cant = g.devolver_longitud();
    char *Marca= new char [cant];
    for (int i=0; i<cant; i++){
        Marca[i]='B';
    }
    list<int> Camino;
    string color= "rojo";
    bool continuar=true;
    int origen, destino;
    cout << "     INGRESE UN NUMERO DE VERTICE ORIGEN DEL GRAFO QUE NO SEA ROJO: \n" << "\n";
    cin >> origen;
    cout<< "      " << endl;
     cout<< "     INGRESE UN NUMERO DE VERTICE DESTINO DEL GRAFO QUE NO SEA ROJO: \n" << "\n";
    cin>> destino;
    cout<< "  " << endl;
    DFS(g,Marca,origen,destino,continuar,Camino,color,coloresVert);
    list<int>:: const_iterator it;
    cout << "                         UN CAMINO ES:              " << endl;
    for (it=Camino.begin(); it !=Camino.end(); it++){
        cout << "                                       \n               " << *it  ;
    }
}

int main(int argc, char **argv)
{
	Grafo<int> g;
    map <int,string> coloresVert;
/*
	// Cargamos un grafo dirigido
	// Primero los vértices
	g.agregar_vertice(1);
	coloresVert[1]="blanco";
	g.agregar_vertice(2);
	coloresVert[2]="rojo";
	g.agregar_vertice(3);
	coloresVert[3]="blanco";
	g.agregar_vertice(4);
	coloresVert[4]="blanco";
	g.agregar_vertice(5);
	coloresVert[5]="blanco";
	g.agregar_vertice(6);
	coloresVert[6]="blanco";

	// Luego los arcos
	g.agregar_arco(1, 2, 0);
	g.agregar_arco(1, 6, 0);
	g.agregar_arco(2, 3, 0);
	g.agregar_arco(2, 5, 0);
	g.agregar_arco(3, 1, 0);
	g.agregar_arco(3, 2, 0);
	g.agregar_arco(3, 4, 0);
	g.agregar_arco(6, 3, 0);
	g.agregar_arco(6, 4, 0);


    //CASO 2
    g.agregar_vertice(1);
	coloresVert[1]="blanco";
	g.agregar_vertice(2);
	coloresVert[2]="rojo";
	g.agregar_vertice(3);
	coloresVert[3]="rojo";
	g.agregar_vertice(4);
	coloresVert[4]="blanco";
	g.agregar_vertice(5);
	coloresVert[5]="blanco";
	g.agregar_vertice(6);
	coloresVert[6]="blanco";

	// Luego los arcos
	g.agregar_arco(1, 2, 0);
	g.agregar_arco(2, 3, 0);
	g.agregar_arco(2, 4, 0);
	g.agregar_arco(3, 4, 0);
	g.agregar_arco(4, 6, 0);
*/
    //CASO 3
    g.agregar_vertice(1);
	coloresVert[1]="blanco";
	g.agregar_vertice(2);
	coloresVert[2]="rojo";
	g.agregar_vertice(3);
	coloresVert[3]="blanco";
	g.agregar_vertice(4);
	coloresVert[4]="blanco";
	g.agregar_vertice(5);
	coloresVert[5]="blanco";
	g.agregar_vertice(6);
	coloresVert[6]="rojo";

	// Luego los arcos
	g.agregar_arco(1, 6, 0);
	g.agregar_arco(1, 3, 0);
	g.agregar_arco(2, 3, 0);
	g.agregar_arco(2, 5, 0);
	g.agregar_arco(3, 5, 0);
	g.agregar_arco(6, 3, 0);

	cout << " " << endl;
	cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;

//--------------------------------MOSTRAMOS EL GRAFO----------------------------------------------------

	cout << "                     ESTRUCTURA DEL GRAFO:\n                     "<< endl;
	cout<< " " << endl;
	cout << "                    \n  " << g <<  "          \n";

    list<int> vertices;
    g.devolver_vertices(vertices);
	list<int>::const_iterator itV= vertices.begin();
    for(itV= vertices.begin();itV!=vertices.end();itV++){
            cout<< "VERTICE : "<< *itV << " ROTULO:  " << coloresVert[*itV]<< "\n";
    }

    cout<< " " << endl;
//-------------------------------FIN DE IMPRESION DEL GRAFO--------------------------------------------------

//------------------------------------INICIO DEL MENU--------------------------------------------------------------

    int opcion;
    do {


        cout << "--------------------------------MENU------------------------------------------------------------------------------------"<< endl;
        cout << " "<< endl;
        cout << "                       (1) BUSCAR CAMINO                "<< endl;
        cout << " "<< endl;
        cout << "                       (2) SALIR                  "<< endl;
        cout << " "<< endl;
        cout << "                       INGRESE LA OPCION:                "<< endl;
        cout << " "<< endl;
        cout << " "<< endl;
        cin>> opcion;

        switch (opcion){

            case 1: buscarCamino(g,coloresVert);
                break;
            case 2:
                break;
            default:
                cout << "              INGRESE UNA OPCION VALIDA" << endl;
        }

    } while (opcion!=2);


//----------------------------------------FIN DEL MENU----------------------------------------------------------------
//---------------------------------INICIO DE PRUEBA DE METODOS DEL GRAFO-------------------------------------------------------

	// Mostramos operaciones del Grafo
    //cout<< g.esta_vacio()<< endl;
    //cout<< g.devolver_longitud()<< endl;
    //cout<< g.existe_vertice(8)<< endl;
    //cout<< g.existe_arco(1,5)<< endl;

    //cout<< g.color_arco(4,6)<< endl;
    /*
    list<int> lista;
    g.devolver_vertices(lista);
    list<int>:: const_iterator itA;
    for (itA=lista.begin(); itA !=lista.end(); itA++){
        cout<< *itA << endl;
    }



    g.eliminar_vertice(1);
    cout<< g.devolver_longitud()<< endl;
    cout<< g.existe_arco(1,3)<<endl;
    g.modificar_costo_arco(1,3,5);
    cout<< g.costo_arco(1,3)<< endl;
    g.eliminar_arco(1,3);
    cout<< g.existe_arco(1,3)<< endl;
    list<typename Grafo<int>::Arco> adyacentes;
    g.devolver_adyacentes(1,adyacentes);
    list<typename Grafo<int>::Arco> ::const_iterator it;
    for (it=adyacentes.begin(); it != adyacentes.end(); it++){
        cout<< it->devolver_adyacente() << endl;
    }
    cout<<adyacentes.size()<<endl;

    */
	return 0;
}

