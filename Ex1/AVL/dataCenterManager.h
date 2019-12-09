//
// Created by danie on 06/12/2019.
//

#ifndef AVL_DATACENTERMANAGER_H
#define AVL_DATACENTERMANAGER_H

#include "avl.h"
#include "dataCenter.h"
#include "library1.h"
#include "key.h"
#include <memory>

class DataCenterManager{
private:
    Avl<int,DataCenter> DCs_by_ID;
    Avl<Key,DataCenter> DCs_by_NumOfLinux;
    Avl<Key,DataCenter> DCs_by_NumOfWindows;
    int num_of_DCs;
public:
    DataCenterManager():num_of_DCs(0){};
    StatusType AddDataCenter(int DC_ID, int num_of_servers);
    StatusType RemoveDataCenter(int DC_ID);
    StatusType RequestServer(int DC_ID, int server_ID, int OS, int* assigned_server_ID);
    StatusType FreeServer(int DC_ID, int server_ID);
    StatusType GetDataCentersByOs(int OS, int** data_centers, int* num_of_data_servers);
};

class AddToArray{
private:
    int i;
    int** IDs_array;
public:
    void operator()(const std::shared_ptr<Node<Key,DataCenter>>& node){
        (this->IDs_array)[0][i] = node->getData()->getID();
        i++;
    }
    explicit AddToArray(int** dcs):i(0),IDs_array(dcs){};
    AddToArray(const AddToArray& a) = delete;
};

#endif //AVL_DATACENTERMANAGER_H
