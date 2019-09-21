#include "ListaCircular.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
nodoListaCircular::nodoListaCircular()
{
    filtroAP = "";
    siguiente = NULL;
    anterior  = NULL;
}

ListaCircular::ListaCircular()
{
    primero = NULL;
}

nodoListaCircular* ListaCircular::crearNodo(string filtroAP,ListaSimple copiaC)
{
    nodoListaCircular *nuevo_nodo = new nodoListaCircular();
    nuevo_nodo->filtroAP = filtroAP;
    nuevo_nodo->copiaCubo = copiaC;
    return nuevo_nodo;
}

bool ListaCircular :: estaVacia()
{
    return(primero==NULL)? true:false;
}

void ListaCircular :: insertar(string filtro,ListaSimple copia)
{
    nodoListaCircular *temp = primero;
    nodoListaCircular *nuevo = crearNodo(filtro,copia);

    if(estaVacia())
    {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        primero = nuevo;
    }
    else
    {
        while(temp->siguiente!=primero)
        {
            temp = temp->siguiente;
        }
        nuevo->anterior = temp;
        nuevo->siguiente = temp->siguiente;
        temp->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
    }
}

void ListaCircular :: Mostrar()
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            cout<<temp->filtroAP<<endl;
            temp = temp->siguiente;
        }
        while(temp!=primero);
    }
}

void ListaCircular :: limpiarLista()
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        primero->siguiente = NULL;
        primero->anterior = NULL;
        primero = NULL;
    }
}

void ListaCircular::graficaListaCircular()
{
    string cad2="";
    string cad4="";
    ofstream archivo;
    archivo.open("C:/GRAFICAS_PROYECTO/listaCircular.dot",ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph arbol\n{"<<endl;
    archivo<<"\trankdir=LR;"<<endl;
    archivo<<"\tgraph [nodesep=0.3];"<<endl;
    archivo<<"\tsubgraph cluster_0{"<<endl;
    archivo<<"\tstyle=filled;"<<endl;
    archivo<<"\tcolor=lightgrey;"<<endl;
    archivo<<"\tlabelloc=t;"<<endl;
    archivo<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cad2 = listarNodos();
    cad4 = apuntadores();
    archivo<<"\n";
    archivo<<cad2<<endl;
    archivo<<"\n";
    archivo<<cad4<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"Filtros Aplicados\n\n\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:/GRAFICAS_PROYECTO/listaCircular.dot -o C:/GRAFICAS_PROYECTO/listaCircular.png -Tpng -Gcharset=utf8");
    system("C:/GRAFICAS_PROYECTO/listaCircular.png");
}

string ListaCircular::listarNodos()
{
    string c="";
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            c += "\tFiltro" + temp->filtroAP+"[label=\"{ |"+temp->filtroAP+"| }\"];\n";
            temp = temp->siguiente;
        }
        while(temp!=primero);
    }
    return c;
}

string ListaCircular :: apuntadores()
{
    string c ="";
    if(estaVacia())
    {
        return c="";
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            c+="\tFiltro"+ temp->filtroAP+"->"+"Filtro"+temp->siguiente->filtroAP+"\n";
            c+="\tFiltro"+ temp->siguiente->filtroAP+"->Filtro"+temp->filtroAP+"\n";
            temp = temp->siguiente;
        }
        while(temp!=primero);
    }
    return c;
}

///graficarCuboCompletoNegativo
void ListaCircular::generarCssNegativo(string key)
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            if(temp->filtroAP==key)
            {
                temp->copiaCubo.aplicarFiltroNegativoCubo();
                break;
            }
            temp = temp->siguiente;
        }
        while(temp!=primero);

    }
}

void ListaCircular::generarCssNegativoPorCapa(string key,int cap)
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            if(temp->filtroAP==key)
            {
                temp->copiaCubo.aplicarFiltroNegativoCapa(cap);
                break;
            }
            temp = temp->siguiente;
        }
        while(temp!=primero);

    }
}

void ListaCircular::generarEscalaGrises(string key)
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            if(temp->filtroAP==key)
            {
                temp->copiaCubo.aplicarFiltroEscalaCubo();
                break;
            }
            temp = temp->siguiente;
        }
        while(temp!=primero);

    }
}

void ListaCircular::generarEscalaGrisesPorCapa(string key,int cap)
{
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            if(temp->filtroAP==key)
            {
                temp->copiaCubo.aplicarFiltroEscalaCapa(cap);
                break;
            }
            temp = temp->siguiente;
        }
        while(temp!=primero);

    }
}

void ListaCircular::exportarImagen(string k,string nom){
    string fil = nom + "FiltroNegativo";
    if(estaVacia())
    {
        cout<<"Lista Filtros Vacia"<<endl;
    }
    else
    {
        nodoListaCircular *temp = primero;
        do
        {
            if(temp->filtroAP==k)
            {
                temp->copiaCubo.generarCss(fil.c_str());
                temp->copiaCubo.generarHTML(fil.c_str());
                break;
            }
            temp = temp->siguiente;
        }
        while(temp!=primero);

    }

}
