
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
#include "utils.hpp"
#include <vector>
#include <map>
#include "map.hpp"
#include <string>
// #include <string_view>


#define	_vector 			ft::Vector
#define	_stack 			ft::Stack
#define	_map 			ft::Map
#define	_make_pair 			ft::make_pair
#define	_pair 				ft::pair
#define _ratio  10
#define T int
#define V int
int main() {
    std::vector<int> v;
    // _map<int> mp;
    _map<int, int> mp;
    for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
     _map<T, V>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    std::cout << "here " << mp.size() << std::endl;
    _map<T, V>::iterator it4 = mp.begin();
    for (; it4 != mp.end(); it4 = mp.begin())
    {
        std::cout << it4._iter << std::endl;
        mp.erase(it4);
    }
    std::cout << "here 2" << std::endl;
    v.push_back(mp.size());
    _map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(_make_pair(i, j));
     _map<T, V>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    ittest = mp2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
     _map<T, V>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    }


