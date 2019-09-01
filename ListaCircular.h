#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <string>
#include <iostream>
using namespace std;

class ListaCircular
{
    public:
        //node attributes
        string filtroAP;
        ListaCircular *siguiente;
        ListaCircular *anterior;
        //prototype of function
        ListaCircular();
        ListaCircular* crearNodo(string filtroAP);
        bool estaVacia(ListaCircular *&primero);
        void insertar(ListaCircular *&primero,string filtro);
        void Mostrar(ListaCircular *&primero);
        void limpiarLista(ListaCircular *&primero);
        void graficaListaCircular(ListaCircular *&primero);
        string listarNodos(ListaCircular *&primero);
        string apuntadores(ListaCircular *&primero);

    protected:

    private:
};

#endif // LISTACIRCULAR_H
