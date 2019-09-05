#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Matriz.h"
class nodoLista{
    public:
        nodoLista();
        Matriz capa;
        nodoLista *siguiente;

};

class ListaSimple
{
    public:
        ListaSimple();
        bool estaVacia();
        void insertarCapa();
        void mostrar();
        nodoLista *primero;
        nodoLista *ultimo;

    protected:

    private:
};

#endif // LISTASIMPLE_H
