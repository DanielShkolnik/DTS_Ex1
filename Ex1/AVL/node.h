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
    Node()= delete;
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

template <class K, class D>
Node<K,D>::Node(K key, D data, const Node<K,D>& papa):key(key),data(data),papa(papa),height(0){}


template <class K, class D>
void Node<K,D>::calcHeight(){
    this->height= max(this->left->height,this->right->height) + 1;
}

template <class K, class D>
void Node<K,D>::setLeft(const Node<K,D>& left){
    this->left=left;
}

template <class K, class D>
void Node<K,D>::setRight(const Node<K,D>& right){
    this->right=right;
}

template <class K, class D>
int Node<K,D>::getHeight() const{
    return this->height;
}

template <class K, class D>
const K& Node<K,D>::getKey() const{
    return this->key;
}

template <class K, class D>
const D& Node<K,D>::getData() const{
    return this->data;
}

template <class K, class D>
Node<K,D>& Node<K,D>::getLeft() const{
    return this->left;
}

template <class K, class D>
Node<K,D>& Node<K,D>::getRight() const{
    return this->right;
}

template <class K, class D>
Node<K,D>& Node<K,D>::getPapa() const{
    return this->papa;
}

template <class K, class D>
void Node<K,D>::setPapa(const Node<K,D>& papa){
    this->papa=papa;
}

int max(int a, int b){
    if (a>b) return a;
    return b;
}

#endif
