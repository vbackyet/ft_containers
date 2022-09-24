
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
#define	_is_integral 			ft::is_integral
#define _ratio  10
#define T int
#define V int


class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

int main() {
//     _vector<T> vector;
//     std::vector<int> v;
//     _vector<int> tmp;
//     tmp.assign(2600 * _ratio, 1);
//     vector.assign(4200 * _ratio, 1);
//     vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());

//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     _vector<A> vv;
//     _vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     vv.insert(vv.begin(), v1.begin(), v1.end());
//     // try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     // catch (...) {
//         // std::cout<< "here " <<std::endl ;
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     // }
//     for (unsigned long i=0; i<v.size(); ++i)
//     std::cout << v[i] << ' ';
//     std::cout << std::endl;
//     std::cout << vv.size() << vv.capacity()<< std::endl;
// ///// NOT MINE ////

//     std::vector<T> vector0;
//    std::vector<int> v0;
//     std::vector<int> tmp0;
//     tmp0.assign(2600 * _ratio, 1);
//     vector0.assign(4200 * _ratio, 1);

//     vector0.insert(vector0.end() - 1000 * _ratio, tmp0.begin(), tmp0.end());

//     v0.push_back(vector0[3]);
//     v0.push_back(vector0.size());
//     v0.push_back(vector0.capacity());

//     std::unique_ptr<B> k20(new B(3));
//     std::unique_ptr<B> k30(new B(4));
//     std::unique_ptr<B> k40(new B(-1));
//     std::vector<A> vv0;
//     std::vector<B*> v10;

//     v10.push_back(&(*k20));
//     v10.push_back(&(*k30));
//     v10.push_back(&(*k40));
//      std::cout<< std::endl << v10.size() << v10.capacity()<< std::endl;


//     // try { vv0.insert(vv0.begin(), v10.begin(), v10.end()); }
//     // catch (...) {
//         // std::cout<< "here " <<std::endl ;
//         // vv0.insert(vv0.begin(), v10.begin(), v10.end());
//         v0.push_back(vv0.size());
//         v0.push_back(vv0.capacity());
//     // }
//     for (unsigned long i=0; i<v0.size(); ++i)
//     std::cout << v0[i] << ' ';

//     std::cout<< std::endl << vv0.size() << vv0.capacity()<< std::endl;






//     _vector<T> vector;
//     std::vector<int> v;
//     vector.assign(10, 1);

//     for (unsigned long i=0; i<vector.size(); ++i)
//     std::cout << vector[i] << ' ' << "\n";

//     v.push_back(*vector.rbegin());
//     v.push_back(*(vector.rbegin() + 1));

//     for (unsigned long i=0; i<v.size(); ++i)
//     std::cout << v[i] << ' ' << "\n";


// ///////
//     std::vector<T> vector0;
//     std::vector<int> v0;
//     vector0.assign(10, 1);

//     v0.push_back(*vector0.rbegin());
//     v0.push_back(*(vector0.rbegin() + 1));

//     for (unsigned long i=0; i<v0.size(); ++i)
//     std::cout << v0[i] << ' '<< "\n";



    std::vector<int> v;
    std::map<T, V> mp;


    mp.insert(std::make_pair(5, 5));
    mp.insert(std::make_pair(3, 3));
    mp.insert(std::make_pair(7, 7));
    typename std::map<T, V>::reverse_iterator rit = mp.rbegin();
    // typename std::map<T, V>::reverse_iterator rit2 = mp.rend();
    std::cout << rit->first << rit->second <<std::endl;
    v.push_back(rit->first);
    // rit++;
    // rit2--;
    // v.push_back(rit->first);
    // v.push_back(rit2->first);
    // rit++;
    // v.push_back(*rit == *rit2);
    // rit2--;
    // v.push_back(rit->first);
    // v.push_back(rit2->first);
    // v.push_back(*rit2 > *rit);
    // v.push_back(*rit2 < *rit);
    // v.push_back((--rit)->first);
    // v.push_back((++rit2)->first);
    // v.push_back((rit--)->first);
    // v.push_back((rit2++)->first);
    for (unsigned long i=0; i<v.size(); ++i)
    std::cout << v[i] << ' ';
    std::cout<< std::endl;
    /////////////
        std::vector<int> v0;
        std::map<T, V> mp0;


    mp0.insert(std::make_pair(5, 5));
    mp0.insert(std::make_pair(3, 3));
    mp0.insert(std::make_pair(7, 7));
    typename std::map<T, V>::reverse_iterator rit0 = mp0.rbegin();
    std::cout << rit0->first << rit0->second <<std::endl;
    // typename _map<T, V>::reverse_iterator rit20 = mp0.rend();
    v0.push_back(rit0->first);
    // rit0++;
    // rit20--;
    // v0.push_back(rit0->first);
    // v0.push_back(rit20->first);
    // rit0++;
    // v0.push_back(*rit0 == *rit20);
    // rit20--;
    // v0.push_back(rit0->first);
    // v0.push_back(rit20->first);
    // v0.push_back(*rit20 > *rit0);
    // v0.push_back(*rit20 < *rit0);
    // v0.push_back((--rit0)->first);
    // v0.push_back((++rit20)->first);
    // v0.push_back((rit0--)->first);
    // v0.push_back((rit20++)->first);
        for (unsigned long i=0; i<v0.size(); ++i)
    std::cout << v0[i] << ' ';
}


