#pragma once
#include <functional>
#include "tree.hpp"
#include <iostream>
#include <ostream>
#include <iterator>
namespace ft
{
    // ключ / значение / как сравнивать / аллокатор
    template< class Key,  class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
    class Map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T>    value_type;
        typedef Compare																				key_compare;
		typedef Allocator																			allocator_type;
        typedef typename Allocator::reference														reference;
		typedef typename Allocator::const_reference													const_reference;
		typedef typename Allocator::pointer															pointer;
		typedef typename Allocator::const_pointer													const_pointer;
		typedef typename Allocator::size_type														size_type;
		typedef typename Allocator::difference_type													difference_type;
        //iterators
    
    private:
        typedef typename Allocator::template rebind< ft::Node<value_type> >::other		allocatorNode;
        key_compare _comp; 
        allocator_type _alloc;
        ft::Tree<key_type, allocatorNode, key_compare>  _tree;

    public:
        Map(/* args */);
        explicit Map( const Compare& comp = key_compare(),const Allocator& alloc = allocator_type() ): _comp(comp) , _alloc(alloc), tree()
        {


        };
        template< class InputIt >
        Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
        Map( const Map& other );
        ~Map();
    };
    
};