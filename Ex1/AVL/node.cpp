//
// Created by danie on 28/11/2019.
//

#include "node.h"
template <class K, class D>
Node<K,D>::Node(K key, D data):key(key),data(data){}


template <class K, class D>
int Node<K,D>::calcHeight(){
    return Node<K,D>::left->height + Node<K,D>::right->height + 1;
}

template <class K, class D>
void Node<K,D>::setLeft(const Node& left){
    Node<K,D>::left=left;
}

template <class K, class D>
void Node<K,D>::setRight(const Node& right){
    Node<K,D>::right=right;
}

template <class K, class D>
int Node<K,D>::getHeight(){
    return Node<K,D>::height;
}
