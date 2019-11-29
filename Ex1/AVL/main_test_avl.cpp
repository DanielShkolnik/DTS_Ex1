#include <iostream>
#include "avl.h"

void print_key(const std::shared_ptr<Node<int,int>>& node_ptr){
   std::cout<<node_ptr->getKey()<<" ";
}

int main() {
   Avl<int,int> a;

   try{

      a.insert(1,1);
      a.insert(2,1);
      a.insert(3,1);
      a.insert(4,1);
      a.insert(5,1);
      a.insert(6,1);
      /*
      a.insert(50,3);
      a.insert(60,3);
      a.insert(55,3);
      a.insert(70,3);
      a.insert(57,3);
      a.insert(80,3);
      */
      inorder(a.getHead(),print_key);
      std::cout<<std::endl;
      postorder(a.getHead(),print_key);
      std::cout<<std::endl<<"finito"<<std::endl;
   }
   catch(Avl<int,int>::KeyExists err) {
      std::cout<<"key exists"<<std::endl;
   }

}