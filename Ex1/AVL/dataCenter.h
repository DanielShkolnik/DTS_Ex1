//
// Created by danie on 06/12/2019.
//

#ifndef AVL_DATACENTER_H
#define AVL_DATACENTER_H

#include <memory>
#include "node.h"
#include "server.h"

class DataCenter{
private:
    int ID;
    std::shared_ptr<Node<int,Server>>* servers_array;
    std::shared_ptr<Node<int,Server>> linux_free_head;
    std::shared_ptr<Node<int,Server>> linux_free_tail;
    std::shared_ptr<Node<int,Server>> windows_free_head;
    std::shared_ptr<Node<int,Server>> windows_free_tail;
    int num_of_linux;
    int num_of_windows;
    int num_of_servers;
    void remove_from_list(int OS, int ID);
    int getAndRemoveFreeServer(std::shared_ptr<Node<int,Server>>& list);
    void appendToList(std::shared_ptr<Node<int,Server>> tail, std::shared_ptr<Node<int,Server>> server_ptr);
public:
    int getID();
    int getNumOfLinux();
    int getNumOfWindows();
    Server* getserver();
    int assignServer(int server_ID, int OS);
    void freeServer(int server_ID);
    class InvalidServerID{};
    class AllServersAreTaken{};
    class ServerIsAlreadyFree{};
};

#endif //AVL_DATACENTER_H
