//
// Created by danie on 28/11/2019.
//

#include "node.h"
template <class K, class D>
Node<K,D>::Node(K key, D data):key(key),data(data){}


template <class K, class D>
void Node<K,D>::calcHeight(){
    this->height= max(this->left->height,this->right->height) + 1;
}

template <class K, class D>
void Node<K,D>::setLeft(const Node<K,D>& left){
    this->left=left;
}

template <class K, class D>
void Node<K,D>::setRight(const Node<K,D>& right){
    this->right=right;
}

template <class K, class D>
int Node<K,D>::getHeight() const{
    return this->height;
}

template <class K, class D>
const K& Node<K,D>::getKey() const{
    return this->key;
}

template <class K, class D>
const D& Node<K,D>::getData() const{
    return this->data;
}

template <class K, class D>
const Node<K,D>& Node<K,D>::getLeft() const{
    return this->left;
}


template <class K, class D>
const Node<K,D>& Node<K,D>::getRight() const{
    return this->right;
}


int max(int a, int b){
    if (a>b) return a;
    return b;
}
