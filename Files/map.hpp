/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:00 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/27 23:36:42 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "_pair_.hpp"
# include "_RBT_.hpp"
# include "_iter_.hpp"
# include <iostream>
# include <memory>

namespace ft{

	template< typename Key,
			typename T,
			typename Compare = std::less<Key>,
			typename Alloc = std::allocator<ft::pair<const Key, T> >
			>
	class map{

		public:
			
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef Compare							key_compare;
			typedef pair<key_type, mapped_type>		value_type;

			// Class value_compare :
			class value_compare{
				
				friend class map;
				
				protected:
					Compare	_comp;
					value_compare(Compare _cmp) : _comp(_cmp) { }
				
				public:
					bool	operator ()(const value_type& _x, const value_type& _y)
					{
						return (_comp(_x._first, _y._first));
					}
			}; // END! class value_compare .

			typedef	Alloc													allocator_type;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::const_pointer					const_pointer;
	};

};

#endif
