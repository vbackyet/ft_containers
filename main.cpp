
# include <memory>
# include <iostream>
# include <cstddef>
# include <limits>
# include <stack>
// # include <vector>
#include "stack.hpp"
# include <iterator>
// #include "vector.hpp"
#include "tree.hpp"
#include <vector>
#include <map>
#include "map.hpp"
#include <string>
#include <string_view>


#define	_vector 			ft::Vector
#define	_stack 			ft::Stack
#define	_map 			ft::Map
#define	_make_pair 			ft::make_pair
#define	_pair 				ft::pair
#define _ratio  1000

int main() {
    std::vector<int> v;
    // _map<int> mp;
    _map<int, int> mp;
    // g_start2 = g_end2 = timer();
    v.push_back(mp.count(0));
    mp.insert(_make_pair(0, 0));
    v.push_back(mp.count(0));


}

