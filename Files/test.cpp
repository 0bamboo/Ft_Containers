# include <iostream>
# include <vector>

int main()
{
	using namespace std;

	vector<int> array_int;

	for (int i = 0; i < 5; i++)
		array_int.push_back(i);
	typedef vector<int>::iterator _iter;

	reverse_iterator<_iter> _revEnd(array_int.begin());
	reverse_iterator<_iter> _revBeg(array_int.end());

	_iter it = _revBeg.base();
	it--; // we need to decrement first cuz the last element is not defined ....
	for( ; it != _revEnd.base() ; --it)
		cout << " " << *it << endl;
	return 0;
}