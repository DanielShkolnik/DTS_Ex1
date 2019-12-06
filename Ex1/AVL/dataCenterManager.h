//
// Created by danie on 06/12/2019.
//

#ifndef AVL_DATACENTERMANAGER_H
#define AVL_DATACENTERMANAGER_H

#include "avl.h"
#include "dataCenter.h"
#include "library1.h"

class DataCenterManager{
private:
    Avl<int,DataCenter> DCs_by_ID;
    Avl<int,DataCenter> DCs_by_NumOfLinux;
    Avl<int,DataCenter> DCs_by_NumOfWindows;
    int num_of_DCs;
public:
    DataCenterManager()= default;
    StatusType AddDataCenter(int DC_ID, int num_of_servers);
    StatusType RemoveDataCenter(int DC_ID);
    StatusType RequestServer(int DC_ID, int server_ID, int OS, int* assigned_server_ID);
    StatusType FreeServer(int DC_ID, int server_ID);
    StatusType GetDataCentersByOs(int OS, int** data_centers, int* num_of_data_servers);
    void Quit();
};



#endif //AVL_DATACENTERMANAGER_H
