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
           typedef ReverseIteratorForVector<iterator> reverse_iterator;
           typedef IteratorForVector<const T> const_iterator;
           typedef ReverseIteratorForVector<const_iterator> const_reverse_iterator;
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
            _start= _alloc.allocate(0);
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


        Vector (const Vector& x): _size_of_vector(x._size_of_vector), _capacity(x._capacity){
        _alloc = allocator_type();
        _start = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size_of_vector; ++i)
                _alloc.construct(_start + i, *(x._start + i));
		};
			


        Vector &operator=(const Vector& x)
        {

            if (this != &x)
            {
                // clear();
				_alloc.deallocate(_start, _capacity); 
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
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new_res! \n";
            if (new_cap <= _capacity)
                return ;
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new_res! \n";
            pointer _new_start = _alloc.allocate(new_cap);
            _capacity = new_cap;
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new_res! \n";
            if (_size_of_vector > 0)
            {
            for(size_type i = 0; i <= _size_of_vector - 1;i++)
            {
    
                _alloc.construct(_new_start + i, *(_start + i) );
            }
            for (size_type i = 0; i < _size_of_vector; i++)
                _alloc.destroy(_start + i);
            }
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new_res2! \n";
            _alloc.deallocate(_start, _capacity);
            _start = _new_start;
            _capacity = new_cap;
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new_res! \n";
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
			friend bool operator== (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs);
			
			template <class TF, class AllocF>
			friend bool operator!= (const Vector<TF, AllocF>& lhs, const Vector<TF, AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator<  (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator<= (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator>  (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs);
				
			template <class TF, class AllocF>
			friend bool operator>= (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs);

			// template <class TF, class AllocF>
			// friend void swap (vector<TF, AllocF>& x, vector<TF, AllocF>& y);

        // консруктор копирования 
        // Vector(const Vector& prev_vector)
        // { 
        //     *this = prev_vector;

        // }


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
            // std::cout << count <<"cap_new! \n";
            // _size_of_vector = count;
 
            reserve(count);
            // std::cout << _size_of_vector <<   "    " << _capacity  <<"  cap_new! \n";
            for(int i = 0; i <  (int) count; i++)
                _start[i] = value; 
            _size_of_vector = count;  
         
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
            // _capacity = _size_of_vector;
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

    		// ReverseIteratorForVector rbegin(){return ReverseIteratorForVector(end());};
			// const_ReverseIteratorForVector rbegin() const {return const_ReverseIteratorForVector(end());};
			// ReverseIteratorForVector rend(){return ReverseIteratorForVector(begin());};
			// const_ReverseIteratorForVector rend() const {return const_ReverseIteratorForVector(begin());};

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
				int		indexPos = pos - this->begin();
				int		n = last - first;
				
				
				if (n <= 0)
					return ;

				int		indexOld = _size_of_vector - 1;
				int		indexNew = _size_of_vector + n - 1;
				unsigned long		sizeNew = _size_of_vector + n;
				unsigned long		capNew = _capacity;

				if (_capacity < sizeNew)
				{					
					pointer		_oldp = _start;

					if (_capacity * 2 < sizeNew)
						capNew = sizeNew;
					else if (_capacity < sizeNew)
						capNew = _capacity * 2;
					_start = _alloc.allocate(capNew);
					for (size_type i = 0; i < _size_of_vector; ++i)
						_alloc.construct(_start + i, *(_oldp + i));
					for (size_type i = 0; i < _size_of_vector; ++i)
						_alloc.destroy(_oldp + i);
					_alloc.deallocate(_oldp, _capacity);

				}

				while (indexOld >= indexPos)
					_start[indexNew--] = _start[indexOld--];
				
				while (indexNew >= 0 && indexNew >= indexPos)
					_start[indexNew--] = *--last;

				
				_size_of_vector += n;
				_capacity = capNew;
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
        if (first < this->begin() || first >= this->end() || last < this->begin() || last >= this->end())
            throw std::out_of_range("Vector");

        unsigned long indFirst = first - this->begin();
        unsigned long indFirstOld = indFirst;
        unsigned long indLast = last - this->begin();


        while (indFirst < _size_of_vector)
        {
            _alloc.destroy(_start + indFirst);
            if (indLast < _size_of_vector)
            {
                _start[indFirst] = _start[indLast];
                ++indLast;
            }
            ++indFirst;
        };
        
        _alloc.destroy(_start + indFirst);
        _size_of_vector = _size_of_vector - (last -first);
        return (_start + indFirstOld );
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
			reverse_iterator rbegin(){return reverse_iterator(end() - 1 );};
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end() -1);};
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

// ReverseIteratorForVector 	std::ReverseIteratorForVector<iterator>
// const_ReverseIteratorForVector 	std::ReverseIteratorForVector<const_iterator>
    };

	template <class TF, class AllocF>
	bool operator== (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		int size = lhs.size();
		for (int i = 0; i < size; ++i)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
	
	template <class TF, class AllocF>
	bool operator != (const Vector<TF, AllocF>& lhs, const Vector<TF, AllocF>& rhs){ return !(lhs == rhs); }
		
	template <class TF, class AllocF>
	bool operator < (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs){ 
		size_t size = lhs.size();
		if (size > rhs.size())
			size = rhs.size();
		for (size_t i = 0; i < size; ++i){
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];
		}
		if (lhs.size() < rhs.size())
			return true;
		return (false); 
		
	}
		
	template <class TF, class AllocF>
	bool operator <= (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs){ return !(rhs < lhs); }
		
	template <class TF, class AllocF>
	bool operator > (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs){ return (rhs < lhs); }
		
	template <class TF, class AllocF>
	bool operator >= (const Vector<TF,AllocF>& lhs, const Vector<TF,AllocF>& rhs){ return !(lhs < rhs); }

}