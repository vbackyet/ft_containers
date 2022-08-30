
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


#define	_vector 			ft::Vector


int main() {
  _vector<int> vector(28, 7);
    _vector<int>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    // g_start2 = timer();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    std::cout << it << std::endl;
    // g_end2 = timer();

}
