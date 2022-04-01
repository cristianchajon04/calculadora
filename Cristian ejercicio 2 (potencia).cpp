#include <iostream>
#include <fstream>
#include "funcion potencia.h"

using namespace std;

int main(){
    float n[1];
    ofstream resultados;
    resultados.open("historial.txt", ios::app);
    if (!resultados.fail()){
        cout << "Potenciacion" << endl;
        cout << "Ingrese la base:" << endl;
        cin >> n[0];
        cout << "Ingrese el exponente:" << endl;
        cin >> n[1];
        if (n[1] < 0){
            cout << "La potencia de " << n[0] << " elevado a " << n[1] << " es: 1/" << potencia(n[0], n[1]) << endl;
            resultados << "La potencia de " << n[0] << " elevado a " << n[1] << " es: 1/" << potencia(n[0], n[1]) << "\n";
        }
        else{
            cout << "La potencia de " << n[0] << " elevado a " << n[1] << " es: " << potencia(n[0], n[1]) << endl;
            resultados << "La potencia de " << n[0] << " elevado a " << n[1] << " es: " << potencia(n[0], n[1]) << "\n";
        }
    }
    else{
        cout << "Hubo un error al crearse el archivo de texto" << endl;
    }
    cout << "Usted esta saliendo del programa." << endl;
    resultados.close();
    return 0;
}