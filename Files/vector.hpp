/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:11 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/02 15:20:03 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "_iter_.hpp"
# include "_equal_.hpp"
# include "_lexicographical_.hpp"
# include "_trait_types_.hpp"

namespace	ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class	vector{

		public:
			// Define the Member Types
			typedef					T									value_type;
			typedef					Alloc								allocator_type;
			typedef	typename 		Alloc::reference					reference;
			typedef typename 		Alloc::const_reference				c_reference;
			typedef typename 		Alloc::pointer						pointer;
			typedef typename 		Alloc::const_pointer				c_pointer;
			typedef					_vectorIter<pointer>				iterator;
			typedef					_vectorIter<c_pointer>				c_iterator;
			typedef	typename		ft::_reverseIter<iterator>			rev_iterator;
			typedef typename		ft::_reverseIter<c_iterator>		c_rev_iterator;
			typedef					std::ptrdiff_t						difference_type;
			typedef					std::size_t							size_type;
		
		private:
			size_type		_size_;
			allocator_type	_alloctype_;
			pointer			_data_;
		
		public:
			// Constructors
			explicit vector(const allocator_type& alloc = allocator_type()) : _size_(0), _alloctype_(alloc), _data_(nullptr) { }
			
		
	};
	// END! Vector 
} // END! ft namespace

#endif
