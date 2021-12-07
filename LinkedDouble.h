//
// Created by lauri on 2/12/2021.
//

#ifndef TALLER_INDIVIDUAL_LINKEDDOUBLE_H
#define TALLER_INDIVIDUAL_LINKEDDOUBLE_H
#include <vector>
#include <string>
#include "NodeDouble.h"
#include "House.h"

template <class T>
class LinkedDouble {

public:
    LinkedDouble() ;

    bool isEmpty();
    void addNodeFirst(T);
    void addNodeLast(T);
    void addNodeSorted(T);
    NodeDouble<T>* findNode(std::string);
    T* findInfo(std::string);
    void addNodeBeforeTo(NodeDouble<T>*,T);
    void addNodeAfterTo(NodeDouble<T>*,T);
    std::vector<T> getLinkedList(bool);
    int getSize();
    T* getObject(int);
    T deleteNode(NodeDouble<T>*);
    T getFirst();
    T getLast();

    virtual ~LinkedDouble();

private:
    NodeDouble<T>*head;
    NodeDouble<T>*last;
};




#endif //TALLER_INDIVIDUAL_LINKEDDOUBLE_H
