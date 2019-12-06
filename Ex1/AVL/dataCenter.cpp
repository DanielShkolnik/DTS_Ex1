//
// Created by danie on 06/12/2019.
//

#include "dataCenter.h"

int DataCenter::assignServer(int server_ID, int OS){
    if(server_ID<0 || server_ID >= this->num_of_servers) throw InvalidServerID();
    if(this->linux_free_head == nullptr && this->windows_free_head == nullptr) throw AllServersAreTaken();
    Server server = this->servers_array[server_ID]->getData();
    //server is not taken
    if(server.getTaken() == false){
        server.setTaken(true);
        server.setOS(OS);
        DataCenter::remove_from_list(OS,server_ID);
        return server.getID();
    }
    //server is taken
    else{
        //OS is linux
        if (OS==0){
            if (this->linux_free_head != nullptr) return getAndRemoveFreeServer(this->linux_free_head);
            else{
                this->windows_free_head->getData().setOS(0);
                return getAndRemoveFreeServer(this->windows_free_head);
            }
        }
        //OS is windows
        else{
            if (this->windows_free_head != nullptr) return getAndRemoveFreeServer(this->windows_free_head);
            else{
                this->linux_free_head->getData().setOS(1);
                return getAndRemoveFreeServer(this->linux_free_head);
            }
        }
    }
}


int DataCenter::getAndRemoveFreeServer(std::shared_ptr<Node<int,Server>>& list){
    list->getData().setTaken(true);
    int assign_ID = list->getData().getID();
    if(list->getData().getOS()==0) this->linux_free_head=this->linux_free_head->getNext();
    else this->windows_free_head=this->windows_free_head->getNext();
    list->setNext(nullptr);
    return assign_ID;
}



void DataCenter::remove_from_list(int OS, int server_ID) {
    std::shared_ptr<Node<int,Server>> server_node=this->servers_array[server_ID];
    //check if head
    if (server_node->getPrev()== nullptr) {
        if (OS == 0) this->linux_free_head = server_node->getNext();
        else this->windows_free_head = server_node->getNext();
    }
    else{
        std::shared_ptr<Node<int,Server>> server_node_prev = server_node->getPrev();
        server_node_prev->setNext(server_node->getNext());
    }
    server_node->setNext(nullptr);
    server_node->setPrev(nullptr);
}


void DataCenter::freeServer(int server_ID){
    if(server_ID >= this->num_of_servers || server_ID < 0) throw InvalidServerID();
    std::shared_ptr<Node<int,Server>> server_ptr = this->servers_array[server_ID];
    server_ptr->getData().setTaken(false); //set free
    // os linux
    if(server_ptr->getData().getOS() == 0){
        server_ptr->
        this->linux_free_tail->setNext(server_ptr);
    }


}