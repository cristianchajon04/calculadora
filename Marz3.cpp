#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    int menu, n1, n2, n3;
    char simbolo;
    string operacion;
    ofstream historial;
    ifstream ver_historial;
    while (menu != 3)
    {
        do
        {
            cout << "Menu del programa" << endl;
            cout << "1- Utilizar la calculadora." << endl;
            cout << "2- Leer historial de operaciones." << endl;
            cout << "3- Salir del programa." << endl;
            cout << "Ingrese la opcion a seguir:" << endl;
            cin >> menu;
            switch (menu)
            {
            case 1:
                system("cls");
                cout << "Calculadora" << endl;
                cout << "Ingrese el primer numero: " << endl;
                cin >> n1;
                cout << "Ingrese el segundo numero: " << endl;
                cin >> n2;
                cout << "Los numeros ingresados seran usados por su valor absoluto." << endl;
                n1 = abs(n1);
                n2 = abs(n2);
                cout << "Operaciones disponibles: Suma, Resta, Multiplicacion, Division." << endl;
                cout << "Ingrese el simbolo de la operacion a realizar (+,-,*,/):" << endl;
                cin >> simbolo;
                if ((((simbolo == '+') || (simbolo == '-')) || (simbolo == '*')) || (simbolo == '/'))
                {
                    if (simbolo == '+')
                    {
                        n3 = abs(n1 + n2);
                        cout << "El resultado de la suma es: " << n3 << endl;
                    }
                    else if (simbolo == '-')
                    {
                        if (n1 < n2)
                        {
                            cout << "El segundo numero es mayor que el primero, solo mostrara el valor absoluto del resultado" << endl;
                            cout << "Presione cualquier tecla para continuar" << endl;
                            getch();
                        }
                        n3 = abs(n1 - n2);
                        cout << "El resultado de la resta es: " << n3 << endl;
                    }
                    else if (simbolo == '*')
                    {
                        n3 = abs(n1 * n2);
                        cout << "El resultado de la multiplicacion es: " << n3 << endl;
                    }
                    else if (simbolo == '/')
                    {
                        if (n2 == 0)
                        {
                            cout << "La operacion no es admitida, sera enviado al menu de opciones." << endl;
                        }
                        else if (n1 % n2 != 0)
                        {
                            cout << "La division no sera exacta. Solo se mostrara el valor absoluto del cociente," << endl;
                            cout << "No se mostrara el residuo. Presione cualquier tecla para continuar" << endl;
                            getch();
                            n3 = abs(n1 / n2);
                            cout << "El resultado de la division es: " << n3 << endl;
                        }
                    }
                    historial.open("Registro.txt", ios::app);
                    if (historial.fail())
                    {
                        cout << "No se pudo crear el archivo." << endl;
                    }
                    else
                    {
                        historial << n1 << simbolo << n2 << "=" << n3 << "\n";
                        historial.close();
                        cout << "En el archivo Registro.txt puede encontrar todas las operaciones hechas en la calculadora" << endl;
                    }
                }
                else
                {
                    cout << "El simbolo digitado es invalido, sera enviado al menu de opciones." << endl;
                }
                break;
            case 2:
                system("cls");
                ver_historial.open("Registro.txt", ios::in);
                cout << "Operaciones realizadas" << endl;
                cout << " " << endl;
                if (ver_historial.fail())
                {
                    cout << "No se pudo abrir el archivo." << endl;
                }
                else
                {
                    while (!ver_historial.eof())
                    {
                        getline(ver_historial, operacion);
                        cout << operacion << endl;
                    }
                }
                ver_historial.close();
                break;
            case 3:
                cout << "Usted saldra del programa." << endl;
                break;
            default:
                cout << "El numero digitado es invalido, intente de nuevo." << endl;
                break;
            }
            system("pause");
        } while ((menu < 1) || (menu > 3));
    }
    return 0;
}
