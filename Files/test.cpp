// # include <iostream>
# include <stdexcept>
# include <vector>
# include "_iter_.hpp"
# include "vector.hpp"


typedef struct t_node {
    t_node *parent;
    t_node *left;
    t_node *right;
    int     val;
    int     height;
    int     color;
}node;

std::allocator<node> alloc;
node*    _left_rotation_(node *current)
{
    node    *tmp = alloc.allocate(1);

    /* 2 
            3
                4
    */
   tmp = current->right;
   current->right = tmp->left;
   tmp->left = current;
   return (tmp);
}

node*   _right_rotation_(node *current)
{
    node    *tmp = alloc.allocate(1);

    /*          3
            2 ===> tmp 
        1
    */

    tmp = current->left;
    current->left = tmp->right;
    tmp->right = current;
    return (tmp);
}

node*   _Left_Right_(node *current)
{
    /*      4
        2
            3   
    */
   current->left = _left_rotation_(current->left);
   return (_right_rotation_(current));
}

node*   _Right_Left_(node*  current)
{
    /*  7
            9
        8
    */
   current->right = _right_rotation_(current->right);
   return (_left_rotation_(current));
}

void vector_iterator_test() {
    std::string arr[] = {"1", "2", "3", "4", "5", "6"};
    ft::vector<std::string> v(arr, arr + static_cast<int>(sizeof(arr) / sizeof(std::string)));
    // ns::vector<std::string> v;
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    v.push_back("4");
    v.push_back("5");
    ft::vector<std::string>::const_iterator it = v.begin();
    ft::vector<std::string>::iterator ite = v.end();
    for (; it != ite; it++)
        std::cout << *it << std::endl; 
    std::cout << "size of vector = " << v.size() << std::endl;
    std::cout << "capacity of vector = " << v.capacity() << std::endl;
    // ns::vector<std::string> vector_swap;
    // for (int i = 0; i < 12; i++)
    //     vector_swap.push_back("1");
    // vector_swap = v;
    // std::cout << "===========\n";
    // std::cout << "size of vector_swap = " << vector_swap.size() << std::endl;
    // std::cout << "capacity of vector_swap = " << vector_swap.capacity() << std::endl;
}
int main()
{
	// -------------------- DUMB TESTS : ------------------------
	vector_iterator_test();
}