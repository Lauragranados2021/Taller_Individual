#include <iostream>
#include <string>
#include "Management.h"

void agregarcasaPrincipio();

void agregarcasaFinal();

void agregarcasaentreafter();

void agregarcasaentreBefore();

void agregarcasasordenadas();

void MostrarLista();

void EncontrarCasa();

Management *house=new Management();
using namespace std;


    int main(){
        char option;
        char *menu = "<<<<<<MENU PRINCIPAL>>>>>>>\n\n"
                     "1. Agregar casa al principio\n"
                     "2. Agregar casa al Final\n"
                     "3. Agregar casa despues de\n"
                     "4. Agregar casa antes de \n"
                     "5. Agregar casa ordenadas \n"
                     "6. Encontrar casa \n"
                     "7. Borrar casa \n"
                     "8. Mostrar la primera casa \n"
                     "9. Mostrar la ultima casa \n"
                     "10. Mostrar todas las casas \n"

                     "11. Borrar la lista  \n\n";

                     "X. Salir\n\nDigite Opcion  ";

        do{
            printf(menu);
            option = getchar();
            switch( option ){
                case '1' :
agregarcasaPrincipio();
                    break;

                case '2' :
                    agregarcasaFinal();
                    break;

                    case '3':
                    agregarcasaentreBefore();
                    break;

                case '4':
                    agregarcasaentreafter();
                    break;

                    case'5':
                    agregarcasasordenadas();
                    break;

                    case '6':
                        EncontrarCasa();
                    break;
                case'7':

                    break;
                case'8':

                    break;
                case'9':

                    break;
                case 'a':
MostrarLista();
                break;
                case 'b':

                    break;




            }
        }while(toupper(option) != 'X');
        return EXIT_SUCCESS;
    }

void EncontrarCasa() {

}

void MostrarLista() {


}

void agregarcasasordenadas() {
    string id, area, color;
    short windows;
    string direccion;
    cout << "escriba el ID de la casa: ";
    cin >> id;
    cout << "Digite la direccion de la casa: ";
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa ";
    cin >> area;
    cout << "Digite el color de la fachada de la casa ";
    cin >> color;
    cout << "Digite la cantidad de ventanas";
    cin >> windows;
    cout << house->addNodeFirstorLastorSorted(id, direccion, area, windows, color, 3);

}

void agregarcasaentreBefore() {
    string idnuevo, area, color, idantiguo;
    short windows;
    string direccion;
    cout << "escriba el ID de la casa: ";
    cin >> idnuevo;
    cout << "Digite la direccion de la casa: ";
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa ";
    cin >> area;
    cout << "Digite el color de la fachada de la casa ";
    cin >> color;
    cout << "Digite la cantidad de ventanas";
    cin >> windows;
    cout << "escriba el ID de la casa anterior: ";
    cin >> idantiguo;
    cout << house->addNodeAfterorBefore(idnuevo,direccion,area,windows,color,2,idantiguo);
}

void agregarcasaentreafter() {
    string idnuevo, area, color, idantiguo;
    short windows;
    string direccion;
    cout << "escriba el ID de la casa: ";
    cin >> idnuevo;
    cout << "Digite la direccion de la casa: ";
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa ";
    cin >> area;
    cout << "Digite el color de la fachada de la casa ";
    cin >> color;
    cout << "Digite la cantidad de ventanas";
    cin >> windows;
    cout << "escriba el ID de la casa siguiente: ";
    cin >> idantiguo;
    cout << house->addNodeAfterorBefore(idnuevo,direccion,area,windows,color,1,idantiguo);
}

void agregarcasaFinal() {
    string id, area, color;
    short windows;
    string direccion;
        cout << "escriba el ID de la casa: ";
        cin >> id;
        cout << "Digite la direccion de la casa: ";
        cin >> direccion;
        cout << "Digite el area en metros cuadrados de la casa ";
        cin >> area;
        cout << "Digite el color de la fachada de la casa ";
        cin >> color;
        cout << "Digite la cantidad de ventanas";
        cin >> windows;
        cout << house->addNodeFirstorLastorSorted(id, direccion, area, windows, color, 2);
}

void agregarcasaPrincipio() {
    string id, area, color;
    short windows;
    string direccion;

    try {
        cout << "escriba el ID de la casa: ";
        cin >> id;
        cout << "Digite la direccion de la casa: ";
        cin>>direccion;
        cout << "Digite el area en metros cuadrados de la casa ";
        cin >> area;
        cout << "Digite el color de la fachada de la casa ";
        cin >> color;
        cout << "Digite la cantidad de ventanas";
        cin >> windows;
        cout << house->addNodeFirstorLastorSorted(id,direccion,area,windows,color,1);
    } catch (exception x) {
        cout << "Error: " << x.what();
    }

}


