#include "Menu.h"
#include "ArbolBB.h"
#include "ListaCircular.h"
#include "ListaSimple.h"
#include "ListaDobleLN.h"
#include "leerArchivo.h"
#include <iostream>
using namespace std;
ListaCircular obj;
ArbolBB obj2;
ArbolBB *raiz = NULL;
ListaDobleLN obj4;
ListaSimple objL;
leerArchivo lee;

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
        //system("cls");
        switch(op)
        {
        case 1:
            /**
            obj.insertar("Hola10");
            obj.insertar("Hola21");
            obj.insertar("Hola32");
            obj.insertar("Hola43");
            obj.insertar("Hola54");
            obj.insertar("Hola65");
            obj.Mostrar();
            obj.graficaListaCircular();

            obj2.insertarNodo(raiz,"Mario1");
            obj2.insertarNodo(raiz,"Pikachu");
            obj2.insertarNodo(raiz,"Boo");
            obj2.insertarNodo(raiz,"Geoff");
            obj2.insertarNodo(raiz,"Mario2");
            obj2.insertarNodo(raiz,"Mushroom");
            obj2.insertarNodo(raiz,"Santiago");
            obj2.insertarNodo(raiz,"Gilberto");
            obj2.insertarNodo(raiz,"Andre");

            obj3.insertarNodo(0,1,"azul");
            obj3.insertarNodo(2,3,"negro");
            obj3.insertarNodo(5,4,"blanco");
            obj3.insertarNodo(6,8,"amarillo");
            obj3.insertarNodo(7,9,"celeste");
            obj3.insertarNodo(7,8,"verde");
            obj3.insertarNodo(7,7,"verde");
            obj3.insertarNodo(7,6,"verde");
            obj3.insertarNodo(5,2,"verde");
            obj3.insertarNodo(10,13,"naranja");
            obj3.insertarNodo(9,11,"naranja");
            obj3.escribirDot();

            obj4.insertarNodo(1,2,"azul",t);
            obj4.insertarNodo(1,2,"azul1",t);
            obj4.insertarNodo(1,2,"azul2",t);
            obj4.insertarNodo(1,2,"azul3",t);
            obj4.insertarNodo(1,2,"azul4",t);
            obj4.mostrar(t);
            obj4.graficaLista(t);
            **/
            lee.leer("prueba.csv");
            break;
        case 2:
            //obj.Mostrar(p);
            break;
        case 3:
            //obj.limpiarLista(p);
            break;
        case 4:
            obj2.recorridoInO(raiz);
            cout<<"-------"<<endl;
            obj2.recorridoPre(raiz);
            cout<<"-------"<<endl;
            obj2.recorridoPost(raiz);
            break;
        case 5:
            //obj.graficaListaCircular(p);
            break;
        case 6:
            menuReportes();
            break;
        case 7:
            system("exit");
            break;
        }
    }while(op!=7);
}

void Menu::menuReportes()
{
    int op=0;
    do{
        cout<<"=============== REPORTS ==============="<<endl;
        cout<<"1.- Imported Images Report"<<endl;
        cout<<"2.- Image Layer Report"<<endl;
        cout<<"3.- Linear Matrix Report"<<endl;
        cout<<"4.- Traversal Report"<<endl;
        cout<<"5.- Filter Report"<<endl;
        cout<<"6.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op){
            case 1:
                obj2.graficarArbol(raiz);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                traversalReport();
                break;
            case 5:
                break;
        }
    }while(op!=6);
}

void Menu:: traversalReport()
{
    int op=0;
    do{
        cout<<"=============== TRAVERSAL REPORT ==============="<<endl;
        cout<<"1.- Inorder Traversal"<<endl;
        cout<<"2.- Postorder Traversal"<<endl;
        cout<<"3.- Preorder Traversal"<<endl;
        cout<<"4.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op){
            case 1:
                obj2.graficaLista(raiz);
                break;
            case 2:
                obj2.graficaListaPostOrden(raiz);
                break;
            case 3:
                 obj2.graficaListaPreOrden(raiz);
                break;
        }
    }while(op!=4);
}
