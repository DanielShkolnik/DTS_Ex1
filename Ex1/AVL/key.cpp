//
// Created by danie on 06/12/2019.
//

#include "key.h"

bool Key::operator<(const Key& other){
    if(this->num_of_servers>other.num_of_servers) return true;
    else if(this->num_of_servers==other.num_of_servers){
        return this->ID<other.ID;
    }
    return false;
}

bool Key::operator==(const Key& other){
    return (this->ID==other.ID && this->num_of_servers==other.num_of_servers);
}