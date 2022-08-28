
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>
# include <vector>
#include "stack.hpp"
# include <iterator>
#include "vector.hpp"
#include "tree.hpp"
#include <vector>
#include <map>
#include "map.hpp"
#include <string>
#include <string_view>





int main(void)
{

// 	std::cout << "===== STACK =====" << std::endl;
// 	ft::Stack <float> my_stack;
// 	ft::Stack <float> my_stack2(my_stack);
// 	std::cout << "-" << std::endl;
// 	my_stack2.push(3.8);
// 	my_stack.push(3.8);
// 	std::cout <<  my_stack2.top() <<"-top" << std::endl;

// 	std::cout << "operator ==" << std::endl;
// 	std::cout << (my_stack == my_stack2) << std::endl;

// // #####################################
// 	std::stack <float>puk1;
// 	std::stack <float>puk2(puk1);
// 	// почему то с флоатом не работает !!!
// 	puk1.push(2);
// 	puk2.push(2);
// 	std::cout << puk1.top() <<std::endl;
// 	std::cout << "operator ==" << std::endl;
// 	std::cout << (puk1 == puk2) << std::endl;


// 	//####################################################
 
    // Print out the vector



    // std::cout << "===== std :: assign =====" << std::endl;

    // std::vector<char> characters;
 
 
    // characters.assign(5, 'a');
 
    // std::vector<int> myvector2;
    // for (int i=1; i<=5; i++) myvector2.push_back(10);
    // std::vector<int>::iterator it2;




    // const std::string extra(6, 'b');
    // characters.assign(extra.begin(), extra.end());

 

    // std::vector<int> c1(3, 100);
    // print(1, c1);
 
    // auto it = c1.begin();
    // it = c1.insert(it, 200);
    // print(2, c1);
    // c1.swap(c1);
    // c1.insert(it, 2, 300);
    // print(3, c1);

    // std::vector<int> c2(2, 400);
    // c1.insert(std::next(it, 2), c2.begin(), c2.end());
    // print(4, c1);
    


    ///////////////my_vector /////////////////
    // ft::Vector<int> c10(3);
    // int i = 100;
    // c10.push_back(i);
    // c10.push_back(100);
    // c10.push_back(100);
    // for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << &c10[i] << " ";}
    // std::cout << "\n=================" <<std::endl;
    // ft::Vector<int>::iterator it1;
    //  it1 = c10.begin();
    //  for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}
    //  std::cout << "\n=================" <<std::endl;
    // it1 = c10.insert(it1, 200);
    // for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}
    //  std::cout << "\n=================" <<std::endl;
    // c10.insert(it1, 2, 300);
    // for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}
    // std::cout << "\n=================" <<std::endl;


    // ft::Vector<int> c20(2);
    // ft::Vector<int> c30(2);
    // c20.assign(25, 7);
    // c30.assign(25, 8);
    // // std::cout << (c20 == c30) << " true "<<std::endl;
    // std::cout << (c20 < c30) << " true "<< std::endl;




    // ft::Tree<int, std::allocator<int>> *my_tree = new ft::Tree<int, std::allocator<int>>();
    // ft::Node<int> *node2 = new ft::Node<int>(23);
    // my_tree->add(new ft::Node<int>(2));
    // my_tree->add(node2);
    // my_tree->add(new ft::Node<int>(1));
    // my_tree->add(new ft::Node<int>(13));
    // my_tree->add(new ft::Node<int>(9));
    // my_tree->add(new ft::Node<int>(15));
    // my_tree->add(new ft::Node<int>(134));
    // ft::Node<int> *head = my_tree->head;
    // my_tree->print_tree(head);
    // my_tree->deleteNode(node2);
    //  my_tree->print_tree(head);

    // 

std::cout << "===== MAp stNDART=====" << std::endl;
  // // (1) Default constructor
  // std::map<std::string, int> map1;
  // map1["something"] = 69;
  // map1["anything"] = 199;
  // map1["that thing"] = 50;
  // std::cout << "map1 = " << map1;
 
  // // (4) Range constructor
  // std::map<std::string, int> iter(map1.find("anything"), map1.end());
  // std::cout << "\niter = " << iter;
  // std::cout << "map1 = " << map1;
 
  // // (6) Copy constructor
  // std::map<std::string, int> copied(map1);
  // std::cout << "\ncopied = " << copied;
  // std::cout << "map1 = " << map1;

std::cout << "===== Map MINE=====" << std::endl;
//  std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
  // (1) Default constructor
  // ft::Map<std::string, int> map10;
  // map1["something"] = 69;
  // map1["anything"] = 199;
  // map1["that thing"] = 50;
  // std::cout << "map1 = " << map10;
 
//   // (4) Range constructor
//   std::map<std::string, int> iter(map10.find("anything"), map10.end());
//   std::cout << "\niter = " << iter;
//   std::cout << "map1 = " << map10;
 
//   // (6) Copy constructor
//   std::map<std::string, int> copied(map10);
//   std::cout << "\ncopied = " << copied;
//   std::cout << "map1 = " << map10;




}
