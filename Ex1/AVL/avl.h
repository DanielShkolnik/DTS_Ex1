#ifndef AVL_H_
#define AVL_H_

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
    void delete(const K& key);
    &Node find(const K& key);
    int getBF(const Node& node);
    void rotateLL(const Node& node);
    void rotateLR(const Node& node);
    void rotateRL(const Node& node);
    void rotateRR(const Node& node);
    **Node<K,D> inorder() const;
    **Node<K,D> preorder() const;
    **Node<K,D> postorder() const;
}



#endif
