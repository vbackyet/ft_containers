#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include <ostream>
#include <iterator>

#include <memory>


namespace ft
{
    struct random_access_iterator_tag {};


    template <class Iter>
    struct iterator_traits
    {
        typedef  ptrdiff_t difference_type;
        typedef typename Iter::value_type  value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };
    // template< class T >
	// struct iterator_traits
    // {

    // };
	template< class T >
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
	
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
    
    template <class Category ,class T, class pointer_ = T*, class reference_ = T&, class distance_ = ptrdiff_t >
    struct iterator
    {
        typedef ptrdiff_t							difference_type;
       typedef Category   iterator_category;
       typedef T value_type;
       typedef pointer_ pointer;
       typedef reference_ reference;
       typedef distance_	Distance;
    };

    template <class T>
    struct IteratorForVector : ft::iterator<std::random_access_iterator_tag, T>
    {

        public:

            typedef T* iterator_type;
            // typedef    pointer;
        	IteratorForVector(const iterator_type it = NULL):_elem(it){};

            IteratorForVector(const IteratorForVector& other) : _elem(other._elem) {};

			// IteratorForVector(typename IteratorForVector::pointer const &vecPoint):_elem(vecPoint){};
            // IteratorForVector(typename IteratorForVector::pointer vecPoint):_elem(vecPoint){};
            T base() const  { return _elem; }
			~IteratorForVector() {};

            bool operator==(IteratorForVector &right){return (_elem == right._elem);}
            bool operator!=(IteratorForVector &right){return (_elem != right._elem);}
			typename IteratorForVector::reference operator*(void) { return (*_elem); };
			typename IteratorForVector::pointer operator->(void) const { return &(*_elem); };


            IteratorForVector &operator++(){ _elem++; return (*this);};
            IteratorForVector operator++(int){ IteratorForVector temp(*this) ;_elem++; return (temp);}; // почему не работает с &???????????????????????????????????? - вроде поняла
            IteratorForVector &operator--(){ _elem--; return (*this);};
            IteratorForVector operator--(int){ IteratorForVector temp(*this) ;_elem--; return (temp);};
            IteratorForVector operator+(int my_change){ _elem = _elem + my_change; return (*this);};
            IteratorForVector operator-(int my_change){ _elem = _elem - my_change; return (*this);};
            IteratorForVector &operator+=(int my_change){ _elem = _elem + my_change; return (*this);};
            IteratorForVector &operator-=(int my_change){ _elem = _elem - my_change; return (*this);};
            IteratorForVector &operator[](int my_change){ _elem = _elem + my_change; return (*this);};
			bool operator>(IteratorForVector const &it) const {return (_elem > it._elem);};
			bool operator<(IteratorForVector const &it) const {return (_elem < it._elem);};
            // операторы для указателей
            int operator-(IteratorForVector const &other_iterator)const { return (this->_elem - other_iterator._elem); };
            int operator+(IteratorForVector const &other_iterator)const { return (this->_elem + other_iterator._elem); };
            bool operator>=(IteratorForVector const &other_iterator) const  { return (this->_elem >= other_iterator._elem); };
            bool operator<=(IteratorForVector const &other_iterator) const  { return (this->_elem <= other_iterator._elem); };
			// iterator_type base() const {return _elem;}

            friend std::ostream &operator<<(std::ostream &os, const IteratorForVector &_date) {
                return os  << _date._elem;}

        private:
            iterator_type _elem;




    };

    template <class T>
    struct ReverseIteratorForVector : ft::iterator<typename ft::iterator_traits<T>::iterator_category, typename ft::iterator_traits<T>::value_type >
    {

        public:
            typedef T iterator_type;

			typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator_type>::value_type			value_type;
			typedef typename	iterator_traits<iterator_type>::pointer				pointer;
			typedef typename	iterator_traits<iterator_type>::reference 			reference;
			typedef typename	iterator_traits<iterator_type>::iterator_category	iterator_category;

        	ReverseIteratorForVector():_elem(0){};
			explicit ReverseIteratorForVector(iterator_type iter) : _elem(iter){};       
            template <class _Up>// для const T*
			ReverseIteratorForVector(const ReverseIteratorForVector<_Up>& __u, typename std::enable_if<std::is_convertible<_Up, T>::value>::type* = 0): _elem(__u.base()){};
            template <class Iter>
            ReverseIteratorForVector& operator=(const ReverseIteratorForVector<Iter>& rev_it) { _elem = rev_it.base(); return *this; }
            T base() const  { return _elem; }

			// IteratorForVector(typename IteratorForVector::pointer const &vecPoint):_elem(vecPoint){};
            // ReverseIteratorForVector(pointer vecPoint):_elem(vecPoint){};

			~ReverseIteratorForVector() {};

            bool operator==(ReverseIteratorForVector &right){return (_elem == right._elem);}
            bool operator!=(ReverseIteratorForVector &right){return (_elem != right._elem);}
            reference operator*(void) { return (*_elem); };
            pointer operator->(void) { return &(*_elem); };



            ReverseIteratorForVector &operator++(){ _elem--; return (*this);};
            ReverseIteratorForVector operator++(int){ ReverseIteratorForVector temp(*this) ;_elem--; return (temp);}; // почему не работает с &???????????????????????????????????? - вроде поняла
            ReverseIteratorForVector &operator--(){ _elem++; return (*this);};
            ReverseIteratorForVector operator--(int){ ReverseIteratorForVector temp(*this) ;_elem++; return (temp);};
            ReverseIteratorForVector operator+(int my_change){ _elem = _elem - my_change; return (*this);};
            ReverseIteratorForVector operator-(int my_change){ _elem = _elem + my_change; return (*this);};
            ReverseIteratorForVector &operator+=(int my_change){ _elem = _elem - my_change; return (*this);};
            ReverseIteratorForVector &operator-=(int my_change){ _elem = _elem + my_change; return (*this);};
            ReverseIteratorForVector &operator[](int my_change){ _elem = _elem + my_change; return (*this);};
			bool operator>(ReverseIteratorForVector const &it) const {return (_elem > it._elem);};
			bool operator<(ReverseIteratorForVector const &it) const {return (_elem < it._elem);};
            // операторы для указателей
            int operator-(ReverseIteratorForVector const &other_iterator)const { return (this->_elem + other_iterator._elem); };
            int operator+(ReverseIteratorForVector const &other_iterator)const { return (this->_elem - other_iterator._elem); };
            bool operator>=(ReverseIteratorForVector const &other_iterator) const  { return (this->_elem >= other_iterator._elem); };
            bool operator<=(ReverseIteratorForVector const &other_iterator) const  { return (this->_elem <= other_iterator._elem); };
			// iterator_type base() const {return _elem;}

            friend std::ostream &operator<<(std::ostream &os, const ReverseIteratorForVector &_date) {
                return os  << _date._elem;}

        private:
            iterator_type _elem;




    };


    template <class T>
    struct IteratorForMap 
    {
        public:
            typedef T* iterator_type;
            typedef typename T::pair_type   value_type;
            typedef typename T::pair_type*   pointer;
            typedef typename T::pair_type&   reference;
			typedef const typename T::pair_type& 					const_reference;
			typedef const typename T::pair_type* 					const_pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;
        // private:
            iterator_type _iter;
        public:
            IteratorForMap(T* val = 0) : _iter(val) {};
            // IteratorForMap(const T* val = nullptr) : _iter(val) {};
            template <class Tp>
			IteratorForMap(const IteratorForMap<Tp> &cp, typename std::enable_if<!std::is_convertible<Tp, iterator_type>::value>::type* = 0):_iter(cp.base()) {};
            iterator_type base() const {return _iter;}
            IteratorForMap(const IteratorForMap& other) : _iter(other._iter) {};
            IteratorForMap &operator=(IteratorForMap const  &cp){
				_iter = cp._iter;
				return (*this);
			};
            ~IteratorForMap(){};

            iterator_type min(iterator_type x)	{
				while (x->left->isNil != true)
					x = x->left;
				return (x);
			}

			iterator_type max(iterator_type x)
			{
				while (x->right->isNil != true)
					x = x->right;
				return (x);
			}

			iterator_type next(){
				iterator_type y;
				if (_iter->right->isNil == false)
					return(min(_iter->right));
				y = _iter->parent;
			
				while (y->isNil == false && _iter == y->right){ // for case if y is right kid of it's parent
					_iter = y;
					y = y->parent;
				}
				return (y);
			}

			iterator_type prev(){
				iterator_type y;

				if (_iter->isNil == true || _iter->left->isNil == false)
					return(max(_iter->left));
				y = _iter->parent;
				while (y->isNil == false && _iter == y->left){ // for case if y is left kid of it's parent
					_iter = y;
					y = y->parent;}
				return (y);
			}

			IteratorForMap& operator++() {
				_iter = next();
				return (*this);
			}

			IteratorForMap operator++(int){ 
				IteratorForMap tem(*this);
				++(*this);
				return tem;
			}	
			IteratorForMap& operator--() {
  
				_iter = prev();
				return *this; 
				
			};

			IteratorForMap operator--(int){
    
				IteratorForMap tem(*this);
				--(*this);
				return tem;
			};
            reference operator*() {return _iter->keyValue;}
			const_reference operator*() const {return _iter->keyValue;}
			pointer operator->() {return pointer(&_iter->keyValue);}
			const_pointer operator->() const {return &(_iter->keyValue);}


            template <class Iter1>
            
            bool operator==(const IteratorForMap<Iter1>& y) {
                return (_iter == y._iter);
            };

            template <class Iter1 >
            
            bool operator!=( const IteratorForMap<Iter1>& y) {
                return !(*this == y);
            };
            
        
    };


}

#endif

