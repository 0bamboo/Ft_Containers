// # include <iostream>
# include <stdexcept>
# include <vector>
# include "_iter_.hpp"

int main()
{
	// -------------------- DUMB TESTS : ------------------------

	// assign :
	std::vector<std::string> _str(4, "hello world");
	std::vector<int> _int(4, 98);

	std::cout << _str[0] << " | " << _str[3] << " | " << _str.size() << std::endl;
	std::cout << _int[0] << " | " << _int[3] << " | " << _int.size() << std::endl;
	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "assign =  fill version using size and value of the new str" << std::endl;
	_str.assign(6, "Changed");
	_int.assign(0, 99);
	std::cout << _str[0] << " | " << _str[3] << " | " << _str.size() << std::endl;
	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << _int[0] << " | " << _int[3] << " | " << _int.size() << std::endl;
	std::vector<std::string>::iterator it = _str.begin();
	std::vector<int>::iterator	_int_it = _int.begin();
	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "assign = range version" << std::endl;
	_str.assign(it, it + 2);
	_int.assign(_int_it, _int_it + 1);
	std::cout << std::endl << "--------------------------------" << std::endl;
	for (;it != _str.end(); it++)
		std::cout << _str[it - _str.begin()] << " | " ;
	std::cout <<std::endl<< "========> size = " << _str.size() << std::endl;
	std::cout << std::endl << "--------------------------------" << std::endl;
	for (;_int_it != _int.end(); _int_it++)
		std::cout << _int[_int_it - _int.begin()] << " | ";
	std::cout <<std::endl<< "========> size = " << _int.size() << std::endl;
	return 0;
}