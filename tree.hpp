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
		Node():color(BLACK), isNil(1),parent(0), left(0), right(0){}; //for nil or root
		Node(T pair):color(RED), isNil(0), parent(0), left(0), right(0), keyValue(pair){};
		Node(const Node &other): 
		color(other.color), isNil(other.isNil), parent(other.parent), left(other.left), right(other.right), keyValue(other.keyValue) {};

		~Node(){};
    };

    template<class T>
    class Tree
    {
    public:
        // ft::Node<T> *head = new ft::Node<T>();
        ft::Node<T> *head = NULL;
        Tree(){};
        ~Tree(){};
        void balance(ft::Node<T> *pasted_node)
        {
            // CASE 1
            
        }
        void add(ft::Node<T> *new_node)
        {
            if (head == NULL)
            {
                head = new_node;}
            else
            {
                Node<T> *curr_node = head;
                
                while(!new_node->isNil)
                {
                    
                    if (new_node->keyValue == curr_node->keyValue)
                        break;
                    if (new_node->keyValue > curr_node->keyValue)
                        {if (curr_node->right != 0) {curr_node = curr_node->right;} 
                        else{curr_node->right = new ft::Node<T>(*new_node);curr_node->right->parent = curr_node;balance(curr_node->right);
                        break;}}
                    else 
                        {if (curr_node->left != 0) curr_node = curr_node->left; 
                        else {curr_node->left = new ft::Node<T>(*new_node);curr_node->left->parent = curr_node;balance(curr_node->left);
                        break;}}
                    // if (curr_node == 0)
                    //     { paste_node(curr_node, new_node);break;}
                }
            }
        };
        void print_node(ft::Node<T> *my_node)
        {
            std::cout << my_node->keyValue << "     ";
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
        void printBT(const std::string& prefix, const ft::Node<T>* nodeV, bool isLeft) const
		{
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );
            
            if (nodeV == NULL){
                std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
                return ;
            }
            // print the value of the node
            if (nodeV->color == 0)
                std::cout <<"\033[0;36m"<< nodeV->keyValue<<"\033[0m"<<std::endl;
            else
                std::cout <<"\033[0;31m"<< nodeV->keyValue << "\033[0m"<<std::endl;
            printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
            printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);		
		}

    };
    

    
} // namespace tree
