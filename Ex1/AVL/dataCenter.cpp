//
// Created by danie on 06/12/2019.
//

#include "dataCenter.h"

int DataCenter::assignServer(int server_ID, int OS){
    if(server_ID<0 || server_ID >= this->num_of_servers) throw InvalidServerID();
    if(this->linux_free_head == nullptr && this->windows_free_head == nullptr) throw AllServersAreTaken();
    Server server = this->servers_array[server_ID]->getData();
    if(server.getTaken() == false){
        server.setTaken(true);
        server.setOS(OS);
    }

}

void DataCenter::remove_from_list(int OS, int ID){
    std::shared_ptr<Node<int,Server>> list;
    if(OS==0){
        list = this->linux_free_head;
        if(list->getData().getID() == ID){
            this->linux_free_head = this->linux_free_head->getNext();
            list->getData().setTaken(true);
        }
    }
    else{
        list = this->windows_free_head;
        if(list->getData().getID() == ID){
            this->windows_free_head = this->windows_free_head->getNext();
            list->getData().setTaken(true);
        }
    }

    std::shared_ptr<Node<int,Server>> prev = list;
    std::shared_ptr<Node<int,Server>> current = list->getNext();

    while(current){
        if(current->getData().getID()==ID){
            current->getData().setTaken(true);
            prev->setNext(current->getNext());
            break;
        }
    }
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