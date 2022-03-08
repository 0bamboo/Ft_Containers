/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/08 20:22:44 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include <set>
# include <list>
# include <iterator>
# include <string>
# include "Files/map.hpp"

class Test{
	private:
		std::string test;
	public:
		Test(const std::string& te = "none"): test(te) { }
		~Test() {}
		void	wave() const { std::cout << "Im Waving !\n"; } 
		
		std::string const& name() const { return this->test;}
		bool operator< (const Test& userObj) const
    	{
       		if(userObj.name() < this->test)
            	return true;
			return false;
    	}
};

std::ostream& operator << (std::ostream& output, const Test& obj)
{
	output << "hi "<< obj.name();
	return output;
}


int main()
{
	// std::map<std::string , int> tet;
	// ft::pair<int , int> t;
	// t.first = -1; t.second =1;
	// tet.insert(std::make_pair("hi", 2));
	// std::map<std::string, int >::iterator t = tet.begin();

	// std::cout << t->first << (*t).second<< std::endl;

	ft::map<int, int> test;
	// ft::map<int, int>* mm = nullptr;
	// test.insert(t);
	test.insert(ft::pair<int, int>(1, 4));
	test.insert(ft::pair<int, int>(2, 4));
	test.insert(ft::pair<int, int>(3, 4));
	test.insert(ft::pair<int, int>(4, 4));
	test.insert(ft::pair<int, int>(5, 4));
	test.insert(ft::pair<int, int>(6, 4));
	test.insert(ft::pair<int, int>(7, 4));
	test.insert(ft::pair<int, int>(8, 4));

	// ft::cout << it->first <<(*it).second<< ft::endl;
	ft::map<int , int >::iterator  i = test.begin();
	ft::map<int, int> another_test;
	ft::map<int , int >::iterator  endd = i;
	std::cout << i->first << std::endl;
	i++;
	std::cout << i->first << std::endl;
	i++;
	std::cout << i->first << std::endl;
	endd = i;
	++endd;
	++endd;
	another_test.insert(i, endd);
	// test.erase(i++);
	// test.erase(i++);
	// test.erase(i++);
	// test.erase(i);
	test.erase(i, endd);
	// test.erase(444);
	// test.erase(2123);
	
	// test.insert(ft::pair<int, int>(4, 4)); // if u insert another one it crushes 
	ft::map<int , int >::iterator  it = test.begin();
	// // ft::cout << en->first << ft::endl;
	for(;it != another_test.end(); it++)
		std::cout<<" = "<< it->first <<" => "<<(*it).second<< std::endl;
	// // it++;
	// for(;it != test.end();it++)
	// test.insert(ft::pair<int, int>(-1, 4));
	// ft::map<int, int>::iterator it = test.begin();
	// std::cout << "hi" << std::endl;
}

