#include <iostream>
#include "avl.h"

void print_key(const std::shared_ptr<Node<int,int>>& node_ptr){
   std::cout<<node_ptr->getKey()<<" ";
}

int main() {
   Avl<int,int> a;

   try{

      a.insert(50,1);
      a.insert(40,1);
      a.insert(100,1);
      a.insert(30,1);
      a.insert(35,1);
      a.insert(45,1);
      a.insert(43,3);
      a.insert(46,3);
      a.insert(90,3);
      a.insert(110,3);
      a.insert(41,3);
      postorder(a.getHead(),print_key);
      std::cout<<std::endl;
      a.delete_element(40);
      postorder(a.getHead(),print_key);
      std::cout<<std::endl;
      a.delete_element(50);
      postorder(a.getHead(),print_key);
      std::cout<<std::endl<<"finito"<<std::endl;
   }
   catch(Avl<int,int>::KeyExists err) {
      std::cout<<"key exists"<<std::endl;
   }

}