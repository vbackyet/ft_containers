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
  template<bool v>
    struct integral_constant
    {
      static const bool value = v;
    //   typedef _Tp                           value_type;
    //   typedef integral_constant<_Tp, __v>   type;
    //   constexpr operator value_type() const { return value; }
    };
  /// The type used as a compile-time boolean with true value.
  typedef integral_constant< true>     true_type;

  /// The type used as a compile-time boolean with false value.
  typedef integral_constant<false>    false_type;
    


    template <class> struct is_integral						    : public false_type {};
    template <> struct is_integral <bool>						: public true_type {};	//explicit template specialization
	template <> struct is_integral <char>						: public true_type {};
	template <> struct is_integral <char16_t>					: public true_type {};
	template <> struct is_integral <char32_t>					: public true_type {};
	template <> struct is_integral <wchar_t>					: public true_type {};
	template <> struct is_integral <signed char>				: public true_type {};
	template <> struct is_integral <short int>					: public true_type {};
	template <> struct is_integral <int>						: public true_type {};
	template <> struct is_integral <long int>					: public true_type {};
	template <> struct is_integral <long long int>				: public true_type {};
	template <> struct is_integral <unsigned char>				: public true_type {};
	template <> struct is_integral <unsigned short int>			: public true_type {};
	template <> struct is_integral <unsigned int>				: public true_type {};
	template <> struct is_integral <unsigned long int>			: public true_type {};
	template <> struct is_integral <unsigned long long int>		: public true_type {};

    template< bool B, class T = void >
    struct enable_if
    {      
    };
    template<class T >
    struct enable_if <true, T>
    {
        typedef T type;
        
    };


    template< class InputIt1, class InputIt2 >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                                  InputIt2 first2, InputIt2 last2 )
    {
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
    }

    
}