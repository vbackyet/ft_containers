
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
#define	_map 			ft::Map
#define	_make_pair 			ft::make_pair
#define _ratio  1000

int main() {
    // _vector<int> vector(28, 7);
    _map<int, int> mp;
    _vector<int> tmp, tmp2;
    std::vector<int> v;

    for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
        mp.insert(_make_pair(i, j));}

    _map<int, int> mp2(mp.begin(), mp.end());

    _map<int, int>::iterator it = mp2.begin();
    for (int i = 0; i < 30 * _ratio; ++i, it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    std::cout << << std::endl;

}

