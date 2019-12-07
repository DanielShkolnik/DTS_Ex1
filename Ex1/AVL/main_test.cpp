#include <iostream>
#include "avl.h"
#include "dataCenterManager.h"
void print_key(const std::shared_ptr<Node<int,int>>& node_ptr){
    std::cout<<"("<<node_ptr->getKey()<<","<<node_ptr->getHeight()<<","<<node_ptr->getData()<<")";
}

int main() {
    Avl<int,int> a;

    try{

        DataCenterManager* DCM = new DataCenterManager(); // Init
        DCM->AddDataCenter(123,5); // AddDataCenter 123 5 # New data center with 5 servers
        DCM->RequestServer(123,3,1); //RequestServer 123 3 1 # Assigns server 3 as Windows
        DCM->RequestServer(123,3,0); //RequestServer 123 3 0 # Assigns server 0 as Linux
        DCM->RequestServer(123,0,1); //RequestServer 123 0 1 # Assigns server 1 as Windows
        DCM->FreeServer(123,1); //FreeServer 123 1 # Frees server 1
        DCM->FreeServer(123,3); //FreeServer 123 3 # Frees server 3
        DCM->FreeServer(123,3); //FreeServer 123 3 # Server 3 is already free
        DCM->AddDataCenter(456,2); //AddDataCenter 456 2 # New data center with 2 servers
        DCM->RequestServer(456,0,1); //RequestServer 456 0 1 # Assigns server 0 as Windows

        /*
        int* array = new(int[]);
        DCM->GetDataCentersByOs(1); //GetDataCentersByOS 1 # Sorted by Windows

        AddDataCenter 789 10
        GetDataCentersByOS 0 # Sorted by Linux
        RemoveDataCenter 123
        RequestServer 123 3 1 # Data center does not exist anymore
        AddDataCenter 123 -5 # Invalid input is checked first
        Quit
        */
        

        std::cout<<std::endl<<"finito"<<std::endl;
    }
    catch(Avl<int,int>::KeyExists err) {
        std::cout<<"key exists"<<std::endl;
    }

}