//
// Created by lauri on 2/12/2021.
//

#include "LinkedDouble.h"

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = last = NULL;
}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {
    NodeDouble<T> *node = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = node;
    } else {
        head->previous = node;
        node->next = head;
        head = node;
    }
}

template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    NodeDouble<T> *node = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = node;//la cabeza y el ultimo son iguales al nuevo nodo si no existe ningun nodo
    } else {
        last->next = node;//apunta al nuevo nodo, le digo que el siguiente es el nuevo nodo
        node->previous = last; //en la parte anterior o last del nuevo nodo es last o el anterior nodo osea que el nodo anterior  al que creamos es last
        last = node; //cmbiamos el apuntado last al nuevo nodo para agrehar otros
    }
}

template<class T>
void LinkedDouble<T>::addNodeSorted(T info) {
    NodeDouble<T> *node = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = node;
    } else if (info.getId().compare(head->info.getId()) < 0) { //si lo que voy agregar es menor al primer nodo
        addNodeFirst(info);

    } else if (info.getId().compare(last->info.getId()) > 0) {//si es mayor al ultimo nodo
        addNodeLast(info);

    } else {
        NodeDouble<T> *act = head;
        NodeDouble<T> *ant = NULL;
        while (info.getId().compare(act->info.getId()) > 0) {
            ant = act;
            act = act->next;
        }
        node->next = act;
        node->previous = ant;
        ant->next = node;
        act->previous = node;
    }
}

template<class T>
NodeDouble<T> *LinkedDouble<T>::findNode(std::string id) {
    NodeDouble<T> *aux = head;
    while (aux != NULL && aux->info.getId().compare(id) != 0) {
        aux = aux->next;
    }

    return aux;
}

template<class T>
T *LinkedDouble<T>::findInfo(std::string id) {
    NodeDouble<T> *aux = head;
    while (aux != NULL) {
        if (aux->info.getId().compare(id) == 0)
            return &aux->info;
    }

    return NULL;
}

template<class T>
void LinkedDouble<T>::addNodeBeforeTo(NodeDouble<T> *before, T info) {
    NodeDouble<T> *node = new NodeDouble<T>(info);
    if (before == head) {
        addNodeFirst(info);
    } else {
        node->next = before;
        node->previous = before->previous;
        before->previous->next = node;
        before->previous = node;
    }
}

template<class T>
void LinkedDouble<T>::addNodeAfterTo(NodeDouble<T> *after, T info) {
    NodeDouble<T> *node = new NodeDouble<T>(info);
    if (after == last) {
        addNodeLast(info);
    } else {
        node->next = after->next;
        node->previous = after;
        after->next = node;
        after->next->previous = node;
    }
}

template<class T>
std::vector<T> LinkedDouble<T>::getLinkedList(bool recorrer) {
    std::vector<T> out;
    NodeDouble<T> *aux = recorrer ? head : last;
    while (aux != NULL) {
        out.push_back(aux->info);
        aux = recorrer ? aux->next : aux->previous;
    }
    return out;
}

template<class T>
int LinkedDouble<T>::getSize() {
    int cont = 0;
    NodeDouble<T> *aux = head;
    while (aux != NULL) {//auxiliar es la cabeza
        cont++;
        aux = aux->next;//le estoy diciendo que el siguiente nodo es la cabeza, cuando el ultimo nodo ya no tenga un siguiente y la cabeza sea nulla se sale y me muestra el numero del tamaño
    }
    return cont;
}

template<class T>
T *LinkedDouble<T>::getObject(int indice) {
    NodeDouble<T> *aux = head;
    int cont = 0;
    while (cont < indice) {
        aux = aux->next;
        cont++;
    }
    return &aux->info;
}

template<class T>
T LinkedDouble<T>::deleteNode(NodeDouble<T> *node) {
    T out = node->info;
    if (node == head == last) {
        head = head->next;
        last = last.previous;
    } else {
        NodeDouble<T> *aux = head;
        NodeDouble<T> *act = node->next;
        while (aux->next != node) {
            aux = aux->next;
        }

        aux->next = act;
        act->previous = aux;

    }
    delete (node);
}

template<class T>
T LinkedDouble<T>::getFirst() {
    NodeDouble<T> *aux = head;
    return &head->info;
}

template<class T>
T LinkedDouble<T>::getLast() {
    NodeDouble<T> *aux = head;
    return &last.info;
}

template<class T>
LinkedDouble<T>::~LinkedDouble() {
    NodeDouble<T> *aux = head;
    while (head != NULL) {
        aux = head;
        head = head->next;
        delete (aux);
    }
}
