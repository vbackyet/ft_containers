#pragma once
#include <functional>
#include "tree.hpp"
#include "utils.hpp"
#include <iostream>
#include <ostream>
#include <iterator>
namespace ft
{
    // ключ / значение / как сравнивать / аллокатор
    template< class Key,  class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class Map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const Key, T>    value_type;
        typedef Compare																				key_compare;
		typedef Allocator																			allocator_type;
        typedef typename Allocator::reference														reference;
		typedef typename Allocator::const_reference													const_reference;
		typedef typename Allocator::pointer															pointer;
		typedef typename Allocator::const_pointer													const_pointer;
		typedef typename Allocator::size_type														size_type;
		typedef typename Allocator::difference_type													difference_type;


                //iterators
        typedef ft::IteratorForMap<ft::Node<value_type> >      iterator;
        typedef ft::IteratorForMap<const ft::Node<value_type> >      const_iterator;

        typedef ft::ReverseIteratorForVector<iterator>														reverse_iterator;
		typedef ft::ReverseIteratorForVector<const_iterator>												const_reverse_iterator;
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
        ft::Tree<value_type, allocatorNode, value_compare>  _Tree;

    public:
        Map( const Compare& comp = key_compare(),const Allocator& alloc = allocator_type() ): _comp(comp) , _alloc(alloc), _Tree(value_compare(comp)){};
        template< class InputIt >
        Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _comp(comp) , _alloc(alloc), _Tree(value_compare(comp))
        {
            insert(first, last);
        };
        Map( const Map& x):_comp(x._comp), _Tree(value_compare(x._comp)){ _Tree = x._Tree; };
        ~Map(){};

        Map& operator=(const Map& other )
        {
            if (*this != other)
            {
            _comp = other._comp;
            _alloc = other._alloc;
            _Tree = other._Tree;
            }
            return *this;
        };



        bool operator==(const Map& other ){ return (_Tree == other._Tree); };

        bool operator!=(const Map& other )
        {
                return!(*this == other);
        };
		bool	operator<(const Map& y){ 
			
			const_iterator it_x = begin();
			const_iterator it_y = y.begin();			

			const_iterator itx_end = end();
			const_iterator ity_end = y.end();

			while (it_x != itx_end && it_y != ity_end) {
				if (it_x->first != it_y->first)
					return (it_x->first < it_y->first);
				else if (it_x->second != it_y->second)
					return (it_x->second < it_y->second);
				++it_x;
				++it_y;
			}
			if (size() < y.size())
				return true;
			return false; 

		 };
        bool	operator > ( const Map& y){ return (y < *this); };

	    bool	operator <= ( const Map& y){ return !( y < *this); };
		
		bool	operator >= ( const Map& y){ return !(*this < y); };
        allocator_type get_allocator() const {return _alloc;}; 

        iterator find (const key_type& k) {	return (iterator(_Tree.TreeSearch(k)));	}

		const_iterator find (const key_type& k) const {	return const_iterator(_Tree.TreeSearch(k));	}
        
		size_type count (const key_type& k) const {
            // std::cout<<  " puk\n";
            // find(k);
            // std::cout<<  " puk2\n";
			if (find(k) == end())
				return 0;
			return 1; };
        ft::pair<iterator,bool> insert(const value_type& v) { return (_Tree.insertNode(v)); }
        template< class InputIt >
        void insert( InputIt first, InputIt last )
        {

            while (first != last){
                //  ft::Node<value_type>    *the_new = new ft::Node<value_type>(ft::make_pair(first->first, first->second));
				_Tree.insertNode(ft::make_pair(first->first, first->second));
				++first;
                }
        };
        iterator begin(){return iterator(_Tree.find_min(_Tree._root));};
        const_iterator begin() const{return const_iterator(_Tree.find_min(_Tree._root));};
        iterator end(){return iterator(_Tree.find_max(_Tree._root));};
        const_iterator end() const{return const_iterator(_Tree.find_max(_Tree._root));};
        size_type size() const{return (_Tree._size);};



        reverse_iterator rbegin(){return reverse_iterator(iterator(_Tree.find_min(_Tree._root)));};
        const_reverse_iterator rbegin() const{return const_reverse_iterator(const_iterator(_Tree.find_min(_Tree._root)));};
        reverse_iterator rend(){return reverse_iterator(iterator(_Tree.find_max(_Tree._root)));};
        const_reverse_iterator rend() const{return const_reverse_iterator(const_iterator(_Tree.find_max(_Tree._root)));};

        // iterator find( const Key& key )
        // {
        //     return (_Tree.TreeSearch(key));
        // }
        
        // const_iterator find( const Key& key ) const
        // {
        //     return (_Tree.TreeSearch(key));    
        // }
                // erase
        void erase( iterator pos )
        {
            // std::cout << "here 3" << std::endl;
            _Tree.rbTreeDelete(pos._iter);
        };
        void erase( iterator first, iterator last )
        {
            iterator it = first;

			while (first != last){
				it = first.next();
				_Tree.rbTreeDelete(first.base());
				first = it;}
        }

        size_type erase( const Key& key )
        {
			Node<value_type>* rmNode = _Tree.TreeSearch(key);
			if (rmNode != end()._iter){
				_Tree.rbTreeDelete(rmNode);
				return 1;}
			else
				return 0;
        }
        bool empty() const  
        {
            if (size() > 0)
                return false;
            return true; 
        }
		pair<iterator,iterator> equal_range (const key_type& k) {return (_Tree.equal_range_unique(k)); };
			
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {return (_Tree.equal_range_unique(k)); };

		mapped_type& operator[] (const key_type& k)	{
			iterator tmp = this->find(k);

			if (tmp == this->end())
				insert(ft::make_pair(k, mapped_type()));
			tmp = this->find(k);
			return ((*tmp).second);
		}

		mapped_type& at (const key_type& k){
			iterator tmp = this->find(k);

			if (tmp == this->end())
				throw std::out_of_range("");
			return ((*tmp).second);
		}
		
		const mapped_type& at (const key_type& k) const {
			iterator tmp = this->find(k);

			if (tmp == this->end())
				throw std::out_of_range("");
			return ((*tmp).second);
		}


        void swap (Map& x){	std::swap(x, *this); }

		void clear(){ _Tree.clear();}

		iterator lower_bound (const key_type& key) { return (_Tree.lower_bound(key)); };

		const_iterator lower_bound (const key_type& key) const { return (_Tree.lower_bound(key));};

		iterator upper_bound (const key_type& key) { return (_Tree.upper_bound(key)); };

		const_iterator upper_bound (const key_type& key) const  { return (_Tree.upper_bound(key)); };
        // rend
    };
};