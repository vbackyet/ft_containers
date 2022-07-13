
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>

#include "stack.hpp"
int main(void)
{

	std::cout << "===== STACK =====" << std::endl;
	ft::Stack <float> my_stack;
	ft::Stack <float> my_stack2(my_stack);
	std::cout << "-" << std::endl;
	my_stack2.push(3.8);
	std::cout <<  my_stack2.top() <<"-top" << std::endl;



// #####################################
	std::stack <float>puk1;
	std::stack <float>puk2(puk1);
	puk1.push(2);
	std::cout << puk1.top() <<std::endl;
}
