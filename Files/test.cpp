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
  try {
    // vector throws a length_error if resized above max_size
    std::vector<int> myvector;
    myvector.resize(myvector.max_size()+1);
  }
  catch (const std::length_error& le) {
	  std::cerr << "Length error: " << le.what() << '\n';
  }
	// for (int i = 0; i < 5; i++)
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