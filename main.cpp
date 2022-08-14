
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>
# include <vector>
#include "stack.hpp"
# include <iterator>
#include "vector.hpp"


void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
}


// void print(int id, ft::Vector<int>& container)
// {
//     std::cout << id << ". ";
//     for (int x: container) {
//          std::cout << x << ' ';
//     }
//     std::cout << '\n';
// }
 
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



std::cout << "===== Vector =====" << std::endl;
    std::vector<int> v;
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Print out the vector



    std::cout << "===== std :: assign =====" << std::endl;

    std::vector<char> characters;
 
 
    characters.assign(5, 'a');
 
    std::vector<int> myvector2;
    for (int i=1; i<=5; i++) myvector2.push_back(10);
    std::vector<int>::iterator it2;




    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());

 

    std::vector<int> c1(3, 100);
    print(1, c1);
 
    auto it = c1.begin();
    it = c1.insert(it, 200);
    print(2, c1);
 
    c1.insert(it, 2, 300);
    print(3, c1);

    std::vector<int> c2(2, 400);
    c1.insert(std::next(it, 2), c2.begin(), c2.end());
    print(4, c1);
    


    ///////////////my_vector /////////////////
    ft::Vector<int> c10(3);
    int i = 100;
    c10.push_back(i);
    c10.push_back(100);
    c10.push_back(100);
    ft::Vector<int>::iterator it1;
     it1 = c10.begin();
     for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}
     std::cout << "\n=================" <<std::endl;
    it1 = c10.insert(it1, 200);
    for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}
     std::cout << "\n=================" <<std::endl;
    c10.insert(it1, 2, 300);
    for(int i = 0 ; i < (int ) c10.size() ; i++) {std::cout << c10[i] << " ";}

    // std::vector<int> c2(2, 400);
    // c1.insert(std::next(it, 2), c2.begin(), c2.end());
    // print(4, c1);



// явная специализация шаблонов
}
