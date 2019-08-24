#include "ListaCircular.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
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
    if(primero == NULL){
        return true;
    }else{
        return false;
    }
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



