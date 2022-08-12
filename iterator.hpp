#pragma once
#include <iostream>
#include <iterator>


namespace ft
{
    struct random_access_iterator_tag {};


    // template <class Iter>
    // class iterator_traits
    // {
    //     typedef typename Iter::difference_type difference_type;
    //     typedef typename Iter::value_type  value_type;
    //     typedef typename Iter::pointer pointer;
    //     typedef typename Iter::reference reference;
    //     typedef typename Iter::iterator_category iterator_category;
    // };
    	template< class T >
	struct iterator_traits
    {

    };
	template< class T >
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};
    template <class Category ,class T, class pointer_ = T*, class reference_ = T&, class distance_ = ptrdiff_t >
    class iterator
    {
       typedef Category   iterator_category;
       typedef T value_type;
       typedef pointer_ pointer;
       typedef reference_ reference;
       typedef distance_	Distance;
    };
    template <class T>
    struct IteratorForVector : ft::iterator<typename ft::iterator_traits<T>::iterator_category, typename ft::iterator_traits<T>::value_type >
    {

        public:
            typedef T iterator_type;
        	IteratorForVector():_elem(0){};
			// IteratorForVector(typename IteratorForVector::pointer const &vecPoint):_elem(vecPoint){};

			~IteratorForVector() {};



			// iterator_type base() const {return _elem;}
			
			// typename IteratorForVector::reference operator*(void) const { return (*_elem); };
			// typename IteratorForVector::pointer operator->(void) const { return &(*_elem); };


        private:
            iterator_type _elem;




    };
}