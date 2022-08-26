#pragma once


#define BLACK 0
#define RED 1

namespace ft
{
    template <class T>
    struct Node
    {
        int color;
        bool isNil; // 
        struct Node* parent;
        struct Node* left;
        struct Node* right;
		T keyValue; // allocates with notes
		Node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil
		Node(T pair):color(RED), isNil(0), parent(0), left(new Node()), right(new Node()), keyValue(pair){};
		Node(const Node &other): 
		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};

		~Node(){};
    };

    template<class T, class Allocator>
    class Tree
    {
    public:
        // ft::Node<T> *head = new ft::Node<T>();
        ft::Node<T> *head = NULL;
        Tree(){};
        ~Tree(){};
        Allocator					_alloc;
        int _size = 0;

        void rightRotate(ft::Node<T>  *x)
		{
			ft::Node<T> * y = x->left;
			x->left = y->right;
			if (y->right->isNil == 1)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == 0){
				head = y;} 			
			else if (x == x->parent->right)
				x->parent->right = y;
			else x->parent->left = y;
			y->right = x;
			x->parent = y;
			
		}

		void leftRotate(ft::Node<T>  *x)
		{	
			ft::Node<T> * y = x->right;
			x->right = y->left;
			if (y->left->isNil == 1)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == 0){
				head = y;} 
			else if (x == x->parent->left)
				x->parent->left = y;
			else x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
        void balance(ft::Node<T> *z)
        {
            // (void)pasted_node;
            ft::Node<T> *y;
            while ( z->parent->color == RED) // пока не дойдем до корня
            {
                
				if (z->parent == z->parent->parent->left){ // parent is left child
					y = z->parent->parent->right;
					if (y->color == RED){ // y is red case
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;}
					else { //y is black case
						if (z == z->parent->right){ //y is black case, triangle relationship
							z = z->parent;
							leftRotate(z);}
						z->parent->color = BLACK; // case 3
						z->parent->parent->color = RED;
						rightRotate(z->parent->parent);}
				}
				else {//parent is right child 
					y = z->parent->parent->left; // то же самое только зеркально
					if (y->color == RED){ // y (uncle) is red case
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
                        }
					else {
						if (z == z->parent->left){ //y is black case, triangle relationship
							z = z->parent;
							rightRotate(z);}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						leftRotate(z->parent->parent);}
				}
                if (z == head)
                    break;
			}
            head->color = BLACK; // case 0
            }

            ft::Node<T>* find_min(ft::Node<T>* x) const {
			while (x->left->isNil != true)
				x = x->left;
			return (x);
		}
        void add(ft::Node<T> *new_node)
        {
            if (head == NULL)
            {
                head = new_node;
                head->color = BLACK;
                // head->parent = new ft::Node<T> ();
                }
            else
            {
                Node<T> *curr_node = head;
                
                while(!curr_node->isNil)
                {
                    
                    if (new_node->keyValue == curr_node->keyValue)
                        break;
                    if (new_node->keyValue > curr_node->keyValue)
                        {
                            if (curr_node->right->isNil != 1) 
                                {curr_node = curr_node->right;} 
                            else
                                {curr_node->right = new_node;
                                new_node->parent = curr_node;
                                balance(curr_node->right);
                                break;}
                        }
                    else 
                        {if (curr_node->left->isNil != 1) 
                            curr_node = curr_node->left; 
                        else 
                            {
                                curr_node->left = new_node;
                                new_node->parent = curr_node;
                                balance(curr_node->left);
                                break;
                            }
                        }
                    // if (curr_node == 0)
                    //     { paste_node(curr_node, new_node);break;}
                }
            }
        };
        void print_tree(ft::Node<T> *my_node)
        {
            // std::cout <<"PRINTTTTT" << my_node << "|"<< std::endl;
            // if (my_node == NULL)
            //     return;
            // std::cout <<    std::endl;
			printBT("", my_node, false);
		
            // std::cout <<    std::endl;
        };
        void DeleteFixup(ft::Node<T> *x)
        {
			ft::Node<T> *w;

			while (x != head && x->color == BLACK){
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
						x = head;
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
						x = head;}
				}
			}
			x->color = BLACK;
		
        }
        void transplant_node(ft::Node<T> *node_to_delete, ft::Node<T> *node_to_transplant)
        {
			if (node_to_delete->parent == 0){
				head = node_to_transplant;} 
			else if (node_to_delete == node_to_delete->parent->left)
				node_to_delete->parent->left = node_to_transplant;
			else
				node_to_delete->parent->right = node_to_transplant;
			node_to_transplant->parent = node_to_delete->parent;
        }
        void deleteNode(ft::Node<T> *node_to_delete)
        {
            ft::Node<T> *x;
            ft::Node<T> *y;
            int deleteOrigCOlor = node_to_delete->color;
            if (node_to_delete->left->isNil)// если есть только правый ребенок
            {
                x = node_to_delete->right; 
                transplant_node(node_to_delete, node_to_delete->right);
            }            
            else if (node_to_delete->right->isNil)// если есть только левый ребенок
            {
                x = node_to_delete->left; 
                transplant_node(node_to_delete, node_to_delete->left);
            }
            else // если есть оба ребенка 
            {
                y = find_min(node_to_delete->right);
                deleteOrigCOlor = y->color; // что вставляем(цвет)
                // transplant_node(node_to_delete, node_to_delete->left);
                x = node_to_delete->right;
				if (y->parent == node_to_delete)
					x->parent = y;
				else{
					transplant_node(y, y->right);
					y->right = node_to_delete->right;
					y->right->parent = y;}
				transplant_node(node_to_delete, y);
				y->left = node_to_delete->left;
				y->left->parent = y;
				y->color = node_to_delete->color; }
			if (deleteOrigCOlor == BLACK)
				DeleteFixup(x);
            // _alloc.destroy(node_to_delete);
			// _alloc.deallocate(node_to_delete, sizeof(ft::Node<T>));
            
        }
        void printBT(const std::string& prefix, const ft::Node<T>* nodeV, bool isLeft) const
		{
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );
            
            if (nodeV->isNil == 1){
                std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
                return ;
            }
            // print the value of the node
            if (nodeV->color == 0)
                std::cout <<"\033[0;36m"<< nodeV->keyValue<<"\033[0m"<<std::endl;
            else
                std::cout <<"\033[0;31m"<< nodeV->keyValue << "\033[0m"<<std::endl;
            printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, true);
            printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, false);		
		}

    };
    

    
} // namespace tree
