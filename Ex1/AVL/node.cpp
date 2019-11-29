//
// Created by danie on 28/11/2019.
//

#include "node.h"
template <class K, class D>
Node<K,D>::Node(K key, D data):key(key),data(data){}

void calcHeight(){
    return this.height;
}
void setLeft(const Node& left);
void setRight(const Node& right);

template <class K, class D>
int Node<K,D>::getHeight(){
    return Node<K,D>::height;
}
