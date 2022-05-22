#include <iostream>
#include <conio.h>

using namespace std;

void menu_principal();
void promedio();
void comparar_notas(int);
void agregar_calificacion();
void eliminar_calificacion();

struct estudiante
{
    char nom[15];
    int calificacion[4];
    bool existencia;
} alumno[5];

int main()
{
    menu_principal();
    return 0;
}

void menu_principal()
{
    int m;
    do
    {
        system("cls");
        cout << "\tMenu principal" << endl;
        cout << "1- Promedio." << endl;
        cout << "2- Calificacion mas alta." << endl;
        cout << "3- Calificacion mas baja." << endl;
        cout << "4- Agregar calificaciones." << endl;
        cout << "5- Eliminar calificaciones." << endl;
        cout << "0- Salir." << endl;
        cout << "Escriba la opcion a seguir:" << endl;
        cin >> m;
        switch (m)
        {
        case 0:
            cout << "Gracias por usar este programa." << endl;
            getch();
            exit(1);
            break;
        case 1:
            promedio();
            break;
        case 2:
            comparar_notas(1);
            break;
        case 3:
            comparar_notas(2);
            break;
        case 4:
            agregar_calificacion();
            break;
        case 5:
            eliminar_calificacion();
            break;
        default:
            cout << "El numero escrito es invalido, intente de nuevo... " << endl;
            break;
        }
    } while (m < 0 || m > 5);
    cout << "Escriba cualquier tecla para volver al menu principal... ";
    getch();
    menu_principal();
}

void promedio()
{
    int clave;
    float promedio;
    cout << "\tPromedio" << endl;
    cout << "Escriba la clave del alumno para calcular su promedio (1-5): ";
    cin.ignore();
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "El numero ingresado es invalido." << endl;
    }
    else if (alumno[clave].existencia == false)
    {
        cout << "No hay notas registradas en esta clave." << endl;
    }
    else
    {
        for (int i = 1; i <= 4; i++)
        {
            promedio = promedio + alumno[clave].calificacion[i];
        }
        cout << "El promedio de " << alumno[clave].nom << " es: " << promedio / 4 << " puntos." << endl;
    }
}

void comparar_notas(int x)
{
    int max = 0, min = 101, clave[1], calificacion[1];
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (alumno[i].existencia == true)
            {
                if (alumno[i].calificacion[j] > max)
                {
                    max = alumno[i].calificacion[j];
                    clave[0] = i;
                    calificacion[0] = j;
                }
                if (alumno[i].calificacion[j] < min)
                {
                    min = alumno[i].calificacion[j];
                    clave[1] = i;
                    calificacion[1] = j;
                }
            }
        }
    }
    if (x == 1)
    {
        cout << "\tCalificacion mas alta" << endl;
        cout << alumno[clave[0]].nom << " tiene la calificacion mas alta." << endl;
        cout << "Su puntuacion es: " << alumno[clave[0]].calificacion[calificacion[0]] << endl;
        cout << "Su calificacion es del bimestre " << calificacion[0] << endl;
    }
    else if (x == 2)
    {
        cout << "\tCalificaion mas baja" << endl;
        cout << alumno[clave[1]].nom << " tiene la calificacion mas baja." << endl;
        cout << "Su puntuacion es: " << alumno[clave[1]].calificacion[calificacion[1]] << endl;
        cout << "Su calificacion es del bimestre " << calificacion[1] << endl;
    }
}

void agregar_calificacion()
{
    int clave = 0;
    cout << "\tAgregar calificacion" << endl;
    cout << "Escriba la clave del alumno para agregar sus calificaciones (1-5):" << endl;
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "El numero escrito es invalido." << endl;
    }
    else if (alumno[clave].existencia == true)
    {
        cout << "Para reemplazar los datos de un alumno primero debe eliminar sus calificaciones." << endl;
    }
    else
    {
        cout << "Escriba el nombre del alumno: ";
        cin.ignore();
        cin.getline(alumno[clave].nom, 15, '\n');
        for (int i = 1; i <= 4; i++)
        {
            do
            {
                cout << "\nEscriba la calificacion del bimestre " << i << ": " << endl;
                cin >> alumno[clave].calificacion[i];
                if ((alumno[clave].calificacion[i] < 0) || (alumno[clave].calificacion[i] > 100))
                {
                    cout << "\nEscriba una calificacion valida entre 0 y 100." << endl;
                    getch();
                }
            } while ((alumno[clave].calificacion[i] < 0) || (alumno[clave].calificacion[i] > 100));
        }
        alumno[clave].existencia = true;
        cout << "Los datos han sido registrados con exito." << endl;
    }
}

void eliminar_calificacion()
{
    cout << "\tEliminar calificaciones" << endl;
    int clave;
    char x;
    cout << "Escriba la clave del alumno para eliminar sus calificaciones (1-5): ";
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "El numero escrito es invalido." << endl;
    }
    else if (alumno[clave].existencia == false)
    {
        cout << "No hay calificaciones registradas en esta clave." << endl;
    }
    else
    {
        cout << "\nDatos por eliminar" << endl;
        cout << "\nNombre del alumno: " << alumno[clave].nom << endl;
        for (int i = 1; i <= 4; i++)
        {
            cout << "Calificacion del bimestre " << i << ": " << alumno[clave].calificacion[i] << endl;
        }
        do
        {
            cout << "Desea eliminar estos datos? (s/n): ";
            cin >> x;
            if ((x == 's') || (x == 'S'))
            {
                for (int i = 1; i <= 15; i++)
                {
                    alumno[clave].nom[i] = 0;
                    for (int j = 1; j <= 4; j++)
                    {
                        alumno[clave].calificacion[j] = 0;
                    }
                }
                alumno[clave].existencia = false;
                cout << "Los datos han sido eliminados con exito." << endl;
            }
            else if ((x == 'n') || (x == 'N'))
            {
                cout << "No se eliminaron los datos." << endl;
            }
            else
            {
                cout << "El caracter escrito es invalido, intente de nuevo." << endl;
            }
        } while ((((x != 's') && (x != 'S')) && (x != 'n')) && (x != 'N'));
    }
}