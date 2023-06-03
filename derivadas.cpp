#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include "main.cpp"
using namespace std;

/*notas aparte. como hacer para no pisarse entre el operador y el signo de n.
explicar todo en el manual
*/
class principal{
    private:
        char operador;
        float n;
        int potencia;
        int flag=0;

    public:
        principal(char,float,int,int); 
        ~principal();
        int setformato();
};

principal::principal (char _operador,float _n,int _potencia,int _flag){
    operador=_operador; n=_n; potencia=_potencia;flag=_flag;
}
principal::~principal(){
}

int principal::setformato(){
    cout<<"1 para n \t 2 para n.X \t 3 para n.X^z \t 4 para e^x \t 5 para a^X"<<endl;
    cout<<"6 para ln(x) \t 7 para √x \t 8 para sen(X) \t 9 para cos(x) \t 10 para tg(x)"<<endl;
    //HACER POR SI INGRESAN UNA OPCION NO VALIDA.
    int eleccion=0;
    cin>>eleccion;
    return eleccion;
}

void pedirCaracter(char& c) {
    cout<<"Ingrese el simbolo aritmetico de de la cuenta: ";cin >> c;
    //SOLO SE VAN A SOPORTAR + O -, DEPURAR ESO. ESTO SE HACE YA QUE NO VAMOS A APLICAR PROPIEDADES.
}
void pedirforma(char& c) {
    cout<<"Seleccione un formato para x : ";
    cout<<"\n1 para (n) \t 2 para (√n+-/*n) \t 3 para (sen(n+*/-n)), (cos(n+*/-n)) o (tg(n+*/-n))\n";
    //HACER POR SI INGRESAN UNA OPCION NO VALIDA.
    cin >> c;
    system ("cls");
}
void pedirforma2(char& c) {
    cout<<"Seleccione un formato para x : ";
    cout<<"\n1 para √(n) || √(n+*/-n) \t 2 para √(sen(n+*/-n)), √(cos(n+*/-n)) o √(tg(n+*/-n))\n";
    //HACER POR SI INGRESAN UNA OPCION NO VALIDA.
    cin >> c;
    system ("cls");
}
void pedirformasen(char& c){
    cout<<"Seleccione un formato  : ";
    cout<<"\n1 para (n) || (n+*/-n) \t 2 para (√n+*/-n)\n";
    //HACER POR SI INGRESAN UNA OPCION NO VALIDA.
    cin >> c;
    system ("cls");
}
int main(){
    char operadores[repes];
    char negpos[repes];
    char forma[repes];
    float n[repes];
    string ndentro[repes];
    int potencia[repes];
    int formato[repes];
    int guia = 0;
    char caracter;

    system("chcp 65001");
    system ("cls");
    int repes;
    cout<<"Ingrese la longitud del calculo a realizar : ";cin>>repes;
    principal *p1[repes];
    for (int i=0; i<repes;i++){
        p1[i]= new principal('n',0,0,0);
    }

    for (int i=0; i<repes;i++){
        system ("cls");
        cout<<"Ingrese el formato del calculo "<<i+1<<" : ";
        cout<<"\n"; formato[i]=p1[i]->setformato();
        system ("cls");
        if (guia==1) {
            if (formato[i]==1){
                cout<<"El formato seleccionado es : n ."<<endl;
                pedirCaracter(operadores[i]);
                cout<<"Ingrese n : "; cin>>n[i];
            }
            if (formato[i]==2){
                cout<<"El formato seleccionado es : n.X ."<<endl;
                pedirCaracter(operadores[i]);
                cout<<"Ingrese n : "; cin>>n[i];
            }
            if (formato[i]==3){
                cout<<"El formato seleccionado es : n.X^z ."<<endl;
                pedirCaracter(operadores[i]);
                cout<<"Ingrese n : "; cin>>n[i];
                cout<<"\nIngrese z : "; cin>>potencia[i];
            }
            if (formato[i]==4){       
                cout<<"El formato seleccionado es : e^x ."<<endl;
                pedirCaracter(operadores[i]);
                cout<<"Ingrese e : ";cin>>n[i];
                cout<<"\nIngrese x : ";cin>>potencia[i];
            }
            if (formato[i]==5){
                cout<<"El formato seleccionado es : a^X ."<<endl;
                pedirCaracter(operadores[i]);
                cout<<"Ingrese a : "; cin>>n[i];
            } 
            if (formato[i]==6){
                cout<<"El formato seleccionado es : ln(X) ."<<endl;
                pedirCaracter(operadores[i]);
                pedirforma(forma[i]);
                    if (forma[i]=='1'){
                        cout<<"El formato seleccionado es : (n) || (n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : ln(√n+-/*n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='3'){
                        cout<<"El formato seleccionado es :  ln(sen(n+*/-n)), ln(cos(n+*/-n)) o ln(tg(n+*/-n)), ingrese sen, cos o tg y junto a el la cuelta"<<endl;
                        cin>>ndentro[i];
                    }
                    //HACER POR SI INGRESAN ALGO QUE NO SEA 1 2 O 3
            }
            if (formato[i]==7){                
                cout<<"El formato seleccionado es : √x ."<<endl;
                pedirCaracter(operadores[i]);
                pedirforma2(forma[i]);
                    if (forma[i]=='1'){//no se toleran raices negativas.
                        cout<<"El formato seleccionado es : √(n) || √(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es :  √(sen), √(cos) o √(tg), ingrese sen, cos o tg y junto a el la cuelta"<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                     //HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
            }
            if (formato[i]==8){   
                pedirCaracter(operadores[i]);
                cout<<"El formato seleccionado es : sen(x) ."<<endl;
                cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                pedirformasen(forma[i]);
                if(negpos[i]=='-'){
                    if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"sen(n) || "<<negpos[i]<<"sen(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"sen(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }}
                else{
                    if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : sen(n) || sen(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : sen(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                }//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
                if (formato[i]==9){ //9 para cos(X)
                    pedirCaracter(operadores[i]);
                    cout<<"El formato seleccionado es : cos(x) ."<<endl;
                    cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                    pedirformasen(forma[i]);
                    if(negpos[i]=='-'){
                        if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"cos(n) || "<<negpos[i]<<"cos(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"cos(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                    else{
                            if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : cos(n) || cos(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : cos(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                    }
                    //HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
                if (formato[i]==10){ 
                    pedirCaracter(operadores[i]);
                    cout<<"El formato seleccionado es : tg(x) ."<<endl;
                    cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                    pedirformasen(forma[i]);
                    if(negpos[i]=='-'){
                    if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"tg(n) || "<<negpos[i]<<"tg(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"tg(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                    else{
                        if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : tg(n) || tg(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : tg(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
            } 
        if (guia==0){
            if (formato[i]==1){
                cout<<"El formato seleccionado es : n ."<<endl;
                cout<<"Ingrese n : "; cin>>n[i];
            }
            if (formato[i]==2){
                cout<<"El formato seleccionado es : n.X ."<<endl;
                cout<<"Ingrese n : "; cin>>n[i];
            }
            if (formato[i]==3){
                cout<<"El formato seleccionado es : n.X^z ."<<endl;
                cout<<"Ingrese n : "; cin>>n[i];
                cout<<"\nIngrese z : "; cin>>potencia[i];  
            }
            if (formato[i]==4){       
                cout<<"El formato seleccionado es : e^x ."<<endl;
                cout<<"Ingrese e : ";cin>>n[i];
                cout<<"\nIngrese x : ";cin>>potencia[i];
            }
            if (formato[i]==5){         
                cout<<"El formato seleccionado es : a^X ."<<endl;
                cout<<"Ingrese a : "; cin>>n[i];
            }
            if (formato[i]==6){
                cout<<"El formato seleccionado es : ln(X) ."<<endl;
                pedirforma(forma[i]);
                if (forma[i]=='1'){
                    cout<<"El formato seleccionado es : (n) || (n+*/-n) ."<<endl;
                    cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                }
                if (forma[i]=='2'){
                    cout<<"El formato seleccionado es : ln(√n+-/*n) ."<<endl;
                    cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                }
                if (forma[i]=='3'){
                    cout<<"El formato seleccionado es :  ln(sen(n+*/-n)), ln(cos(n+*/-n)) o ln(tg(n+*/-n)), ingrese sen, cos o tg y junto a la cuelta"<<endl;
                    cin>>ndentro[i];
                }
                //HACER POR SI INGRESAN ALGO QUE NO SEA 1 2 O 3
            }
            if (formato[i]==7){                
                cout<<"El formato seleccionado es : √x ."<<endl;
                pedirforma2(forma[i]);
                    if (forma[i]=='1'){
                        cout<<"El formato seleccionado es : √(n) || √(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es :  √(sen), √(cos) o √(tg), ingrese sen, cos o tg y junto a el la cuelta"<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    //HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
            }
            if (formato[i]==8){   
                cout<<"El formato seleccionado es : sen(X) ."<<endl;
                cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                //HACER POR SI INGRESAN ALGO QUE NO SEA + O -.
                pedirformasen(forma[i]);
                if (negpos[i]=='-'){
                    if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"sen(n) || "<<negpos[i]<<"sen(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : "<<negpos[i]<<"sen(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                else{
                    if (forma[i]=='1'){ 
                        cout<<"El formato seleccionado es : sen(n) || sen(n+*/-n) ."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }
                    if (forma[i]=='2'){
                        cout<<"El formato seleccionado es : sen(√n+*/-n)."<<endl;
                        cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                    }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
            if (formato[i]==9){ 
                    cout<<"El formato seleccionado es : cos(x) ."<<endl;
                    cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                    //HACER POR SI INGRESAN ALGO QUE NO SEA + O -.
                    pedirformasen(forma[i]);
                    if (negpos[i]=='-'){
                        if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"cos(n) || "<<negpos[i]<<"cos(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"cos(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                    else{
                        if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : cos(n) || cos(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : cos(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
            if (formato[i]==10){ 
                    cout<<"El formato seleccionado es : tg(x) ."<<endl;
                    cout<<"Ingrese + si quiere sen sea positivo o - si quiere que sen sea negativo : "<<endl;cin>>negpos[i];
                    pedirformasen(forma[i]);
                    if (negpos[i]=='-'){    
                        if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"tg(n) || "<<negpos[i]<<"tg(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : "<<negpos[i]<<"tg(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }}//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                    else{
                        if (forma[i]=='1'){ 
                            cout<<"El formato seleccionado es : tg(n) || tg(n+*/-n) ."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                        if (forma[i]=='2'){
                            cout<<"El formato seleccionado es : tg(√n+*/-n)."<<endl;
                            cout<<"Ingrese el contenido : ";cin>>ndentro[i];
                        }
                    }//HACER POR SI INGRESAN ALGO QUE NO SEA 1 O 2
                }
        guia=1;
        }
    }
    
    system ("cls");
    cout<<"Mostrando la cuenta:"<<endl;
    int bandera=0;

    for (int i=0; i<repes;i++){
        if (bandera==1){
            if (formato[i]==1){
                cout<<operadores[i]<<n[i];
            }
        if (formato[i]==2){
            cout<<operadores[i]<<n[i]<<"X";
        }
        if (formato[i]==3){
            cout<<operadores[i]<<n[i]<<"X^"<<potencia[i];
        }
        if (formato[i]==4){
            cout<<operadores[i]<<n[i]<<"^"<<potencia[i];
        }
        if (formato[i]==5){
            cout<<operadores[i]<<n[i]<<"^X";
        }
        if (formato[i]==6){
            if (forma[i]=='1'){
                    cout<<operadores[i]<<"ln("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"ln(√"<<ndentro[i]<<")";
                }
                if (forma[i]=='3'){
                    cout<<operadores[i]<<"ln("<<ndentro[i]<<")";
                }
        }
        if (formato[i]==7){                 
                    cout<<operadores[i]<<"√("<<ndentro[i]<<")";
                }
        if (formato[i]==8){
            if(negpos[i]=='+'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"sen("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"sen(√"<<ndentro[i]<<")";
                }}
            if(negpos[i]=='-'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<negpos[i]<<"sen("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<negpos[i]<<"sen(√"<<ndentro[i]<<")";
                }
            }
        }
        if (formato[i]==9){
            if(negpos[i]=='-'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<negpos[i]<<"cos("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<negpos[i]<<"cos(√"<<ndentro[i]<<")";
                }}
            else{
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"cos("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"cos(√"<<ndentro[i]<<")";
                }
            }
        }
        if (formato[i]==10){
            if (negpos[i]=='-'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<negpos[i]<<"tg("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<negpos[i]<<"tg(√"<<ndentro[i]<<")";
                }
            }
            else{
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"tg("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"tg(√"<<ndentro[i]<<")";
                }

            }
        }
    }
        if (bandera==0){

                if (formato[i]==1){
                    cout<<n[i];
                }
                if (formato[i]==2){
                    cout<<n[i]<<"X";
                }
                if (formato[i]==3){
                    cout<<n[i]<<"X^"<<potencia[i];
                }
                if (formato[i]==4){
                    cout<<n[i]<<"^"<<potencia[i];
                }
                if (formato[i]==5){
                    cout<<n[i]<<"^X";
                }
                if (formato[i]==6){
                        if (forma[i]=='1'){
                            cout<<"ln("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<"ln(√"<<ndentro[i]<<")";
                        }
                        if (forma[i]=='3'){
                            cout<<"ln("<<ndentro[i]<<")";
                        }
                }
                if (formato[i]==7){                
                    cout<<"√("<<ndentro[i]<<")";
                }
                if (formato[i]==8){
                    if(negpos[i]=='-'){
                        if (forma[i]=='1'){
                            cout<<negpos[i]<<"sen("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<negpos[i]<<"sen(√"<<ndentro[i]<<")";
                        }
                    }
                    else{
                        if (forma[i]=='1'){
                            cout<<"sen("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<"sen(√"<<ndentro[i]<<")";
                        }
                        }
                    }
                if (formato[i]==9){
                    if(negpos[i]=='-'){
                        if (forma[i]=='1'){
                            cout<<negpos[i]<<"cos("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<negpos[i]<<"cos(√"<<ndentro[i]<<")";
                        }
                    }
                    else{
                        if (forma[i]=='1'){
                            cout<<"cos("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<"cos(√"<<ndentro[i]<<")";
                        }
                        }
                    }
            if (formato[i]==10){
                if (negpos[i]=='-'){
                    if (forma[i]=='1'){
                        cout<<negpos[i]<<"tg("<<ndentro[i]<<")";
                    }
                    if (forma[i]=='2'){
                        cout<<negpos[i]<<"tg(√"<<ndentro[i]<<")";
                    }
                }
                else{
                    if (forma[i]=='1'){
                        cout<<"tg("<<ndentro[i]<<")";
                    }
                    if (forma[i]=='2'){
                        cout<<"tg(√"<<ndentro[i]<<")";
                    }

                }
            }
    bandera=1;
        }
    }
    
    cout<<"\nAhora se muestran las derivas."<<endl;
    bandera=0;
    for (int i=0; i<repes;i++){
        if (bandera==1){
            if (formato[i]==1){
                cout<<operadores[i]<<n[i]-n[i];
            }
            if (formato[i]==2){
                    cout<<operadores[i]<<n[i];
            }
            if (formato[i]==3){
                if (potencia[i]==2){
                    cout<<operadores[i]<<n[i]*potencia[i]<<"X";
                }
                else{
                    cout<<operadores[i]<<n[i]*potencia[i]<<"X^"<<potencia[i]-1;
                }
            }
            if (formato[i]==4){     
                cout<<operadores[i]<<n[i]<<"^"<<potencia[i];
            }
            if (formato[i]==5){     
                cout<<operadores[i]<<n[i]<<"^X"<<".ln("<<n[i]<<")";
            }
            if (formato[i]==6){ 
                if (forma[i]=='1'){
                        cout<<operadores[i]<<"1/"<<ndentro[i];
                }
                if (forma[i]=='2'){
                        cout<<operadores[i]<<"1/√"<<ndentro[i];
                }
                if (forma[i]=='3'){
                        cout<<operadores[i]<<"1/"<<ndentro[i];
                }
            }
            if (formato[i]==7){                 
                cout<<operadores[i]<<"1/2√"<<ndentro[i];
            }
            if (formato[i]==8){
                if(negpos[i]=='-'){
                    if (forma[i]=='1'){
                        cout<<operadores[i]<<negpos[i]<<"cos("<<ndentro[i]<<")";
                    }
                    if (forma[i]=='2'){
                        cout<<operadores[i]<<negpos[i]<<"cos(√"<<ndentro[i]<<")";
                    }
                }
            if (negpos[i]=='+'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"cos("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"cos(√"<<ndentro[i]<<")";
                }
            }
        }
        
        if (formato[i]==9){
            if(negpos[i]=='-'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"sen("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"sen(√"<<ndentro[i]<<")";
                }
            }
            if(negpos[i]=='+'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"-sen("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"-sen(√"<<ndentro[i]<<")";
                }
            }
        }
        if (formato[i]==10){
            if(negpos[i]=='-'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<negpos[i]<<"1/cos^2("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<negpos[i]<<"1/cos^2(√"<<ndentro[i]<<")";
                }
        }
            if(negpos[i]=='+'){
                if (forma[i]=='1'){
                    cout<<operadores[i]<<"1/cos^2("<<ndentro[i]<<")";
                }
                if (forma[i]=='2'){
                    cout<<operadores[i]<<"1/cos^2(√"<<ndentro[i]<<")";
                }
            }
        }
    }
    if (bandera==0){
        if (formato[i]==1){
            cout<<n[i]-n[i];
        }
                if (formato[i]==2){
                    cout<<n[i];
                }
                if (formato[i]==3){
                    if (potencia[i]==2){
                        cout<<n[i]*potencia[i]<<"X";
                    }
                    if (potencia[i]!=2){
                        cout<<n[i]*potencia[i]<<"X^"<<potencia[i]-1;
                    }
                }
                if (formato[i]==4){     
                    cout<<n[i]<<"^"<<potencia[i];
                }
                if (formato[i]==5){     
                    cout<<n[i]<<"^X"<<".ln("<<n[i]<<")";
                }
                if (formato[i]==6){ 
                    if (forma[i]=='1'){
                            cout<<"1/"<<ndentro[i];
                    }
                    if (forma[i]=='2'){
                            cout<<"1/√"<<ndentro[i];
                    }
                    if (forma[i]=='3'){
                            cout<<"1/"<<ndentro[i];
                    }
                }
                if (formato[i]==7){                 
                    cout<<"1/2√"<<ndentro[i];
                }
                if (formato[i]==8){
                    if(negpos[i]=='-'){
                        if (forma[i]=='1'){
                            cout<<negpos[i]<<"cos("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<negpos[i]<<"cos(√"<<ndentro[i]<<")";
                        }
                    }
                    if(negpos[i]=='+'){
                        if (forma[i]=='1'){
                            cout<<"cos("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<"cos(√"<<ndentro[i]<<")";
                        }
                    }
                }
                if (formato[i]==9){
                    if(negpos[i]=='-'){
                        if (forma[i]=='1'){
                            cout<<"sen("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<"sen(√"<<ndentro[i]<<")";
                        }
                    }
                    if(negpos[i]=='+'){
                        if (forma[i]=='1'){
                            cout<<negpos[i]<<"sen("<<ndentro[i]<<")";
                        }
                        if (forma[i]=='2'){
                            cout<<negpos[i]<<"sen(√"<<ndentro[i]<<")";
                        }
                    }
                }
            if (formato[i]==10){
                if(negpos[i]=='-'){
                    if (forma[i]=='1'){
                        cout<<negpos[i]<<"1/cos^2("<<ndentro[i]<<")";
                    }
                    if (forma[i]=='2'){
                        cout<<negpos[i]<<"1/cos^2(√"<<ndentro[i]<<")";
                    }
                }
                if(negpos[i]=='+'){
                    if (forma[i]=='1'){
                        cout<<"1/cos^2("<<ndentro[i]<<")";
                    }
                    if (forma[i]=='2'){
                        cout<<"1/cos^2(√"<<ndentro[i]<<")";
                    }
                }
            }

            bandera=1;
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}