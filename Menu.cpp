#include "Menu.h"
#include "ArbolBB.h"
#include "ListaCircular.h"
#include <iostream>
using namespace std;
ListaCircular obj;
ListaCircular *p = NULL;
ArbolBB obj2;
ArbolBB *raiz = NULL;
Menu::Menu()
{
    mostrarMenu();
}

void Menu::mostrarMenu()
{
    int op =0;
    do
    {
        cout<<"=============== PHOTOGEN++ ==============="<<endl;
        cout<<"1.- Insert Image"<<endl;
        cout<<"2.- Select Image"<<endl;
        cout<<"3.- Apply Filters"<<endl;
        cout<<"4.- Manual Editing"<<endl;
        cout<<"5.- Export Image"<<endl;
        cout<<"6.- Reports"<<endl;
        cout<<"7.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            obj.insertar(p,"Hola10");
            obj.insertar(p,"Hola21");
            obj.insertar(p,"Hola32");
            obj.insertar(p,"Hola43");
            obj.insertar(p,"Hola54");
            obj.insertar(p,"Hola65");

            obj2.insertarNodo(raiz,"Mario1");
            obj2.insertarNodo(raiz,"Pikachu");
            obj2.insertarNodo(raiz,"Boo");
            obj2.insertarNodo(raiz,"Geoff");
            obj2.insertarNodo(raiz,"Mario2");
            obj2.insertarNodo(raiz,"Mushroom");
            obj2.insertarNodo(raiz,"Santiago");
            obj2.insertarNodo(raiz,"Gilberto");
            obj2.insertarNodo(raiz,"Andre");

            break;
        case 2:
            obj.Mostrar(p);
            break;
        case 3:
            obj.limpiarLista(p);
            break;
        case 4:
            obj2.recorridoInO(raiz);
            cout<<"-------"<<endl;
            obj2.recorridoPre(raiz);
            cout<<"-------"<<endl;
            obj2.recorridoPost(raiz);
            break;
        case 5:
            obj2.graficarArbol(raiz);
            obj2.graficaLista(raiz);
            obj2.graficaListaPostOrden(raiz);
            obj2.graficaListaPreOrden(raiz);
            obj.graficaListaCircular(p);
            break;
        case 6:
            break;
        case 7:
            system("exit");
            break;
        }
    }while(op!=7);
}
