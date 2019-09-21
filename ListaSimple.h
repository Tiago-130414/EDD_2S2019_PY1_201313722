#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Matriz.h"
#include <string>
using namespace std;
class nodoLista
{
public:
    nodoLista();
    int numeroCapa;
    string nombreArchivo;
    Matriz capa;
    Matriz archivoOriginal;
    nodoLista *siguiente;
    string rutaSinArchivo;

};

class ListaSimple
{
public:
    ListaSimple();
    bool estaVacia();
    void insertarCapa(int capa,string nom,string temp,string nombreImagen);
    void mostrar();
    string intToString(int val);
    nodoLista *primero;
    nodoLista *ultimo;
    void insertarDatosMatriz(string datMatriz,nodoLista *&,string nombreImagen);
    void insertarDatosMatrizArchivoOriginal(string,nodoLista *&,string);
    void generarHTML(string);
    void generarCss(string nomImg);
    string leerArchivoConfig(string archivo);
    int stringToInt(string s);
    int multiply(int x,int y);
    string retornarRutaPrimero();
    string divCSS();
    string escribirDivHTML(int imageW,int imageH);
    int leerInicialIW(string archivo);
    int leerInicialIH(string archivo);
    bool existeCapa(int capa);
    void imageLayerReport(string& image);
    void generarGraficaCapa(int capa,string nombreImagen);
    void generarGraficaLinealizacionFilas(int capa,string nom);
    void generarGraficaLinealizacionColumnas(int capa,string nom);
    ///filtros
    void aplicarFiltroNegativoCubo();
    void aplicarFiltroEscalaCubo();
    void aplicarFiltroEscalaCapa(int key);
    void aplicarFiltroNegativoCapa(int numCapa);
protected:

private:
};

#endif // LISTASIMPLE_H
