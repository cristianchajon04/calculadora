#include <iostream>

using namespace std;

int main(){
    float colegiatura = 2500;
    int porcentaje = 0;
    float preciofinal = 0;
    float promedio = 0;
    cout << "Descuento en colegiatura" << endl;
    cout << "Ingrese el promedio de sus notas:" << endl;
    cin >> promedio;

    if (promedio < 0 || promedio > 100){
        cout << "Ingrese un numero valido" << endl;
    }
    else{
        if (promedio >= 90){
            cout << "Su colegiatura tiene un descuento del 20%." << endl;
            porcentaje = 20;
        }
        else if (promedio > 79 && promedio < 90){
            cout << "Su colegiatura tiene un descuento del 10%." << endl;
            porcentaje = 10;
        }
        else if (promedio >= 69 && promedio < 80){
            cout << "Su colegiatura tiene un descuento del 5%." << endl;
            porcentaje = 5;
        }
        else{
            cout << "Usted no tiene descuento en su colegiatura." << endl;
        }
        preciofinal = colegiatura - ((colegiatura * porcentaje) / 100);
        cout << "La cuota de su colegiatura es: " << preciofinal << "quetzales." << endl;
    }
    return 0;
}