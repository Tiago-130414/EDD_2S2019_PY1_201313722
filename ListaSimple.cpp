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

void ListaSimple::insertarCapa(int capa,string nom,string temp,string nombreImagen)
{
    string ruta = string(temp)+string(nom);
    nodoLista *nuevo = new nodoLista();
    nuevo->nombreArchivo = nom;
    nuevo->numeroCapa = capa;
    if(nom!="config.csv"){
        insertarDatosMatriz(ruta.c_str(),nuevo,nombreImagen);
    }
    if(estaVacia()){
        primero = nuevo;
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

void ListaSimple::insertarDatosMatriz(string datMatriz,nodoLista *&nuevo,string nombreImagen){
    ifstream file(datMatriz.c_str());
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
    }
    file.close();
    //////////////servira para graficar matriz x capa
    string nomArchivo = nombreImagen+"capa"+intToString(nuevo->numeroCapa);
    nuevo->capa.escribirDot(nomArchivo.c_str());
}

string ListaSimple::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}
