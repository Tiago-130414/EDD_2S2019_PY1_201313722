#include "ListaDobleLN.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
ListaDobleLN::ListaDobleLN()
{
    //ctor
}

bool ListaDobleLN::estaVacia(ListaDobleLN *&primero)
{
 return (primero==NULL)? true:false;
}

ListaDobleLN* ListaDobleLN::crearNodo(int posX,int posY,string color)
{
   ListaDobleLN *nuevo_nodo = new ListaDobleLN();
   nuevo_nodo->posicionX = posX;
   nuevo_nodo->posicionY = posY;
   nuevo_nodo->colorRGB = color;
   nuevo_nodo->siguiente = NULL;
   nuevo_nodo->anterior =NULL;
   return nuevo_nodo;
}

void ListaDobleLN::insertarNodo(int pX,int pY,string co,ListaDobleLN *&primero)
{
    ListaDobleLN *nuevo = crearNodo(pX,pY,co);
    if(estaVacia(primero))
    {
        primero = nuevo;
        cout<<"insertado al inicio"<<endl;
    }else
    {
        ListaDobleLN *temp = primero;
        while(temp->siguiente!=NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente= nuevo;
        nuevo->anterior = temp;
        cout<<"insertado al final"<<endl;
    }
}

void ListaDobleLN::mostrar(ListaDobleLN *&primero)
{
    if(estaVacia(primero)){
        cout<<"esta vacia"<<endl;
    }else{
        ListaDobleLN *temp = primero;
        while(temp!=NULL){
            cout<<temp->colorRGB<<endl;
            temp = temp->siguiente;
        }
    }
}

void ListaDobleLN::graficaLista(ListaDobleLN *&primero){
    string cad2;
    string cad4;
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaD.dot",ios::out);
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
    cad2 = defineNodos(primero);
    cad4 = apuntarNodos(primero);
    archivo<<"\n";
    archivo<<cad2<<endl;
    archivo<<"\n";
    archivo<<cad4<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"Linealizacion Por:\";\n\n"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaD.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaD.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\listaD.png");
}

string ListaDobleLN::defineNodos(ListaDobleLN *&primero)
{
    string cad="";
    ListaDobleLN *temp = primero;
    while(temp!=NULL){
         cad += "\tNodo"+temp->colorRGB+"X"+intToString(temp->posicionX)+"Y"+intToString(temp->posicionY)+"[label=\"{("+intToString(temp->posicionX)+","+intToString(temp->posicionY)+")"+temp->colorRGB+"}\"];\n";
         temp = temp->siguiente;
    }
    return cad;
}


string ListaDobleLN::apuntarNodos(ListaDobleLN *&primero)
{
    string cad="";
    ListaDobleLN *temp = primero;
    while(temp->siguiente!=NULL){
        cad += "\tNodo"+temp->colorRGB+"X"+intToString(temp->posicionX)+"Y"+intToString(temp->posicionY)+"->"+"Nodo"+temp->siguiente->colorRGB+"X"+intToString(temp->siguiente->posicionX)+"Y"+intToString(temp->siguiente->posicionY)+";\n";
        temp = temp->siguiente;
    }
    return cad;
}


string ListaDobleLN::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}
