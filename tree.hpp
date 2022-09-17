#pragma once
#include "iterator.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "utils.hpp"
#define BLACK 0
#define RED 1

// namespace ft
// {
//     template <class T>
//     struct Node
//     {
//         int color;
//         bool isNil; // 
//         struct Node* parent;
//         struct Node* left;
//         struct Node* right;
// 		typedef T pair_type;
// 		T keyValue; // allocates with notes
// 		// typedef T.first f_value;
// 		// typedef T.second s_value;
// 		Node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
// 		Node(T pair):color(RED), isNil(0), parent(0), left(new Node()), right(new Node()), keyValue(pair){};
// 		// Node(const T pair):color(RED), isNil(0), parent(0), left(new Node()), right(new Node()), keyValue(pair){};
// 		Node(const Node &other): 
// 		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};
//             friend std::ostream &operator<<(std::ostream &os, const Node &_my_Node) {
//                 return os  << _my_Node.keyValue << " _____";}
// 		~Node(){};
//     };


	

//     template<class T, class Allocator, class Comparator>
//     class Tree
//     {
//     public:
//         // ft::Node<T> *head = new ft::Node<T>();
		
//         ft::Node<T> *head;
// 		typedef typename ft::IteratorForMap<ft::Node<T> >						iterator;
// 		typedef typename T::first_type												key_type;
// 		typedef typename T::second_type											mapped_type;

//         Allocator					_alloc;
//         Comparator					_compare;
//         size_t _size;

//         Tree(const Comparator &comp):head(NULL), _compare(comp),_size(0) {};
	
//         ~Tree(){};


// 		// iterator begin() const {return min(*head);};
// 		// iterator end() const {return max(*head);};
// 		Tree &operator=(const Tree &other)
// 		{
// 			// // тут дерево чистится и вставляется другое дерево в него
// 			if (this != &other)
// 			{
// 				// this.clearAll();
// 			// 	std::cout << "puki puk" << std::endl;

// 				iterator first(find_min(other.head));
// 				iterator last(find_max(other.head));


// 				while (first != last)
// 				{
// 					ft::Node<T> *_puk = new ft::Node<T>(first._iter->keyValue);
// 					add(_puk);
// 					first++;
// 					_size++;
// 					// std::cout << "puki puk: " << first._iter << "  "<<last._iter <<std::endl;
// 					// usleep(3000000);
// 				}
// 				ft::Node<T> *_puk = new ft::Node<T>(first._iter->keyValue);
// 				add(_puk);


// 			}
// 			return *this;
// 		};

//         void rightRotate(ft::Node<T>  *x)
// 		{
// 			ft::Node<T> * y = x->left;
// 			x->left = y->right;
// 			if (y->right->isNil == 1)
// 				y->right->parent = x;
// 			y->parent = x->parent;
// 			if (x->parent == 0){
// 				head = y;} 			
// 			else if (x == x->parent->right)
// 				x->parent->right = y;
// 			else x->parent->left = y;
// 			y->right = x;
// 			x->parent = y;
			
// 		}

// 		void leftRotate(ft::Node<T>  *x)
// 		{	
// 			ft::Node<T> * y = x->right;
// 			x->right = y->left;
// 			if (y->left->isNil == 1)
// 				y->left->parent = x;
// 			y->parent = x->parent;
// 			if (x->parent == 0){
// 				head = y;} 
// 			else if (x == x->parent->left)
// 				x->parent->left = y;
// 			else x->parent->right = y;
// 			y->left = x;
// 			x->parent = y;
// 		}
//         void balance(ft::Node<T> *z)
//         {
//             // (void)pasted_Node;
//             ft::Node<T> *y;

// 			while (z->parent->color == RED){ // parent is red 

// 				if (z->parent == z->parent->parent->left){ // z parent is left child
// 					y = z->parent->parent->right;
// 					if (y->color == RED){ // y is red case
// 						z->parent->color = BLACK;
// 						y->color = BLACK;
// 						z->parent->parent->color = RED;
// 						z = z->parent->parent;}
// 					else {
// 						if (z == z->parent->right){ //y is black case, triangle relationship
// 							z = z->parent;
// 							leftRotate(z);}
// 						z->parent->color = BLACK;
// 						z->parent->parent->color = RED;
// 						rightRotate(z->parent->parent);}
// 				}
// 				else {
// 					y = z->parent->parent->left;
// 					if (y->color == RED){ // y (uncle) is red case
// 						z->parent->color = BLACK;
// 						y->color = BLACK;
// 						z->parent->parent->color = RED;
// 						z = z->parent->parent;}
// 					else {
// 						if (z == z->parent->left){ //y is black case, triangle relationship
// 							z = z->parent;
// 							rightRotate(z);}
// 						z->parent->color = BLACK;
// 						z->parent->parent->color = RED;
// 						leftRotate(z->parent->parent);}
// 				}
// 				                if (z == head)
//                     break;

// 			}
//             head->color = BLACK; // case 0
//             }

//             ft::Node<T>* find_min(ft::Node<T>* x) const {
// 			if (x == NULL)
// 				return x;
// 			// std::cout << "!!!!!!!!!!" << std::endl;
// 			// std::cout << x->keyValue << std::endl;
// 			while (x->left->isNil != true){
// 				x = x->left; 
// 				// std::cout << x->keyValue << x << " :key" <<std::endl;
// 				}
// 			return (x);
// 		}

//             ft::Node<T>* find_max(ft::Node<T>* x) const {
// 			if (x == NULL)
// 				return x;
// 			while (x->right->isNil != true)
// 				x = x->right;
// 			return (x);
// 		}

//         void add(ft::Node<T> *new_Node)
//         {
// 			_size++;

//             if (head == NULL)
//             {
// 				std::cout << "puk " << std::endl;
//                 head = new_Node;
// 				// ft::Node<T> *mill_head = new ft::Node<T> ();
//                 head->color = BLACK;
// 				// mill_head->right = head;
//                 }
//             else
//             {
//                 Node<T> *curr_Node = head;
                
//                 while(!curr_Node->isNil)
//                 {
                    
//                     if (new_Node->keyValue == curr_Node->keyValue)
//                         break;
//                     if (new_Node->keyValue > curr_Node->keyValue)
//                         {
//                             if (curr_Node->right->isNil != 1) 
//                                 {curr_Node = curr_Node->right;} 
//                             else
//                                 {curr_Node->right = new_Node;
//                                 new_Node->parent = curr_Node;
// 								new_Node->color = RED;
//                                 balance(curr_Node->right);
								
//                                 break;}
//                         }
//                     else 
//                         {if (curr_Node->left->isNil != 1) 
//                             curr_Node = curr_Node->left; 
//                         else 
//                             {
//                                 curr_Node->left = new_Node;
//                                 new_Node->parent = curr_Node;
// 								new_Node->color = RED;
//                                 balance(curr_Node->left);
//                                 break;
//                             }
//                         }
//                     // if (curr_Node == 0)
//                     //     { paste_Node(curr_Node, new_Node);break;}
//                 }
//             }
// 			std::cout << "after_balance add: " << std::endl;
// 			print_Tree(head);
//         };
//         void print_Tree(ft::Node<T> *my_Node)
//         {
//             // std::cout <<"PRINTTTTT" << my_Node << "|"<< std::endl;
//             if (my_Node == NULL)
//                 return;
//             // std::cout <<    std::endl;
// 			printBT("", my_Node, false);
		
//             // std::cout <<    std::endl;
//         };


//         void DeleteFixup(ft::Node<T> *x)
//         {
// 			ft::Node<T> *w;
			
// 			while (x != head && x->color == BLACK){
// 				if (x == x->parent->left){
// 					w = x->parent->right;
// 					if (w->color == RED){
// 						w->color = BLACK;
// 						x->parent->color = RED;
// 						leftRotate(x->parent);
// 						w = x->parent->right; }
// 					if (w->left->color == BLACK && w->right->color == BLACK){
// 						w->color = RED;
// 						x = x->parent; }
// 					else {
// 						if (w->right->color == BLACK) {
// 							w->left->color = BLACK;
// 							w->color = RED;
// 							rightRotate(w);
// 							w = x->parent->right; }
// 						w->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						w->right->color = BLACK;
// 						leftRotate(x->parent);
// 						x = head;
// 					}		
// 				}
// 				else {
// 					w = x->parent->left;
// 					if (w->color == RED){
// 						w->color = BLACK;
// 						x->parent->color = RED;
// 						rightRotate(x->parent);
// 						w = x->parent->left; }
// 					if (w->right->color == BLACK && w->left->color == BLACK){
// 						w->color = RED;
// 						x = x->parent; }
// 					else {
// 						if (w->left->color == BLACK) {
// 							w->right->color = BLACK;
// 							w->color = RED;
// 							leftRotate(w);
// 							w = x->parent->left; }
// 						w->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						w->left->color = BLACK;
// 						rightRotate(x->parent);
// 						x = head;}
// 				}
// 			}
// 			x->color = BLACK;
		
//         }

// 		ft::Node<T>* TreeSearch(const key_type& k) const
// 		{
// 			ft::Node<T>* x = head;
// 			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
// 			if (head == NULL)
// 				return head;
// 			while (x->isNil != true && k != x->keyValue.first) {	
// 				if (_compare(kPair, x->keyValue) == true )
// 					x = x->left;			
// 				else 
// 					x = x->right; }
// 			return (x);

// 		}
//         void transplant_Node(ft::Node<T> *Node_to_delete, ft::Node<T> *Node_to_transplant)
//         {
// 			if (Node_to_delete->parent == 0){
// 				head = Node_to_transplant;} 
// 			else if (Node_to_delete == Node_to_delete->parent->left)
// 				Node_to_delete->parent->left = Node_to_transplant;
// 			else
// 				Node_to_delete->parent->right = Node_to_transplant;
// 			Node_to_transplant->parent = Node_to_delete->parent;
//         }
//         void deleteNode(iterator Node_to_del)
//         {
// 			ft::Node<T> *Node_to_delete = Node_to_del._iter;
//             ft::Node<T> *x;
//             ft::Node<T> *y;
// 			// iterator x;
//             // iterator y;
// 			std::cout << "before: " << std::endl;
// 			print_Tree(head);
//             int deleteOrigCOlor = Node_to_delete->color;
			
// 			_size--;
//             if (Node_to_delete->left->isNil)// если есть только правый ребенок
//             {
//                 x = Node_to_delete->right; 
//                 transplant_Node(Node_to_delete, Node_to_delete->right);
//             }            
//             else if (Node_to_delete->right->isNil)// если есть только левый ребенок
//             {
//                 x = Node_to_delete->left; 
//                 transplant_Node(Node_to_delete, Node_to_delete->left);
//             }
//             else // если есть оба ребенка 
//             {
//                 y = find_min(Node_to_delete->right);
//                 deleteOrigCOlor = y->color; // что вставляем(цвет)
//                 // transplant_Node(Node_to_delete, Node_to_delete->left);
//                 x = Node_to_delete->right;
// 				if (y->parent == Node_to_delete)
// 					x->parent = y;
// 				else{
// 					transplant_Node(y, y->right);
// 					y->right = Node_to_delete->right;
// 					y->right->parent = y;}
// 				transplant_Node(Node_to_delete, y);
// 				y->left = Node_to_delete->left;
// 				y->left->parent = y;
// 				y->color = Node_to_delete->color; }
			
// 			if (deleteOrigCOlor == BLACK)
// 				DeleteFixup(x);
// 			print_Tree(head);
// 			std::cout << "Fixed" << std::endl;
//             // _alloc.destroy(Node_to_delete);
// 			// _alloc.deallocate(Node_to_delete, sizeof(ft::Node<T>));
            
//         }
// 		bool	operator==(const ft::Tree<T, Allocator, Comparator> y){
// 			if (_size != y._size)
// 				return false;
// 			return (ft::equal(iterator(find_min(head)), iterator(find_max(head)), iterator(y.find_min(y.head))));
// 		};
//         void printBT(const std::string& prefix, const ft::Node<T>* NodeV, bool isLeft) const
// 		{
//             std::cout << prefix;

//             std::cout << (isLeft ? "├──" : "└──" );
            
//             if (NodeV->isNil == 1){
//                 std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
//                 return ;
//             }
//             // print the value of the Node
// 			ft::pair<int,int> my_pair = NodeV->keyValue;
//             if (NodeV->color == 0)
//                 std::cout <<"\033[0;36m"<< my_pair.first<<"\033[0m"<<std::endl;
//             else
//                 std::cout <<"\033[0;31m"<< my_pair.first << "\033[0m"<<std::endl;
//             printBT( prefix + (isLeft ? "│   " : "    "), NodeV->right, true);
//             printBT( prefix + (isLeft ? "│   " : "    "), NodeV->left, false);		
// 		}

//     };
    

    
// } // namespace Tree


// #ifndef Tree_HPP
// #define Tree_HPP

// #include <memory>
// #include "utils.hpp"
// #include "iterator.hpp"

// #define BLACK 0
// #define RED 1


// namespace ft
// {
// 	template<class T>
// 	struct Node
// 	{
// 		int color;
// 		bool isNil; // 
// 		struct Node* parent;
// 		struct Node* left;
// 		struct Node* right;

// 		T keyValue; // allocates with notes
// 		Node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
// 		Node(T pair):color(RED), isNil(0), parent(0), left(0), right(0), keyValue(pair){};
// 		Node(const Node &other): 
// 		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};

// 		~Node(){};
// 	};



// 	template <class Pair, class Allocator, class Compare >
// 	class Tree
// 	{
// 	public:
// 		typedef Pair																		value_type;
// 		typedef Compare 																	key_compare;
// 		typedef Allocator 																	allocator_type;
// 		typedef typename value_type::first_type												key_type;
// 		typedef typename value_type::second_type											mapped_type;
// 		typedef typename ft::mapIterator<Node<value_type>*, value_type>						iterator;
// 		// typedef Allocator::
		

// 	private:
// 		key_compare					_compare;	
// 		Node<value_type>* 			_nil;
// 		Node<value_type>* 			_root;
// 		size_t						_size; //excludes nil

// 	public:
// 		Allocator					_alloc;

// 	public:
// 		Tree(const key_compare &comp):_compare(comp), _size(0){
// 			_nil = _alloc.allocate(1);
// 			_alloc.construct(_nil, Node<value_type>());
// 			_nil->left = _nil->right = _nil->parent = _nil;
// 			_root = _nil;
// 		};		
// 		Tree(const Tree& copy){	*this = copy;};
// 		Tree &operator=(const Tree& copy){
// 			if (this != &copy){
// 				clear();
				
// 				iterator first = copy.begin();
// 				iterator last = copy.end();
// 				while(first!= last){
// 					insertNode(*first);
// 					first++;}				 
// 			}
// 			return *this;

// 		}

// 		~Tree(){ clearAll(); };

// 		// key_type root() { return _root->keyValue.first;}

// 		void destroy(Node<value_type>* nd)
// 		{
// 			if (nd != _nil)
// 			{
// 				destroy(nd->left);
// 				destroy(nd->right);
// 				_alloc.destroy(nd);
// 				_alloc.deallocate(nd, sizeof(Node<value_type>));
// 			}
// 		}

// 		void clear(void) {
// 			destroy(_root);
// 			_size = 0;
// 			_nil->left = _nil->right = _nil->parent = _nil;
// 			_root = _nil;

// 		}

// 		void clearAll(void)
// 		{
// 			clear();
// 			_alloc.destroy(_nil);
// 			_alloc.deallocate(_nil, sizeof(ft::Node<value_type>));

// 		}

// 		Node<value_type>* begin(void) const {
// 			Node<value_type>* tmp = min(_root);
// 			return (tmp);
// 		}

// 		Node<value_type>* end(void) const {
// 			Node<value_type>* tmp = _root;
// 			while (tmp != _nil)
// 				tmp = tmp->right;
// 			return (tmp);
// 		}
				
// 		ft::pair<Node<value_type>*, bool> insertNode(const value_type& val)
// 		{
// 			Node<value_type>* x = _root;
// 			Node<value_type>* y = _nil;
			
// 			while (x != _nil){
// 				y = x;
// 				if (x->keyValue.first == val.first)
// 					return (ft::make_pair(x, false));
// 				if  (_compare(val, x->keyValue))
// 					x = x->left;
// 				else
// 					x = x->right;}
// 			Node<value_type>* newNode = _alloc.allocate(1);
// 			_alloc.construct(newNode, ft::Node<value_type>(val));
			
// 			newNode->parent = y;
// 			if (y == _nil){
// 				_root = newNode;
// 				_root->parent = _nil; //different from algor
// 				_nil->left = _root;} 
// 			else if  (_compare(val, y->keyValue))
// 				y->left = newNode;
// 			else
// 				y->right = newNode;
// 			newNode->left = newNode->right = _nil;
// 			newNode->color = RED;
// 			insertFixup(newNode);
// 			++_size;
// 			return (ft::make_pair(newNode, true));

// 		}
		
// 		void insertFixup(Node<value_type> *z)
// 		{
// 			Node<value_type>* y;

// 			while (z->parent->color == RED){ // parent is red 
// 				if (z->parent == z->parent->parent->left){ // z parent is left child
// 					y = z->parent->parent->right;
// 					if (y->color == RED){ // y is red case
// 						z->parent->color = BLACK;
// 						y->color = BLACK;
// 						z->parent->parent->color = RED;
// 						z = z->parent->parent;}
// 					else {
// 						if (z == z->parent->right){ //y is black case, triangle relationship
// 							z = z->parent;
// 							leftRotate(z);}
// 						z->parent->color = BLACK;
// 						z->parent->parent->color = RED;
// 						rightRotate(z->parent->parent);}
// 				}
// 				else {
// 					y = z->parent->parent->left;
// 					if (y->color == RED){ // y (uncle) is red case
// 						z->parent->color = BLACK;
// 						y->color = BLACK;
// 						z->parent->parent->color = RED;
// 						z = z->parent->parent;}
// 					else {
// 						if (z == z->parent->left){ //y is black case, triangle relationship
// 							z = z->parent;
// 							rightRotate(z);}
// 						z->parent->color = BLACK;
// 						z->parent->parent->color = RED;
// 						leftRotate(z->parent->parent);}
// 				}
// 			}
// 			_root->color = BLACK; // case 0
// 		}

// 		void rightRotate(Node<value_type> *x)
// 		{
// 			Node<value_type>* y = x->left;
// 			x->left = y->right;
// 			if (y->right != _nil)
// 				y->right->parent = x;
// 			y->parent = x->parent;
// 			if (x->parent == _nil){
// 				_root = y;
// 				_nil->left = _root;} 			
// 			else if (x == x->parent->right)
// 				x->parent->right = y;
// 			else x->parent->left = y;
// 			y->right = x;
// 			x->parent = y;
			
// 		}

// 		void leftRotate(Node<value_type> *x)
// 		{	
// 			Node<value_type>* y = x->right;
// 			x->right = y->left;
// 			if (y->left != _nil)
// 				y->left->parent = x;
// 			y->parent = x->parent;
// 			if (x->parent == _nil){
// 				_root = y;
// 				_nil->left = _root;} 
// 			else if (x == x->parent->left)
// 				x->parent->left = y;
// 			else x->parent->right = y;
// 			y->left = x;
// 			x->parent = y;
// 		}

// 		void transplant(Node<value_type> *u, Node<value_type> *v)
// 		{
// 			if (u->parent == _nil){
// 				_root = v;
// 				_nil->left = _root;} 
// 			else if (u == u->parent->left)
// 				u->parent->left = v;
// 			else
// 				u->parent->right = v;
// 			v->parent = u->parent;
// 		}

		

// 		void deleteFixup(Node<value_type> *x){
// 			Node<value_type> *w;

// 			while (x != _root && x->color == BLACK){
// 				if (x == x->parent->left){
// 					w = x->parent->right;
// 					if (w->color == RED){
// 						w->color = BLACK;
// 						x->parent->color = RED;
// 						leftRotate(x->parent);
// 						w = x->parent->right; }
// 					if (w->left->color == BLACK && w->right->color == BLACK){
// 						w->color = RED;
// 						x = x->parent; }
// 					else {
// 						if (w->right->color == BLACK) {
// 							w->left->color = BLACK;
// 							w->color = RED;
// 							rightRotate(w);
// 							w = x->parent->right; }
// 						w->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						w->right->color = BLACK;
// 						leftRotate(x->parent);
// 						x = _root;
// 					}		
// 				}
// 				else {
// 					w = x->parent->left;
// 					if (w->color == RED){
// 						w->color = BLACK;
// 						x->parent->color = RED;
// 						rightRotate(x->parent);
// 						w = x->parent->left; }
// 					if (w->right->color == BLACK && w->left->color == BLACK){
// 						w->color = RED;
// 						x = x->parent; }
// 					else {
// 						if (w->left->color == BLACK) {
// 							w->right->color = BLACK;
// 							w->color = RED;
// 							leftRotate(w);
// 							w = x->parent->left; }
// 						w->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						w->left->color = BLACK;
// 						rightRotate(x->parent);
// 						x = _root;}
// 				}
// 			}
// 			x->color = BLACK;
// 		}
		
// 		void rbTreeDelete(Node<value_type> *z)
// 		{
// 			Node<value_type> 	*x;
// 			Node<value_type> 	*y = z;
// 			int 				yOriginalColor = y->color;

// 			if (z == _nil){
// 				std::cerr << "Tree end() cannot be erased" << std::endl;
// 				throw ; }
// 			if (z->left == _nil){
// 				x = z->right; 
// 				transplant(z, z->right); }
// 			else if (z->right == _nil) {
// 				x = z->left; 
// 				transplant(z, z->left);}
// 			else {
// 				y = min(z->right);
// 				yOriginalColor = y->color;
// 				x = y->right;
// 				if (y->parent == z)
// 					x->parent = y;
// 				else{
// 					transplant(y, y->right);
// 					y->right = z->right;
// 					y->right->parent = y;}
// 				transplant(z, y);
// 				y->left = z->left;
// 				y->left->parent = y;
// 				y->color = z->color; }
// 			if (yOriginalColor == BLACK)
// 				deleteFixup(x);
// 			_alloc.destroy(z);
// 			_alloc.deallocate(z, sizeof(Node<value_type>));
// 			--_size;
// 			if (_size == 0)
// 				_root = _nil;
			
// 		}

// 		Node<value_type>* TreeSearch(const key_type& k) const
// 		{
// 			Node<value_type>* x = _root;
// 			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);

// 			while (x != _nil && k != x->keyValue.first) {	
// 				if (_compare(kPair, x->keyValue) == true )
// 					x = x->left;			
// 				else 
// 					x = x->right; }
// 			return (x);

// 		}

// 		size_t size(void) const { return _size; }

// 		Node<value_type>* lower_bound (const key_type & k) const
// 		{
// 			Node<value_type>* rootp = _root;
// 			Node<value_type>* result = _nil;
// 			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
// 			while (rootp != _nil)
// 			{
// 			    if (!_compare(rootp->keyValue, kPair)) {
// 			        result = rootp;
// 			        rootp = rootp->left; }
// 			    else
// 			        rootp = rootp->right;
// 			}
// 		    return (result);
// 		}

// 		Node<value_type>* upper_bound (const key_type & k) const
// 		{
// 			Node<value_type>* rootp = _root;
// 			Node<value_type>* result = _nil;
// 			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
// 			while (rootp != _nil)
// 			{
// 			    if (_compare(kPair, rootp->keyValue)) {
// 			        result = rootp;
// 			        rootp = rootp->left; }
// 			    else
// 			        rootp = rootp->right;
// 			}
// 		    return (result);
// 		}

// 		ft::pair<iterator, iterator> equal_range_unique(const key_type& k) 
// 		{
// 			typedef ft::pair<iterator, iterator> _Pp;

// 			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
// 			Node<value_type>* result = _nil;
// 			Node<value_type>* rootp = _root;

// 			while (rootp != _nil)
// 			{
// 				if (_compare(kPair, rootp->keyValue)){
// 					result =rootp;
// 					rootp = rootp->left;}
// 				else if (_compare(rootp->keyValue, kPair))
// 					rootp = rootp->right;
// 				else
// 					return _Pp(iterator(rootp), iterator(rootp->right != _nil ? min(rootp->right) : result));
// 			}

// 			return _Pp(iterator(result), iterator(result));
// 		}

// 		void printBT(const std::string& prefix, const Node<value_type>* NodeV, bool isLeft) const
// 		{
// 				std::cout << prefix;

// 				std::cout << (isLeft ? "├──" : "└──" );
				
// 				if (NodeV == _nil){
// 					std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
// 					return ;
// 				}
// 				// print the value of the Node
// 				if (NodeV->color == 0)
// 					std::cout <<"\033[0;36m"<< NodeV->keyValue.first<<"\033[0m"<<std::endl;
// 				else
// 					std::cout <<"\033[0;31m"<< NodeV->keyValue.first << "\033[0m"<<std::endl;
// 				printBT( prefix + (isLeft ? "│   " : "    "), NodeV->left, true);
// 				printBT( prefix + (isLeft ? "│   " : "    "), NodeV->right, false);		
// 		}

// 		void printTree(){
// 			printBT("", _root, false);
// 		}


// 		Node<value_type>* min(Node<value_type>* x) const {
// 			while (x->left->isNil != true)
// 				x = x->left;
// 			return (x);
// 		}
		
// 		friend bool	operator==(const Tree& x, const Tree& y){
// 			if (x.size() != y.size())
// 				return false;
// 			return (ft::equal(iterator(x.begin()), iterator(x.end()), iterator(y.begin())));
// 		};
		
// 	};
	 
// }

// #endif

#pragma once

#include <memory>
#include "utils.hpp"
#include "iterator.hpp"

#define BLACK 0
#define RED 1


namespace ft
{
	template<class T>
	struct Node
	{
		int color;
		bool isNil; // 
		struct Node* parent;
		struct Node* left;
		struct Node* right;
		typedef T pair_type;
		T keyValue; // allocates with notes
		Node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
		Node(T pair):color(RED), isNil(0), parent(0), left(0), right(0), keyValue(pair){};
		Node(const Node &other): 
		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};

		~Node(){};
	};



	template <class Pair, class Allocator, class Compare >
	class Tree
	{
	public:
		typedef Pair																		value_type;
		typedef Compare 																	key_compare;
		typedef Allocator 																	allocator_type;
		typedef typename value_type::first_type												key_type;
		typedef typename value_type::second_type											mapped_type;
		typedef typename ft::IteratorForMap<ft::Node<Pair> >						iterator;
		// typedef Allocator::
		

	private:
		key_compare					_compare;	
		Node<value_type>* 			_nil;
		// Node<value_type>* 			_root;


	public:
		Allocator					_alloc;
				size_t						_size; //excludes nil

	public:
		Node<value_type>* 			_root;
		Tree(const key_compare &comp):_compare(comp), _size(0){
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, Node<value_type>());
			_nil->left = _nil->right = _nil->parent = _nil;
			_root = _nil;
		};		
		Tree(const Tree& copy){	*this = copy;};
		Tree &operator=(const Tree& copy){
			if (this != &copy){
				clear();
				
				iterator first = copy.begin();
				iterator last = copy.end();
				while(first!= last){
					insertNode(*first);
					first++;}				 
			}
			return *this;

		}

		~Tree(){ clearAll(); };

		// key_type root() { return _root->keyValue.first;}

		void destroy(Node<value_type>* nd)
		{
			if (nd != _nil)
			{
				destroy(nd->left);
				destroy(nd->right);
				_alloc.destroy(nd);
				_alloc.deallocate(nd, sizeof(Node<value_type>));
			}
		}

		void clear(void) {
			destroy(_root);
			_size = 0;
			_nil->left = _nil->right = _nil->parent = _nil;
			_root = _nil;

		}

		void clearAll(void)
		{
			clear();
			_alloc.destroy(_nil);
			_alloc.deallocate(_nil, sizeof(ft::Node<value_type>));

		}

		Node<value_type>* begin(void) const {
			Node<value_type>* tmp = min(_root);
			return (tmp);
		}

		Node<value_type>* end(void) const {
			Node<value_type>* tmp = _root;
			while (tmp != _nil)
				tmp = tmp->right;
			return (tmp);
		}
				
		ft::pair<Node<value_type>*, bool> insertNode(const value_type& val)
		{
			Node<value_type>* x = _root;
			Node<value_type>* y = _nil;
			
			while (x != _nil){
				y = x;
				if (x->keyValue.first == val.first)
					return (ft::make_pair(x, false));
				if  (_compare(val, x->keyValue))
					x = x->left;
				else
					x = x->right;}
			Node<value_type>* newNode = _alloc.allocate(1);
			_alloc.construct(newNode, ft::Node<value_type>(val));
			
			newNode->parent = y;
			if (y == _nil){
				_root = newNode;
				_root->parent = _nil; //different from algor
				_nil->left = _root;} 
			else if  (_compare(val, y->keyValue))
				y->left = newNode;
			else
				y->right = newNode;
			newNode->left = newNode->right = _nil;
			newNode->color = RED;
			insertFixup(newNode);
			++_size;
			return (ft::make_pair(newNode, true));

		}
		
		void insertFixup(Node<value_type> *z)
		{
			Node<value_type>* y;

			while (z->parent->color == RED){ // parent is red 
				if (z->parent == z->parent->parent->left){ // z parent is left child
					y = z->parent->parent->right;
					if (y->color == RED){ // y is red case
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;}
					else {
						if (z == z->parent->right){ //y is black case, triangle relationship
							z = z->parent;
							leftRotate(z);}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rightRotate(z->parent->parent);}
				}
				else {
					y = z->parent->parent->left;
					if (y->color == RED){ // y (uncle) is red case
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;}
					else {
						if (z == z->parent->left){ //y is black case, triangle relationship
							z = z->parent;
							rightRotate(z);}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						leftRotate(z->parent->parent);}
				}
			}
			_root->color = BLACK; // case 0
		}

		void rightRotate(Node<value_type> *x)
		{
			Node<value_type>* y = x->left;
			x->left = y->right;
			if (y->right != _nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == _nil){
				_root = y;
				_nil->left = _root;} 			
			else if (x == x->parent->right)
				x->parent->right = y;
			else x->parent->left = y;
			y->right = x;
			x->parent = y;
			
		}

		void leftRotate(Node<value_type> *x)
		{	
			Node<value_type>* y = x->right;
			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _nil){
				_root = y;
				_nil->left = _root;} 
			else if (x == x->parent->left)
				x->parent->left = y;
			else x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void transplant(Node<value_type> *u, Node<value_type> *v)
		{
			if (u->parent == _nil){
				_root = v;
				_nil->left = _root;} 
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		

		void deleteFixup(Node<value_type> *x){
			Node<value_type> *w;

			while (x != _root && x->color == BLACK){
				if (x == x->parent->left){
					w = x->parent->right;
					if (w->color == RED){
						w->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						w = x->parent->right; }
					if (w->left->color == BLACK && w->right->color == BLACK){
						w->color = RED;
						x = x->parent; }
					else {
						if (w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = x->parent->right; }
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						leftRotate(x->parent);
						x = _root;
					}		
				}
				else {
					w = x->parent->left;
					if (w->color == RED){
						w->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						w = x->parent->left; }
					if (w->right->color == BLACK && w->left->color == BLACK){
						w->color = RED;
						x = x->parent; }
					else {
						if (w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							leftRotate(w);
							w = x->parent->left; }
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						rightRotate(x->parent);
						x = _root;}
				}
			}
			x->color = BLACK;
		}
		
		void rbTreeDelete(Node<value_type> *z)
		{
			Node<value_type> 	*x;
			Node<value_type> 	*y = z;
			int 				yOriginalColor = y->color;

			if (z == _nil){
				std::cerr << "Tree end() cannot be erased" << std::endl;
				throw ; }
			if (z->left == _nil){
				x = z->right; 
				transplant(z, z->right); }
			else if (z->right == _nil) {
				x = z->left; 
				transplant(z, z->left);}
			else {
				y = min(z->right);
				yOriginalColor = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color; }
			if (yOriginalColor == BLACK)
				deleteFixup(x);
			_alloc.destroy(z);
			_alloc.deallocate(z, sizeof(Node<value_type>));
			--_size;
			if (_size == 0)
				_root = _nil;
			
		}

		Node<value_type>* TreeSearch(const key_type& k) const
		{
			Node<value_type>* x = _root;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);

			while (x != _nil && k != x->keyValue.first) {	
				if (_compare(kPair, x->keyValue) == true )
					x = x->left;			
				else 
					x = x->right; }
			return (x);

		}

		size_t size(void) const { return _size; }

		Node<value_type>* lower_bound (const key_type & k) const
		{
			Node<value_type>* rootp = _root;
			Node<value_type>* result = _nil;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
			while (rootp != _nil)
			{
			    if (!_compare(rootp->keyValue, kPair)) {
			        result = rootp;
			        rootp = rootp->left; }
			    else
			        rootp = rootp->right;
			}
		    return (result);
		}

		Node<value_type>* upper_bound (const key_type & k) const
		{
			Node<value_type>* rootp = _root;
			Node<value_type>* result = _nil;
			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			
			while (rootp != _nil)
			{
			    if (_compare(kPair, rootp->keyValue)) {
			        result = rootp;
			        rootp = rootp->left; }
			    else
			        rootp = rootp->right;
			}
		    return (result);
		}

		ft::pair<iterator, iterator> equal_range_unique(const key_type& k) 
		{
			typedef ft::pair<iterator, iterator> _Pp;

			ft::pair<key_type, mapped_type> kPair = ft::make_pair(k, 0);
			Node<value_type>* result = _nil;
			Node<value_type>* rootp = _root;

			while (rootp != _nil)
			{
				if (_compare(kPair, rootp->keyValue)){
					result =rootp;
					rootp = rootp->left;}
				else if (_compare(rootp->keyValue, kPair))
					rootp = rootp->right;
				else
					return _Pp(iterator(rootp), iterator(rootp->right != _nil ? min(rootp->right) : result));
			}

			return _Pp(iterator(result), iterator(result));
		}

		void printBT(const std::string& prefix, const Node<value_type>* NodeV, bool isLeft) const
		{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );
				
				if (NodeV == _nil){
					std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
					return ;
				}
				// print the value of the Node
				if (NodeV->color == 0)
					std::cout <<"\033[0;36m"<< NodeV->keyValue.first<<"\033[0m"<<std::endl;
				else
					std::cout <<"\033[0;31m"<< NodeV->keyValue.first << "\033[0m"<<std::endl;
				printBT( prefix + (isLeft ? "│   " : "    "), NodeV->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), NodeV->right, false);		
		}

		void printTree(){
			printBT("", _root, false);
		}

		ft::Node<Pair>* find_min(ft::Node<Pair>* x) const {
			if (x == NULL)
				return x;
			// std::cout << "!!!!!!!!!!" << std::endl;
			// std::cout << x->keyValue << std::endl;
			while (x->left->isNil != true){
				x = x->left; 
				// std::cout << x->keyValue << x << " :key" <<std::endl;
				}
			return (x);
		}

            ft::Node<Pair>* find_max(ft::Node<Pair>* x) const {
			if (x == NULL)
				return x;
			while (x->right->isNil != true)
				x = x->right;
			return (x);
		}


		Node<value_type>* min(Node<value_type>* x) const {
			while (x->left->isNil != true)
				x = x->left;
			return (x);
		}
		
		friend bool	operator==(const Tree& x, const Tree& y){
			if (x.size() != y.size())
				return false;
			return (ft::equal(iterator(x.begin()), iterator(x.end()), iterator(y.begin())));
		};
		
	};
	 
}

