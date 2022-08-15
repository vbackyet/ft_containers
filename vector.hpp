#pragma once 
#include <stdexcept>

#include "iterator.hpp"
#include "utils.hpp"
    // // allocator for integer values
    // allocator<int> myAllocator;
 
    // // allocate space for five ints
    // int* arr = myAllocator.allocate(5);
 
    // // construct arr[0] and arr[3]
    // // myAllocator.construct(arr, 100); // no longer allowed in C++20
    // arr[0] = 100; // do this instead
    // arr[3] = 10;
 
    // cout << arr[3] << endl;
    // cout << arr[0] << endl;
 
    // // deallocate space for five ints
    // myAllocator.deallocate(arr, 5);
 
    // return 0;



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
           typedef IteratorForVector<T*> iterator;
        private:
            size_type _size_of_vector; // размер вектора 
            allocator_type _alloc; //  
            size_type _capacity; // вместительность 
            pointer  _start; // начало выделенной памяти на вектор
            // pointer _p;
    /////////////////////////// CONSTRUCTOR ///////////////////////////////
    // консруктор нормальный vector <string> ivector;
    public:
        explicit Vector(const allocator_type& _allocator  = allocator_type()):  _alloc(_allocator)
        {
            std::cout << "Создано нормально vector без аргументов" << std::endl;
            // _alloc = 0 ;
            _size_of_vector = 0;
            // _alloc = allocator_type();
            _start= NULL;
            _capacity = 0;

        } 
        // конструктор нормальный с размером вектора vector <int> vector_first(5);
        explicit Vector(size_type Vector_size, const allocator_type& _allocator  = allocator_type()) :  _alloc(_allocator)
        {
            // _alloc =_allocator; // почему так constructor for 'ft::Vector<int>' must explicitly initialize the reference member '_alloc'
            std::cout << "Создано нормально vector  с размером " <<  Vector_size <<std::endl;
            _size_of_vector = 0;
            _start= _alloc.allocate(Vector_size);
            _capacity = Vector_size;

        }      
        size_type capacity() const { return _capacity; }
		size_type size() const {return _size_of_vector;}
			
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
        bool operator!=(Vector& x)
        {
            if (x._start != _start)
                return true;
            return false;
        }

        // Vector& operator= (const Vector& x)
        // {
        //     if (this != &x)
		// 	    this->assign(other.begin(), other.end());
		//     return *this;
        // }
        
        // консруктор копирования 
        explicit Vector(const Vector& prev_vector)
            { 
                std::cout << "Создано при помощи копирования" << std::endl;
                prev_vector = *this;

            }
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
            // создаем нужный вектор и делаем swap????
            if (count > _capacity)
            {
                // если нужно поменять большее количество ячеек чем есть в векторе

            }
            else if (count > _size_of_vector)
            {
            // если нужно поменять большее количество ячеек чем заполнено в векторе
            }
            else
            {
                //хватает места - нужно вставить и изменить размер !
                
                // _start. // заполняем вектор 
            for (size_type i = 0; i < count; ++i)
            {
                *_start = value;
                std::cout << "puk puk " << std::endl;
            }
                // удаляем остатки вектора 
                _size_of_vector = count;
            }
            
        }
        // template< class InputIt >
        // void assign( InputIt first, InputIt last )
        // {

        // }


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
    const_reference at( size_type pos ) const { return _start.at(pos);}
    const_reference operator[]( size_type pos ) const    { return _start.at(pos);}
    reference front()    {        return *_start;    }
    const_reference front() const {return *_start;}
    reference back() { return *(_start + _size_of_vector - 1);}
    const_reference back() const { return *(_start + _size_of_vector - 1);}
    T* data() { return _start; }
    const T* data() const { return _start; }

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
    
    void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::Is_integral<InputIterator>::value, iterator>::type = 0 )
    {

        
    }
    /////////////////////////// ITERATOR ///////////////////////////////

			iterator begin(){ return (_start); };
			// const_iterator begin() const { return (_p); }
			iterator end(){ return (_start + _size_of_vector); }
			// const_iterator end() const{ return (_p + _size_of_vector);}
			// reverse_iterator rbegin(){return reverse_iterator(end());};
			// const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
			// reverse_iterator rend(){return reverse_iterator(begin());};
			// const_reverse_iterator rend() const {return const_reverse_iterator(begin());};
    /////////////////////////// DESTRUCTOR ///////////////////////////////
        ~Vector()
        { std::cout << "Деструктор вызван" << std::endl;
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