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

};

class ListaSimple
{
    public:
        ListaSimple();
        bool estaVacia();
        void insertarCapa(int capa,string nom);
        void mostrar();
        string intToString(int val);
        nodoLista *primero;
        nodoLista *ultimo;
        void insertarDatosMatriz(string datMatriz,nodoLista *&);

    protected:

    private:
};

#endif // LISTASIMPLE_H
