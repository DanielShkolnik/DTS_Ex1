//
// Created by danie on 06/12/2019.
//

#include "dataCenterManager.h"
StatusType DataCenterManager::RequestServer(int DC_ID, int server_ID, int OS, int* assigned_server_ID){
    if((OS!=0 && OS!=1) || !assigned_server_ID) return INVALID_INPUT;
    try{
        std::shared_ptr<Node<int,DataCenter>> DC_ptr = this->DCs_by_ID.find(DC_ID);
        *assigned_server_ID = DC_ptr->getData().assignServer(server_ID,OS);
        return SUCCESS;
    }
    catch(Avl<int,DataCenter>::KeyNotFound& e){
        return FAILURE;
    }
    catch(DataCenter::AllServersAreTaken& e){
        return FAILURE;
    }
    catch(DataCenter::InvalidServerID& e){
        return INVALID_INPUT;
    }
    catch(std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
}

StatusType DataCenterManager::RemoveDataCenter(int DC_ID){
    try{
        this->DCs_by_ID.delete_element(DC_ID);
    }
    catch(Avl<K,D>::KeyNotFound())
}

StatusType DataCenterManager::FreeServer(int DC_ID, int server_ID){
    try{
        std::shared_ptr<Node<int,DataCenter>> DC_ptr = this->DCs_by_ID.find(DC_ID);
        DC_ptr->getData().freeServer(server_ID);
        return SUCCESS;
    }
}