#include <iostream>

using namespace std;

int main(){
    int numnota;
    cout << "Calculo de promedio" << endl;
    cout << "Ingrese el numero de notas para calcular su promedio:" << endl;
    cin >> numnota;
    if (numnota > 0){
        float notas[numnota];
        notas[0] = 0;
        for (int i = 1; i <= numnota; i++){
            cout << "Ingrese la nota No. " << i << ":" << endl;
            cin >> notas[i];
            notas[0] += notas[i];
        }
        cout << "El promedio de sus notas es: " << notas[0] / numnota << endl;
    }
    else{
        cout << "El numero ingresado no es valido." << endl;
    }
    system("pause");
    return 0;
}