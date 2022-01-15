/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:24:07 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/13 20:43:48 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP
# define _STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector<T> >
	class stack{
		
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		protected:
			container_type _container;

		public:
			explicit stack(const container_type &_cont = container_type()) : _container(_cont) {}

			bool empty() const { return (_container.empty()); }

			size_type size() const { return (_container.size()); }

			value_type &top() { return (_container.back()); }

			const value_type &top() const { return (_container.back()); }

			void push(const value_type &value) { return (_container.push_back(value)); }

			void pop() { return (_container.pop_back()); }

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
		return (_left._container == _right._container);
	}
	template <class T1, class Container1>
	bool operator!=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return !(_left == _right);
	}
	template <class T1, class Container1>
	bool operator<(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (_left._container < _right._container);
	}
	template <class T1, class Container1>
	bool operator<=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (!(_left > _right));
	}
	template <class T1, class Container1>
	bool operator>(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (_left._container > _right._container);
	}
	template <class T1, class Container1>
	bool operator>=(const stack<T1, Container1> &_left, const stack<T1, Container1> &_right)
	{
		return (!(_left < _right));
	}
 
 } // END! FT NAMESPACE

#endif
