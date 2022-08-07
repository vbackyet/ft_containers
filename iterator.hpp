#pragma once
#include <iostream>
#include <iterator>


namespace ft
{
    template <class It>
    class LegacyRandomAccessIterator
    {
        private:
        public:
         typedef typename std::iterator_traits<It>::value_type value_type;
         typedef typename std::iterator_traits<It>::difference_type difference_type;
         typedef typename std::iterator_traits<It>::reference reference;

    };
}