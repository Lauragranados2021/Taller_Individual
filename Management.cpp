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

bool Management::nodeExist(std::string id) {
if(casa->findNode(id)==NULL) {
    return false;
}
return true;
}

House Management::DeleteNode(std::string id) {
    if (nodeExist(id) == true) {
        return casa->deleteNode(casa->findNode(id));
    }
    return House();
}

bool Management::addNodeFirstorLastorSorted(std::string id, std::string direccion, std::string area, short windows, std::string color, int opcion) {
    switch(opcion){
        case 1:
            if(nodeExist(id)==false){
             casa->addNodeFirst(House(id,direccion,area,windows,color));
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

bool Management::emptyList() {
    if(casa->getSize()>0){
        return true;
    }
    return false;
}
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

std::string Management::findHouses(std::string id) {
    if(nodeExist(id)==false){
      return casa->findInfo(id)->getId()+" "+casa->findInfo(id)->getDireccion()+" "+casa->findInfo(id)->getArea()+" " +std::to_string(casa->findInfo(id)->getWindows())+" "+casa->findInfo(id)->getColor();
    }
return "Casa no encontrada";
}

std::string Management::MostrarFirst() {
    return casa->getFirst().getId()+" "+casa->getFirst().getDireccion()+" "+casa->getFirst().getArea()+" " +std::to_string(casa->getFirst().getWindows())+casa->getFirst().getColor();

}

std::string Management::mostrarLast() {
    return casa->getLast().getId()+" "+casa->getLast().getDireccion()+" "+casa->getLast().getArea()+" " +std::to_string(casa->getLast().getWindows())+casa->getLast().getColor();
}


