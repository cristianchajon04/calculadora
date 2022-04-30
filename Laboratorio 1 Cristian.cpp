#include <iostream>

using namespace std;

int main(){
    int menu=0, numero;
    char letra = 0;
    while (menu != 3){
        system("cls");
        cout << "Programa con menu" << endl;
        cout << "1- Numero par o impar." << endl;
        cout << "2- Letra vocal o consonante." << endl;
        cout << "0- Salir." << endl;
        cout << "Ingrese la opcion a seguir: " << endl;
        cin >> menu;
        while ((menu < 1) || (menu > 3)){
            cout << "El numero digitado es invalido, intente de nuevo... " << endl;
            system("pause");
            cout << "Ingrese la opcion a seguir: " << endl;
            cin >> menu;
        }
        switch (menu){
        case 1:
            cout << "Ingrese un numero entero:" << endl;
            cin >> numero;
            if (numero % 2 == 0){
                cout << "Es par" << endl;
            }
            else{
                cout << "Es impar" << endl;
            }
            break;
        case 2:
            cout << "Letras" << endl;
            do{
                cout << "Ingrese una letra:" << endl;
                cin >> letra;
                if (letra == '0' || letra == '1' || letra == '2' || letra == '3' || letra == '4' || letra == '5' || letra == '6' || letra == '7' || letra == '8' || letra == '9'){
                    cout << "No se permiten numeros para esta funcion." << endl;
                }
            } while (letra == '0' || letra == '1' || letra == '2' || letra == '3' || letra == '4' || letra == '5' || letra == '6' || letra == '7' || letra == '8' || letra == '9');
            switch (letra){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cout << "Es una vocal." << endl;
                break;
            default:
                cout << "Es una consonante." << endl;
                break;
            }
            break;
        case 3:
            cout << "Saldra del programa." << endl;
            break;
        }
        system("pause");
    }
    return 0;
}
