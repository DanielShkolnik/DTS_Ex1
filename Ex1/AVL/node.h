#ifndef NODE_H_
#define NODE_H_

template <class K, class D>
class Node{
private :
    K key;
    D data;
    Node* left;
    Node* right;
    Node* papa;
    int height;
public:
    Node()= default;
    Node(K key, D data,const Node<K,D>& papa);
    ~Node()= default;
    Node(const Node<K,D>& node)= default;
    Node<K,D>& operator=(const Node<K,D>& node)= default;
    void calcHeight();
    void setLeft(const Node<K,D>& left);
    void setRight(const Node<K,D>& right);
    int getHeight() const;
    const K& getKey() const;
    const D& getData() const;
    Node<K,D>& getLeft() const;
    Node<K,D>& getRight() const;
    Node<K,D>& getPapa() const;
    void setPapa(const Node<K,D>& papa);

};
int max(int a, int b);

#endif
