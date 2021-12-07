//
// Created by lauri on 2/12/2021.
//

#include "LinkedDouble.h"
#include "House.h"

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = last = NULL;
}
/**
 * @brief Me corrobora que el primer y ultimo nodo es nulo o vacio
 * @tparam T variable de tipo template o  variable generica
 * @return que el primero y ultimo nodo es nullo o vacio
 */
template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}
/**
 * @brief Agrega Nodo al principio de la lista
 * @tparam T variable de tipo template o  variable generica
 * @param info  Le llega la informacion que contiene el objeto que se va agregar en la lista
 */
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
/**
 * @brief Agrega nodos al final de la lista
 * @tparam T variable de tipo template o  variable generica
 * @param info  Le llega la informacion que contiene el objeto que se va agregar al final de la lista
 */
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
/**
 * @brief Agrega nodos de mayor a menor segun la clave del id
 * @tparam T variable de tipo template o  variable generica
 * @param info  Le llega la informacion que contiene el objeto que se va agregar al final de la lista
 */
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
/**
 * @brief Encontrar la direccion de memoria en la que se encuentra nodo
 * @tparam T variable de tipo template o  variable generica
 * @param id string que me ayuda a buscar el objeto
 * @return Objeto de tipo nodo con la direccion que necesitamos
 */
template<class T>
NodeDouble<T> *LinkedDouble<T>::findNode(std::string id) {
    NodeDouble<T> *aux = head;
    while (aux != NULL && aux->info.getId().compare(id) != 0) {
        aux = aux->next;
    }

    return aux;
}
/**
 * @brief Metodo que me encuentra la informacion de un nodo
 * @tparam T variable de tipo template o  variable generica
 * @param id string que me ayuda a buscar la informacion del  objeto
 * @return Informacion completa de lo que hay dentro del nodo con ayuda de la direccion de memoria
 */
template<class T>
T *LinkedDouble<T>::findInfo(std::string id) {
    NodeDouble<T> *aux = head;

    while (aux != NULL) {
        if (aux->info.getId().compare(id) == 0) {

            return &aux->info;
        }
    }

    return NULL;
}
/**
 * @brief Metodo para agregar un nodo anterior a otro
 * @tparam T variable de tipo template o  variable generica
 * @param before  el nodo al que le vamos agregar un nuevo nodo previo
 * @param info Informacion del nuevo nodo
 */
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
/**
 * @brief Metodo para agregar un nodo despues de otro
 * @tparam T variable de tipo template o  variable generica
 * @param after el nodo anterior al nuevo nodo a agregar
 * @param info informacion del objeto que va estar dentro del nuevo nodo
 */
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
/**
 * @brief Metodo para Recorrer el metodo ya sea de adelante para atras o atras para adelante
 * @tparam T  variable de tipo template o  variable generica
 * @param recorrer Boleano que nos indica de que forma se va a recorrer el vector compuesto por los nodos
 * @return Muestra la lista completa de nodos
 */
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
/**
 * @brief Metodo para obtener cuantos elementos hay dentro de lista
 * @tparam T variable de tipo template o  variable generica
 * @return entero que me muestra tamaño del vector
 */
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
/**
 * @brief Metodo Para buscar dentro de lista por medio de un indice
 * @tparam T  variable de tipo template o  variable generica
 * @param indice entero que me dice cual objeto o nodo devolver
 * @return me devuelve un apuntador con la informacion
 */

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
/**
 * @brief Me ayuda a borrar un nodo enviandole uno como parametro
 * @tparam T  variable de tipo template o  variable generica
 * @param node  Vairable de tipo nodoDoble que me indicara cual borrar de la lista
 * @return Me devuelve el nodo borrado
 */
template<class T>
T LinkedDouble<T>::deleteNode(NodeDouble<T> *node) {
    T out = node->info;
    NodeDouble<T>* ant=NULL;
    if (node == head && node->next== NULL) {
        head = NULL;
        last = NULL;
    } else {
        if(node==head){
            head=head->next;
            head->previous=NULL;
        }else if(node==last){
            last=last->previous;
            last->next=NULL;

        }else{
            NodeDouble<T> *aux = head;
            while (aux->next != node) {
                aux = aux->next;
            }
            aux->next=node->next;
            ant=node->next;
            ant->previous=aux;
        }
    }
    delete (node);
    return out;
}
/**
 * @brief Muestra el primer objeto del nodo
 * @tparam T  variable de tipo template o  variable generica
 * @return  muestra la cabeza de la lista
 */
template<class T>
T LinkedDouble<T>::getFirst() {
    T out=head->info;
    return out;
}
/**
 * @brief Muestra el ultimo elemento de la lista
 * @tparam T  variable de tipo template o  variable generica
 * @return Me muestra last o ultimo elemento de la lista
 */
template<class T>
T LinkedDouble<T>::getLast() {
   T out=last->info;
    return out;
}
/**
 * @brief Destructor de la lista
 * @tparam T  variable de tipo template o  variable generica
 */
template<class T>
LinkedDouble<T>::~LinkedDouble() {
    NodeDouble<T> *aux = head;
    while (head != NULL) {
        aux = head;
        head = head->next;
        delete (aux);
    }
}
