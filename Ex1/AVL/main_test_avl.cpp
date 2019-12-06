#include <iostream>
#include "avl.h"
void print_key(const std::shared_ptr<Node<int,int>>& node_ptr){
   std::cout<<"("<<node_ptr->getKey()<<","<<node_ptr->getHeight()<<","<<node_ptr->getData()<<")";
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
      a.delete_element(40);
      a.delete_element(50);
      a.insert(120,3);
      a.insert(130,3);
      a.insert(38,3);
      a.insert(36,3);
      a.insert(95,3);
      a.insert(107,3);
      a.insert(103,3);
      a.insert(115,3);
      a.delete_element(100);
      a.delete_element(90);
      a.delete_element(41);
      a.delete_element(36);
      a.delete_element(35);
      a.insert(47,3);
      a.insert(80,3);
      a.delete_element(43);
      a.insert(10,3);
      a.delete_element(45);
      a.delete_element(38);
      a.delete_element(30);
      a.insert(150,3);
      a.insert(140,3);
      a.delete_element(47);
      a.insert(111,3);
      a.insert(125,3);
      a.delete_element(115);
      a.find(125)->setData(10);
      postorder(a.getHead(),print_key);
      std::cout<<std::endl;
      std::cout<<std::endl<<"finito"<<std::endl;
   }
   catch(Avl<int,int>::KeyExists err) {
      std::cout<<"key exists"<<std::endl;
   }

}