#pragma once 

#include <vector>


namespace ft
{
    template <class T, class container_aka_vector = std::vector<T> >
    class Stack
    {
        //member functions



        // public:
        //     typedef container vector_type;
        //     typedef typename vector_type::value_type value_type;


        public:
        typedef typename container_aka_vector::value_type             value_type; // воруем у вектора его тип
        typedef typename container_aka_vector::reference              reference;
        typedef typename container_aka_vector::const_reference        const_reference;
        typedef typename container_aka_vector::size_type              size_type;

// typename here is letting the compiler know that value_type is a type and not a static member of container_type
    // protected:

        container_aka_vector _stack_prototype; // автоматическое создание "ветора" при создании стэка
        //constructors 
        explicit Stack(const container_aka_vector& cont = container_aka_vector()) : _stack_prototype(cont) 
        {std::cout << "Создано нормально" << std::endl;} 
        // при создании стека мы 
        Stack(const Stack& prev_stack) : _stack_prototype(prev_stack._stack_prototype) 
        { std::cout << "Создано при помощи копирования" << std::endl;}

        Stack &operator=(const Stack& copy_stack)
        {
            std::cout << "Operator = called" << std::endl;
            if (this != &copy_stack)
            {
                this->_stack_prototype = copy_stack._stack_prototype;
                return *this;
            }

            return *this;
        }
        //element access
        // Returns reference to the top element in the stack. This is the most recently pushed element.
        //  This element will be removed on a call to pop(). Effectively calls c.back(). 
        reference top()
        {
            return (_stack_prototype.back());
        }

        //capacity
// true if the underlying container is empty, false otherwise
        bool empty()
        {
            return _stack_prototype.empty();
        }

        size_type size()
        {
            return _stack_prototype.size();
        }
        //modifiers
        // Insert element
        // Inserts a new element at the top of the stack, above its current top element. 
        // The content of this new element is initialized to a copy of val.
        void push(value_type the_el)
        {
            _stack_prototype.push_back(the_el);
        }
        void pop()
        {
            _stack_prototype.pop_back();
        }
        void emplace()
        {
            
        }


//  emplace
// (C++11)
// 	constructs element in-place at the top
// (public member function)
// swap
// (C++11)
// 	swaps the contents
// (public member function)


    };
}