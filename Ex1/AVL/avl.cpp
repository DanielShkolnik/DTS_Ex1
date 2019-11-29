//
// Created by danie on 28/11/2019.
//

#include "avl.h"

// gets the key and returns element with the nearest existing key
template <class K, class D>
Node<K,D>& Avl<K,D>::find_nearest(K key) {
    if(this->head == nullptr) return nullptr; // avl is empty.
    Node<K,D> current_node = this->head;
    Node<K,D> prev_node = this->head;
    while (current_node){
        prev_node = current_node;
        if(key > current_node.getKey()){
            current_node = current_node.getRight();
        } else if(key == current_node.getKey()){
            return current_node;
        } else{
            current_node = current_node.getLeft();
        }
    }
    return prev_node;
}
template <class K, class D>
void Avl<K,D>::rotateLL(const Node<K,D>& B){
    Node<K,D>& A = B.getLeft();
    Node<K,D>& A_right = A.getRight();
    A.setRight(B);
    B.setLeft(A_right);
}

template <class K, class D>
void Avl<K,D>::rotateLR(const Node<K,D>& C){
    Node<K,D>& B = C.getLeft();
    Node<K,D>& A = B.getRight();
    Node<K,D>& A_left = A.getLeft();
    Node<K,D>& A_right = A.getRight();
    A.setLeft(B);
    B.setRight(A_left);
    A.setRight(C);
    C.setLeft(A_right);
}
template <class K, class D>
Node<K,D>& Avl<K,D>::find(const K& key){
    Node<K,D>& nearest = this->find_nearest(key);
    if(nearest== nullptr || nearest.getKey() != key){
        throw Avl<K,D>::KeyNotFound(); //empty tree
    }
    if(nearest.getKey()==key)
        return nearest;
}

template <class K, class D>
void Avl<K,D>::delete_element(const K& key){
    Node<K,D>& nearest = this->find_nearest(key);
    if(nearest.getKey()!=key) throw Avl<K,D>::KeyNotFound();
    Node<K,D>& current = nearest;
    while (current){
        int prev_height = current.getHeight();
        current.calcHeight();
        //int BF = current.get
    }
}