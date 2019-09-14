#include "Matriz.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>
#include "ListaDobleLN.h"
using namespace std;
ListaDobleLN linealizarF;
ListaDobleLN linealizarC;
NodoFC::NodoFC(int fil,int col,string co)
{
    //ctor
    fila = fil;
    columna = col;
    color =co;
    siguiente = NULL;
    anterior = NULL;
    arriba = NULL;
    abajo = NULL;
}

Matriz::Matriz()
{
    //ctor
    columnas = NULL;
    filas = NULL;
}
///insertar valores en matriz
void Matriz::insertarNodo(int fil,int col,string co)
{
    NodoFC *nuevoCol = new NodoFC(0,col,"Columna ");
    enlazarColumna(columnas,nuevoCol,col);
    NodoFC *nuevoFil = new NodoFC(fil,0,"Fila ");
    enlazarFila(filas,nuevoFil,fil);
    NodoFC *nuevo = new NodoFC(fil,col,co);
    enlazarColumna(nuevoFil->siguiente,nuevo,col);
    enlazarFila(nuevoCol->abajo,nuevo,fil);
}

void Matriz::enlazarColumna(NodoFC *&pivote,NodoFC *&nuevoCol,int columna)
{
    NodoFC *temporalColumnas = pivote;
    if(pivote==NULL)
    {
        pivote= nuevoCol;
    }
    else
    {
        ///temporal columnas es donde se coloca el dato nuevo
        while((temporalColumnas!=NULL)&&(temporalColumnas->siguiente!=NULL)&&(temporalColumnas->siguiente->columna<=columna))
        {
            temporalColumnas = temporalColumnas->siguiente;
        }
        if(temporalColumnas->columna<columna)
        {
            if(temporalColumnas->siguiente==NULL)
            {
                temporalColumnas->siguiente = nuevoCol;
                nuevoCol->anterior = temporalColumnas;
            }
            else
            {
                //nodo temporal
                NodoFC *tempSig = temporalColumnas->siguiente;
                //insertando y cambiando punteros
                nuevoCol->siguiente = temporalColumnas->siguiente;
                nuevoCol->anterior =temporalColumnas->anterior;
                temporalColumnas->siguiente = nuevoCol;
                tempSig->anterior = nuevoCol;
            }
        }
        else if(temporalColumnas->columna>columna)
        {
            nuevoCol->siguiente = temporalColumnas;
            temporalColumnas->anterior = nuevoCol;
            pivote = nuevoCol;
        }
        else
        {
            nuevoCol = temporalColumnas;

        }
    }
}

void Matriz::enlazarFila(NodoFC *&pivote,NodoFC *&nuevoFil,int fila)
{
    NodoFC *temporalFilas= pivote;
    if(pivote==NULL)
    {
        pivote = nuevoFil;
    }
    else
    {
        ///temporal columnas es donde se coloca el dato nuevo

        while((temporalFilas!=NULL)&&(temporalFilas->abajo!=NULL)&&(temporalFilas->abajo->fila<=fila))
        {
            temporalFilas = temporalFilas->abajo;
        }
        if(temporalFilas->fila<fila)
        {
            if(temporalFilas->abajo==NULL)
            {
                temporalFilas->abajo = nuevoFil;
                nuevoFil->arriba = temporalFilas;
            }
            else
            {
                //nodo temporal
                NodoFC *tempSig = temporalFilas->abajo;
                //insertando y cambiando punteros
                nuevoFil->abajo = temporalFilas->abajo;
                nuevoFil->arriba =temporalFilas->arriba;
                temporalFilas->abajo = nuevoFil;
                tempSig->arriba = nuevoFil;
            }
        }
        else if(temporalFilas->fila>fila)
        {
            nuevoFil->abajo = temporalFilas;
            temporalFilas->arriba = nuevoFil;
            pivote = nuevoFil;
        }
        else
        {
            nuevoFil = temporalFilas;
        }
    }
}
///mostrar matriz en consola
void Matriz::imprimir()
{
    NodoFC *tempoF = filas;
    NodoFC *tempoC = columnas;
    while(tempoC!=NULL)
    {
        //cout<<tempoC->color<<"-Fila: "<<tempoC->fila<<"-Columna: "<<tempoC->columna<<endl;
        NodoFC *tempInterior = tempoC->abajo;
        while(tempInterior!=NULL)
        {
            cout<<"-Fila: "<<tempInterior->fila<<"Columna: "<<tempInterior->columna<<"color: "<<tempInterior->color<<endl;
            tempInterior = tempInterior->abajo;
        }
        tempoC = tempoC->siguiente;
    }
}

///generar grafica de matriz
void Matriz::escribirDot(string nomImg)
{
    string arrCad = nomImg+".dot";
    string compilarDot;
    string abrirImagen;
    ofstream archivo;
    archivo.open("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\"+arrCad,ios::out);
    if(archivo.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivo<<"digraph G {\ngraph [ranksep=\"0.5\", nodesep=\"0.5\"];\n"<<endl;
    archivo<<"Matriz[width = 1.0 group = \"Mt0\",  style=filled,shape=\"underline\",fillcolor=\"yellow:blue\" label=\"Matriz\"];\n"<<endl;
    archivo<<creandoNodosFilaGuia()<<endl;
    archivo<<creandoNodosColumnaGuia()<<endl;
    archivo<<nodosContenidoFila()<<endl;
    archivo<<rankSame()<<endl;
    archivo<<enlazarColumnaConNodo()<<endl;
    archivo<<enlazarNodosMediosColumna()<<endl;
    archivo<<"\n"<<endl;
    archivo<<"\n}"<<endl;
    archivo.close();
    compilarDot = "dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\"+nomImg+".dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\"+nomImg+".png -Tpng -Gcharset=utf8";
    system(compilarDot.c_str());
    abrirImagen ="C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\"+nomImg+".png";
    system(abrirImagen.c_str());
    //system("dot C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\grafica.dot -o C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\grafica.png -Tpng -Gcharset=utf8");
    //system("C:\\Users\\santi\\OneDrive\\Desktop\\EDD_2S2019_PY1_201313722\\grafica.png");
}


string Matriz::creandoNodosFilaGuia()
{
    NodoFC *filaG = filas;
    string cad="";
    while(filaG!=NULL)
    {

        cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->fila))->str();
        cad+="[label=\"";
        cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->fila))->str()+"\"";
        cad+="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"yellow\", group = Mt0] ;\n";

        filaG=filaG->abajo;
    }
    filaG=filas;

    while(filaG!=NULL)
    {
        if(filaG->abajo!=NULL)
        {
            cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->fila))->str();
            cad+="->";
            cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->abajo->fila))->str();
            cad+=";\n";
            cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->abajo->fila))->str();
            cad+="->";
            cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filaG->fila))->str();
            cad+=";\n";
        }

        filaG = filaG->abajo;
    }

    return cad;
}

string Matriz::creandoNodosColumnaGuia()
{

    NodoFC *columnaG = columnas;
    string cad="";
    string primF="";
    string primC="";
    primC = "C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnas->columna))->str();
    primF = "F"+static_cast<std::ostringstream*>(&(std::ostringstream() << filas->fila))->str();
    while(columnaG!=NULL)
    {

        cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str();
        cad+="[label=\"";
        cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str()+"\"";
        cad+="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"yellow\", group =";
        cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str()+"] ;\n";

        columnaG = columnaG->siguiente;
    }
    columnaG = columnas;
    while(columnaG!=NULL)
    {
        if(columnaG->siguiente!=NULL)
        {
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str();
            cad+="->";
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->siguiente->columna))->str();
            cad+=";\n";
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->siguiente->columna))->str();
            cad+="->";
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str();
            cad+=";\n";
        }
        columnaG = columnaG->siguiente;
    }

    columnaG = columnas;
    cad+="{rank = same; Matriz;";
    while(columnaG!=NULL)
    {
        cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << columnaG->columna))->str();
        if(columnaG->siguiente!=NULL)
        {
            cad+=";";
        }
        columnaG = columnaG->siguiente;
    }
    cad+="}\n";
    cad+="Matriz ->"+primC+";\n";
    cad+="Matriz ->"+primF+";\n";
    return cad;

}

string Matriz::nodosContenidoFila()
{
    string cad="";
    NodoFC *filCont = filas;//baja
    NodoFC *enlace = filas;//hacer enlaces fila guia primer nodo
    NodoFC *aux;//verificar si hay nodos despues del primero
    NodoFC *primero;
    while(filCont!=NULL)
    {
        if(filCont->siguiente!=NULL)
        {
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << filCont->siguiente->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << filCont->siguiente->columna))->str();
            cad+="[label=\"";
            cad+=filCont->siguiente->color+"\"";
            cad+="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"yellow\", group =";
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << filCont->siguiente->columna))->str()+"] ;\n";
        }

        filCont=filCont->abajo;
    }

    while(enlace!=NULL)
    {
        if(enlace->siguiente!=NULL)
        {
            cad+="F" + static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->fila))->str();
            cad+="->";
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->siguiente->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->siguiente->columna))->str();
            cad+="[constraint = false];\n";
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->siguiente->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->siguiente->columna))->str();
            cad+="->";
            cad+="F" + static_cast<std::ostringstream*>(&(std::ostringstream() << enlace->fila))->str();
            cad+="[constraint = false];\n";
        }
        enlace = enlace->abajo;
    }

    enlace = filas;

    while(enlace!=NULL)
    {
        if(enlace->siguiente->siguiente!=NULL)
        {
            primero = enlace->siguiente->siguiente;
            while(primero!=NULL)
            {
                cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->fila))->str();
                cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str();
                cad+="[label=\"";
                cad+=primero->color+"\"";
                cad+="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"yellow\", group =";
                cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str()+"] ;\n";
                primero = primero->siguiente;
            }
        }
        enlace= enlace->abajo;
    }
    enlace = filas;
    while(enlace!=NULL)
    {
        if(enlace->siguiente!=NULL)
        {
            primero = enlace->siguiente;
            while(primero!=NULL)
            {
                if(primero->siguiente!=NULL)
                {
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str();
                    cad+="->";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->siguiente->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->siguiente->columna))->str();
                    cad+="[constraint = false];\n";
                    cad+="\n";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->siguiente->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->siguiente->columna))->str();
                    cad+="->";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str();
                    cad+="[constraint = false];\n";
                }
                primero = primero->siguiente;
            }
        }
        enlace = enlace->abajo;
    }

    return cad;
}

string Matriz::rankSame()
{
    NodoFC* tempFBaja = filas;
    NodoFC* tempFDerecha;
    string cad="";
    while(tempFBaja!=NULL)
    {
        cad+="{rank = same;";
        cad+="F"+static_cast<std::ostringstream*>(&(std::ostringstream() << tempFBaja->fila))->str()+";";
        tempFDerecha = tempFBaja->siguiente;
        while(tempFDerecha!=NULL)
        {
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << tempFDerecha->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << tempFDerecha->columna))->str();
            cad+=";";

            tempFDerecha = tempFDerecha->siguiente;
        }
        cad+="}\n";

        tempFBaja =tempFBaja->abajo;

    }
    return cad;
}

string Matriz::enlazarColumnaConNodo()
{
    NodoFC *auxColNod=columnas;//mueve derecha

    string cad="";
    while(auxColNod!=NULL)
    {
        if(auxColNod->abajo!=NULL)
        {
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->columna))->str();
            cad+="->";
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->abajo->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->abajo->columna))->str();
            cad+=";\n";
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->abajo->fila))->str();
            cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->abajo->columna))->str();
            cad+="->";
            cad+="C"+static_cast<std::ostringstream*>(&(std::ostringstream() << auxColNod->columna))->str();
            cad+=";\n";
        }
        auxColNod = auxColNod->siguiente;
    }

    return cad;
}

string Matriz::enlazarNodosMediosColumna()
{
    string cad="";
    NodoFC *auxND = columnas;
    NodoFC *primero;
    while(auxND!=NULL)
    {
        if(auxND->abajo!=NULL)
        {
            primero = auxND->abajo;
            while(primero!=NULL)
            {
                if(primero->abajo!=NULL)
                {
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str();
                    cad+="->";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->abajo->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->abajo->columna))->str();
                    cad+="\n";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->abajo->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->abajo->columna))->str();
                    cad+="->";
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->fila))->str();
                    cad+=static_cast<std::ostringstream*>(&(std::ostringstream() << primero->columna))->str();
                    cad+="[constraint = false];\n";
                }
                primero = primero->abajo;
            }
        }
        auxND = auxND->siguiente;
    }

    return cad;
}
///metodos int y string
string Matriz::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}

int Matriz::stringToInt(string s)
{
    stringstream cast(s);
    int x = 0;
    cast >> x;
    return x;
}

///grafica linealizacion
void Matriz::linealizarFilas(){
    NodoFC *tempoF = filas;
    cout<<tempoF->siguiente->color<<endl;
    while(tempoF!=NULL)
    {
        NodoFC *tempInterior = tempoF->siguiente;
        while(tempInterior!=NULL)
        {
             linealizarF.insertarNodo(tempInterior->fila,tempInterior->columna,tempInterior->color);
            tempInterior = tempInterior->siguiente;
        }
        tempoF = tempoF->abajo;
    }
    linealizarF.graficaLista();
}

void Matriz::linealizarColumnas()
{
    NodoFC *tempoC = columnas;
    while(tempoC!=NULL)
    {
        NodoFC *tempInterior = tempoC->abajo;
        while(tempInterior!=NULL)
        {
             linealizarC.insertarNodo(tempInterior->fila,tempInterior->columna,tempInterior->color);
            tempInterior = tempInterior->abajo;
        }
        tempoC = tempoC->siguiente;
    }
    linealizarC.graficaLista();

}

///numero columnas
int Matriz::numeroColumnas(){
    int nc=0;
    NodoFC *tempoC = columnas;
    while(tempoC!=NULL)
    {
        nc+=1;
        tempoC = tempoC->siguiente;
    }
    return nc;
}
///numero filas
int Matriz::numeroFilas(){
    int nf=0;
    NodoFC *tempoF = filas;
    while(tempoF!=NULL)
    {
        nf+=1;
        tempoF = tempoF->abajo;
    }
    return nf;
}
///vector de linealizacion

string Matriz::LinMF(){
    string datosLinealizados="";
    NodoFC *tempoF = filas;
    NodoFC *tempoC = columnas;
    while(tempoC!=NULL)
    {
        //cout<<tempoC->color<<"-Fila: "<<tempoC->fila<<"-Columna: "<<tempoC->columna<<endl;
        NodoFC *tempInterior = tempoF->siguiente;
        while(tempInterior!=NULL)
        {
            stringstream s(tempInterior->color);
            string r="";
            string g="";
            string b="";
            string RGB="";
            int R=0;
            int G=0;
            int B=0;
            int i=0;
            int j=0;
            getline(s,r,'-');
            getline(s,g,'-');
            getline(s,b,'\n');
            R = stringToInt(r);
            G = stringToInt(g);
            B = stringToInt(b);
            RGB = rgbToHex(R,G,B,true);
            i = tempInterior->fila;
            j = tempInterior->columna;
            int k = calcularK(i,j);
            datosLinealizados += ".pixel:nth-child("+intToString(k)+"){\n";
            datosLinealizados += "background: "+ RGB+";\n";
            datosLinealizados +="}\n";
            //cout<<"-Fila: "<<tempInterior->fila<<"Columna: "<<tempInterior->columna<<"color: "<<tempInterior->color<<endl;
            tempInterior = tempInterior->siguiente;
        }
        tempoC = tempoC->abajo;
    }

    return datosLinealizados;
}

int Matriz::calcularK(int fila,int columna){
    int K=0;
    K =fila*numeroColumnas() + columna;
    return K;
}


///convertir rgb a hex
string Matriz::rgbToHex(int r, int g, int b, bool with_head)
{
	stringstream ss;
	if (with_head)
		ss << "#";
	ss << hex << (r << 16 | g << 8 | b);
	return ss.str();
}
