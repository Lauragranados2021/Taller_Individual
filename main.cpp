#include <iostream>

using namespace std;


    int main(){
        char option;
        char *menu = "<<<<<<MENU PRINCIPAL>>>>>>>\n\n"
                     "1. Agregar Servicio\n"
                     "2. Consultar Servicios\n"
                     "3. Sumar Servicios\n"
                     "4. Totalizar Consumos\n"
                     "X. Salir\n\nDigite Opcion  ";

        do{
            printf(menu);
            option = getchar();
            switch( option ){
                case '1' :

                    break;

                case '2' :


                    break;

                case '3':


                    break;

                case '4':

                    break;



            }
        }while(toupper(option) != 'X');
        return EXIT_SUCCESS;
    }

