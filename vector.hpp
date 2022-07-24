#pragma once 


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
        protected:
           typedef T   value_type;
//         value_type 	T
// allocator_type 	Allocator
// size_type 	Unsigned integer type (usually std::size_t)
// difference_type 	Signed integer type (usually std::ptrdiff_t)
// reference 	value_type&
// const_reference 	const value_type&
// pointer 	Allocator::pointer 	(until C++11)
// std::allocator_traits<Allocator>::pointer 	(since C++11)
// const_pointer 	Allocator::const_pointer 	(until C++11)
// std::allocator_traits<Allocator>::const_pointer 	(since C++11)
// iterator 	

// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type
// 	(until C++20)

// LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to value_type
// 	(since C++20)
// const_iterator 	

// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type
// 	(until C++20)

// LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to const value_type
// 	(since C++20)
// reverse_iterator 	std::reverse_iterator<iterator>
// const_reverse_iterator 	std::reverse_iterator<const_iterator>
    };
}