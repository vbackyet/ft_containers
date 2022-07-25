#pragma once 
#include <iterator>

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
    template <class T, class A = std::allocator<T>>
    class Vector
    {
        public:
           typedef T   value_type;
           typedef A   allocator_type;
           typedef typename allocator_type::size_type   size_type;
           typedef typename allocator_type::pointer   pointer;
        private:
            size_type _size_of_vector;
            //allocator_type& _alloc;
            size_type _capacity;
            pointer  _start;
    /////////////////////////// CONSTRUCTOR ///////////////////////////////
    // консруктор нормальный vector <string> ivector;
    public:
        explicit Vector() 
        {
            std::cout << "Создано нормально vector без аргументов" << std::endl;
            const allocator_type& _alloc = allocator_type();
            _size_of_vector = 0;
            _alloc = allocator_type();
            _start= NULL;
            _capacity = 0;

        } 
        // конструктор нормальный с размером вектора vector <int> vector_first(5);
        explicit Vector(size_type Vector_size)
        {
            const allocator_type& _alloc = allocator_type();
            std::cout << "Создано нормально vector  с размером " <<  Vector_size <<std::endl;
            _size_of_vector = Vector_size;
            _alloc = allocator_type();
            _start= _alloc.allocate(Vector_size);
            _capacity = Vector_size;

        } 
        
        // консруктор копирования 
        Vector(const Vector& prev_vector)
            { std::cout << "Создано при помощи копирования" << std::endl;}

// int main( )
// {
//    allocator<int> v1Alloc;
//    allocator<int>::pointer v1aPtr;
//    v1aPtr = v1Alloc.allocate ( 10 );

//    int i;
//    for ( i = 0 ; i < 10 ; i++ )
//    {
//       v1aPtr[ i ] = i;
//    }

//    for ( i = 0 ; i < 10 ; i++ )
//    {
//       cout << v1aPtr[ i ] << " ";
//    }
//    cout << endl;
//    v1Alloc.deallocate( v1aPtr, 10 );
// }




    /////////////////////////// DESTRUCTOR ///////////////////////////////
        ~Vector()
        { std::cout << "Деструктор вызван" << std::endl;
        _alloc.deallocate( _alloc, _size_of_vector );}
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