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

void DeleteCasas();

void MostrarFirst();

void MostrarLast();

Management *house=new Management();
using namespace std;


    int main(){
        char option;
        string Bienvenida = "<<<<<<MENU PRINCIPAL>>>>>>>\n\n";
        string menu =   "1. Agregar casa al principio\n"
                     "2. Agregar casa al Final\n"
                     "3. Agregar casa despues de\n"
                     "4. Agregar casa antes de \n"
                     "5. Agregar casa ordenadas \n"
                     "6. Encontrar casa \n"
                     "7. Borrar casa \n"
                     "8. Mostrar la primera casa \n"
                     "9. Mostrar la ultima casa \n"
                     "a. Mostrar todas las casas \n"

                      "X. Salir ";

        do{
            cout<<Bienvenida<<endl;
            cout<<menu<<endl;
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
DeleteCasas();
                    break;
                case'8':
MostrarFirst();
                    break;
                case'9':
MostrarLast();
                    break;
                case 'a':
                 MostrarLista();
                break;
                    fflush(stdin);


            }
        }while(toupper(option) != 'X');
        delete(house);
        return EXIT_SUCCESS;
    }

void MostrarLast() {
cout<<house->mostrarLast();
}

void MostrarFirst() {
        cout<<house->MostrarFirst();

}

void DeleteCasas() {
string id;
cout<<" Digite el ID de la  casa: \n";
cin>>id;
cout<<house->DeleteNode(id);
}

void EncontrarCasa() {
string id;
cout<<" Digite el ID de la casa \n";
cin>>id;
cout<<house->findHouses(id);
}

void MostrarLista() {
house->getList();

}


void agregarcasasordenadas() {
    string id, area, color;
    short windows;
    string direccion;
    cout << "Digite el ID de la casa: "<<endl;
    cin >> id;
    cout << "Digite la direccion de la casa: "<<endl;
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa: "<<endl;
    cin >> area;
    cout << "Digite el color de la fachada de la casa: "<<endl;
    cin >> color;
    cout << "Digite la cantidad de ventanas:  "<<endl;
    cin >> windows;
    cout << house->addNodeFirstorLastorSorted(id, direccion, area, windows, color, 3);

}

void agregarcasaentreBefore() {
    string idnuevo, area, color, idantiguo;
    short windows;
    string direccion;
    cout << "escriba el ID de la casa: "<<endl;
    cin >> idnuevo;
    cout << "Digite la direccion de la casa: "<<endl;
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa:  "<<endl;
    cin >> area;
    cout << "Digite el color de la fachada de la casa: "<<endl;
    cin >> color;
    cout << "Digite la cantidad de ventanas:  "<<endl;
    cin >> windows;
    cout << "escriba el ID de la casa anterior: "<<endl;
    cin >> idantiguo;
    cout << house->addNodeAfterorBefore(idnuevo,direccion,area,windows,color,2,idantiguo);
}

void agregarcasaentreafter() {
    string idnuevo, area, color, idantiguo;
    short windows;
    string direccion;
    cout << "escriba el ID de la casa: "<<endl;
    cin >> idnuevo;
    cout << "Digite la direccion de la casa: "<<endl;
    cin >> direccion;
    cout << "Digite el area en metros cuadrados de la casa:  "<<endl;
    cin >> area;
    cout << "Digite el color de la fachada de la casa:  "<<endl;
    cin >> color;
    cout << "Digite la cantidad de ventanas:  "<<endl;
    cin >> windows;
    cout << "escriba el ID de la casa siguiente: "<<endl;
    cin >> idantiguo;
    cout << house->addNodeAfterorBefore(idnuevo,direccion,area,windows,color,1,idantiguo);
}

void agregarcasaFinal() {
    string id, area, color;
    short windows;
    string direccion;
        cout << "escriba el ID de la casa: "<<endl;
        cin >> id;
        cout << "Digite la direccion de la casa: "<<endl;
        cin >> direccion;
        cout << "Digite el area en metros cuadrados de la casa: "<<endl;
        cin >> area;
        cout << "Digite el color de la fachada de la casa: "<<endl;
        cin >> color;
        cout << "Digite la cantidad de ventanas: "<<endl;
        cin >> windows;
        cout << house->addNodeFirstorLastorSorted(id, direccion, area, windows, color, 2);
}

void agregarcasaPrincipio() {
    string id, area, color;
    short windows;
    string direccion;

    try {
        cout << "escriba el ID de la casa: "<<endl;
        cin >> id;
        cout << "Digite la direccion de la casa: "<<endl;
        cin>>direccion;
        cout << "Digite el area en metros cuadrados de la casa:  "<<endl;
        cin >> area;
        cout <<" Digite el color de la fachada de la casa: "<<endl;
        cin >> color;
        cout <<" Digite la cantidad de ventanas: "<<endl;
        cin >> windows;
        cout << house->addNodeFirstorLastorSorted(id,direccion,area,windows,color,1);
    } catch (exception x) {
        cout << "Error: " << x.what();
    }

}


