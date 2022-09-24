#pragma once


// #include <types>
// • enable_if
// Yes, it is C++11 but you will be able to implement it in a C++98 manner.
// This is asked so you can discover SFINAE.
// • is_integral
// • equal and/or lexicographical_compare
// • std::pair
// • std::make_pair
namespace ft
{


	// 	template <class _T1, class _T2> 
	// struct is_convertible: public ft::integral_constant<bool,  __is_convertible_to(_T1, _T2)> {};
    // enable_if
	// integral_constant
	template <class T, bool v>
	struct integral_constant 
	{
		static const bool value = v;
		typedef bool value_type;
		typedef integral_constant<T,v> type;
		operator value_type(){ 
			return v; }
	};


	typedef ft::integral_constant<bool,true>	true_type;
	typedef ft::integral_constant<bool,false>	false_type;


	// is_integral
	template <class> struct is_integral							: public false_type {};	//primary template
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

  // equal
	// equal
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, (void) ++first2)
		{
			if (!pred(*first1, *first2))
				return false;
		}
		return true;
	};



  ///////////////////////////

    template< bool B, class T = void >
    struct enable_if
    {      
    };
    template<class T >
    struct enable_if <true, T>
    {
        typedef T type;
        
    };
	// pair
	template <class key, class value> 
	struct pair
	{
		typedef key		first_type;
		typedef value 	second_type;

		first_type first;
		second_type second;

		pair():first(), second(){};

		template<class U, class V> 
			pair (const pair<U,V>& pr):first(pr.first), second(pr.second){ 	};
		pair (const first_type& a, const second_type& b):first(a), second(b){};

		// pair& operator=(const pair& pr){
		// 	if (this != &pr){
		// 		first = pr.first;
		// 		second = pr.second;
		// 	}
		// 	return *this;
		// }
	};

	// make pair
	template <class T1, class T2>
	ft::pair<T1,T2> 
	make_pair(T1 x, T2 y) { 
		return (pair<T1,T2>(x,y) );
	}

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

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