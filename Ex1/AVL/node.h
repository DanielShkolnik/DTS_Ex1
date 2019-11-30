#ifndef NODE_H_
#define NODE_H_

#include <memory>
template <class K, class D>
class Node{
private :
    K key;
    D data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> papa;
    int height;
public:
    Node()= delete;
    Node(K key, D data,std::shared_ptr<Node> papa);
    ~Node()= default;
    Node(const Node&)= delete;
    std::shared_ptr<Node> operator=(const Node&)= delete;
    void calcHeight();
    void setLeft(const std::shared_ptr<Node<K,D>>& left);
    void setRight(const std::shared_ptr<Node<K,D>>& right);
    int getHeight() const;
    const K& getKey() const;
    const D& getData() const;
    std::shared_ptr<Node> getLeft();
    std::shared_ptr<Node> getRight();
    std::shared_ptr<Node> getPapa();
    void setPapa(std::shared_ptr<Node> papa);
    bool isLeaf();
    bool isRoot();

};

static int max(int a, int b){
    if (a>b) return a;
    return b;
}

template <class K, class D>
Node<K,D>::Node(K key, D data, std::shared_ptr<Node<K,D>> papa):key(key),data(data),papa(papa),height(1){}


template <class K, class D>
void Node<K,D>::calcHeight(){
    if(this->left== nullptr && this->right== nullptr)this->height = 1; //leaf
    else if(this->left== nullptr) this->height = this->right->height +1; // no left son
    else if(this->right== nullptr) this->height = this->left->height +1; // no right son
    else this->height= max(this->left->height,this->right->height) + 1; // max between sons
}

template <class K, class D>
void Node<K,D>::setLeft(const std::shared_ptr<Node<K,D>>& left){
    this->left = left;
}

template <class K, class D>
void Node<K,D>::setRight(const std::shared_ptr<Node<K,D>>& right){
    this->right = right;
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
std::shared_ptr<Node<K,D>> Node<K,D>::getLeft(){
    return this->left;
}

template <class K, class D>
std::shared_ptr<Node<K,D>> Node<K,D>::getRight(){
    return this->right;
}

template <class K, class D>
std::shared_ptr<Node<K,D>> Node<K,D>::getPapa(){
    return this->papa;
}

template <class K, class D>
void Node<K,D>::setPapa(std::shared_ptr<Node<K,D>> papa){
    this->papa= papa;
}

template <class K, class D>
bool Node<K,D>::isLeaf() {
    return  (this->getRight() == nullptr && this->getLeft() == nullptr);
}
template <class K, class D>
bool Node<K,D>::isRoot(){
    return this->getPapa() == nullptr;
}

#endif
