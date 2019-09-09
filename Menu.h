#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;
class Menu
{
    public:
        Menu();
        void mostrarMenu();
        void menuReportes();
        void traversalReport();
        void leerArchivoCapas(string archivo);
        int stringToInt(string s);


    protected:

    private:
};

#endif // MENU_H
