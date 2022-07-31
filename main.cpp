
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>
# include <vector>
#include "stack.hpp"

// #include "vector.hpp"
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

	ft::Vector <int> my_vector;
}
