#include <iostream>

using namespace std;

int main(){
    int x, i = 1;
    cout << "Ingrese el numero de la tabla de dividir que desea ver:" << endl;
    cin >> x;
    while (i <= 10){
        cout << x << "/" << i << "=" << x / i << endl;
        i++;
    }
    system("pause");
    return 0;
}