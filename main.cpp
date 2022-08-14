
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



    std::cout << "===== std :: assign =====" << std::endl;

    std::vector<char> characters;
 
 
    characters.assign(5, 'a');
 
    std::vector<int> myvector2;
    for (int i=1; i<=5; i++) myvector2.push_back(10);
    std::vector<int>::iterator it2;




    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());

 
    // characters.assign({'C', '+', '+', '1', '1'});
    // print_vector();

    std::vector<int> bar;
    std::vector<int>::size_type sz;
     sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(23);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }
        bar.reserve(2);
    std::cout << bar.at(0) << std::endl;



    std::cout << "===== ft :: assign =====" << std::endl;
    ft::Vector <int> my_vector(6);
    for (int i=1; i<=3; i++) my_vector.push_back(i);
    for (int i=0; i<3; i++) 
    {   try
        {std::cout << my_vector[i] <<  " |" <<std::endl;}
        catch(...){
        std::cout <<  " |" <<std::endl;}
        }
    // const int u = my_vector.at(0);
    std::cout <<  my_vector.size() <<" " << my_vector.front() << " end\n";
    // std::cout << my_vector[0]<< "\n";
    ft::Vector<int>::value_type a = 6;
    // ft::Vector<int>::allocator_type o;
    a = 4;
    ft::Vector<int>::iterator ptr;
    ptr = my_vector.begin();
    std::cout << my_vector.capacity() << '\n';
    my_vector.reserve(100);
    std::cout << my_vector.capacity() << '\n';

// явная специализация шаблонов
}
