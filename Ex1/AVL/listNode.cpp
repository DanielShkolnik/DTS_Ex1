//
// Created by danie on 07/12/2019.
//

#include "listNode.h"



ListNode::~ListNode(){
    delete this->server;
}

ListNode::ListNode(const ListNode& listNode){
    this->server = new Server(*(listNode.server));
    this->next = listNode.next;
    this->prev = listNode.prev;
}

ListNode& ListNode::operator=(const ListNode& listNode){
    delete this->server;
    this->server = new Server(*(listNode.server));
    this->next = listNode.next;
    this->prev = listNode.prev;
    return *this;
}

void ListNode::setNext(ListNode* next){
    this->next = next;
}

void ListNode::setPrev(ListNode* prev){
    this->prev = prev;
}

ListNode* ListNode::getNext(){
    return this->next;
}

ListNode* ListNode::getPrev(){
    return this->prev;
}

Server* ListNode::getServer(){
    return this->server;
}

void ListNode::setServer(Server* server){
    delete this->server;
    this->server = server;
}
