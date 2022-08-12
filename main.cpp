
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>
# include <vector>
#include "stack.hpp"
# include <iterator>
#include "vector.hpp"
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
    std::cout << "v = { ";
    for (int n : v) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";


    std::cout << "===== std :: assign =====" << std::endl;

    std::vector<char> characters;
 
    auto print_vector = [&](){
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
 
    characters.assign(5, 'a');
    print_vector();
 
    std::vector<int> myvector2;
    for (int i=1; i<=5; i++) myvector2.push_back(10);
    std::vector<int>::iterator it2 = myvector2.begin() ;

    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);
    std::cout << "myvector contains:";
    std::vector<int>::iterator it = myvector.begin() ;
    std::cout << "***********************" << *it;
    it++;
    it2= it;
    std::cout << "***********************" << *(it2-1);
    std::cout << '\n';





    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_vector();
 
    // characters.assign({'C', '+', '+', '1', '1'});
    // print_vector();


    std::cout << "===== ft :: assign =====" << std::endl;
    ft::Vector <int> my_vector(6);
    ft::Vector<int>::value_type a = 6;
    ft::Vector<int>::allocator_type o;
    a = 4;
    std::vector<int>::iterator ptr;
    //  std::cout << o << std::endl;
    // my_vector.assign(4, 1);
    //    auto print_my_vector = [&](){
    // for (int u : my_vector)
    //         std::cout << u << ' ';
    //     std::cout << '\n';  
    // };
    // print_my_vector();
// явная специализация шаблонов
}
