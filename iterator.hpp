#pragma once
#include <iostream>
#include <ostream>
#include <iterator>

#include <memory>





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
    struct iterator
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
            // typedef    pointer;
        	IteratorForVector():_elem(0){};
            
            // template <class _Up>// для const T*
			// IteratorForVector(const IteratorForVector<_Up>& __u, typename std::enable_if<std::is_convertible<_Up, T>::value>::type* = 0): _elem(__u.base()){};
            // T base() const  { return _elem; }

			// IteratorForVector(typename IteratorForVector::pointer const &vecPoint):_elem(vecPoint){};
            IteratorForVector(typename IteratorForVector::pointer vecPoint):_elem(vecPoint){};

			~IteratorForVector() {};
            bool operator!=(IteratorForVector &right)
            {
                return (_elem != right._elem);
            }
            IteratorForVector &operator++(){ _elem++; return (*this);};
            IteratorForVector operator++(int){ IteratorForVector temp(*this) ;_elem++; return (temp);}; // почему не работает с &???????????????????????????????????? - вроде поняла
            IteratorForVector &operator--(){ _elem--; return (*this);};
            IteratorForVector operator--(int){ IteratorForVector temp(*this) ;_elem--; return (temp);};
            IteratorForVector operator+(int my_change){ _elem = _elem + my_change; return (*this);};
typename IteratorForVector::reference operator*(void) const { return (*_elem); };

            // операторы для указателей
            int operator-(IteratorForVector const &other_iterator)const { return (this->_elem - other_iterator._elem); };
            bool operator>=(IteratorForVector const &other_iterator) const  { return (this->_elem >= other_iterator._elem); };
			// iterator_type base() const {return _elem;}

			// typename IteratorForVector::reference operator*(void) const { return (*_elem); };
			// typename IteratorForVector::pointer operator->(void) const { return &(*_elem); };
            friend std::ostream &operator<<(std::ostream &os, const IteratorForVector &_date) {
                return os  << _date._elem;}

        private:
            iterator_type _elem;




    };

}

