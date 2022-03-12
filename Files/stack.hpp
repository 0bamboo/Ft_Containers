/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:24:07 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/12 13:53:02 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP
# define _STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector<T> >
	class stack{
		
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type c;

		public:
			explicit stack(const container_type &_cont = container_type()) : c(_cont) {}

			bool empty() const { return (c.empty()); }

			size_type size() const { return (c.size()); }

			value_type &top() { return (c.back()); }

			const value_type &top() const { return (c.back()); }

			void push(const value_type &value) { return (c.push_back(value)); }

			void pop() { return (c.pop_back()); }

			// Operational operators :
			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
			template <class T1, class Container1>
			friend bool operator!=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
			template <class T1, class Container1>
			friend bool operator<=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
			template <class T1, class Container1>
			friend bool operator>(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
			template <class T1, class Container1>
			friend bool operator>=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right);
	
	}; // END! stack
	
	// [Non-member functions] Operational operators :
	
	template <class T1, class Container1>
	bool operator==(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (_left.c == _right.c);
	}
	template <class T1, class Container1>
	bool operator!=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return !(_left == _right);
	}
	template <class T1, class Container1>
	bool operator<(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (_left.c < _right.c);
	}
	template <class T1, class Container1>
	bool operator<=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (!(_left > _right));
	}
	template <class T1, class Container1>
	bool operator>(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (_left.c > _right.c);
	}
	template <class T1, class Container1>
	bool operator>=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (!(_left < _right));
	}
 
 } // END! FT NAMESPACE

#endif
