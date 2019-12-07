//
// Created by danie on 07/12/2019.
//

#ifndef AVL_LIST_H
#define AVL_LIST_H

#include "server.h"

class List{
private :
    Server* server;
    *List next;
    *List prev;
    public:
    Node()= delete;
    Node(K key, D data,std::shared_ptr<Node> papa);

    ~Node();
    Node(const Node& node) = delete;
    Node& operator=(const Node& node) = delete;
    void calcHeight();
    void setLeft(const std::shared_ptr<Node<K,D>>& left);
    void setRight(const std::shared_ptr<Node<K,D>>& right);
    int getHeight() const;
    const K& getKey() const;
    D& getData();
    void setData(const D& data);
    std::shared_ptr<Node> getLeft();
    std::shared_ptr<Node> getRight();
    std::shared_ptr<Node> getPapa();
    void setPapa(std::shared_ptr<Node> papa);
    bool isLeaf();
    bool isRoot();
    // for list use.
    std::shared_ptr<Node> getNext();
    std::shared_ptr<Node> getPrev();
    void setPrev(const std::shared_ptr<Node>& prev);
    void setNext(const std::shared_ptr<Node>& next);
    Node(K key, D data,std::shared_ptr<Node> prev,std::shared_ptr<Node> next);
};



#endif //AVL_LIST_H
