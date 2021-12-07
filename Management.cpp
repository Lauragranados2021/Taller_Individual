//
// Created by lauri on 2/12/2021.
//

#include "Management.h"
#include "linkedDouble.cpp"

#include "House.h"
#include<iostream>
//LinkedDouble<Books>* ld=new LinkedDouble<Books>();

LinkedDouble<House>* casa=new LinkedDouble<House>();


Management::Management() {}
/**
 *@brief busca un nodo y si no existe entonces me devuelve falso por el contrario si lo encunetra me devuelve que lo encontro
 * @param id string que me ayuda a encontrar el nodo
 * @return un boleando que confirma la existencia del nodo o de la casa
 */
bool Management::nodeExist(std::string id) {
if(casa->findNode(id)==NULL) {
    return false;
}
return true;
}
/**
 *@brief
 * @param id string que me funciona como clave
 * @return Me devuelve el objeto que borre
 */
House Management::DeleteNode(std::string id) {
    if (nodeExist(id) == true) {
        return casa->deleteNode(casa->findNode(id));
    }
    return House();
}
/**
 *@brief Metodo que agrega casas al inicio al final o de manera ordenada con un clave que le indica cual debe elegir. Me va retornar teniendo en cuenta si existe o no el metodo, si no existe lo agregara, de lo contrarioo me devolvera un valor de falso que me diga que no se creo
 * @param id string que me manda la clave de mi casa
 * @param direccion string para crear direccciones
 * @param area string para crear areas de las casas
 * @param windows entero corto que me dice el numero de ventanas
 * @param color string para crear los colores respectivos de la casa
 * @param opcion entero clave para el switch que nos ayuda a decidir de que manera agregar
 * @return me retorna si se agregan las casas
 *
 */
bool Management::addNodeFirstorLastorSorted(std::string id, std::string direccion, std::string area, short windows, std::string color, int opcion) {
    switch(opcion){
        case 1:
            if(nodeExist(id)==false){
             casa->addNodeFirst(House(id,direccion,area,windows,color));
             std::cout<<" \n se agrego \n";
             return true;
            } else{
                return false;

            }
            break;
        case 2:
            if(nodeExist(id)==false){
                casa->addNodeLast(House(id,direccion,area,windows,color));
                return true;
            } else{
                return false;
            }
            break;
        case 3:
   casa->addNodeSorted(House(id,direccion,area,windows,color))  ;
   return true;
    }
    return false;
}
/**
 * @brief metodo que me confirma si la lista es vacia es una precondicion para mostrar
 * @return booleano que me dice si es verdad que la lista de casas esta vacia
 */
bool Management::emptyList() {
    if(casa->getSize()>0){
        return true;
    }
    return false;
}
/**
 * @brief Muestra la lista de adelante hacia atras primero verifica que la lista no esta vacia
 */
void Management::getList()  {
    if(emptyList()==true) {
        for (House book: casa->getLinkedList(true)) {
            std::cout << "\n" << book << "\n";
        }
    }
    else{
        std::cout<<"Lista vacia";
    }
}
/**
 * @brief Metodo para agregar nodos o casas dentro de la lista puede ser antes de un nodo o despues de un nodo
 * @param idnuevo string clave de la nueva cas a agregar
 * @param direccion string que muestras direcciones de las nuevas casas
 * @param area string para crear areas de las casas
 * @param windows entero corto que me dice el numero de ventanas
 * @param color string para crear los colores respectivos de la casa
 * @param opcion entero clave para el switch que nos ayuda a decidir de que manera agregar si antes o despues
 * @param idantiguo string que me ayuda a identificar donde poner el nodo nuevo ya sea como siguiente o como anterior
 * @return boleano que corrovora si se agrego o no validando primero que no exista el nodo
 */
bool Management::addNodeAfterorBefore(std::string idnuevo, std::string direccion, std::string area, short windows, std::string color, int opcion, std::string idantiguo) {
    switch(opcion){
        case 1:
            if(nodeExist(idantiguo)== true){
                casa->addNodeAfterTo(casa->findNode(idantiguo),House(idnuevo,direccion,area,windows,color));
                return true;
            } else{
                return false;
            }
            break;
        case 2:
            if(nodeExist(idantiguo)==true){
                casa->addNodeBeforeTo(casa->findNode(idantiguo),House(idnuevo,direccion,area,windows,color));
                return true;
            } else{
                return false;
            }
            break;
    }
    return false;
}
/**
 * @brief Metodo que me busca una casa por medio del atributo id
 * @param id string clave para buscar una casa por la clave
 * @return informacion completa de la casa que buscamos
 */
std::string Management::findHouses(std::string id) {
    if(nodeExist(id)==true){
      return " id :"+casa->findInfo(id)->getId()+" Direccion: "+casa->findInfo(id)->getDireccion()+" Area:  "+casa->findInfo(id)->getArea()+" Ventanas: " +std::to_string(casa->findInfo(id)->getWindows())+" Color:"+casa->findInfo(id)->getColor();
    }
return "Casa no encontrada";
}
/**
 * @brief me muestra la cabeza de la lista enlazada
 * @return  me muestra la cabeza de la lista
 */
std::string Management::MostrarFirst() {
    return " id: " +casa->getFirst().getId()+ " Direccion: "+casa->getFirst().getDireccion()+" Area: "+casa->getFirst().getArea()+ "Ventanas: " +std::to_string(casa->getFirst().getWindows())+" Color: "+casa->getFirst().getColor();

}
/**
 * @brief Muestra el que esta de primero en la pila
 * @return Muestra last o el ultimo nodo de la lista
 */
std::string Management::mostrarLast() {
    return "id: "+casa->getLast().getId()+" Direccion: "+casa->getLast().getDireccion()+" Area:  "+casa->getLast().getArea()+" Ventanas: " +std::to_string(casa->getLast().getWindows())+" Color: "+casa->getLast().getColor();
}


