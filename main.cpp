/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/06 03:41:58 by abdait-m         ###   ########.fr       */
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
	std::map<std::string , int> test;

	ft::map<int, int> test;
	// std::map<int, int>* mm = nullptr;

	test.insert(ft::make_pair(3, 4));
	// ft::map<int, int>::iterator it = test.begin();
	// std::cout << "hi" << std::endl;
}

