#include "ListaSimple.h"
#include <string>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
int f=0;
nodoLista::nodoLista()
{
    numeroCapa = 0;
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

void ListaSimple::insertarCapa(int capa,string nom)
{
    nodoLista *nuevo = new nodoLista();
    nuevo->nombreArchivo = nom;
    nuevo->numeroCapa = capa;
    insertarDatosMatriz(nom,nuevo);
    //pasar nombre de archivo para que guarde en matriz

    if(estaVacia()){
        primero = nuevo;
        //ultimo = primero;
    }else{
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

void ListaSimple::mostrar(){
    if(estaVacia()){
        cout<<"esta vacia"<<endl;
    }else{
        nodoLista *temp = primero;
        while(temp!=NULL){
            cout<<"capa"<<intToString(temp->numeroCapa)<<endl;
            cout<<"nombreArchivo:"<<temp->nombreArchivo<<endl;
            temp = temp->siguiente;
        }

    }
}

void ListaSimple::insertarDatosMatriz(string datMatriz,nodoLista *&nuevo){
    ifstream file(datMatriz);
    if(!file.is_open()) cout<<"Error: Archivo no abierto"<<'\n';
    string RGB;
    string RGBU;
    int c=0;
    int fi=0;
    while(file.good()){
       getline(file,RGBU,'\n');
       stringstream s(RGBU);
       c=0;
       while(getline(s,RGB,',')){
        if(RGB!="x"&&RGB!=" "&&RGB!="\n"){
           nuevo->capa.insertarNodo(fi,c,RGB);
        }
        c++;
       }
       fi++;
       cout<<"--------------"<<endl;
    }
    file.close();
    string nomArchivo = "capa"+intToString(nuevo->numeroCapa);
    nuevo->capa.escribirDot(nomArchivo);
}

string ListaSimple::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}
