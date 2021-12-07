//
// Created by lauri on 2/12/2021.
//

#ifndef TALLER_INDIVIDUAL_MANAGEMENT_H
#define TALLER_INDIVIDUAL_MANAGEMENT_H
#include <string>
#include "House.h"

class Management {
public:
    Management();
    bool nodeExist(std::string);//con findnode no con find infoo
    House DeleteNode(std::string);
    bool addNodeFirstorLastorSorted(std::string,std::string,std::string,short,std::string,int);
    bool addNodeAfterorBefore(std::string,std::string,std::string,short,std::string,int,std::string);
    bool emptyList();
    void getList();
    std::string findHouses(std::string);
    std::string MostrarFirst();
    std::string mostrarLast();

};


#endif //TALLER_INDIVIDUAL_MANAGEMENT_H
