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
    if(DC_ID<=0) return INVALID_INPUT;
    try{
        this->DCs_by_ID.delete_element(DC_ID);
    }
    catch(Avl<int,DataCenter>::KeyNotFound& e){
        return FAILURE;
    }
    catch(std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    }
}

StatusType DataCenterManager::GetDataCentersByOs(int OS, int** data_centers, int* num_of_data_servers){
    if(!data_centers || (OS!=0 && OS!=1) || !num_of_data_servers) return INVALID_INPUT;
    if(this->DCs_by_ID.getHead()== nullptr) return FAILURE;
    try{
        //linux servers
        if(OS==0){

        }


    }
    catch(std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    }

}


void addDCToArray(const std::shared_ptr<Node<Key,DataCenter>>& data_center){

}