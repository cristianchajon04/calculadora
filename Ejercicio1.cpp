#include <iostream>

using namespace std;

int main(){
    float n;
    cout << "Ingrese un numero real:" << endl;
    cin >> n;
    if (n < 100){
        cout << "El numero " << n << " es menor que 100" << endl;
    }
    else if (n > 100){
        cout << "El numero " << n << " es mayor que 100" << endl;
    }
    else{
        cout << "Son numeros iguales." << endl;
    }
    system("pause");
    return 0;
}