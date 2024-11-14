#ifndef GRAFO_H_
#define GRAFO_H_

#include <cstdio>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cassert>
#include "iostream"

using namespace std;

//------------------------------HEADER CLASE ARCO------------------------------------------

template <typename C> class Grafo {

    public:

	    class Arco {
	        public:
	        	Arco(); //Constructor vacío
        		Arco(int adyacente, const C & costo); //Constructor con información
        		int devolver_adyacente() const;
        		const C & devolver_costo() const;

//------------------------------ESTRUCTURA PRIVADA ARCO--------------------------------------------------

	        private:
	        	int adyacente;
		        C costo;//VALOR PARAMETRIZADO DADO POR LA CATEDRA
	    };

//----------------------------------FIN HEADER ARCO--------------------------------------------------
//--------------------------------HEADER CLASE GRAFO-------------------------------------------------
    public:

    	Grafo(); //CONTRUCTOR VACIO
    	Grafo(const Grafo & otroGrafo);//DADO EN LABORATORIO
    	~Grafo();//DESTRUCTOR
    	Grafo & operator = (const Grafo & otroGrafo); //Si quiero asignar un grafo a otro
    	bool esta_vacio() const;// Devuelve true si la cantidad de vértices es cero
    	int devolver_longitud() const;// Indica la cantidad de vértices del grafo
    	bool existe_vertice(int vertice) const;
    	bool existe_arco(int origen, int destino) const;
    	const C & costo_arco(int origen, int destino) const;// PRE CONDICION: existe_arco(origen, destino)
    	void devolver_vertices(list<int> & vertices) const;//DADA UNA LISTA DEVUELVE LOS VERTICES
    	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;//DADA UNA LISTA DE ARCOS DEVUELVE LOS ADYACENTES
    	void agregar_vertice(int vertice);// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
    	void eliminar_vertice(int vertice);
    	void modificar_costo_arco(int origen, int destino, const C & costo);// PRE CONDICION: existeArco(origen, destino)
    	void agregar_arco(int origen, int destino, const C & costo);// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
    	void eliminar_arco(int origen, int destino);// POST CONDICION: !existeArco(origen, destino)
    	void vaciar();
//--------------------------ESTRUCTURA PIVADA DEL GRAFO--------------------------------------------------------------------------------------------

private:

    map < int , map <int,C> > vertices ;

//--------------------------FUNCIONES PRIVADAS DEL GRAFO------------------------------------------------------------------------------------------------

	void eliminarArcosDe( int vertice ){
	    typename map < int , map <int,C> >::iterator it_origen;
	    for (it_origen = vertices.begin() ; it_origen != vertices.end() ; it_origen++ ){
	        typename map<int,C>::iterator it_destino = it_origen->second.find(vertice);
	        if (it_destino != it_origen->second.end() )
	            it_origen->second.erase(vertice);
	    }

	}


};

//-------------------------FIN DEL HEADER DE GRAFO------------------------------------------

//-------------------------FUNCIONES DE ARCO-------------------------------------------

template <typename C> Grafo<C>::Arco::Arco()
{
    //CONSTRUCTOR VACIO
}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{
    this->adyacente = adyacente;
    this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const
{
    return adyacente;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
    return costo;
}
//--------------------------FIN FUNCIONES DE ARCO--------------------------------------------
//--------------------------INICIO DE FUNCIONES DE GRAFO-------------------------------------

template <typename C> Grafo<C>::Grafo()
{
    //CONSTRUCTOR VACIO
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{
    //DADO EN LABORATORIO
}

template <typename C> Grafo<C>::~Grafo()
{
    //DESTRUCTOR
}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
    return *this; //ASIGNA UN GRAFO A OTRO
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
    return vertices.empty();
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
    return vertices.size();
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
    typename map < int , map <int,C> >::const_iterator it = vertices.find(vertice);
    bool e = false;
    if (it != vertices.end()){
        e = true;
    }

    return e;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    typename map < int , map <int,C> >::const_iterator it_origen = vertices.find(origen);

    if (it_origen != vertices.end()){
       typename map <int,C>::const_iterator it_destino = it_origen->second.find(destino);
        return it_destino != it_origen->second.end();
    }
    else
       return false;

}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{
    typename map < int , map <int,C> >::const_iterator it_origen = vertices.find(origen);
    assert (it_origen != vertices.end());
    typename map <int,C>::const_iterator it_destino = it_origen->second.find(destino);
    assert (it_destino != it_origen->second.end());
    return it_destino->second;
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{
    typename map < int , map <int,C> >::const_iterator it;
    for (it = this->vertices.begin() ; it!= this->vertices.end() ; it++)
        vertices.push_back(it->first);
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
   typename map < int , map <int,C> >::const_iterator it_origen = vertices.find(origen);
   if(it_origen != vertices.end()){
      typename map <int,C>::const_iterator it_destino;
      for (it_destino = it_origen->second.begin() ; it_destino != it_origen->second.end() ; it_destino++)
            adyacentes.push_back( Arco(it_destino->first , it_destino->second) );
   }

}
template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    vertices.insert(make_pair< int , map <int,C> >(vertice,map<int,C>()));
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
   typename map < int , map <int,C> >::iterator it = vertices.find(vertice);

   if(it != vertices.end()){
       vertices.erase(vertice);
       eliminarArcosDe(it->first);
   }

}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    typename map < int , map <int,C> >::iterator it_origen = vertices.find(origen);
    if (it_origen != vertices.end()) {
        typename map <int,C>::iterator it_destino = it_origen->second.find(destino);
        if (it_destino != it_origen->second.end()){
            it_destino->second = costo;
        }
    }
}
template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{

  if( (existe_vertice(origen) && (existe_vertice(destino)))) {
     typename map < int , map <int,C> >::iterator it_origen = vertices.find(origen);
     Arco a(destino,costo);
     it_origen->second.insert(make_pair<int ,C> (destino,costo));
  }


}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
  typename map < int , map <int,C> >::iterator it_origen = vertices.find(origen);
  if( it_origen != vertices.end() ){
     typename  map <int,C>::iterator it_destino = it_origen->second.find(destino);
     if(it_destino != it_origen->second.end())
        it_origen->second.erase(destino);
  }

}

template <typename C> void Grafo<C>::vaciar()
{
    vertices.clear();
}
//--------------------------FIN DE LA CLASE GRAFO---------------------------------------



#endif

