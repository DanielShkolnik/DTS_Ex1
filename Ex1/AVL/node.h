#ifndef NODE_H_
#define NODE_H_

template <class K, class D>
class Node{
private :
    K key;
    D data;
    Node* left;
    Node* right;
    int height;
public:
    Node()= default;
    Node(K key, D data);
    ~Node()= default;
    Node(const Node<K,D>& node)= default;
    Node<K,D>& operator=(const Node<K,D>& node)= default;
    void calcHeight();
    void setLeft(const Node<K,D>& left);
    void setRight(const Node<K,D>& right);
    int getHeight();
};

#endif
