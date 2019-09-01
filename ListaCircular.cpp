#include "ListaCircular.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
ListaCircular::ListaCircular()
{
    filtroAP = "";
    siguiente = NULL;
    anterior = NULL;
}

ListaCircular* ListaCircular::crearNodo(string filtroAP)
{
    ListaCircular *nuevo_nodo = new ListaCircular();
    nuevo_nodo->filtroAP = filtroAP;
    return nuevo_nodo;
}

bool ListaCircular :: estaVacia(ListaCircular *&primero)
{
  return(primero==NULL)? true:false;
}

void ListaCircular :: insertar(ListaCircular *&primero,string filtro)
{
    ListaCircular *temp = primero;
    ListaCircular *nuevo = crearNodo(filtro);

    if(estaVacia(primero))
    {
      nuevo->siguiente = nuevo;
      nuevo->anterior = nuevo;
      primero = nuevo;
    }else{
        while(temp->siguiente!=primero){
            temp = temp->siguiente;
        }
        nuevo->anterior = temp;
        nuevo->siguiente = temp->siguiente;
        temp->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
    }
}

void ListaCircular :: Mostrar(ListaCircular *&primero)
{
    if(estaVacia(primero)){
     cout<<"Lista Filtros Vacia"<<endl;
    }else{
        ListaCircular *temp = primero;
        do{
            cout<<temp->filtroAP<<endl;
            temp = temp->siguiente;
        }while(temp!=primero);
    }
}

void ListaCircular :: limpiarLista(ListaCircular *&primero)
{
    if(estaVacia(primero)){
        cout<<"Lista Filtros Vacia"<<endl;
    }else{
        primero->siguiente = NULL;
        primero->anterior = NULL;
        primero = NULL;
    }
}

void ListaCircular::graficaListaCircular(ListaCircular *&primero){
    string cad2;
    string cad4;
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaCircular.dot",ios::out);
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
    cad2 = listarNodos(primero);
    cad4 = apuntadores(primero);
    archivo<<"\n";
    archivo<<cad2<<endl;
    archivo<<"\n";
    archivo<<cad4<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"Filtros Aplicados\n\n\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaCircular.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaCircular.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaCircular.png");
    //limpiarCadenas();
}

string ListaCircular::listarNodos(ListaCircular *&primero){
    string c="";
    if(estaVacia(primero)){
        cout<<"Lista Filtros Vacia"<<endl;
    }else{
        ListaCircular *temp = primero;
        do{
            c += "\tFiltro" + temp->filtroAP+"[label=\"{ |"+temp->filtroAP+"| }\"];\n";
            temp = temp->siguiente;
        }while(temp!=primero);
    }
    return c;
}

string ListaCircular :: apuntadores(ListaCircular *&primero)
{
    string c ="";
    if(estaVacia(primero))
    {
        return c="";
    }else{
        ListaCircular *temp = primero;
        do{
        c+="\tFiltro"+ temp->filtroAP+"->"+"Filtro"+temp->siguiente->filtroAP+"\n";
        c+="\tFiltro"+ temp->siguiente->filtroAP+"->Filtro"+temp->filtroAP+"\n";
        temp = temp->siguiente;
        }while(temp!=primero);
    }
    return c;
}


