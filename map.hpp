#pragma once
#include <functional>
namespace ft
{
    template<

    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >>
    class Map
    {
    private:
        /* data */
    public:
        Map(/* args */);
        ~Map();
    };
    
};