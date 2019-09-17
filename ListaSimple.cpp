#include "ListaSimple.h"
#include <string>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>
#include <direct.h>
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
///funciones lista
bool ListaSimple::estaVacia(){
    return (primero==NULL)? true:false;
}

void ListaSimple::insertarCapa(int capa,string nom,string temp,string nombreImagen)
{
    string ruta = string(temp)+string(nom);
    nodoLista *nuevo = new nodoLista();
    nuevo->nombreArchivo = nom;
    nuevo->numeroCapa = capa;
    nuevo->rutaSinArchivo = temp;
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

///funciones reportes
string ListaSimple::retornarRutaPrimero(){
    string rut;
    if(estaVacia()){
        cout<<"esta vacia"<<endl;
    }else{
        nodoLista *temp = primero;
        rut = temp->rutaSinArchivo.c_str();
    }
    return rut;
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

///Generar Imagen
void ListaSimple::generarHTML(string nomImg){
    string nomHtml = nomImg+".html";
    string rt="C:/EXPORT/";
    rt= string(rt) + string(nomImg);
    rt = rt +"/";
    rt = string(rt) + string (nomHtml);
    string divHTML="";
    int width=0;
    int height=0;
    ofstream archivo;
    archivo.open(rt.c_str(),ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"<!DOCTYPE html>\n"<<endl;
    archivo<<"<html>"<<endl;
    archivo<<"<head>\n"<<endl;
    archivo<<"   <link rel=\"stylesheet\" href=\""+nomImg+".css\">\n"<<endl;
    archivo<<"</head>"<<endl;
    archivo<<"<body>\n"<<endl;
    archivo<<"<div class=\"canvas\">\n"<<endl;
    string ruta= string(retornarRutaPrimero())+string("config.csv");
    height = leerInicialIH(ruta.c_str());
    width = leerInicialIW(ruta.c_str());
    divHTML = escribirDivHTML(width,height);
    archivo<<divHTML<<endl;
    archivo<<"</div>\n"<<endl;
    archivo<<"</body>"<<endl;
    archivo<<"</html>"<<endl;
    archivo.close();
}

void ListaSimple::generarCss(string nomImg){
    string divS="";
    string nomCSS = nomImg+".css";
    string rt="C:/EXPORT/";
    rt= string(rt) + string(nomImg);
    mkdir(rt.c_str());
    rt += "/"+nomCSS;
    ofstream archivo;
    archivo.open(rt.c_str(),ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"body{"<<endl;
    archivo<<"background: #333333;"<<endl;
    archivo<<"height: 100vh;"<<endl;
    archivo<<"display: flex;"<<endl;
    archivo<<"justify-content: center;"<<endl;
    archivo<<"align-items: center;"<<endl;
    archivo<<"}\n\n"<<endl;
    string ruta= string(retornarRutaPrimero())+string("config.csv");
    archivo<<leerArchivoConfig(ruta.c_str())<<endl;
    divS = divCSS();
    archivo<<divS<<endl;
    archivo.close();
}


string ListaSimple::divCSS(){
    string div = "";
    nodoLista *temp = primero;
    while(temp!=NULL){
        div += temp->capa.LinMF();
        temp = temp->siguiente;
    }
    return div;
}


string ListaSimple::leerArchivoConfig(string archivo){
    string c="";
    ifstream file(archivo);
    if(!file.is_open()) cout<<"Error: Archivo no abierto"<<'\n';
    string config;
    string value;
    int imageW=0;
    int imageH=0;
    int pixelW=0;
    int pixelH=0;
    int canvasW=0;
    int canvasH=0;
    while(file.good()){
        config="";
        value="";
        getline(file,config,',');
        getline(file,value,'\n');
        if(config =="image_width"){
            imageW = stringToInt(value);
        }else if(config=="image_height"){
            imageH = stringToInt(value);
        }else if(config=="pixel_width"){
            pixelW = stringToInt(value);
        }else if(config=="pixel_height"){
            pixelH = stringToInt(value);
        }
    }
    file.close();
    canvasW = multiply(imageW,pixelW);
    canvasH = multiply(imageH,pixelH);
    c += ".canvas {\n";
    c += "width:"+ intToString(canvasH)+"px;\n";
    c += "height:"+intToString(canvasW)+"px;\n";
    c += "}\n\n";
    c += ".pixel {\n";
    c += "width:"+intToString(pixelW)+"px;\n";
    c += "height:"+intToString(pixelH)+"px;\n";
    c += "float: left;\n";
    c +="}\n\n";
    return c;
}

int ListaSimple::leerInicialIW(string archivo){
    string c="";
    ifstream file(archivo);
    if(!file.is_open()) cout<<"Error: Archivo no abierto"<<'\n';
    string config;
    string value;
    int imageW=0;
    while(file.good()){
        config="";
        value="";
        getline(file,config,',');
        getline(file,value,'\n');
        if(config =="image_width"){
            imageW = stringToInt(value);
        }
    }
    file.close();

    return imageW;
}
int ListaSimple::leerInicialIH(string archivo){
    string c="";
    ifstream file(archivo);
    if(!file.is_open()) cout<<"Error: Archivo no abierto"<<'\n';
    string config;
    string value;
    int imageH=0;
    while(file.good()){
        config="";
        value="";
        getline(file,config,',');
        getline(file,value,'\n');
        if(config=="image_height"){
            imageH = stringToInt(value);
        }
    }
    file.close();

    return imageH;
}


string ListaSimple::escribirDivHTML(int imageW,int imageH){
    string div ="";
    int cantidadD =0;
    cantidadD = multiply(imageW,imageH);
    for(int i=0;i<cantidadD;i++){
        div += "    <div class=\"pixel\"></div>\n";
    }
    return div;
}


int ListaSimple::stringToInt(string s)
{
    stringstream cast(s);
    int x = 0;
    cast >> x;
    return x;
}

int ListaSimple::multiply(int x,int y){
    int multiplication=0;
    multiplication = x*y;
    return multiplication;
}
