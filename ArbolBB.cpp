#include "ArbolBB.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
string cad="";
string cad3="";
string cadInO="";
string apIno="\t";

ArbolBB::ArbolBB()
{
    //ctor
}

bool ArbolBB::estaVacio(ArbolBB *&raiz)
{
    return (raiz==NULL)? true:false;
}

ArbolBB* ArbolBB::crearNodo(string imagen,string rutaArchivo,string rutaSinArchivo)
{
    ArbolBB *nuevo_nodo = new ArbolBB();
    nuevo_nodo->nombreIMG = imagen;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL;
    leerArchivoCapas(rutaArchivo,nuevo_nodo,rutaSinArchivo,imagen);
    return nuevo_nodo;
}

void ArbolBB::insertarNodo(ArbolBB *&raiz,string imagen,string rutaArchivoCSV,string rutaSinAr){
    if(raiz==NULL){
        ArbolBB *nuevo = crearNodo(imagen,rutaArchivoCSV,rutaSinAr);
        raiz = nuevo;
    }else{
        string r = raiz->nombreIMG;
        if(imagen<r){
            insertarNodo(raiz->izquierda,imagen,rutaArchivoCSV,rutaSinAr);
        }else{
            insertarNodo(raiz->derecha,imagen,rutaArchivoCSV,rutaSinAr);
        }
    }
}

///insercion de datos en estructuras mediante archivos csv

void ArbolBB::leerArchivoCapas(string archivo,ArbolBB *&nuevo,string rutaTemp,string nombreImagen){
    ifstream file(archivo.c_str());
    if(!file.is_open()) cout<<"Error: Archivo abierto"<<'\n';
    string layer;
    string nameFile;
    while(file.good()){
        layer="";
        nameFile="";
        getline(file,layer,',');
        getline(file,nameFile,'\n');
            if(layer!=" "&&layer!="\n"&&layer!=""){
                if(nameFile!=" "&&nameFile!="\n"&&nameFile!=""){
                    if(nameFile!="File"&&layer!="Layer"){
                            //aqui me quede
                        nuevo->cubo.insertarCapa(stringToInt(layer),nameFile,rutaTemp,nombreImagen);
                    }
                }
            }
    }
    file.close();
}

////////////BUSCAR NODO EN ARBOL
ArbolBB* ArbolBB::buscar(ArbolBB *&raiz, string key)
{
   if(estaVacio(raiz)){
        return NULL;
   }else if(raiz->nombreIMG==key){
        return raiz;
   }else if(key<raiz->nombreIMG){
        return buscar(raiz->izquierda,key);
   }else{
        return buscar(raiz->derecha,key);
   }
}
////////////RECORRIDOS ARBOL
void ArbolBB::recorridoPre(ArbolBB *&raiz)
{
    if(estaVacio(raiz))
    {
        return;

    }else
    {
        cout<<raiz->nombreIMG<<"-";
        recorridoPre(raiz->izquierda);
        recorridoPre(raiz->derecha);
    }
}

void ArbolBB::recorridoInO(ArbolBB *&raiz)
{
    if(estaVacio(raiz))
    {
        return;
    }else
    {
        recorridoInO(raiz->izquierda);
        cout<<raiz->nombreIMG<<endl;;
        recorridoInO(raiz->derecha);
    }

}

void ArbolBB::recorridoPost(ArbolBB *&raiz)
{
    if(estaVacio(raiz))
    {
        return;

    }else
    {
        recorridoPost(raiz->izquierda);
        recorridoPost(raiz->derecha);
        cout<<raiz->nombreIMG<<"-";

    }

}

ArbolBB* ArbolBB::eliminarNodo(ArbolBB *&raiz,string elimina)
{
    if(estaVacio(raiz)){
        return raiz;
    }
    if(raiz->nombreIMG>elimina)
    {
       raiz->izquierda=eliminarNodo(raiz->izquierda,elimina);
       return raiz;
    }
    else if(raiz->nombreIMG<elimina)
    {
        raiz->derecha = eliminarNodo(raiz->derecha,elimina);
        return raiz;
    }

    if(raiz->izquierda==NULL)
    {
        ArbolBB *temp = raiz->derecha;
        delete raiz;
        return temp;
    }
    else if(raiz->derecha==NULL)
    {
        ArbolBB *temp = raiz->izquierda;
        delete raiz;
        return temp;
    }
    else{
        ArbolBB *scc = raiz->derecha;
        ArbolBB *temp = raiz->derecha;
        while(temp->izquierda!=NULL){
            scc = temp;
            temp = temp->izquierda;
        }

        scc->izquierda = temp->derecha;
        raiz->nombreIMG = temp->nombreIMG;
        delete temp;
        return raiz;
    }
}

///////////GRAFICA GENERAL DE ARBOL
void ArbolBB::graficarArbol(ArbolBB *&raiz)
{

    string cad2;
    string cad4;
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbol.dot",ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph arbol\n{"<<endl;
    archivo<<"\trankdir=TB;"<<endl;
    archivo<<"\tordering=out;";
    archivo<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivo<<"\tsubgraph cluster_0{"<<endl;
    archivo<<"\tstyle=filled;"<<endl;
    archivo<<"\tcolor=lightgrey;"<<endl;
    archivo<<"\tlabelloc=t;"<<endl;
    archivo<<"\tnode [shape = record, style=\"rounded,filled\", fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cad2 = listadoNodos(raiz);
    cad4 = apuntadores(raiz);
    archivo<<"\n";
    archivo<<cad2<<endl;
    archivo<<"\n";
    archivo<<cad4<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"Arbol Binario De Busqueda\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbol.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbol.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbol.png");
    limpiarCadenas();
}

string ArbolBB::listadoNodos(ArbolBB *&raiz)
{
    if(estaVacio(raiz))
    {
        return cad;
    }else
    {
        listadoNodos(raiz->izquierda);
        cad+= "\tNodo"+raiz->nombreIMG+"[label=\"<izquierda>|"+raiz->nombreIMG+"|<derecha>\"];\n";
        listadoNodos(raiz->derecha);
    }
    return cad;
}

string ArbolBB::apuntadores(ArbolBB *raiz)
{
      if(estaVacio(raiz))
    {
        return cad3;
    }else
    {

        apuntadores(raiz->izquierda);
        if(raiz->izquierda!=nullptr){
        cad3 += "\tNodo"+raiz->nombreIMG+":izquierda->Nodo"+raiz->izquierda->nombreIMG+";\n";
        }

        if(raiz->derecha!=nullptr){
        cad3 += "\tNodo"+raiz->nombreIMG+":derecha->Nodo"+raiz->derecha->nombreIMG+";\n";
         }
        apuntadores(raiz->derecha);

    }
    return cad3;
}


///////////GRAFICA RECORRIDO INORDEN
void ArbolBB::graficaLista(ArbolBB *&raiz){
    string cad5="";
    string cad6="";
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolIno.dot",ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph arbol\n{"<<endl;
    archivo<<"\trankdir=LR;"<<endl;
    archivo<<"\tordering=out;";
    archivo<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivo<<"\tsubgraph cluster_0{"<<endl;
    archivo<<"\tstyle=filled;"<<endl;
    archivo<<"\tcolor=lightgrey;"<<endl;
    archivo<<"\tlabelloc=t;"<<endl;
    archivo<<"\tnode [shape = rectangle, style=\"rounded,filled\", fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    archivo<<"\n";
    cad5=listadoNodosInorder(raiz);
    cad6 = apuntadoresInorder(raiz);
    cad6 = limpiarEspaciosBlanco(cad6);
    cad6 = eliminarUltimaFlecha(cad6);
    cad6 +=";";
    archivo<<cad5<<endl;
    archivo<<"\n";
    archivo<<cad6<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"InOrder Traversal\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolIno.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolIno.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolIno.png");
    limpiarCadenas();
}

string ArbolBB::listadoNodosInorder(ArbolBB *raiz){
    if(estaVacio(raiz))
    {
        return cadInO;
    }else
    {
        listadoNodosInorder(raiz->izquierda);
        cadInO+= "\tNodo"+raiz->nombreIMG+"[label=\""+raiz->nombreIMG+"\"];\n";
        listadoNodosInorder(raiz->derecha);
    }
    return cadInO;
}

string ArbolBB::apuntadoresInorder(ArbolBB *raiz){
     if(estaVacio(raiz))
    {
        return apIno;
    }else
    {

        apuntadoresInorder(raiz->izquierda);
        apIno += "Nodo"+raiz->nombreIMG+"->";
        apuntadoresInorder(raiz->derecha);

    }
    return apIno;
}

//////////GRAFICA RECORRIDO POSTORDER
void ArbolBB::graficaListaPostOrden(ArbolBB *raiz){
    string cad5="";
    string cad6="";
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPost.dot",ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph arbol\n{"<<endl;
    archivo<<"\trankdir=LR;"<<endl;
    archivo<<"\tordering=out;";
    archivo<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivo<<"\tsubgraph cluster_0{"<<endl;
    archivo<<"\tstyle=filled;"<<endl;
    archivo<<"\tcolor=lightgrey;"<<endl;
    archivo<<"\tlabelloc=t;"<<endl;
    archivo<<"\tnode [shape = rectangle, style=\"rounded,filled\", fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    archivo<<"\n";
    cad5=listadoNodosPostorder(raiz);
    cad6 = apuntadorNodosPostorder(raiz);
    cad6 = limpiarEspaciosBlanco(cad6);
    cad6 = eliminarUltimaFlecha(cad6);
    cad6 +=";";
    archivo<<cad5<<endl;
    archivo<<"\n";
    archivo<<cad6<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"PostOrder Traversal\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPost.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPost.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPost.png");
    limpiarCadenas();

}

string ArbolBB::listadoNodosPostorder(ArbolBB *raiz){
    if(estaVacio(raiz))
    {
        return cadInO;

    }else
    {
        listadoNodosPostorder(raiz->izquierda);
        listadoNodosPostorder(raiz->derecha);
        cadInO+= "\tNodo"+raiz->nombreIMG+"[label=\""+raiz->nombreIMG+"\"];\n";
    }
    return cadInO;
}

string ArbolBB::apuntadorNodosPostorder(ArbolBB *raiz){
    if(estaVacio(raiz))
    {
        return apIno;

    }else
    {
        apuntadorNodosPostorder(raiz->izquierda);
        apuntadorNodosPostorder(raiz->derecha);
        apIno += "Nodo"+raiz->nombreIMG+"->";
    }
    return apIno;
}

//////////GRAFICA RECORRIDO PREORDER
void ArbolBB::graficaListaPreOrden(ArbolBB *raiz){
  string cad5="";
    string cad6="";
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPre.dot",ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph arbol\n{"<<endl;
    archivo<<"\trankdir=LR;"<<endl;
    archivo<<"\tordering=out;";
    archivo<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivo<<"\tsubgraph cluster_0{"<<endl;
    archivo<<"\tstyle=filled;"<<endl;
    archivo<<"\tcolor=lightgrey;"<<endl;
    archivo<<"\tlabelloc=t;"<<endl;
    archivo<<"\tnode [shape = rectangle, style=\"rounded,filled\", fillcolor=\"pink:red\",width=0.7,height=0.5];"<<endl;
    archivo<<"\n";
    cad5=listadoNodosPreorder(raiz);
    cad6 = apuntadorNodosPreorder(raiz);
    cad6 = limpiarEspaciosBlanco(cad6);
    cad6 = eliminarUltimaFlecha(cad6);
    cad6 +=";";
    archivo<<cad5<<endl;
    archivo<<"\n";
    archivo<<cad6<<endl;
    archivo<<"\n";
    archivo<<"\tlabel=\"PreOrder Traversal\";"<<endl;
    archivo<<"\t}"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
    system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPre.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPre.png -Tpng -Gcharset=utf8");
    system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\arbolPre.png");
    limpiarCadenas();
}

string ArbolBB::listadoNodosPreorder(ArbolBB *raiz){
     if(estaVacio(raiz))
    {
        return cadInO;

    }else
    {
        cadInO+= "\tNodo"+raiz->nombreIMG+"[label=\""+raiz->nombreIMG+"\"];\n";
        listadoNodosPreorder(raiz->izquierda);
        listadoNodosPreorder(raiz->derecha);
    }
    return cadInO;
}

string ArbolBB::apuntadorNodosPreorder(ArbolBB *raiz){
    if(estaVacio(raiz))
    {
        return apIno;

    }else
    {
        apIno += "Nodo"+raiz->nombreIMG+"->";
        apuntadorNodosPreorder(raiz->izquierda);
        apuntadorNodosPreorder(raiz->derecha);
    }
    return apIno;
}

//////////METODOS STRING
void ArbolBB::limpiarCadenas(){
    cad = "";
    cad3= "";
    apIno = "\t";
    cadInO="";
}

string ArbolBB::eliminarUltimaFlecha(string c){
    int tam = c.length();
    c= c.erase(tam-2);
    return c;
}

string ArbolBB::limpiarEspaciosBlanco(string c){
 string out ="";
 string in =c;
 for(int i = 0; i < in.length(); i++) {
        if(in[i] == ' ') {
            continue;
        } else {
             out+= in[i];
        }
    }
    return out;
}

int ArbolBB::stringToInt(string n){
    stringstream cast(n);
    int x =0;
    cast>>x;
    return x;
}
