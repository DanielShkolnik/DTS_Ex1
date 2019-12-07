//
// Created by danie on 07/12/2019.
//

#ifndef AVL_ListNode_H
#define AVL_ListNode_H

#include "server.h"

class ListNode{
private :
    Server* server;
    ListNode* next;
    ListNode* prev;
    public:
    ListNode()= default;
    ListNode(Server* server, ListNode* next = nullptr, ListNode* prev = nullptr):server(new Server(server)),next(next),prev(prev);
    ~ListNode(); //delete new Server
    ListNode(const ListNode& ListNode);
    ListNode& operator=(const ListNode& ListNode);
    void setNext(const ListNode& next);
    void setPrev(const ListNode& prev);
    ListNode* getNext();
    ListNode* getPrev();
    Server* getServer();
    void setServer(const Server& server);
};


#endif //AVL_ListNode_H
