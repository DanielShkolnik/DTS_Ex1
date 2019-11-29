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
