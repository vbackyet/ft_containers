#pragma once
// • enable_if
// Yes, it is C++11 but you will be able to implement it in a C++98 manner.
// This is asked so you can discover SFINAE.
// • is_integral
// • equal and/or lexicographical_compare
// • std::pair
// • std::make_pair
namespace ft
{
    // enable_if
        template< bool B, class T = void >
    struct enable_if
    {      
    };
    template<class T >
    struct enable_if <true, T>
    {
        typedef T type;
        
    };
}