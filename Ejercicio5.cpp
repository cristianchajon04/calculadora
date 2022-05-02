#include <iostream>

using namespace std;

int main(){
    string producto;
    int cantidad;
    float precio, precio_total;
    char origen;
    cout << "Solicitud de compra de producto" << endl;
    cout << "Ingrese el nombre del producto:" << endl;
    cin >> producto;
    cout << "Ingrese la cantidad de " << producto << ":" << endl;
    cin >> cantidad;
    cout << "Ingrese el precio por unidad: Q";
    cin >> precio;
    cout << "Ingrese el origen del producto, digite \'n\' si es nacional o \'e\' si es extranjero:" << endl;
    cin >> origen;
    if (origen == 'n'){
        precio_total = precio * cantidad;
        cout << "A continuacion se hara una orden de compra" << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio: Q" << precio << endl;
        cout << "Total: Q" << precio_total << endl;
    }
    else if (origen == 'e'){
        cout << "No se hara una orden de compra" << endl;
    }
    else{
        cout << "El caracter ingresado no es valido." << endl;
    }
    system("pause");
    return 0;
}