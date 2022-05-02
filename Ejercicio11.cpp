#include <iostream>

using namespace std;

int main(){
    int x, x1;
    cout << "Ingrese el valor de x:" << endl;
    cin >> x;
    switch (x){
    case 3:
        cout << "Funcion 1: potencia al cuadrado" << endl;
        cout << x << " elevado al cuadrado es: " << x * x << endl;
        break;
    case -4:
        cout << "Funcion 2: conversion de numero a positivo" << endl;
        cout << x << " convertido a numero positivo es " << x * -1 << endl;
        break;
    case 5:
        x1 = x;
        x = 1;
        cout << "Funcion 3: factorial" << endl;
        for (int i = 1; i <= 5; i++){
            x *= i;
        }
        cout << "La factorial de " << x1 << " es: " << x << endl;
        break;
    default:
        cout << "El numero ingresado no contiene funciones" << endl;
        break;
    }
    system("pause");
    return 0;
}