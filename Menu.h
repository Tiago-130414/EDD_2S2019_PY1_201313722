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
    void leerArchivoConfig(string archivo);
    int stringToInt(string s);
    void seleccionarImagenArbol(string& imagen);
    void imageLayerReport(string& image);


protected:

private:
};

#endif // MENU_H
