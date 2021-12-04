//
// Created by lauri on 2/12/2021.
//

#ifndef TALLER_INDIVIDUAL_NODEDOUBLE_H
#define TALLER_INDIVIDUAL_NODEDOUBLE_H
#include<cstdlib>
template<class T>class LinkedDouble;
template<class T>

class NodeDouble {
    friend class LinkedDouble<T>;
public:
    NodeDouble(T info):info(info){
        next=previous=NULL;
    }
private:
    T info;
    NodeDouble<T>* next;
    NodeDouble<T>* previous;
};


#endif //TALLER_INDIVIDUAL_NODEDOUBLE_H
