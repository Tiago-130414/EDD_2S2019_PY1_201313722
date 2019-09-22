#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <string>
#include <iostream>
#include "ListaSimple.h"
using namespace std;
class nodoListaCircular
{
public:
    //node attributes
    nodoListaCircular();
    string filtroAP;
    ListaSimple copiaCubo;
    nodoListaCircular *siguiente;
    nodoListaCircular *anterior;

};
class ListaCircular
{
public:
    //first node
    nodoListaCircular *primero;
    //prototype of function
    ListaCircular();
    nodoListaCircular* crearNodo(string filtroAP,ListaSimple copiaC);
    bool estaVacia();
    void insertar(string filtro,ListaSimple copia);
    void Mostrar();
    void limpiarLista();
    void graficaListaCircular();
    string listarNodos();
    string apuntadores();

    ///filtro negativo
    void generarCssNegativo(string key);
    void generarCssNegativoPorCapa(string key,int cap);
    ///filtro escala de grises
    void generarEscalaGrises(string key);
    void generarEscalaGrisesPorCapa(string key,int cap);
    ///exportar imagen
    void exportarImagen(string k,string nom);
    ListaSimple buscar(string filtro);


protected:

private:
};

#endif // LISTACIRCULAR_H
