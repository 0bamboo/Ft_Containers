#include <iostream>
#include <string>
#include <deque>

#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

// #include "map.hpp"
// #include "set.hpp"
// #include "stack.hpp"
#include "Files/vector.hpp"
// #include "algorithm.hpp"
#include <cstdlib>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template <typename T, class Container = std::deque<T> >
// class MuntantStack: public ns::stack<T, Container>
// {
//     public:
//         MuntantStack() {}
//         MuntantStack(const MuntantStack<T, Container>& src) { *this = src; }
//         MuntantStack<T, Container>& operator=(const MuntantStack<T, Container>& rhs) {
//             if (this != &rhs)
//                 this->c = rhs.c;
//             return *this;
//         }
//         ~MuntantStack() {}
//         typedef typename ns::stack<T, Container>::container_type::iterator iterator; 
//         typedef typename ns::stack<T, Container>::container_type::const_iterator const_iterator;
//         iterator begin() {
//             return this->c.begin();
//         }
//         const_iterator begin() const {
//             return this->c.begin();
//         }
//         iterator end() {
//             return this->c.end();
//         }
//         const_iterator end() const {
//             return this->c.end();
//         }
// };

// Stack tests

void stack_test() {
    MuntantStack<int, ns::vector<int> > s;
    MuntantStack<int, ns::vector<int> > s1;
    for (int i = 0; i < 10; i++)
        s.push(i);
    for (int i = 0; i < 11; i++)
        s1.push(i);
    MuntantStack<int, ns::vector<int> >::iterator it = s.begin();
    for (; it != s.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "=========== empty ===========\n";
    std::cout << s.empty() << std::endl;
    std::cout << "=========== size ===========\n";
    std::cout << s.size() << std::endl;
    std::cout << "=========== pop ===========\n";
    while (!s.empty()) {
        std::cout << ' ' << s.top();
        s.pop();
    }
    std::cout << "\n";
    std::cout << (s == s1) << std::endl;
    std::cout << (s != s1) << std::endl;
    std::cout << (s < s1) << std::endl;
    std::cout << (s <= s1) << std::endl;
    std::cout << (s > s1) << std::endl;
    std::cout << (s >= s1) << std::endl;
}


// Vector tests
void vector_iterator_test() {
    std::string arr[] = {"1", "2", "3", "4", "5", "6"};
    ns::vector<std::string> v(arr, arr + static_cast<int>(sizeof(arr) / sizeof(std::string)));
    // ns::vector<std::string> v;
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    v.push_back("4");
    v.push_back("5");
    ns::vector<std::string>::const_iterator it = v.begin();
    ns::vector<std::string>::iterator ite = v.end();
    for (; it != ite; it++)
        std::cout << *it << std::endl; 
    std::cout << "size of vector = " << v.size() << std::endl;
    std::cout << "capacity of vector = " << v.capacity() << std::endl;
    ns::vector<std::string> vector_swap;
    for (int i = 0; i < 12; i++)
        vector_swap.push_back("1");
    // vector_swap = v;
    std::cout << "===========\n";
    std::cout << "size of vector_swap = " << vector_swap.size() << std::endl;
    std::cout << "capacity of vector_swap = " << vector_swap.capacity() << std::endl;
}
void vector_capacity_test() {
    ns::vector<unsigned long> vector_int(10, 5);
    std::cout << "max size = " << vector_int.max_size() << std::endl;
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.push_back(1);
    std::cout << "==== after push_back ====\n";
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.resize(50, 2);
    std::cout << "==== vector_int after resize ====\n";
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.resize(10, 3);
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    std::cout << "==== vector_int after reserve ====\n";
    vector_int.reserve(100);
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
}
void vector_access_test() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ns::vector<int> vector_string(arr, arr + static_cast<int>(sizeof(arr) / sizeof(int)));
    std::cout << "==== test try catch ====\n";
    try {
        for (size_t i = 0; i < 8; i++)
            std::cout << vector_string.at(i) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
void vector_modifiers_test() {
    ns::vector<int> vector_int;
    ns::vector<int> vector_range;
    std::cout << "==== assign range method ====\n";
    for (int i = 0; i < 10; i++)
        vector_range.push_back(i);
    // ns::vector<int>::iterator  it = vector_range.begin();
    // for (; it != vector_range.end(); it++)
    //     std::cout << " | " <<*it<< " | ";
    // std::cout << vector_range.end() - vector_range.begin() <<"\n";
    vector_int.assign(vector_range.begin(), vector_range.end());
    std::cout <<"|"<< vector_int.size() <<"|"<< std::endl;
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capacity: " << vector_int.capacity() << std::endl;
    std::cout << "==== assign method ====\n";
    ns::vector<int> v_range(15, 5);
    v_range.assign(10, 10);
    std::cout << "v_range size: " << v_range.size() << std::endl;
    std::cout << "v_range capacity: " << v_range.capacity() << std::endl;
}

void vector_modifiers_second_test() {
    ns::vector<int> vector_int;
    vector_int.assign(100, 2);
    std::cout << "insert(p, v)\n";
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    ns::vector<int>::iterator it = vector_int.insert(vector_int.begin(), 10);
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    std::cout << "insert(p, v)\n";
    std::cout <<"first element : "<< *it << std::endl;
    std::cout << "--------------------------\n";
    it = vector_int.insert(vector_int.end(), 100);
    std::cout << "--------------------------\n";
    std::cout <<"last element : "<< *it << std::endl;
    std::cout << "end = " << *vector_int.end() << std::endl;
    int i = 0;
    for (ns::vector<int>::iterator b = vector_int.begin(); b != vector_int.end(); b++, i++)
    {
        std::cout <<"idx = "<<i<<" => "<< *b<< " | size = " <<vector_int.size()<< std::endl;
    }
    std::cout << vector_int[12] << std::endl;
    std::cout << "insert(p, n, v)\n";
    vector_int.insert(it, 138, 17); // n = 70
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    
    for (ns::vector<int>::iterator b = vector_int.begin(); b != vector_int.end(); b++)
        std::cout << *b<< std::endl;
    ns::vector<int> vector_range;
    vector_range.assign(50, 5);
    ns::vector<int>::iterator itv = vector_range.begin();
    // itv++;
    // itv++;
    // itv++;
    std::cout << "insert(p, f, l)\n";
    vector_range.insert(itv, vector_int.begin(), vector_int.end());
    for (int i = 0; i < (int)vector_range.size(); i++)
        std::cout << vector_range[i] << std::endl;
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    std::cout << "vector_range size: " << vector_range.size() << std::endl;
    std::cout << "vector_range capactiy: " << vector_range.capacity() << std::endl;
    ns::vector<int>::iterator r = vector_int.erase(vector_int.begin());
    std::cout << *r << std::endl;
    ns::vector<int>::iterator e = vector_int.end();
    // e--;
    e--;
    e--;
    vector_int.erase(vector_int.begin(), e);
    for (int i = 0; i < (int)vector_int.size(); i++)
        std::cout << vector_int[i] << std::endl;
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    vector_range.clear();
    std::cout << "vector_range size: " << vector_range.size() << std::endl;
    std::cout << "vector_range capactiy: " << vector_range.capacity() << std::endl;
}

void vector_random_test() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    ns::vector<int> vector_range(arr, arr + static_cast<int>(sizeof(arr) / sizeof(int)));
    ns::vector<int> vector_int;
    for (int i = 0; i < 15; i++)
        vector_int.push_back(i); 
    std::cout << "size of vector_int: " << vector_int.size() << std::endl;
    std::cout << "size of vector_range: " << vector_range.size() << std::endl;
    std::cout << "capacity of vector_range: " << vector_range.capacity() << std::endl;
    std::cout << "==== after = operator ====\n";
    vector_int = vector_range;
    std::cout << "size of vector_int: " << vector_int.size() << std::endl;
    std::cout << "capacity of vector_int: " << vector_int.capacity() << std::endl;
    for (int i = 0; i < (int)vector_int.size(); i++)
        std::cout << vector_int[i] << std::endl;
    std::cout << "=== copy constructor ====\n";
    ns::vector<int> vector_copy(vector_int);
    for (int i = 0; i < (int)vector_copy.size(); i++)
        std::cout << vector_copy[i] << std::endl; 
    std::cout << "size of vector_copy: " << vector_copy.size() << std::endl;
    std::cout << "capacity of vector_copy: " << vector_copy.capacity() << std::endl;
}
void vector_time_test() {
    ns::vector<int> vector_int;
    ns::vector<int> vector_swap;
    for (int i = 0; i < COUNT; i++)
        vector_int.push_back(i);
    vector_swap.swap(vector_int);
    std::cout << "vector_swap size: " << vector_swap.size() << std::endl;
    std::cout << "vector_swap capacity: " << vector_swap.capacity() << std::endl;
    for (int i = 0; i < COUNT; i++)
        std::cout << vector_swap[i] << std::endl;
}

void vector_test_operations() {
    ns::vector<int> v;
    ns::vector<int> v1;
    v.assign(10, 15);
    for (int i = 0; i < 12; i++)
        v.push_back(i);
    std::cout << (v == v1) << std::endl;
    std::cout << (v != v1) << std::endl;
    std::cout << (v < v1) << std::endl;
    std::cout << (v <= v1) << std::endl;
    std::cout << (v > v1) << std::endl;
    std::cout << (v >= v1) << std::endl;
}

void vector_reverse_iterator_test() {

    ns::vector<int> vector_int;
    for (int i = -1; i < 10; i++)
        vector_int.push_back(i);
    ns::vector<int>::reverse_iterator it = vector_int.rbegin();
    ns::vector<int>::reverse_iterator itend = vector_int.rend();
    // std::cout << "First element : "<< *(it)<< "  last element : "<< * (itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    // std::cout << "First element : "<< *(++it)<< "  last element : "<< * (--itend)<<std::endl;
    for (; it != itend; it++)
        std::cout << *it << std::endl;
}

// Map tests
// void map_iterator_test() {
//     ns::map<std::string, int> _map;

//     _map["a"] = 1;
//     _map["b"] = 2;
//     _map["c"] = 3;
//     _map["d"] = 4;
//     _map["e"] = 5;
//     _map["f"] = 6;
//     std::cout << "_map\n";
//     for (ns::map<std::string, int>::iterator it = _map.begin(); it != _map.end(); it++)
//         std::cout << "first: " << it->first << " second: " << it->second << std::endl;
//     ns::map<std::string, int> _map_range(_map.begin(), _map.end());
//     std::cout << "_map_range\n";
//     for (ns::map<std::string, int>::iterator it = _map_range.begin(); it != _map_range.end(); it++)
//         std::cout << "first: " << it->first << " second: " << it->second << std::endl;
//     std::cout << "_map_copy\n";
//     ns::map<std::string, int> _map_copy(_map_range);
//     for (ns::map<std::string, int>::iterator it = _map_copy.begin(); it != _map_copy.end(); it++)
//         std::cout << "first: " << it->first << " second: " << it->second << std::endl;
//     std::cout << "_map_assign\n";
//     ns::map<std::string, int> _map_assign;

//     _map_assign = _map_range;
//     for (ns::map<std::string, int>::iterator it = _map_assign.begin(); it != _map_assign.end(); it++)
//         std::cout << "first: " << it->first << " second: " << it->second << std::endl;
// }
// void map_capacity_test() {
//     ns::map<char, int> _map;

//     _map['a'] = 1;
//     _map['b'] = 2;
//     _map['c'] = 3;
//     std::cout << "size method\n";
//     std::cout << "_map size is " << _map.size() << "\n";
//     std::cout << "max size method\n";
//     std::cout << "theoretically the map container can hold up to " << _map.max_size() << "\n";
//     std::cout << "empty method\n";
//     while (!_map.empty()) {
//         std::cout << _map.begin()->first << " => " << _map.begin()->second << "\n";
//         _map.erase(_map.begin());
//     }
// }
// void map_access_test() {
//     ns::map<char, std::string> _map;

//     _map['1'] = "C";
//     _map['2'] = "C++";
//     _map['3'] = "RUST";

//     std::cout << "_map['a'] is " << _map['1'] << "\n";
//     std::cout << "_map['b'] is " << _map['2'] << "\n";
//     std::cout << "_map['c'] is " << _map['3'] << "\n";
//     std::cout << "_map['d'] is " << _map['4'] << "\n";
//     std::cout << "_map now contains " << _map.size() << " elements\n";
// }
// void map_modifiers_test() {
//     ns::map<char, int> _map;
// 	std::cout << "======================= INSERT BEGIN =======================\n";
//     std::cout << "first insert method\n";
//     _map.insert(ns::pair<char, int>('a', 100));
//     _map.insert(ns::pair<char, int>('z', 200));
//     ns::pair<ns::map<char, int>::iterator, bool> ret;
//     ret = _map.insert(ns::pair<char, int>('z', 500));
//     if (ret.second == false) {
//         std::cout << "element 'z' already existed";
//         std::cout << " with a value of " << ret.first->second << "\n";
//     }
//     std::cout << "second insert method\n";
// 	ns::map<char,int>::iterator r = _map.begin();
// 	_map.insert(r, ns::pair<char,int>('b',300));
// 	_map.insert(r, ns::pair<char,int>('c',400)); 
// 	for (ns::map<char, int>::iterator it = _map.begin(); it != _map.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "third insert method\n";
// 	ns::map<char, int> _map_range;

// 	_map_range.insert(_map.begin(), _map.end());
// 	for (ns::map<char, int>::iterator it = _map_range.begin(); it != _map_range.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "======================= INSERT END =======================\n\n";
// 	std::cout << "======================= ERASE BEGIN =======================\n";
// 	std::cout << "erasing by iterator\n";
// 	ns::map<char, int>::iterator itrm = _map_range.find('b');
// 	_map_range.erase(itrm);
// 	std::cout << "erasing by key\n";
// 	_map_range.erase('c');
// 	itrm = _map_range.find('z');
// 	std::cout << "erasing by range\n";
// 	_map_range.erase(itrm, _map_range.end());
// 	for (itrm = _map_range.begin(); itrm != _map_range.end(); itrm++)
// 		std::cout << "first " << itrm->first << " second " << itrm->second << "\n";
// 	std::cout << "======================= ERASE BEGIN =======================\n\n";
// 	std::cout << "======================= SWAP BEGIN =======================\n";
// 	ns::map<char, int> foo, bar;
// 	foo['x'] = 100;
// 	foo['y'] = 200;

// 	bar['a'] = 11;
// 	bar['b'] = 22;
// 	bar['c'] = 33;
// 	foo.swap(bar);
// 	std::cout << "foo contains:\n";
// 	for (ns::map<char, int>::iterator it = foo.begin(); it != foo.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "bar contains:\n";
// 	for (ns::map<char, int>::iterator it = bar.begin(); it != bar.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "======================= SWAP END =======================\n\n";
// 	std::cout << "======================= CLEAR BEGIN =======================\n";
// 	_map.clear();
// 	std::cout << "_map size after clear: " << _map.size() << "\n";
// 	_map['m'] = 100;
// 	_map['r'] = 125;
// 	for (ns::map<char, int>::iterator it = _map.begin(); it != _map.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "======================= CLEAR END =======================\n";
// }
// void map_operations_test() {
// 	ns::map<char, int> _map;
// 	ns::map<char, int>::iterator itf;

// 	_map['a'] = 50;
// 	_map['b'] = 100;
// 	_map['c'] = 200;
// 	_map['d'] = 400;
// 	_map['e'] = 800;
// 	_map['f'] = 1600;

// 	std::cout << "======================= FIND BEGIN =======================\n";
// 	itf = _map.find('c');
// 	if (itf != _map.end())
// 		_map.erase(itf);
// 	for (ns::map<char, int>::iterator it = _map.begin(); it != _map.end(); it++)
// 		std::cout << "first " << it->first << " second " << it->second << "\n";
// 	std::cout << "======================= FIND END =======================\n\n";
// 	std::cout << "======================= COUNT BEGIN =======================\n";
// 	for (char c = 'a'; c < 'h'; c++)
// 	{
// 		std::cout << c;
// 		if (_map.count(c) > 0)
// 			std::cout << " is an element of _map\n";
// 		else
// 			std::cout << " is not an element of _map\n";
// 	}
// 	std::cout << "======================= COUNT END =======================\n\n";
// 	std::cout << "======================= LOWER_BOUND BEGIN =======================\n";
// 	ns::map<char, int>::iterator lb = _map.lower_bound('b');
// 	std::cout << "lower bound of 'b' is " << lb->first << "\n";
// 	lb = _map.lower_bound('f');
// 	std::cout << "lower bound of 'f' is " << lb->first << "\n";
// 	std::cout << "======================= LOWER_BOUND END =======================\n\n";
// 	std::cout << "======================= UPPER_BOUND BEGIN =======================\n";
// 	ns::map<char, int>::iterator ub = _map.upper_bound('b');
// 	std::cout << "upper bound of 'b' is " << ub->first << "\n";
// 	ub = _map.upper_bound('e');
// 	std::cout << "upper bound of 'e' is " << ub->first << "\n";
// 	std::cout << "======================= UPPER_BOUND END =======================\n\n";
// 		std::cout << "======================= EQUAL_RANGE BEGIN =======================\n";
// 	ns::pair<ns::map<char, int>::iterator, ns::map<char, int>::iterator> ret = _map.equal_range('b');
// 	std::cout << "lower_bound points to " << ret.first->first << std::endl;
// 	std::cout << "upper_bound points to " << ret.second->first << std::endl;
// 	std::cout << "======================= EQUAL_RANGE END =======================\n\n";
// }
// void map_time_test() {
// 	ns::map<int, int> _map_int;
// 	ns::map<int, int> _map_swap;

// 	for (int i = 0; i < COUNT; i++)
// 		_map_int.insert(ns::pair<int, int>(i, i));
// 	_map_swap.swap(_map_int);
// 	for (int i = 0; i < COUNT; i++)
// 		std::cout << _map_swap[i] << std::endl;
// }

// void map_reverse_iterator_test() {
//     ns::map<int, char> _map;

//     _map[1] = 'a';
//     _map[2] = 'b';
//     _map[3] = 'c';
//     _map[4] = 'd';
//     _map[5] = 'e';
//     _map[6] = 'f';
//     _map[7] = 'g';
//     _map[8] = 'h';
//     for (ns::map<int, char>::reverse_iterator it = _map.rbegin(); it != _map.rend(); it++)
//         std::cout << "first: " << it->first << " second: " << it->second << std::endl;
// }

// // Set tests
// void set_iterator_test() {
//     int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
//     std::cout << "construct a set with a range of ints\n";
//     ns::set<int> _set(arr, arr + static_cast<int>(sizeof(arr) / sizeof(int)));
//     for (ns::set<int>::iterator it = _set.begin(); it != _set.end(); it++)
//         std::cout << *it << std::endl;
//     std::cout << "set copy constructor\n";
//     ns::set<int> _set_copy(_set);
//     for (ns::set<int>::iterator it = _set_copy.begin(); it != _set_copy.end(); it++)
//         std::cout << *it << std::endl;
// 	std::cout << "set range constructor\n";
// 	ns::set<int> _set_range(_set.begin(), _set.end());
// 	_set_range.insert(90);
// 	_set_range.insert(100);
//     for (ns::set<int>::iterator it = _set_range.begin(); it != _set_range.end(); it++)
//         std::cout << *it << std::endl;
//     std::cout << "_set_assign\n";
//     ns::set<int> _set_assign;

//     _set_assign = _set_range;
//     for (ns::set<int>::iterator it = _set_assign.begin(); it != _set_assign.end(); it++)
//         std::cout << *it << std::endl;
// }
// void set_capacity_test() {
// 	ns::set<char> _set;

// 	_set.insert('a');
// 	_set.insert('b');
// 	_set.insert('c');
// 	_set.insert('d');

// 	std::cout << "size method\n";
//     std::cout << "_set size is " << _set.size() << "\n";
// 	std::cout << "max size method\n";
//     std::cout << "theoretically the set container can hold up to " << _set.max_size() << "\n";
// 	std::cout << "empty method\n";
// 	while (!_set.empty()) {
// 		std::cout << *(_set.begin()) << "\n";
// 		_set.erase(_set.begin());
// 	}
// }
// void set_modifiers_test() {
// 	ns::set<int> _set;
//     std::cout << "======================= INSERT BEGIN =======================\n";
//     std::cout << "first insert method\n";
//     _set.insert(100);
//     _set.insert(200);
//     ns::pair<ns::set<int>::iterator, bool> ret;
//     ret = _set.insert(200);
//     if (ret.second == false) {
//         std::cout << "this element already existed";
//         std::cout << " with a value of " << *ret.first << "\n";
//     }
//     std::cout << "second insert method\n";
// 	ns::set<int>::iterator r = _set.begin();
// 	_set.insert(r, 300);
// 	_set.insert(r, 400);
//     _set.insert(r, 500);
// 	for (ns::set<int>::iterator it = _set.begin(); it != _set.end(); it++)
// 		std::cout << *it << "\n";
// 	std::cout << "third insert method\n";
// 	ns::set<int> _set_range;

// 	_set_range.insert(_set.begin(), _set.end());
// 	for (ns::set<int>::iterator it = _set.begin(); it != _set.end(); it++)
// 		std::cout << *it << "\n";
//     std::cout << "======================= INSERT END =======================\n\n";
//     std::cout << "======================= ERASE BEGIN =======================\n";
// 	std::cout << "erasing by iterator\n";
// 	ns::set<int>::iterator itrm = _set_range.find(300);
// 	_set_range.erase(itrm);
// 	std::cout << "erasing by value\n";
// 	_set_range.erase(400);
// 	itrm = _set_range.find(200);
// 	std::cout << "erasing by range\n";
// 	_set_range.erase(itrm, _set_range.end());
// 	for (itrm = _set_range.begin(); itrm != _set_range.end(); itrm++)
// 		std::cout << *itrm << "\n";
//     std::cout << "======================= ERASE END =======================\n\n";
//     std::cout << "======================= SWAP BEGIN =======================\n";
// 	ns::set<char> foo, bar;
// 	foo.insert('x');
// 	foo.insert('y');

// 	bar.insert('a');
// 	bar.insert('b');
// 	bar.insert('c');
// 	foo.swap(bar);
// 	std::cout << "foo contains:\n";
// 	for (ns::set<char>::iterator it = foo.begin(); it != foo.end(); it++)
// 		std::cout << *it << "\n";
// 	std::cout << "bar contains:\n";
// 	for (ns::set<char>::iterator it = bar.begin(); it != bar.end(); it++)
// 		std::cout << *it << "\n";
//     std::cout << "======================= SWAP END =======================\n\n";
//     std::cout << "======================= CLEAR BEGIN =======================\n";
// 	_set.clear();
// 	std::cout << "_map size after clear: " << _set.size() << "\n";
// 	_set.insert(100);
// 	_set.insert(125);
// 	for (ns::set<int>::iterator it = _set.begin(); it != _set.end(); it++)
// 		std::cout << *it << "\n";
//     std::cout << "======================= CLEAR END =======================\n\n";
// }
// void set_operations_test() {
// 	ns::set<char> _set;
// 	ns::set<char>::iterator itf;

// 	_set.insert('a');
// 	_set.insert('b');
// 	_set.insert('c');
// 	_set.insert('d');
// 	_set.insert('e');
// 	_set.insert('f');

// 	std::cout << "======================= FIND BEGIN =======================\n";
// 	itf = _set.find('c');
// 	if (itf != _set.end())
// 		_set.erase(itf);
// 	for (ns::set<char>::iterator it = _set.begin(); it != _set.end(); it++)
// 		std::cout << *it << std::endl;
// 	std::cout << "======================= FIND END =======================\n\n";
// 	std::cout << "======================= COUNT BEGIN =======================\n";
// 	for (char c = 'a'; c < 'h'; c++) {
// 		std::cout << c;
// 		if (_set.count(c) > 0)
// 			std::cout << " is an element of _set\n";
// 		else
// 			std::cout << " is not an element of _set\n";
// 	}
// 	std::cout << "======================= COUNT END =======================\n\n";
// 	std::cout << "======================= LOWER_BOUND BEGIN =======================\n";
// 	ns::set<char>::iterator lb = _set.lower_bound('b');
// 	std::cout << "lower bound of 'b' is " << *lb << "\n";
// 	lb = _set.lower_bound('f');
// 	std::cout << "lower bound of 'f' is " << *lb << "\n";
// 	std::cout << "======================= LOWER_BOUND END =======================\n\n";
// 	std::cout << "======================= UPPER_BOUND BEGIN =======================\n";
// 	ns::set<char>::iterator ub = _set.upper_bound('b');
// 	std::cout << "upper bound of 'b' is " << *ub << "\n";
// 	ub = _set.upper_bound('e');
// 	std::cout << "upper bound of 'e' is " << *ub << "\n";
// 	std::cout << "======================= UPPER_BOUND END =======================\n\n";
// 		std::cout << "======================= EQUAL_RANGE BEGIN =======================\n";
// 	ns::pair<ns::set<char>::iterator, ns::set<char>::iterator> ret = _set.equal_range('b');
// 	std::cout << "lower_bound points to " << *ret.first << std::endl;
// 	std::cout << "upper_bound points to " << *ret.second << std::endl;
// 	std::cout << "======================= EQUAL_RANGE END =======================\n\n";
// }
// void set_time_test() {
// 	ns::set<int> _set_int;
// 	ns::set<int> _set_swap;

// 	for (int i = 0; i < COUNT; i++)
// 		_set_int.insert(i);
// 	_set_swap.swap(_set_int);
// 	for (ns::set<int>::iterator it = _set_swap.begin(); it != _set_swap.end(); it++)
// 		std::cout << *it << std::endl;
// }

// void set_reverse_iterator_test() {
//     ns::set<int> _set;
//     for (int i = 0; i < 12; i++)
//         _set.insert(i);
//     for (ns::set<int>::reverse_iterator it = _set.rbegin(); it != _set.rend(); it++)
//         std::cout << *it << std::endl;
// }

// void print(int i) {
//     std::cout << i << std::endl;
// }

// void generic_algorithms_test() {
//     ns::vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(4);
//     v.push_back(4);
//     v.push_back(5);
//     v.push_back(6);
//     std::cout << "===================== FIND =====================\n";
//     std::cout << "found: " << *std::find(v.begin(), v.end(), 2) << std::endl;
//     std::cout << "min element: " << *std::min_element(v.begin(), v.end()) << std::endl;
//     std::cout << "max element: " << *std::max_element(v.begin(), v.end()) << std::endl;
//     std::cout << "===================== FOR_EACH =====================\n";
//     std::for_each(v.begin(), v.end(), print);
//     std::cout << "===================== COUNT =====================\n";
//     std::cout << "element 4 appears " << std::count(v.begin(), v.end(), 4) << " times." << std::endl;
//     std::for_each(v.begin(), v.end(), print);
//     std::cout << "===================== REVERSE =====================\n";
//     std::reverse(v.begin(), v.end());
//     std::for_each(v.begin(), v.end(), print);
// }

int main() {
    // Vector
    vector_iterator_test();
    // vector_capacity_test();
    // vector_modifiers_test();
    // vector_modifiers_second_test();
    // vector_random_test();
    // vector_access_test();
    // vector_test_operations();
    // vector_reverse_iterator_test();
    // vector_time_test();

    // Stack
    // stack_test();

    // // Map
    // map_iterator_test();
    // map_capacity_test();
    // map_access_test();
    // map_modifiers_test();
    // map_operations_test();
    // map_reverse_iterator_test();
    // // map_time_test();

    // // Set
    // set_iterator_test();
    // set_capacity_test();
    // set_modifiers_test();
    // set_operations_test();
    // set_reverse_iterator_test();
    // set_time_test();

    // Generic algorithms
    // generic_algorithms_test();
}
