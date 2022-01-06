// # include <iostream>
# include <stdexcept>
# include <vector>
# include "_iter_.hpp"

int main()
{
	// using namespace std;

	// vector<int> array_int;
	// vector<string> array_str;
	// vector<char> array_char;
	// vector<long> vec_long;

	// cout << array_int.max_size() << "\n" << array_str.max_size() << "\n" \
	// << array_char.max_size() <<"\n"<< vec_long.max_size() << endl;
	// std::cout << numeric_limits<long>::max() << endl;
	// std::vector<int> test;
	// for (int i = 0; i < 3; i++)
	// 	test.push_back(i);
	// for (unsigned long i = 0; i < test.size(); i++)
	// 	std::cout << test[i] << " | ";
	// test.assign(0, 88);
	// std::cout << std::endl <<test.capacity() << std::endl;
	// for (unsigned long i = 0; i < test.size(); i++)
	// 	std::cout << test[i] << " | ";
	// // test.clear();
	// std::cout << std::endl <<test.capacity() <<" || "<< test.size()<< std::endl;
	std::vector<int> _vec;
	_vec.push_back(3);
	_vec.push_back(3);
	_vec.push_back(3);
	std::cout << "size and capacity : " << _vec.size() << " | " << _vec.capacity() << std::endl;
	_vec.insert(_vec.begin(), 4);
	_vec.insert(_vec.begin(), 2);
	size_t j = 0;
	for (size_t i= 0; j < _vec.size(); j++,i++)
		std::cout << _vec[j] << " | ";
	std::cout << std::endl;
	// _vec.pop_back();
	// _vec.pop_back();

	std::cout << "size and capacity : " << _vec.size() << " | " << _vec.capacity() << std::endl;

	// 	array_int.push_back(i);
	// typedef vector<int>::iterator _iter;
	// ft::_reverseIter<_iter> _revEnd(array_int.begin());
	// ft::_reverseIter<_iter> _revBeg(array_int.end());

	// _iter it = _revBeg.base();
	// it--; // we need to decrement first cuz the last element is not defined ....
	// for( ; it != _revEnd.base() ; --it)
	// 	cout << " " << *it << endl;
	return 0;
}