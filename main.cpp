/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:06 by abdait-m          #+#    #+#             */
/*   Updated: 2022/02/17 18:13:14 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include <list>
# include <iterator>

int main()
{
	std::map<int , int> test;
	std::map<int, int>::iterator it;
	std::list<int> etest;

	test.insert(std::make_pair(3,3));
	it = test.lower_bound(2);
	std::cout << it->first << std::endl;

}