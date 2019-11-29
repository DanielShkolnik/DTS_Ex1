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
void Avl<K,D>::rotateRR(const Node<K,D>& B){
    Node<K,D>& A=B.getRight();
    Node<K,D>& A_left=A.getLeft();
    A.setLeft(B);
    B.setRight(A_left);
}

template <class K, class D>
void Avl<K,D>::rotateRL(const Node<K,D>& C){
    Node<K,D>& B=C.getRight();
    Node<K,D>& A=B.getLeft();
    Node<K,D>& A_left=A.getLeft();
    Node<K,D>& A_right=A.getRight();
    A.setLeft(C);
    C.setRight(A_left)
    A.setRight(B);
    B.setLeft(A_right);
}

template <class K, class D>
int Avl<K,D>::getBF(const Node<K,D>& node){
    return node.getLeft().getHeight()-node.getRight().getHeight();
}

template <class K, class D>
void Avl<K,D>::insert(const K& key, const D& data){
    Node<K,D>& nearest_node=this->find_nearest(key);
    if (nearest_node.getKey()==key) throw Avl<K,D>::KeyExists();
    Node<K,D>& new_node=Node<K,D>(key,data,nearest_node);
    if (key>nearest_node.getKey()) nearest_node.setRight(new_node);
    if (key<nearest_node.getKey()) nearest_node.setLeft(new_node);
    Node<K,D>& current=new_node;
}

template <class K, class D>
void Avl<K,D>::fix_BFs(Node<K,D>& node){

}


