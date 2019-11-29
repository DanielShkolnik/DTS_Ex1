

#ifndef AVL_H_
#define AVL_H_

#include "node.h"

template <class K, class D>
class Avl{
private:
    int verticesNum;
    Node<K,D> head;
public:
    Avl();
    ~Avl();
    Avl(const Avl& avl)= delete;
    Avl& operator=(const Avl& avl)= delete;
    void insert(const K& key, const D& data);
    void delete_element(const K& key);
    Node<K,D>& find(const K& key);
    int getBF(const Node<K,D>& node);
    void rotateLL(const Node<K,D>& node);
    void rotateLR(const Node<K,D>& node);
    void rotateRL(const Node<K,D>& node);
    void rotateRR(const Node<K,D>& node);
    Node<K,D>** inorder() const;
    Node<K,D>** preorder() const;
    Node<K,D>** postorder() const;
};



#endif
