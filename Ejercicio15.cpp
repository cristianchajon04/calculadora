#include <iostream>

using namespace std;

int main(){
    int x;
    cout << "Ingrese el numero de la tabla de multiplicar que desea ver:" << endl;
    cin >> x;
    for (int i = 1; i <= 10; i++){
        cout << x << "*" << i << "=" << x * i << endl;
    }
    system("pause");
    return 0;
}