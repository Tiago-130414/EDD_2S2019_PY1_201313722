#include "leerArchivo.h"
#include <iostream>
#include <fstream>
#
using namespace std;
leerArchivo::leerArchivo()
{
    //ctor
}

void leerArchivo::leer(string archivo)
{
    ifstream file(archivo);
    if(!file.is_open()) cout<<"Error: Archivo abierto"<<'\n';
    string layer;
    string nameFile;
    while(file.good()){
        layer="";
        nameFile="";
        getline(file,layer,';');
        getline(file,nameFile,'\n');
        if(layer!=" "&&layer!="\n"&&layer!=""){
            cout<<"Numero de capa:"<<layer<<"\n"<<endl;
        }
        if(nameFile!=" "&&nameFile!="\n"&&nameFile!=""){
            cout<<"Nombre de archivo: "<<nameFile<<"\n"<<endl;
        }
    }
    file.close();
}
