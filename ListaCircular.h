#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <string>
#include <iostream>
using namespace std;
class nodoListaCircular
{
    public:
        //node attributes
        nodoListaCircular();
        string filtroAP;
        nodoListaCircular *siguiente;
        nodoListaCircular *anterior;

};
class ListaCircular
{
    public:
        //first node
        nodoListaCircular *primero;
        //prototype of function
        ListaCircular();
        nodoListaCircular* crearNodo(string filtroAP);
        bool estaVacia();
        void insertar(string filtro);
        void Mostrar();
        void limpiarLista();
        void graficaListaCircular();
        string listarNodos();
        string apuntadores();


    protected:

    private:
};

#endif // LISTACIRCULAR_H
