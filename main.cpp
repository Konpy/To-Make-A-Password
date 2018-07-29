/*Gabriel Fontanez
#Estudiante 842-15-3288
Curso : COMP 3081 sec
Programa # 5
Este programa le pedira al usuario para un password y lo verifica
si tiene una letra mayuscula, minuscula, y digito, alo contratio
le seguira pidiendo al usuario para un password correcto. */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

enum areglo
{
    Password_SIZE = 99999                // El maximo que se le puede poner al password
};

int exam(char []);                       // Prototipo de funciones para verificar si el password
int retry(char []);                      //tiene letra mayuscula minuscula y digito.
int redo(int);                     // Para poder empesar denuevo.


int main()
{
    char password[Password_SIZE];                   // Arreglo para el password.
    int wordCap = 0;                                // Para contar el numero de characters en el password.
    unsigned int star = 0;                          // Para poder selecionar si quieres empesar el programa de nuevo


        //Mensaje de introducion
        cout << " \t\t\t\t*Bienvenidos* \n";
        cout << "Este programa le preguntara al usuario para un password.\n";
        //Se entra al primer ciclo para buscar el password y seguir buscando hasta que el usuario siere el programa.
do
{
        cout << "Cual es el password que deseas usar?\n";
        cout << "\nEl password debe tener:\nLetra mayuscula, minuscula y un numero. ";
        cout << "\nde al menos 6 caracteres ";
        cin.getline(password,Password_SIZE);
        wordCap = strlen(password);
        // Ciclo para regresar cuando hay un error en el password.
        while (1)
        {
            //Se pregunta para el password
            //Si wordCap no es al menos 6 characteres le sigue pidiendo al usuario el password
              while (wordCap <= 5)
            {
                cout << "Intente de nuevo ";
                cin.getline(password,Password_SIZE);
                wordCap = strlen(password);
            }

              {
                if(exam(password))              //Llamada de funciones
                    continue;                   //Si es cierta continua si no regresa a preguntar para el password.
                break;
              }
        }
        //Se pregunta si se quiere hacer otro password
        cout << "Deseas hacer otro password?" << endl;
        cout << "Oprime 0 para empesar de nuevo.\nOprime 1 para serar el programa." << endl;
        cin >>star;
} while (star == 0);
    if (star == 1)
    {
        return 0;
    }
}

int exam (char login[])               // Calculos del password
{
    bool upper = 0, lower = 0, num = 0;        // Para decir si el password deverdad tiene mayuscula minuscula o digito.
    for (int counter = 0; counter <= strlen(login); counter++) // Contador para leer el password.
    {
        if(isupper(login[counter]))            //Cambia el valor de upper a 1 si hay letra mayuscula.
            upper = 1;                         //Lo mismo pasa con las siguientes.
        else if (islower(login[counter]))
            lower = 1;
        else if (isdigit(login[counter]))
            num = 1;
    }
    // Le dice al usuario que le falta.
    if (!upper)
       {
        cout << "El password requiere letra mayuscula." << endl;
       }
    if (!lower)
    {
        cout << "El password requiere letra minuscula" << endl;
    }
    if (!num)
    {
        cout << "El password requiere un digito" << endl;
    }
    //Si todos son cierta regresa a main para la proxima pregunta.
    if (upper && lower && num)
    {
        cout << "El password es valido\n" << endl;
        return 0;
    }
    // Si hay un error regresa al while (1)
    else
        return 1;
}
