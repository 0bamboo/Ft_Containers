/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _iter_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:54:05 by abdait-m          #+#    #+#             */
/*   Updated: 2021/12/31 14:14:42 by abdait-m         ###   ########.fr       */
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
	class It_vector : public _RANDOM_ACCESS_ITERATOR_ {

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
	class It_reverse : public iterator<typename iterator_traits<It>::iterator_category,
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
				It_reverse() { } // default constructor
				It_reverse(iterator_type it):_current_it(it) { } // Constructs a reverse iterator from some orginal iterator it(biderictional or random)
				template <typename new_it>
				It_reverse(const It_reverse<new_it>& rev_it) 
				{
					
				}

			private:
				iterator_type		_current_it;
		
	};
	// END! ------------- REVERSE_ITERATOR ------------
} // END! ft namespace

#endif
