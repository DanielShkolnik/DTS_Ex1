//
// Created by danie on 06/12/2019.
//

#ifndef AVL_KEY_H
#define AVL_KEY_H

class Key{
private:
    int ID;
    int num_of_servers;
public:
    Key()= default;
    ~Key()= default;
    Key(const Key& key)= default;
    Key& operator=(const Key& key)= default;
    bool operator<(const Key& other);
    bool operator==(const Key& other);
};

#endif //AVL_KEY_H