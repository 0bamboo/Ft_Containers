/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:56:09 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include <set>
# include <list>
# include <iterator>
# include <string>
# include "Files/map.hpp"
# include "Files/set.hpp"



int main()
{

	ft::map<int, int> test;
	ft::set<int> ta;



	ta.insert(0);
	std::cout << *(ta.begin()) << std::endl;
	// ft::map<int, int>* mm = nullptr;
	// test.insert(t);
	// test.insert(ft::pair<int, int>(1, 4));  
	test.insert(ft::pair<int, int>(12, 4));
	test.insert(ft::pair<int, int>(25, 4));
	test.insert(ft::pair<int, int>(2, 4));
	test.insert(ft::pair<int, int>(112, 4));
	test.insert(ft::pair<int, int>(212, 4));
	test.insert(ft::pair<int, int>(2, 4));
	test.insert(ft::pair<int, int>(21, 4));
	test.insert(ft::pair<int, int>(1811, 4));
	test.insert(ft::pair<int, int>(3251, 4));
	test.insert(ft::pair<int, int>(61, 4));
	// test.insert(ft::pair<int, int>(741, 4));
	// test.insert(ft::pair<int, int>(81, 4));
	
	// for (int i = -1431; i < 500; i++)
	// 	test.insert(ft::pair<int, int>(i, i%2));

	// ft::cout << it->first <<(*it).second<< ft::endl;

	
	ft::map<int, int> tata(test);
	ft::map<int, int>::iterator lower_ = test.lower_bound(-999);
	ft::map<int, int>::iterator upper_ = test.upper_bound(-999);
	std::cout << "lower -----|" << (*lower_).first << "|upper --------|" << (*upper_).first << std::endl;



	ft::map<int , int >::iterator  endd = test.find(3);
	// test.erase(2);
	ft::map<int , int >::iterator  i = test.begin();
	// test.erase(0);
	// test.erase(i, test.find(5));
	// for (int i = -1431; i < 500; i++)
	// 	test.erase(i);
	// test.insert(ft::make_pair(3, 2));
	// test.insert(ft::make_pair(32, 32));
	// test.insert(ft::make_pair(2343, 4442));
	// test.insert(ft::make_pair(-243, 2));

	test._shape_();


	std::cout << "empty = "  << test.empty() << std::endl;
	std::cout << "count = "  << test.count(509) << std::endl;
	// ++i;// segfault why!!!!!!!!!!!
	// test.erase(0);
	// i++;
	// test.erase(1);
	// i++;
	test.erase(22);
	// test.erase(31);
	// test.erase(111);
	// test.erase(212);
	// test.erase(61);
	// test.erase(201);
	test.erase(2);
	test.insert(ft::pair<int, int>(14, 4));
	test.erase(21);
	test._shape_();
	// test.erase(i, endd);
	// ft::map<int, int> another_test;
	// test.erase(i, endd);
	// test.erase(i, endd);
	
	ft::map<int , int >::iterator  it = test.begin();
	for(;it != test.end(); it++)
		std::cout<<" = "<< it->first <<" => "<<(*it).second<< std::endl;
	
	std::cout << "-----------------------STD----------------\n";

	std::map<int, int>	test_2;
	test_2.insert(std::pair<int, int>(12, 4));
	test_2.insert(std::pair<int, int>(0, 4));
	test_2.insert(std::pair<int, int>(2, 4));
	test_2.insert(std::pair<int, int>(112, 4));
	test_2.insert(std::pair<int, int>(212, 4));
	test_2.insert(std::pair<int, int>(22, 4));
	test_2.insert(std::pair<int, int>(201, 4));
	test_2.insert(std::pair<int, int>(111, 4));
	test_2.insert(std::pair<int, int>(31, 4));
	test_2.insert(std::pair<int, int>(61, 4));
	test_2.insert(std::pair<int, int>(741, 4));
	test_2.insert(std::pair<int, int>(81, 4));
	// int a = 3, b= 4;
	std::map<int, int>::iterator lower = test_2.lower_bound(-999);
	std::map<int, int>::iterator upper = test_2.upper_bound(-999);
	std::cout << "lower bound "<< "  => |" << (*lower).first << "| uppper bound "<<" => |" << (*upper).first << std::endl;
	// // std::map<int, int>	map_2;
	// std::map<int, int>::iterator	s = test_2.begin();
	// test_2.erase(s, test_2.find(5));
	// s++;
	// std::map<int, int>::iterator	ss = test_2.find(3);
	// test_2.erase(s, ss);
	std::cout << "max size = "  << test_2.max_size() << std::endl;
	std::map<int , int >::iterator  iit = test_2.begin();
	for(;iit != test_2.end(); iit++)
		std::cout<<" = "<< iit->first <<" => "<<(*iit).second<< std::endl;
}

