#include <iostream>
using namespace std;
#include "lineales.cpp"
#include "derivadas.cpp"

int main(){
    int menu;

    do{
        cout << "-- Sistema de resolucion de ecuaciones --" << endl;
        cout << "1. Ecuaciones lineales." << endl;
        cout << "2. Derivadas." << endl;
        cout << "3. Salir." << endl;
        cin >> menu;
        switch (menu){
            case 1:
                menuLineales();
                break;
            case 2:
                menuDerivadas();
                break;
            default:
                cout << "Opcion incorrecta, ingrese de nuevo!" << endl;
                break;
        }
    } while (menu != 3);
    return 0;
}