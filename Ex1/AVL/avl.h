#ifndef AVL_H_
#define AVL_H_

#include "node.h"
#include <memory>
template <class K, class D>
class Avl{
private:
    std::shared_ptr<Node<K,D>> head;
    std::shared_ptr<Node<K,D>> find_nearest(K key);
    void fix_BFs(std::shared_ptr<Node<K,D>> leaf); //CHANGE TO SMART PTR
    bool is_left_son(std::shared_ptr<Node<K,D>> node);
    void update_head(std::shared_ptr<Node<K,D>> node);
    void fix_relations(std::shared_ptr<Node<K,D>> A, std::shared_ptr<Node<K,D>> B);
public:
    Avl():head(nullptr){}
    ~Avl()= default;
    Avl(const Avl& avl)= delete;
    Avl& operator=(const Avl& avl)= delete;
    void insert(const K& key, const D& data); // Daniel
    void delete_element(const K& key); // Omer
    std::shared_ptr<Node<K,D>> find(const K& key); // Omer
    std::shared_ptr<Node<K,D>> getHead();
    int getBF(std::shared_ptr<Node<K,D>> node); // Dainel
    void rotateLL(std::shared_ptr<Node<K,D>> node); // Omer
    void rotateLR(std::shared_ptr<Node<K,D>> node); // Omer
    void rotateRL(std::shared_ptr<Node<K,D>> node); // Daniel
    void rotateRR(std::shared_ptr<Node<K,D>> node); // Daniel

    class Error{};
    class KeyExists{};
    class KeyNotFound{};
};

template <class K, class D>
void Avl<K,D>::insert(const K& key, const D& data){
    std::shared_ptr<Node<K,D>> nearest_node=this->find_nearest(key);
    std::shared_ptr<Node<K,D>> new_node_ptr = std::shared_ptr<Node<K,D>>(new Node<K,D>(key,data,nearest_node));
    if(nearest_node == nullptr){
        this->head=new_node_ptr;
        return;
    }
    if (nearest_node->getKey()==key) throw Avl<K,D>::KeyExists();
    if (key>nearest_node->getKey()) nearest_node->setRight(new_node_ptr);
    if (key<nearest_node->getKey()) nearest_node->setLeft(new_node_ptr);
    this->fix_BFs(new_node_ptr);
    this->update_head(new_node_ptr);
}

// gets the key and returns element with the nearest existing key
template <class K, class D>
std::shared_ptr<Node<K,D>> Avl<K,D>::find_nearest(K key) {
    if(this->head == nullptr) return nullptr; // avl is empty->
    std::shared_ptr<Node<K,D>> current_node = this->head;
    std::shared_ptr<Node<K,D>> prev_node = this->head;
    while (current_node){
        prev_node = current_node;
        if(key > current_node->getKey()){
            current_node = current_node->getRight();
        } else if(key == current_node->getKey()){
            return current_node;
        } else{
            current_node = current_node->getLeft();
        }
    }
    return prev_node;
}
template <class K, class D>
void Avl<K,D>::rotateLL(std::shared_ptr<Node<K,D>> B){
    std::shared_ptr<Node<K,D>> B_papa=B->getPapa();
    std::shared_ptr<Node<K,D>> A = B->getLeft();
    std::shared_ptr<Node<K,D>> A_right = A->getRight();
    A->setRight(B);
    B->setLeft(A_right);
    if (B_papa!=nullptr)fix_relations(B_papa,A);
    else A->setPapa(nullptr);
    fix_relations(A,B);
    if (A_right!= nullptr) fix_relations(B,A_right);
    A->calcHeight();
    B->calcHeight();
}

template <class K, class D>
void Avl<K,D>::rotateLR(std::shared_ptr<Node<K,D>> C){
    std::shared_ptr<Node<K,D>> B = C->getLeft();
    std::shared_ptr<Node<K,D>> A = B->getRight();
    std::shared_ptr<Node<K,D>> A_left = A->getLeft();
    std::shared_ptr<Node<K,D>> A_right = A->getRight();
    std::shared_ptr<Node<K,D>> C_papa = C->getPapa();
    A->setLeft(B);
    B->setRight(A_left);
    A->setRight(C);
    C->setLeft(A_right);
    if(C_papa == nullptr) A->setPapa(nullptr);
    else fix_relations(C_papa,A);
    fix_relations(A,C);
    fix_relations(A,B);
    if(A_left != nullptr) fix_relations(B,A_left);
    if(A_right != nullptr) fix_relations(C,A_right);
    A->calcHeight();
    B->calcHeight();
    C->calcHeight();
}
template <class K, class D>
std::shared_ptr<Node<K,D>> Avl<K,D>::find(const K& key){
    std::shared_ptr<Node<K,D>> nearest = this->find_nearest(key);
    if(nearest== nullptr || nearest->getKey() != key){
        throw Avl<K,D>::KeyNotFound(); //empty tree
    }
    if(nearest->getKey()==key)
        return nearest;
}

template <class K, class D>
void remove_from_papa(const std::shared_ptr<Node<K,D>>& node){
    if(node->isRoot()) return;
    if(is_left_son(node)) node->getPapa()->setLeft(nullptr);
    else node->getPapa()->setRight(nullptr);
}
template <class K, class D>
void connect_right_son_to_grandpapa(const std::shared_ptr<Node<K,D>>& node){
    if(node->isRoot()) return;
}

template <class K, class D>
void Avl<K,D>::delete_element(const K& key){
    // left->right->right....
    std::shared_ptr<Node<K,D>> nearest = this->find_nearest(key);
    if(nearest== nullptr || nearest->getKey()!=key) throw Avl<K,D>::KeyNotFound();

    // only one element
    if(nearest->isLeaf() && nearest->isRoot()) this->head = nullptr;
    //leaf and not root => papa exists
    else if(nearest->isLeaf()) remove_from_papa(nearest);
    //no left son but not leaf => right son and papa exists
    else if(nearest->getLeft()== nullptr){

    }
        //find the right left left->->-> son
    else{
        std::shared_ptr<Node<K,D>> current = nearest->getRight();
        while (current->getLeft()!= nullptr){
            current = current->getLeft();
        }
        if(is_left_son(nearest)){
            nearest->getPapa()->setLeft(current);
        }
        else{
            nearest->getPapa()->setRight(current);
        }
        current->setLeft(nearest->getLeft());
        current->setRight(nearest->getRight());
        current->setPapa(nearest->getPapa());
    }
    this->update_head(nearest); // get the root from the deleted node
}
template <class K, class D>
bool Avl<K,D>::is_left_son(std::shared_ptr<Node<K,D>> node){
    return node->getPapa()->getLeft()->getKey()==node->getKey();
}
template <class K, class D>
void Avl<K,D>::rotateRR(std::shared_ptr<Node<K,D>> B){
    std::shared_ptr<Node<K,D>> B_papa=B->getPapa();
    std::shared_ptr<Node<K,D>> A=B->getRight();
    std::shared_ptr<Node<K,D>> A_left=A->getLeft();
    A->setLeft(B);
    B->setRight(A_left);
    if (B_papa!=nullptr)fix_relations(B_papa,A);
    else A->setPapa(nullptr);
    fix_relations(A,B);
    if (A_left!= nullptr) fix_relations(B,A_left);
    B->calcHeight();
    A->calcHeight();
}

template <class K, class D>
void Avl<K,D>::rotateRL(std::shared_ptr<Node<K,D>> C){
    std::shared_ptr<Node<K,D>> C_papa=C->getPapa();
    std::shared_ptr<Node<K,D>> B=C->getRight();
    std::shared_ptr<Node<K,D>> A=B->getLeft();
    std::shared_ptr<Node<K,D>> A_left=A->getLeft();
    std::shared_ptr<Node<K,D>> A_right=A->getRight();
    A->setLeft(C);
    C->setRight(A_left);
    A->setRight(B);
    B->setLeft(A_right);
    if(C_papa!= nullptr)fix_relations(C_papa,A);
    else A->setPapa(nullptr);
    if(A_left!= nullptr)fix_relations(C,A_left);
    fix_relations(A,B);
    fix_relations(A,C);
    if(A_right!= nullptr)fix_relations(B,A_right);
    C->calcHeight();
    B->calcHeight();
    A->calcHeight();
}

template <class K, class D>
int Avl<K,D>::getBF(std::shared_ptr<Node<K,D>> node){
    if(node->getLeft()== nullptr && node->getRight()== nullptr) return 0; // leaf
    else if(node->getRight()==nullptr) return node->getLeft()->getHeight(); // no right son
    else if(node->getLeft()==nullptr) return -(node->getRight()->getHeight()); // // no left son
    return node->getLeft()->getHeight()-node->getRight()->getHeight();
}



template <class K, class D>
void Avl<K,D>::fix_BFs(std::shared_ptr<Node<K,D>> leaf){
    std::shared_ptr<Node<K,D>> current = leaf->getPapa();
    if(current == nullptr) return;
    while (current){
        int prev_height = current->getHeight();
        current->calcHeight();
        std::shared_ptr<Node<K,D>> prev = current;
        current = current->getPapa();

        if(prev_height == prev->getHeight()){
            return;
        }
        int BF = this->getBF(prev);
        //LL
        if(BF == 2 && this->getBF(prev->getLeft())>=0){
            this->rotateLL(prev);
        }
        //LR
        else if(BF == 2 && this->getBF(prev->getLeft())==-1){
            this->rotateLR(prev);
        }
        //RL
        else if(BF==-2 && this->getBF(prev->getRight())==1){
            this->rotateRL(prev);
        }
        //RR
        else if(BF==-2 && this->getBF(prev->getRight())<=0){
            this->rotateRR(prev);
        }

    }
}


template <class K, class D, class P>
void inorder(std::shared_ptr<Node<K,D>> node, P predicate){
    if (node== nullptr) return;
    inorder(node->getLeft(),predicate);
    predicate(node);
    inorder(node->getRight(),predicate);
}

template <class K, class D, class P>
void preorder(std::shared_ptr<Node<K,D>> node, P predicate){
    if (node== nullptr) return;
    predicate(node);
    preorder(node->getLeft(),predicate);
    preorder(node->getRight(),predicate);
}

template <class K, class D, class P>
void postorder(std::shared_ptr<Node<K,D>> node, P predicate){
    if (node== nullptr) return;
    postorder(node->getLeft(),predicate);
    postorder(node->getRight(),predicate);
    predicate(node);
}
template <class K, class D>
std::shared_ptr<Node<K,D>> Avl<K,D>::getHead(){
    return this->head;
}
template <class K, class D>
void Avl<K,D>::update_head(std::shared_ptr<Node<K,D>> node){
    while(node->getPapa() != nullptr){
        node = node->getPapa();
    }
    this->head = node;
}

template <class K, class D>
void Avl<K,D>::fix_relations(std::shared_ptr<Node<K,D>> papa, std::shared_ptr<Node<K,D>> son){
    if (!papa || !son) throw Avl<K,D>::Error();
    if (papa->getKey()>son->getKey()) papa->setLeft(son);
    else papa->setRight(son);
    son->setPapa(papa);
}



#endif
