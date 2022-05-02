#include <iostream>

using namespace std;

int main(){
    int n, multiplo;
    cout << "Ingrese un numero entero:" << endl;
    cin >> n;
    multiplo = n % 3;
    if (multiplo == 0){
        if (n > 50){
            cout << "El numero " << n << " es mayor que 50 y es multiplo de 3." << endl;
        }
        else if (n < 50){
            cout << "El numero " << n << " es menor que 50 pero es multiplo de 3." << endl;
        }
    }
    else{
        if (n > 50){
            cout << "El numero " << n << " es mayor que 50 pero no es multiplo de 3." << endl;
        }
        else if (n < 50){
            cout << "El numero " << n << " es menor que 50 y no es multiplo de 3." << endl;
        }
        else{
            cout << "El numero 50 no es multiplo de 3." << endl;
        }
    }
    system("pause");
    return 0;
}