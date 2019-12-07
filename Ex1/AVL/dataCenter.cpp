//
// Created by danie on 06/12/2019.
//

#include "dataCenter.h"

int DataCenter::assignServer(int server_ID, int OS){
    if(server_ID<0 || server_ID >= this->num_of_servers) throw InvalidServerID();
    if(this->linux_free_head == nullptr && this->windows_free_head == nullptr) throw AllServersAreTaken();
    Server& server = this->servers_array[server_ID]->getData();
    //server is not taken
    if(server.getTaken() == false){
        server.setTaken(true);
        int prev_OS=server.getOS();
        if(prev_OS!=OS){
            server.setOS(OS);
            if(OS==0){
                this->num_of_linux++;
                this->num_of_windows--;
            }
            else{
                this->num_of_linux--;
                this->num_of_windows++;
            }
        }
        remove_from_list(prev_OS,server_ID);
        return server.getID();
    }
    //server is taken
    else{
        //OS is linux
        if (OS==0){
            if (this->linux_free_head != nullptr) return getAndRemoveFreeServer(0);
            else{
                this->windows_free_head->getData().setOS(0);
                this->num_of_linux++;
                this->num_of_windows--;
                return getAndRemoveFreeServer(1);
            }
        }
        //OS is windows
        else{
            if (this->windows_free_head != nullptr) return getAndRemoveFreeServer(1);
            else{
                this->linux_free_head->getData().setOS(1);
                this->num_of_linux--;
                this->num_of_windows++;
                return getAndRemoveFreeServer(0);
            }
        }
    }
}

// gets the first free server
int DataCenter::getAndRemoveFreeServer(int OS){
    std::shared_ptr<Node<int,Server>> head_ptr;
    if(OS==0)head_ptr = this->linux_free_head;
    else  head_ptr = this->windows_free_head;
    head_ptr->getData().setTaken(true);
    int assign_ID = head_ptr->getData().getID();
    if(OS ==0) this->linux_free_head=this->linux_free_head->getNext();
    else this->windows_free_head=this->windows_free_head->getNext();
    // set the new head prev flied to null
    head_ptr->getNext()->setPrev(nullptr);
    head_ptr->setNext(nullptr);
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
    // if server is already free dont append it to free list
    if(!(server_ptr->getData().getTaken())) throw ServerIsAlreadyFree();
    server_ptr->getData().setTaken(false); //set free
    // os linux
    if(server_ptr->getData().getOS() == 0){
        appendToList(0,server_ptr);
    }
    // os windows
    else{
        appendToList(1,server_ptr);
    }
}

void DataCenter::appendToList(int OS, std::shared_ptr<Node<int,Server>>& server_ptr){
    //linux
    if(OS==0){
        // list is empty
        if(linux_free_head == nullptr){
            linux_free_head = server_ptr;
            linux_free_tail = server_ptr;
        }
        else{
            server_ptr->setPrev(linux_free_tail);
            linux_free_tail->setNext(server_ptr);
            linux_free_tail = linux_free_tail->getNext();
        }
    }
    //windows
    else{
        // list is empty
        if(windows_free_head == nullptr){
            windows_free_head = server_ptr;
            windows_free_tail = server_ptr;
        }
        else{
            server_ptr->setPrev(windows_free_tail);
            windows_free_tail->setNext(server_ptr);
            windows_free_tail = windows_free_tail->getNext();
        }
    }

}

int DataCenter::getID(){
    return this->ID;
}

int DataCenter::getNumOfLinux(){
    return this->num_of_linux;
}

int DataCenter::getNumOfWindows(){
    return this->num_of_windows;
}


DataCenter::DataCenter(int ID, int num_of_servers):ID(ID), servers_array(new std::shared_ptr<Node<int,Server>>[num_of_servers]),windows_free_head(nullptr)
                        ,windows_free_tail(nullptr),num_of_linux(num_of_servers),num_of_windows(0),num_of_servers(num_of_servers){
    Server server(0,0);
    std::shared_ptr<Node<int,Server>> current_server_ptr(new Node<int,Server>(0,server, nullptr, nullptr));
    this->servers_array[0]=current_server_ptr;
    this->linux_free_head=current_server_ptr;
    for(int i=1; i<num_of_servers; i++){
        server=Server(i,0);
        std::shared_ptr<Node<int,Server>> next_server_ptr(new Node<int,Server>(i,server, current_server_ptr, nullptr));
        current_server_ptr->setNext(next_server_ptr);
        this->servers_array[i]=next_server_ptr;
        current_server_ptr=next_server_ptr;
    }
    this->linux_free_tail=current_server_ptr;
}


DataCenter::~DataCenter(){
    std::shared_ptr<Node<int,Server>> current_w = this->windows_free_head;
    while (current_w){
        std::shared_ptr<Node<int,Server>> prev_w = current_w;
        prev_w->setPrev(nullptr);
        prev_w->setNext(nullptr);
        current_w = current_w->getNext();
    }

    std::shared_ptr<Node<int,Server>> current_l = this->linux_free_head;
    while (current_l){
        std::shared_ptr<Node<int,Server>> prev_l = current_l;
        prev_l->setPrev(nullptr);
        prev_l->setNext(nullptr);
        current_l = current_l->getNext();
    }
    this->linux_free_head = nullptr;
    this->linux_free_tail = nullptr;
    this->windows_free_head = nullptr;
    this->windows_free_tail = nullptr;

    delete[] this->servers_array;
    this->servers_array = nullptr;
}

DataCenter::DataCenter(const DataCenter& dc){
    this->ID = dc.ID;
    this->num_of_linux = dc.num_of_linux;
    this->num_of_windows = dc.num_of_windows;
    this->num_of_servers = dc.num_of_servers;
    this->servers_array = new std::shared_ptr<Node<int,Server>>[dc.num_of_servers];
    for(int i=0; i<dc.num_of_servers; i++){
        this->servers_array[i] = std::shared_ptr<Node<int,Server>>(new Node<int,Server>(dc.servers_array[i]->getKey(),
                                                                    dc.servers_array[i]->getData()));
    }
    this->linux_free_head = dc.linux_free_head;
    this->linux_free_tail = dc.linux_free_tail;
    this->windows_free_head = dc.windows_free_head;
    this->windows_free_tail = dc.windows_free_tail;
}

DataCenter& DataCenter::operator=(const DataCenter& dc){
    this->ID = dc.ID;
    this->num_of_linux = dc.num_of_linux;
    this->num_of_windows = dc.num_of_windows;
    this->num_of_servers = dc.num_of_servers;
    this->servers_array = new std::shared_ptr<Node<int,Server>>[dc.num_of_servers];
    for(int i=0; i<dc.num_of_servers; i++){
        this->servers_array[i] = dc.servers_array[i];
    }
    this->linux_free_head = dc.linux_free_head;
    this->linux_free_tail = dc.linux_free_tail;
    this->windows_free_head = dc.windows_free_head;
    this->windows_free_tail = dc.windows_free_tail;
    return *this;
}