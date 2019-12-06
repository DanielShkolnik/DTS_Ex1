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
    std::shared_ptr<Node<int,Server>> windows_free_head;
    int num_of_linux;
    int num_of_windows;
public:
    int getID();
    int getNumOfLinux();
    int getNumOfWindows();
};

#endif //AVL_DATACENTER_H
