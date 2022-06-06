#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

void menu();
void Escribir_calificaciones();
void revisar_calificaciones(float &, int); // verifica que se Escriban calificaciones validas
string cursos(int &);
bool certificado(float &, float &, float &); // dira si el alumno es promovido o no promovido
void resultados();                           // enseña la calificacion mas alta y mas baja
void leer_informacion();                     // aqui lee la informacion en archivos .txt

float calificacion[4];
bool calificaciones_escritas;

ofstream escritura;
ifstream lectura;

int main()
{int argc;
    system("Title Sistema de calificaciones");
    do
    {
        cout << "\tDeteccion de archivo \"calificaciones.txt\"" << endl;
        cout << "1) Extraer calificaciones almacenadas en el fichero." << endl;
        cout << "2) Hacer un nuevo fichero con otras calificaciones." << endl;
        cout << "Escriba la opcion que desea seguir:" << endl;
        cin >> argc;
        if (argc == 1)
        {
            leer_informacion();
        }
        else if (argc == 2)
        {
        }
        else
        {
            cout << "El numero escrito es invalido, intente de nuevo..." << endl;
            getch();
        }
    } while (argc < 1 || argc > 2);
    cout << "\nEscriba cualquier tecla para dirigirse al menu del sistema..." << endl;
    getch();
    menu();
    return 0;
}

void menu()
{
    int m;
    do
    {
        system("cls");
        cout << "\tMenu principal del sistema de calificaciones" << endl;
        cout << "1) Escribir calificaciones de cursos." << endl;
        cout << "2) Evaluar resultados." << endl;
        cout << "0) Cerrar programa." << endl;
        cout << "Escriba la opcion que desea seguir:" << endl;
        cin >> m;
        if (m >= 1 && m <= 2)
        {
            system("cls");
        }
        switch (m)
        {
        case 0:
            escritura.close();
            cout << "Gracias por usar este programa, nos vemos en la proxima sesion." << endl;
            getch();
            exit(1);
            break;
        case 1:
            Escribir_calificaciones();
            break;
        case 2:
            resultados();
            break;
        default:
            cout << "El numero escrito es invalido, intente de nuevo..." << endl;
            getch();
            break;
        }
    } while (m < 0 || m > 2);
    cout << "\nEscriba cualquier tecla para dirigirse al menu del sistema...";
    getch();
    menu();
}

void Escribir_calificaciones()
{
    cout << "\tAgregar calificaciones" << endl;
    switch (calificaciones_escritas)
    {
    case true:
        cout << "Las calificaciones ya fueron escritas con anterioridad." << endl;
        break;
    case false:
        cout << "Escriba la calificacion de programacion: " << endl;
        cin >> calificacion[1];
        revisar_calificaciones(calificacion[1], 1);
        cout << "Escriba la calificacion de algoritmos: " << endl;
        cin >> calificacion[2];
        revisar_calificaciones(calificacion[2], 2);
        cout << "Escriba la calificacion de logica de sistemas: " << endl;
        cin >> calificacion[3];
        revisar_calificaciones(calificacion[3], 3);
        calificaciones_escritas = true;
        cout << "Los datos del estudiante se registraron con exito." << endl;
        break;
    }
}

void revisar_calificaciones(float &calificacion, int x)
{
    if ((calificacion < 0) || (calificacion > 100))
    {
        do
        {
            cout << "\nEscriba una calificacion valida entre 0 y 100..." << endl;
            getch();
            cout << "Escriba la calificacion de " << cursos(x) << ": " << endl;
            cin >> calificacion;
        } while ((calificacion < 0) || (calificacion > 100));
    }
}

string cursos(int &c)
{
    string p;
    switch (c)
    {
    case 1:
        p = "programacion";
        break;
    case 2:
        p = "algoritmos";
        break;
    case 3:
        p = "logica de sistemas";
        break;
    }
    return p;
}

void resultados()
{
    cout << "\tResultados" << endl;
    int nota_max = 0, nota_min = 101, x, y;
    string promocion;

    switch (calificaciones_escritas)
    {
    case true:

        for (int j = 1; j <= 3; j++)
        {
            if (calificacion[j] > nota_max) // para calcular la calificacion mas alta
            {
                nota_max = calificacion[j];
                x = j;
            }
            if (calificacion[j] < nota_min) // para calcular la calificacion mas baja
            {
                nota_min = calificacion[j];
                y = j;
            }
        }
        cout << "\n*****************************" << endl;
        cout << "\tNota mas alta \nDel curso \"" << cursos(x) << "\"\ntiene la puntuacion: " << calificacion[x] << endl;
        cout << "\tNota mas baja \nDel curso \"" << cursos(y) << "\"\ntiene la puntuacion: " << calificacion[y] << endl;
        cout << "\tPromedio \nSu puntuacion es: " << (calificacion[1] + calificacion[2] + calificacion[3]) / 3 << endl;
        if (certificado(calificacion[1], calificacion[2], calificacion[3]) == false)
        {
            promocion = "NO PROMOVIDO";
        }
        else
        {
            promocion = "PROMOVIDO";
        }
        cout << "\nCondicion del estudiante: " << promocion << endl;
        cout << "*****************************" << endl;
        escritura.open("calificaciones.txt", ios::app);
        if (!escritura.fail())
        {
            escritura << calificacion[1] << " " << calificacion[2] << " " << calificacion[3] << "\n";
            escritura.close();
            cout << "\nEn el archivo \"calificaciones.txt\" puede encontrar las calificaciones almacenadas." << endl;
        }
        else
        {
            cout << "No se pudo crear el archivo, probablemente su equipo esta protegido ante escritura de datos." << endl;
            return;
        }
        break;

    case false:
        cout << "No hay calificaciones registradas para ejecutar esta funcion." << endl;
        break;
    }
}

bool certificado(float &n1, float &n2, float &n3)
{
    if ((n1 >= 61) || (n2 >= 61) || (n3 >= 61))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void leer_informacion()
{
    int i = 1;
    float numero;
    string texto;
    lectura.open("calificaciones.txt", ios::in);
    cout << "\tLectura de datos" << endl;
    if (!lectura.fail())
    {
        cout << "Estas son las calificaciones almacenadas en el archivo de texto" << endl;
        while (lectura >> numero)
        {
            calificacion[i] = numero;
            cout << "Nota de " << cursos(i) << ": " << calificacion[i] << endl;
            i++;
        }
        calificaciones_escritas = true;
        cout << "\nProceda a ver los resultados." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo, talvez se elimino el archivo." << endl;
    }
    lectura.close();
}
