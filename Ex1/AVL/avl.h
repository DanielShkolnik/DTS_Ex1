#ifndef AVL_H_
#define AVL_H_

#include "node.h"

template <class K, class D>
class Avl{
private:
    int verticesNum;
    Node<K,D> head;
    Node<K,D>& find_nearest(K key);
public:
    Avl()= default;
    ~Avl()= default;
    Avl(const Avl& avl)= delete;
    Avl& operator=(const Avl& avl)= delete;
    void insert(const K& key, const D& data); // Daniel
    void delete_element(const K& key); // Daniel
    Node<K,D>& find(const K& key); // Omer
    int getBF(const Node<K,D>& node); // Dainel
    void rotateLL(const Node<K,D>& node); // Omer
    void rotateLR(const Node<K,D>& node); // Omer
    void rotateRL(const Node<K,D>& node); // Daniel
    void rotateRR(const Node<K,D>& node); // Daniel
    Node<K,D>** inorder() const; // Omer
    Node<K,D>** preorder() const; // Omer
    Node<K,D>** postorder() const; // Daniel

    class KeyExists{};
    class KeyNotFound{};
};



#endif
