
#include"library1.h"
#include "dataCenterManager.h"

void *Init() {
    DataCenterManager *DS = new DataCenterManager ();
    return (void*)DS;
}
StatusType AddDataCenter(void *DS, int dataCenterID, int numOfServers) {
    return ((DataCenterManager *)DS)-> AddDataCenter(dataCenterID, numOfServers);
}

StatusType RemoveDataCenter(void *DS, int dataCenterID){
    return ((DataCenterManager *)DS)-> RemoveDataCenter(dataCenterID);
}

StatusType RequestServer(void *DS, int dataCenterID, int serverID, int os, int *assignedID){
    return ((DataCenterManager *)DS)-> RequestServer(dataCenterID,serverID,os,assignedID);
}

StatusType FreeServer(void *DS, int dataCenterID, int serverID){
    return ((DataCenterManager *)DS)-> FreeServer(dataCenterID,serverID);
}

StatusType GetDataCentersByOS(void *DS, int os, int **dataCenters, int* numOfDataCenters){
    return ((DataCenterManager *)DS)-> GetDataCentersByOs(os,dataCenters,numOfDataCenters);
}

void Quit(void** DS){
    delete *(DataCenterManager **)DS;
    *DS = nullptr;
}