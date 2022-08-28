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
        typedef ft::IteratorForMap<ft::Node<value_type>*>      iterator;
        typedef ft::IteratorForMap<ft::Node<const value_type>*>      const_iterator;

        typedef ft::ReverseIteratorForVector<iterator>														reverse_iterator;
		typedef ft::ReverseIteratorForVector<const_iterator>												const_reverse_iterator;
        typedef 
        class value_compare: public std::binary_function<value_type, value_type, bool>
        {
            friend class ft::Map<Key, T, Compare, Allocator>;
            protected:
            Compare comp;

            value_compare(Compare __c)
            : comp(__c) { }

            public:
                bool operator()(const value_type& __x, const value_type& __y) const { return comp(__x.first, __y.first); }
        };
    
    private:
        typedef typename Allocator::template rebind< ft::Node<value_type> >::other		allocatorNode;
        key_compare _comp; 
        allocator_type _alloc;
        ft::Tree<key_type, allocatorNode, value_compare>  _tree;

    public:
        Map(/* args */);
        explicit Map( const Compare& comp = key_compare(),const Allocator& alloc = allocator_type() ): _comp(comp) , _alloc(alloc), _tree(value_compare(comp)){};
        template< class InputIt >
        Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _comp(comp) , _alloc(alloc), _tree(value_compare(comp))
        {
            insert(first, last);
        };
        Map( const Map& other x):_comp(x._comp), _tree(value_compare(x._comp)){ _tree = x._tree; };
        ~Map();
    };
    
};