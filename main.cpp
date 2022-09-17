
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

    // std::vector<int> v;

    // for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
    //     mp.insert(_make_pair(i, j));
    //     std::cout << mp.size() << std::endl;
    // }
    // // g_start2 = timer();
    // _map<int, int> mp2(mp.begin(), mp.end());
    // // g_end2 = timer();
    // _map<int, int>::iterator it = mp2.begin();



    // for (int i = 0; i < 30 * _ratio; ++i, it++) {
    //     v.push_back(it->first);
    //     v.push_back(it->second);

    // }
    // ////////////////
    // std::map<T, V> mp20;

    //     std::vector<int> v1;

    // for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
    //     mp20.insert(std::make_pair(i, j));
    // }

    // std::map<int, int> mp3(mp20.begin(), mp20.end());

    // std::map<int, int>::iterator it2 = mp3.begin();
    // for (int i = 0; i < 30 * _ratio; ++i, it2++) {
    //     v1.push_back(it2->first);
    //     v1.push_back(it2->second);
    // }
    


    fillMap(mp);
    for (typename _map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    _map<int, int, std::greater<int> > mp2;
    mp2.insert(_make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    _map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for (typename _map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for (typename _map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for (typename _map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for (typename _map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for (typename _map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::logical_and<int> > mp8;
    fillMap(mp8);
    for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }


    v.push_back(mp1.size());
    // return v;
    }


