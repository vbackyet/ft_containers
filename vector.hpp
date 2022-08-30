#pragma once 
#include <stdexcept>

#include "iterator.hpp"
#include "utils.hpp"




namespace ft
{
    template <class T, class A = std::allocator<T> >
    // создаем ветктор с типом Т -  создается аллокатор который выдеяет потом память
    class Vector
    {
        public:
           typedef T   value_type; // ака инт
           typedef A   allocator_type; // ака маллок для инта
           typedef typename allocator_type::size_type   size_type; 
           typedef typename allocator_type::pointer   pointer; // указатель 
           typedef typename allocator_type::reference   reference; // указатель 
           typedef typename allocator_type::const_reference   const_reference; // указатель 
           typedef IteratorForVector<T> iterator;
           typedef ReverseIteratorForVector<T*> reverse_iterator;
           typedef IteratorForVector<const T> const_iterator;
           typedef ReverseIteratorForVector<const T*> const_reverse_iterator;
        private:
            size_type _size_of_vector; // размер вектора 
            allocator_type _alloc; //  
            size_type _capacity; // вместительность 
            pointer  _start; // начало выделенной памяти на вектор
            reverse_iterator _r_start;
            
    /////////////////////////// CONSTRUCTOR ///////////////////////////////
    // консруктор нормальный vector <string> ivector;
    public:
        explicit Vector(const allocator_type& _allocator  = allocator_type()):  _alloc(_allocator)
        {
            // std::cout << "Создано нормально vector без аргументов" << std::endl;
            // _alloc = 0 ;
            _size_of_vector = 0;
            // _alloc = allocator_type();
            _start= NULL;
            _capacity = 0;

        } 
        // конструктор нормальный с размером вектора vector <int> vector_first(5);
        explicit Vector(size_type Vector_size, const value_type& val = value_type(), const allocator_type& _allocator  = allocator_type()) :  _alloc(_allocator)
        {
            // _alloc =_allocator; // почему так constructor for 'ft::Vector<int>' must explicitly initialize the reference member '_alloc'
            // std::cout << "Создано нормально vector  с размером " <<  Vector_size <<std::endl;
            _size_of_vector = 0;
            _start= _alloc.allocate(Vector_size);
            _capacity = Vector_size;
            this->assign(Vector_size , val);

        }     
			
        template <class InIter> 
        Vector (InIter first, InIter last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InIter>::value, InIter>::type* =0) : _size_of_vector(0),_alloc(alloc), _capacity(0), _start(0)
        {
            this->assign(first, last);
        };   

        Vector &operator=(const Vector& x)
        {

            if (this != &x)
            {
                // clear();
                // _alloc.deallocate(_start, _capacity); // вызывается ошибка
                _size_of_vector = x._size_of_vector;
                _capacity = x._capacity;
                _start = _alloc.allocate(_capacity);

                for (size_type i = 0; i < _size_of_vector; ++i)
                    _alloc.construct(_start + i, *(x._start + i));
            }
            return (*this);
        };     
        size_type max_size() const { return (allocator_type().max_size()); }    
        size_type capacity() const { return _capacity; }
		size_type size() const {return _size_of_vector;}
			bool empty() const { return (_size_of_vector > 0 ? false : true); }
        void reserve( size_type new_cap )
        {
            if (new_cap <= _capacity)
                return ;

            pointer _new_start = _alloc.allocate(new_cap);
            _capacity = new_cap;
            for(size_type i = 0; i <= _size_of_vector - 1;i++)
            {
                _alloc.construct(_new_start + i, *(_start + i) );
            }
            for (size_type i = 0; i < _size_of_vector; i++)
                _alloc.destroy(_start + i);
            _alloc.deallocate(_start, _capacity);
            _start = _new_start;
            _capacity = new_cap;
        }
        void push_back(const value_type &element_to_insert)
        {
            int i = 1;
            if (_capacity == _size_of_vector)
            {
                if (_size_of_vector != 0)
                    i = _capacity *2;
                reserve(i);
            }
            _alloc.construct(_start + _size_of_vector, element_to_insert );
            _size_of_vector++; 
        }

        template <class TF, class AllocF>
        friend bool operator==(const ft::Vector<TF,AllocF>& lhs, const ft::Vector<TF,AllocF>& rhs)
        {
            if(lhs._size_of_vector != rhs._size_of_vector)
                return false;
            for( size_type i = 0; i < lhs._size_of_vector; i++)
            {
                if (lhs[i] != rhs[i])
                    return false;
            }
            return true;
        }
        template <class TF, class AllocF>
        friend bool operator!=(const ft::Vector<TF,AllocF>& lhs, const ft::Vector<TF,AllocF>& rhs)
        {
            return (!(lhs == rhs));
        }
        template< class TF, class AllocF >
        friend bool operator>(const ft::Vector<TF,AllocF>& lhs, const ft::Vector<TF,AllocF>& rhs)
        {
            return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }
        template< class TF, class AllocF >
        friend bool operator<(const ft::Vector<TF,AllocF>& rhs, const ft::Vector<TF,AllocF>& lhs)
        {
            return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }
        // консруктор копирования 
        Vector(const Vector& prev_vector)
        { 
            *this = prev_vector;

        }


        	// 		Vector (const Vector& prev_vector): _size_of_vector(x._size_of_vector), _capacity(x._capacity){
			// 	_alloc = allocator_type();
			// 	_p = _alloc.allocate(_capacity);
			// 	for (size_type i = 0; i < _size; ++i)
			// 			_alloc.construct(_p + i, *(x._p + i));
			// };
        allocator_type get_allocator()
        {
            return (_alloc);
        }

        // assign !!!
// std::vector<int>::iterator it;
// for(it = v.begin(); it != v.end(); ++it)
//     cout << *it;



        void assign(size_type count, const T& value )
        {
            // this->clear();
            _size_of_vector = count;
            reserve(_size_of_vector);
            for(int i = 0; i <  (int) _size_of_vector; i++)
                _start[i] = value;            
        }
        template< class InputIt >
        void assign( InputIt first, InputIt last,  typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = 0 )
        {
            // this->clear();

				_size_of_vector = last - first;
			
            if (_capacity < _size_of_vector)
            {
                // if (_capacity > 0)
                    _alloc.deallocate(_start, _capacity);
                _capacity = _size_of_vector;
                _start = _alloc.allocate(_capacity);
            }
            
            for (int i = 0;	first != last; ++first){
                _alloc.construct(_start + i, *first);
                i++;
            }
            
        }


    /////////////////////////// ELEMNT ACCESS ///////////////////////////////

    reference at( size_type pos )
    {
        if (pos >= 0)
        {
            pointer _at_p  = _start + pos;
            return *(_at_p);
        }
        else
            throw std::invalid_argument("");
    }
    reference operator[]( size_type pos )
    {
        if (pos >= 0)
        {
            pointer _at_p  = _start + pos;
            return *(_at_p);
        }
        else
            throw std::invalid_argument("");
    }

    const_reference at (size_type n) const {
        if (_size_of_vector > 0)
            return(_start[n]);
        else 
            throw std::invalid_argument("");
    }

    const_reference operator[](size_type n) const {
        if (_size_of_vector > 0)
            return(_start[n]);
        else 
            throw std::invalid_argument("");
    }
    reference front()    {        return *_start;    }
    const_reference front() const {return *_start;}
    reference back() { return *(_start + _size_of_vector - 1);}
    const_reference back() const { return *(_start + _size_of_vector - 1);}
    T* data() { return _start; }
    const T* data() const { return _start; }

    		// reverse_iterator rbegin(){return reverse_iterator(end());};
			// const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
			// reverse_iterator rend(){return reverse_iterator(begin());};
			// const_reverse_iterator rend() const {return const_reverse_iterator(begin());};

    /////////////////////////// MODIFIERS ///////////////////////////////
    void clear()
    {
            for (size_type i = 0; i < _size_of_vector; i++)
                _alloc.destroy(_start + i);
            _size_of_vector = 0;
    }
    //// insert ///
    iterator insert( iterator pos, const T& value )
    {
        int ind = pos - this->begin();
        insert(pos, 1, value);

        return (this->begin() + ind);
    }
    void insert( iterator pos, size_type count, const T& value )
    {
        int insertStart = pos - this->begin();
        int oldEnd = _size_of_vector - 1;
        int newEnd = _size_of_vector - 1 + count;
        // int i = 1;
        // std::cout<< "|" << insertStart << "| :unsertStart " << oldEnd << " oldEnd " << newEnd << " newEnd " << std::endl;
        // capacity 
        if (_capacity*2 < (_size_of_vector + count))
            reserve(_size_of_vector + count);
        else if (_capacity < (_size_of_vector + count))
            reserve(_capacity*2);
        // for(int i = 0 ; i < (int ) _capacity ; i++) {std::cout << _start[i] << " v ";}
        while(newEnd > (insertStart + (int)count - 1))
        {
            _start[newEnd--] = _start[oldEnd--];
            // i++;
        }
        // std::cout<< "|" << insertStart << "| :unsertStart " << newEnd << " newEnd " << std::endl;
        while(newEnd >= insertStart)
        {
            _start[newEnd--] = value;
        }
        _size_of_vector += count;
    }

    template< class InputIt >    
    void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = 0 )
    {


        int count = last - first;
        int insertStart = pos - this->begin();
        int oldEnd = _size_of_vector - 1;
        int newEnd = _size_of_vector - 1 + count;
        if (_capacity*2 < (_size_of_vector + count))
            reserve(_size_of_vector + count);
        else if (_capacity < (_size_of_vector + count))
            reserve(_capacity*2);
        // std::cout<< size_of_vec << " puk "<< std::endl;
        ///////////// cycle 
        while(newEnd > (insertStart + (int)count - 1))
        {
            _start[newEnd--] = _start[oldEnd--];
            // i++;
        }
        // std::cout<< "|" << insertStart << "| :unsertStart " << newEnd << " newEnd " << std::endl;
        while(newEnd >= insertStart)
        {
            _start[newEnd--] = *first++;
        }
        _size_of_vector += count;

        
    }
    /// erase

    iterator erase( iterator pos )
    {
        if (pos < this->begin() || pos >= this->end())
            throw std::out_of_range("");
        int strtInsrt = pos - this->begin();
        size_type i;
        for ( i = strtInsrt; i < _size_of_vector; i++)
        {
            _alloc.destroy(_start + i);
           _start[i] = _start[i+1];
           
        }
        _alloc.destroy(_start + i + 1);
        
        _size_of_vector--;
        return (_start + strtInsrt);
    }
    iterator erase( iterator first, iterator last )
    {
        if (first < this->begin() || last >= this->end())
            throw std::out_of_range("");
        int delta = last - first;
        int strtInsrt = first - this->begin();
        size_type i;
        for ( i = strtInsrt; (int )i <= delta + strtInsrt ; i++)
        {
            _alloc.destroy(_start + i);
           _start[i] = _start[i+delta];
           
        }
        while (i++ < _size_of_vector)
        {
            _alloc.destroy(_start + i);
           
        }

        _size_of_vector-= delta;
        return (_start + strtInsrt);
    }
    void pop_back()
    {
        _size_of_vector--;
		_alloc.destroy(_start +_size_of_vector);
    }
    void resize( size_type count, value_type value = value_type() )
    {
        while (_capacity < count)
            reserve(_capacity*2);
        for (; _size_of_vector < count; _size_of_vector++)
            _alloc.construct(_start + _size_of_vector, value);
        for (; _size_of_vector > count;)
            this->pop_back();
    }
    template <class P>
    void    pre_swap(P &__y , P &_x) 
    {
    P __tmp = _x;
    _x = __y;
    __y = __tmp;
    }
    void swap( Vector& other )
    {
        pre_swap(other._size_of_vector ,_size_of_vector);
        pre_swap(other._alloc ,_alloc);
        pre_swap(other._capacity ,_capacity);
        pre_swap(other._start ,_start);
    }
    /////////////////////////// ITERATOR ///////////////////////////////

			// iterator begin(){ return (_start); };

            iterator begin(){ return iterator(_start); };
            const_iterator begin() const { return const_iterator(_start); };
			
            // const_iterator begin() const { return (_start); }
			
            iterator end(){ return (_start + _size_of_vector); }
			const_iterator end() const{ return (_start + _size_of_vector);}

            /// rbegin
			reverse_iterator rbegin(){return reverse_iterator(end());};
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
			reverse_iterator rend(){return reverse_iterator(begin());};
			const_reverse_iterator rend() const {return const_reverse_iterator(begin());};


            // rend
    /////////////////////////// DESTRUCTOR ///////////////////////////////
        ~Vector()
        { 
            // std::cout << "Деструктор вызван" << std::endl;
        _alloc.deallocate( _start, _size_of_vector );}
// size_type 	Unsigned integer type (usually std::size_t)
// difference_type 	Signed integer type (usually std::ptrdiff_t)
// reference 	value_type&
// const_reference 	const value_type&
// const_pointer 	Allocator::const_pointer 	(until C++11)
// iterator 	

// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type
// 	(until C++20)
// const_iterator 	

// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type
// 	(until C++20)

// reverse_iterator 	std::reverse_iterator<iterator>
// const_reverse_iterator 	std::reverse_iterator<const_iterator>
    };
}