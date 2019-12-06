//
// Created by danie on 06/12/2019.
//

#include "server.h"

int Server::getID(){
    return this->ID;
}

int Server::getOS(){
    return this->OS;
}

void Server::setOS(int OS){
    this->OS=OS;
}

bool Server::getTaken(){
    return this->taken;
}

void Server::setTaken(bool isTaken){
    this->taken=isTaken;
}
