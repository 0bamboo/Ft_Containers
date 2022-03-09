/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/09 00:46:47 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include <set>
# include <list>
# include <iterator>
# include <string>
# include "Files/map.hpp"



int main()
{

	ft::map<int, int> test;
	// ft::map<int, int>* mm = nullptr;
	// test.insert(t);
	test.insert(ft::pair<int, int>(1, 4));
	test.insert(ft::pair<int, int>(2, 4));
	test.insert(ft::pair<int, int>(3, 4));
	test.insert(ft::pair<int, int>(4, 4));
	test.insert(ft::pair<int, int>(5, 4));
	test.insert(ft::pair<int, int>(12, 4));
	test.insert(ft::pair<int, int>(0, 4));
	test.insert(ft::pair<int, int>(-12, 4));

	// ft::cout << it->first <<(*it).second<< ft::endl;
	ft::map<int , int >::iterator  endd = test.find(3);
	// test.erase(2);
	ft::map<int , int >::iterator  i = test.begin();
	// test.erase(0);
	test.erase(i, test.find(5));
	// ++i;// segfault why!!!!!!!!!!!
	// test.erase(0);
	// i++;
	// test.erase(1);
	// i++;
	// test.erase(2);
	// test.erase(i, endd);
	// ft::map<int, int> another_test;
	// test.erase(i, endd);
	// test.erase(i, endd);
	
	ft::map<int , int >::iterator  it = test.begin();
	for(;it != test.end(); it++)
		std::cout<<" = "<< it->first <<" => "<<(*it).second<< std::endl;
	
	// std::cout << "-----------------------STD----------------\n";

	std::map<int, int>	test_2;
	test_2.insert(std::pair<int, int>(1,4));
	test_2.insert(std::pair<int, int>(2,4));
	test_2.insert(std::pair<int, int>(3,4));
	test_2.insert(std::pair<int, int>(4,4));
	test_2.insert(std::pair<int, int>(5,4));
	test_2.insert(std::pair<int, int>(12, 4));
	test_2.insert(std::pair<int, int>(0, 4));
	test_2.insert(std::pair<int, int>(-12, 4));
	// std::map<int, int>	map_2;
	std::map<int, int>::iterator	s = test_2.begin();
	test_2.erase(s, test_2.find(5));
	// s++;
	// std::map<int, int>::iterator	ss = test_2.find(3);
	// test_2.erase(s, ss);
	std::map<int , int >::iterator  iit = test_2.begin();
	for(;iit != test_2.end(); iit++)
		std::cout<<" = "<< iit->first <<" => "<<(*iit).second<< std::endl;
}

