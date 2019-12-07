//
// Created by danie on 07/12/2019.
//

#include "listNode.h"



ListNode::~ListNode(){
    delete this->server;
}

ListNode::ListNode(const ListNode& ListNode){

}

ListNode& ListNode::operator=(const ListNode& ListNode){

}

void ListNode::setNext(const ListNode& next){

}

void ListNode::setPrev(const ListNode& prev){

}

ListNode* ListNode::getNext(){

}

ListNode* ListNode::getPrev(){

}

Server* ListNode::getServer(){

}

void ListNode::setServer(const Server& server){

}