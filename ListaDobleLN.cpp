#include "ListaDobleLN.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
nodoListaDobleLN::nodoListaDobleLN()
{
    siguiente=NULL;
    anterior=NULL;
}
ListaDobleLN::ListaDobleLN()
{
    //ctor
    primero = NULL;
}

bool ListaDobleLN::estaVacia()
{
    return (primero==NULL)? true:false;
}

nodoListaDobleLN* ListaDobleLN::crearNodo(int posX,int posY,string color)
{
    nodoListaDobleLN *nuevo_nodo = new nodoListaDobleLN();
    nuevo_nodo->posicionX = posX;
    nuevo_nodo->posicionY = posY;
    nuevo_nodo->colorRGB = color;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior =NULL;
    return nuevo_nodo;
}

void ListaDobleLN::insertarNodo(int pX,int pY,string co)
{
    nodoListaDobleLN *nuevo = crearNodo(pX,pY,co);
    if(estaVacia())
    {
        primero = nuevo;
    }
    else
    {
        nodoListaDobleLN *temp = primero;
        while(temp->siguiente!=NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente= nuevo;
        nuevo->anterior = temp;
    }
}

void ListaDobleLN::mostrar()
{
    if(estaVacia())
    {
        cout<<"esta vacia"<<endl;
    }
    else
    {
        nodoListaDobleLN *temp = primero;
        while(temp!=NULL)
        {
            cout<<temp->colorRGB<<endl;
            temp = temp->siguiente;
        }
    }
}

void ListaDobleLN::graficaLista(string nomGrafica, string tipoLN)
{
    string crearDot = "C:/GRAFICAS_PROYECTO/"+nomGrafica+".dot";
    string compilarDot;
    string abrirDot;
    string cad2;
    string cad4;
    string tipL = "\tlabel=\"Linealizacion Por:"+tipoLN+"\";\n\n";
    ofstream archivo;
    archivo.open(crearDot.c_str(),ios::out);
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
    archivo<<"\tnode [shape = record, style=\"filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cad2 = defineNodos();
    cad4 = apuntarNodos();
    archivo<<"\n";
    archivo<<cad2<<endl;
    archivo<<"\n";
    archivo<<cad4<<endl;
    archivo<<"\n";
    archivo<<tipL.c_str()<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    compilarDot = "dot C:/GRAFICAS_PROYECTO/"+nomGrafica+".dot -o C:/GRAFICAS_PROYECTO/"+nomGrafica+".png -Tpng -Gcharset=utf8";
    system(compilarDot.c_str());
    abrirDot ="C:/GRAFICAS_PROYECTO/"+nomGrafica+".png";
    system(abrirDot.c_str());
}

string ListaDobleLN::defineNodos()
{
    string cad="";
    if(estaVacia())
    {
        cout<<"No fue posible linealizar"<<endl;
    }
    else
    {
        nodoListaDobleLN *temp = primero;
        while(temp!=NULL)
        {
            cad += "\tNodoX"+intToString(temp->posicionX)+"Y"+intToString(temp->posicionY)+"[label=\"{("+intToString(temp->posicionX)+","+intToString(temp->posicionY)+")"+temp->colorRGB+"}\"];\n";
            temp = temp->siguiente;
        }
    }
    return cad;
}


string ListaDobleLN::apuntarNodos()
{
    string cad="";
    if(estaVacia())
    {
        cout<<"no fue posible linealizar"<<endl;
    }
    else
    {
        nodoListaDobleLN *temp = primero;
        while(temp->siguiente!=NULL)
        {
            cad += "\tNodoX"+intToString(temp->posicionX)+"Y"+intToString(temp->posicionY)+"->"+"Nodo"+"X"+intToString(temp->siguiente->posicionX)+"Y"+intToString(temp->siguiente->posicionY)+";\n";
            temp = temp->siguiente;
        }
    }
    return cad;
}


string ListaDobleLN::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}
