/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _iter_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:54:05 by abdait-m          #+#    #+#             */
/*   Updated: 2021/12/31 18:54:20 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_HPP
#define _ITER_HPP

#include <iostream>
# define _RANDOM_ACCESS_ITERATOR_ iterator<std::random_access_iterator_tag, typename iterator_traits<It>::value_type>

namespace	ft
{
	// The base class of iterator:
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
	class iterator{
		
		public:
			typedef T         value_type;		// Type  of elements ponted by the iterator.
			typedef Distance  difference_type;	// Type to represent the difference between two iterators
			typedef Pointer   pointer;			// Type to represent a pointer to an element poited by the iterator
			typedef Reference reference;		// Type to represent a reference to an element pointed by the iterator
			typedef Category  iterator_category;// Category to which the iterator belongs to (random - input_iterator - bidirectional - ...)
	};

	// The base class of iterator traits :
	template <typename It>
	class	iterator_traits{

		public:
			typedef typename It::value_type			value_type;
			typedef typename It::difference_type	difference_type;
			typedef typename It::pointer			pointer;
			typedef typename It::reference			reference;
			typedef typename It::iterator_category	iterator_category;

	};

	// ----------- RANDOM_ACCESS_ITERATOR_TAG ----------- {
		
	// Iterator traits for pointer types :
	template <typename It>
	class	iterator_traits<It*>{
		
		public:
			typedef typename	std::random_access_iterator_tag	iterator_category;
			typedef				It								value_type;
			typedef				ptrdiff_t						difference_type;
			typedef				It*								pointer;
			typedef				It&								reference;

	};

	//Iterator traits for const pointer types :
	template <typename It>
	class	iterator_traits<const It*>{
		
		typedef typename	std::random_access_iterator_tag	iterator_category;
		typedef				It								value_type;
		typedef				ptrdiff_t						difference_type;
		typedef				const It*						pointer;
		typedef				const It&						reference;
		
	};

	template <typename It>
	class _vectorIter : public _RANDOM_ACCESS_ITERATOR_ {

		public:
			// Typedefs :
			typedef				It										iterator_type;
			typedef typename	iterator_traits<It>::pointer			pointer;
			typedef typename	iterator_traits<It>::reference			reference;
			typedef typename	iterator_traits<It>::difference_type	difference_type;
			
			// 
		
		private:
			iterator_type	_current_it;
	};
	// } END! -> ----------- RANDOM_ACCESS_ITERATOR_TAG -----------

	// ------------- REVERSE_ITERATOR ------------ {
	template <typename It>
	class _reverseIter : public iterator<typename iterator_traits<It>::iterator_category,
									typename iterator_traits<It>::value_type,
									typename iterator_traits<It>::reference,
									typename iterator_traits<It>::difference_type,
									typename iterator_traits<It>::pointer
							>{
			public:
				// Typedefs :
				typedef				It										iterator_type;
				typedef typename	iterator_traits<It>::pointer			pointer;
				typedef typename	iterator_traits<It>::reference			reference;
				typedef typename	iterator_traits<It>::difference_type	difference_type;
				
				// Construction :
				_reverseIter() { } // default constructor
				_reverseIter(iterator_type it):_current_it(it) { } // Constructs a reverse iterator from orginal iterator it(biderictional or random)
				template <typename new_it>
				_reverseIter(const _reverseIter<new_it>& rev_it):_current_it(rev_it.base()) { } // Construct with the iterator of rev_it

				// Base(): returns a copy of the base iterator .
				iterator_type	base() const { return (this->_current_it); } 

				// Dereference iterator : 
				reference	operator*() const
				{
					iterator_type	tmp = _current_it;
					
					return (*--tmp);
				}

				// Addition operator :
				_reverseIter	operator+(difference_type _diff) const
				{
					return (_reverseIter(_current_it - _diff));
				}

				// Substraction operator :
				_reverseIter	operator-(difference_type _diff) const
				{
					return (_reverseIter(_current_it + _diff));
				}

				// Increment iterator position : {
				// pre-increment :
				_reverseIter&	operator++() { return (--(*this)); }
				// post-increment :
				_reverseIter	operator++(int)
				{
					_reverseIter	tmp(*this);
					
					--(*this);
					return (tmp);
				}
				//}
				
				// Decrement iterator position : {
				// pre-decrement :
				_reverseIter&	operator--() { return (++(*this)); }
				// post-decrement :
				_reverseIter	operator--(int)
				{
					_reverseIter	tmp(*this);
					
					++(*this);
					return (tmp);
				}
				//}

				// Advance iterator : decreases the rev_iter by _diff elements positions
				_reverseIter&	operator+=(difference_type _diff)
				{
					this->_current_it -= _diff;
					return (*this);
				}

				// Retrocede iterator : advance the rev_it by _diff elements positions.
				_reverseIter&	operator-=(difference_type _diff)
				{
					this->_current_it += _diff;
					return (*this);
				}

				// Dereference iterator : returns a pointer to the element pointer to by the iterator (in order to access one of its members.)
				pointer	operator->() const
				{
					return &(operator*());
				}
				
				// Dereference iterator with offset :
				reference	operator[](difference_type _diff) const
				{
					return (*(*this + _diff));
				}
				
			private:
				iterator_type		_current_it;
		
	};
	// END! ------------- REVERSE_ITERATOR ------------
	
} // END! ft namespace

#endif
