#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Matriz.h"
#include <string>
using namespace std;
class nodoLista{
    public:
        nodoLista();
        int numeroCapa;
        string nombreArchivo;
        Matriz capa;
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
    protected:

    private:
};

#endif // LISTASIMPLE_H
