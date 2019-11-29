#include <iostream>
#include "avl.h"

void print_key(const std::shared_ptr<Node<int,int>>& node_ptr){
   std::cout<<node_ptr->getKey()<<std::endl;
}

int main() {
   Avl<int,int> a;

   try{
      a.insert(5,3);
      a.insert(6,3);
      a.insert(7,3);
      a.insert(8,3);
      a.insert(9,3);
      inorder(a.getHead(),print_key);
      std::cout<<" Finito Pappie"<<std::endl;
   }
   catch(Avl<int,int>::KeyExists err) {
      std::cout<<"key exists"<<std::endl;
   }

}