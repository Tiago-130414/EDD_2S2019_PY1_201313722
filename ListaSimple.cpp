#include "ListaSimple.h"
using namespace std;
nodoLista::nodoLista()
{
    siguiente = NULL;
}

ListaSimple::ListaSimple()
{
    //ctor
    primero = NULL;
    ultimo = NULL;
}

bool ListaSimple::estaVacia(){
    return (primero==NULL)? true:false;
}


void ListaSimple::insertarCapa()
{
    nodoLista *nuevo = new nodoLista();
    nuevo->capa.insertarNodo(1,2,"blanco");
    nuevo->capa.insertarNodo(2,2,"negro");
    nuevo->capa.insertarNodo(5,2,"azul");
    nuevo->capa.insertarNodo(9,9,"rojo");
    nuevo->capa.escribirDot();
    nuevo->capa.imprimir();
    nuevo->capa.linealizarFilas();
    if(estaVacia()){
        primero = nuevo;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

void ListaSimple::mostrar(){
    if(estaVacia()){
        cout<<"esta vacia"<<endl;
    }else{
        nodoLista *temp = primero;
        while(temp!=NULL){
            cout<<temp<<endl;
            temp = temp->siguiente;
        }

    }

}
