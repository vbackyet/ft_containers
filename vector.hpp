#pragma once 
#include <iterator>
#include "iterator.hpp"

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
           typedef typename allocator_type::size_type   size_type; // я не знаю что это
           typedef typename allocator_type::pointer   pointer; // указатель 
           typedef IteratorForVector<T*> iterator;
        //    typedef iterator:: 
        private:
            size_type _size_of_vector; // размер вектора 
            allocator_type _alloc; //  
            size_type _capacity; // вместительность 
            pointer  _start; // начало выделенной памяти на вектор
            iterator _p;
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
            _size_of_vector = Vector_size;
            _start= _alloc.allocate(Vector_size);
            _capacity = Vector_size;

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

    /////////////////////////// ITERATOR ///////////////////////////////

			iterator begin(){ return (_p); };
			// const_iterator begin() const { return (_p); }
			iterator end(){ return (_p + _size_of_vector); }
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