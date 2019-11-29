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
    if(nearest== nullptr || nearest.getKey()!=key) throw Avl<K,D>::KeyNotFound();
    //leaf
    if(nearest.getRight()== nullptr && nearest.getLeft()== nullptr){
        if(is_left_son(nearest)){
            nearest.getPapa().setLeft(nullptr);
        }
        else{
            nearest.getPapa().setRight(nullptr);
        }
    }
    //no right son
    else if(nearest.getRight()== nullptr){
        if(is_left_son(nearest)){
            nearest.getPapa().setLeft(nearest.getLeft());
        }
        else{
            nearest.getPapa().setRight(nearest.getLeft());
        }
        // update papa after switch
        nearest.getLeft().setPapa(nearest.getPapa());
    }
    //find the right left left... son
    else{
        Node<K,D>& current = nearest.getRight();
        while (current.getLeft()!= nullptr){
            current = current.getLeft();
        }
        if(is_left_son(nearest)){
            nearest.getPapa().setLeft(current);
        }
        else{
            nearest.getPapa().setRight(current);
        }
        current.setLeft(nearest.getLeft());
        current.setPapa(nearest.getPapa());
    }
    delete nearest;
}
template <class K, class D>
bool Avl<K,D>::is_left_son(const Node<K,D>& node){
    return node.getPapa().getLeft().getKey()==node.getKey();
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
    C.setRight(A_left);
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
    if(nearest_node== nullptr){
        this->head=new_node;
        return;
    }
    if (key>nearest_node.getKey()) nearest_node.setRight(new_node);
    if (key<nearest_node.getKey()) nearest_node.setLeft(new_node);
    this->fix_BFs(new_node);
}

template <class K, class D>
void Avl<K,D>::fix_BFs(Node<K,D>& leaf){
    Node<K,D>& current = leaf;
    while (current){
        int prev_height = current.getHeight();
        current.calcHeight();
        if(prev_height == current.getHeight()){
            return;
        }
        int BF = this->getBF(current);
        //LL
        if(BF == 2 && this->getBF(current.getLeft())>=0){
            this->rotateLL(current);
        }
        //LR
        if(BF == 2 && this->getBF(current.getLeft())==-1){
            this->rotateLR(current);
        }
        //RL
        if(BF==-2 && this->getBF(current.getRight())==1){
            this->rotateRL(current);
        }
        //RR
        if(BF==-2 && this->getBF(current.getRight())<=0){
            this->rotateRR(current);
        }
        current = current.getPapa();
    }
}


