/******************************************************************************
Resolucion de Raíces de Ecuaciones No Lineales - Metodo Bisección
*******************************************************************************/
#include <iostream>
#include <iomanip> // Para establecer cantidad de decimales
#include <cmath>
#include "main.cpp"

using namespace std;
class dato
{
private:
    int opcion;
    double f(double x);
public:
    dato();
    void sistemas();
    void setdato(int);
    int getdato(int);
    void imprimePuntos(double a, double b);
    
};

//Constructores
dato::dato(){
}
//Funcion setters y getters
void dato::setdato(int _opcion){
    opcion= _opcion;
}

int dato::getdato(int){
    return opcion;
}
/*******************************FUNCION PROGRAMA***********************************/
void dato::sistemas(){
    
    double a, b, error;
    float xr; // raiz de la función

    cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
    cout << "\nIngrese el rango de analisis [a, b]" << endl;
    cout << "\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    imprimePuntos(a, b);

    cout << "\nEscoja el intervalo adecuado" << endl;
    cout << "\na = ";
    cin >> a;

    cout << "b = ";
    cin >> b;


    if (f(a) * f(b) > 0) {
        cout << "\nNo se puede aplicar el metodo de la biseccion\n";
        cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
    } else {
        cout << "Error = ";
        cin >> error;
        cout << "\na\tb\tx\tf(a)\tf(b)\tf(x)\n" << endl;
        do {
            xr = (a + b) / 2.0;
            cout << a << "\t" << b << "\t" << xr << "\t";
            cout << f(a) << "\t" << f(b) << "\t" << f(xr) <<"\t"<< endl;
    
            if (abs(f(xr)) <= error) { 
                cout << "\n\nPara un Error de " << error << " la raiz de f es " << xr << endl;
                break;
            } else {
                if (f(xr) * f(a) > 0) {
                    a = xr;
                } else if (f(xr) * f(b) > 0) {
                    b = xr;
                }
            }
            
        } while (1);
}
}
/*******************************DECLARACION FUNCION*********************************/
double dato::f(double x) {
   return exp(-1 * x) - cos(3 * x) - 0.5;
}




/*******************************IMPRIME INTERACCIONES*******************************/
void dato:: imprimePuntos(double a, double b){
    int INTERVALOS=0;

    double mitad = 0;

    cout << "Ingrece numeros de Interacciones deseadas: ";
    cin >> INTERVALOS;
    mitad = (b - a) / INTERVALOS;
    cout << "\n";
    cout << "\tx\tf(x)\n" << endl;
    for (int i = 0; i < INTERVALOS+1; i++) {
        cout << "\t" << a << "\t" << f(a) << endl;
        a = a + mitad;
    }
}


/***************************************MENU****************************************/
int menuLineales(){  
    dato o; 
    dato M;
    int menu
    //o.setdato(x);
    cout << setprecision(2); // Establecemos  decimales
    
    do{
        cout << "//== Sistema de ecuaciones lineales ==// " << endl;
        cout << "1. Resolver ecuacion." << endl;
        cout << "2. Volver al menu principal." << endl;

        switch(menu){
            case 1:
                M.sistemas();
                break;
            case 2:
                cout << "Volviendo... \n\n" << endl;
                main();
                break;
            default:
                cout << "Opcion incorrecta, ingrese de nuevo!" << endl;
                break;
        }
    }while(menu != 2);
}












