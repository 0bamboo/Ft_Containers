/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/02 19:32:09 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include <list>
# include <iterator>
# include <string>

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
	// std::map<std::string , int> test;
	Test	first_instance("aaa");
	Test	second_instance("aa");
	Test	third_instance("aaaaa");

	std::map<Test, std::string> another_test;
	another_test.insert(std::make_pair(first_instance, "im second"));
	another_test.insert(std::make_pair(second_instance, "last"));
	another_test.insert(std::make_pair(third_instance, "first"));
	std::map<Test, std::string>::iterator __it = another_test.begin();
	
	// test.insert(std::pair<std::string, int>("abc", 23));
	// test.insert(std::pair<std::string, int>("abcd", 23));
	// test.insert(std::pair<std::string, int>("ab", 23));
	// test.insert(std::make_pair("a", 23));
	// test.insert(std::make_pair("bzs", 23));

	// test["a"] = 454545;
	// test.insert(std::make_pair("a", 111));
	// std::cout << another_test[first_instance];
	// std::map<std::string, int>::iterator it = test.begin();

	
	for(;__it != another_test.end(); __it++)
		std::cout << __it->first <<"  | "<< __it->second <<std::endl;
}

