#include <iostream>
#include <math.h>

using namespace std;

int main(){
    float raiz;
    cout << "Lista de numeros enteros de 50 a 30" << endl;
    for (int i = 50; i >= 30; i--){
        raiz = pow(i, (double)1 / 3);
        cout << "\nNumero " << i << endl;
        cout << "Su potencia al cuadrado es: " << pow(i, 2) << endl;
        cout << "Su raiz al cubo es: " << raiz << endl;
    }
    system("pause");
    return 0;
}