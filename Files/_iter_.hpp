/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _iter_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:54:05 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/12 18:41:05 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER__HPP
#define _ITER__HPP

#include <iostream>

namespace	ft
{
	// The base class of iterator:
	template <typename Category, typename T, typename Distance = std::ptrdiff_t,
          typename Pointer = T*, typename Reference = T&>
	class iterator{
		
		public:
			typedef T         value_type;		// Type  of elements pointed by the iterator.
			typedef Distance  difference_type;	// Type to represent the difference between two iterators
			typedef Pointer   pointer;			// Type to represent a pointer to an element pointed by the iterator
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
			typedef				std::ptrdiff_t					difference_type;
			typedef				It*								pointer;
			typedef				It&								reference;

	};

	//Iterator traits for const pointer types :
	template <typename It>
	class	iterator_traits<const It*>{

		public:
			typedef typename	std::random_access_iterator_tag	iterator_category;
			typedef				It								value_type;
			typedef				std::ptrdiff_t					difference_type;
			typedef				const It*						pointer;
			typedef				const It&						reference;
		
	};

	template <typename It>
	class _vectorIter : public iterator<std::random_access_iterator_tag, typename iterator_traits<It>::value_type> {
		
		public:
			// Typedefs :
			typedef				It										iterator_type;
			typedef typename	iterator_traits<It>::pointer			pointer;
			typedef typename	iterator_traits<It>::reference			reference;
			typedef typename	iterator_traits<It>::difference_type	difference_type;
			
		private:
			iterator_type	_current_it;
		
		public:
			// Construction :
			_vectorIter():_current_it() { }
			_vectorIter(It& _it) : _current_it(_it) { }
			_vectorIter(const It& _it) : _current_it(_it) { }
			template <typename Iter>
			_vectorIter(const _vectorIter<Iter>& _it) : _current_it(_it.base()) { }
			~_vectorIter() { } // Destructor
			
			
			iterator_type	base() const { return (this->_current_it); } 

			// Dereference iterator : 
			reference	operator*() const
			{
				return (*_current_it);
			}

			// Addition operator :
			_vectorIter	operator+(difference_type _diff) const
			{
				return (_vectorIter(_current_it + _diff));
			}

			// Substraction operator :
			_vectorIter	operator-(difference_type _diff) const
			{
				return (_vectorIter(_current_it - _diff));
			}

			// Increment iterator position : {
			// post-increment :
			_vectorIter	operator++(int)
			{
				_vectorIter	tmp(*this);
				
				++(*this);
				return (tmp);
			}
			
			// pre-increment :
			_vectorIter&	operator++() {
				_current_it++;
				return *this;
			 }
			//}
			
			// Decrement iterator position : {
			// post-decrement :
			_vectorIter	operator--(int)
			{
				_vectorIter	tmp(*this);
				
				--(*this);
				return (tmp);
			}
			
			// pre-decrement :
			_vectorIter&	operator--() { 
				_current_it--;
				return *this;
			 }
			//}

			// Advance iterator : decreases the rev_iter by _diff elements positions
			_vectorIter&	operator+=(difference_type _diff)
			{
				this->_current_it += _diff;
				return (*this);
			}

			// Retrocede iterator : advance the rev_it by _diff elements positions.
			_vectorIter&	operator-=(difference_type _diff)
			{
				this->_current_it -= _diff;
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
		
	};
	// NON-MEMBER FUNCTIONS OVERLOADS

	// Relational operators :
	
	template <typename Iter, typename Iter1>
	bool	operator == (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (_left.base() == _right.base());
	}

	template <typename Iter, typename Iter1>
	bool	operator != (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (!(_left.base() == _right.base()));
	}

	template <typename Iter, typename Iter1>
	bool	operator < (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (_left.base() < _right.base());
	}

	template <typename Iter, typename Iter1>
	bool	operator > (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (_right.base() < _left.base());
	}
	
	template <typename Iter, typename Iter1>
	bool	operator >= (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (!(_left < _right));
	}

	template <typename Iter, typename Iter1>
	bool	operator <= (const _vectorIter<Iter>& _left, const _vectorIter<Iter1>& _right)
	{
		return (!(_right < _left));
	}
	
	// Function template for Addition and Substraction
	template <typename Iter>
	_vectorIter<Iter>	operator + (typename _vectorIter<Iter>::difference_type _diff, const _vectorIter<Iter> _revIt)
	{
		return (_revIt.base() + _diff);
	}

	template <typename Iter>
	typename _vectorIter<Iter>::difference_type	operator - (const _vectorIter<Iter>& _left, const _vectorIter<Iter>& _right)
	{
		return (_left.base() - _right.base());
	}

	// END! NON-MEMBER FUNCTIONS OVERLOADS
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
				~_reverseIter() { } // Destructor

				
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
				_reverseIter&	operator++()
				{ 
					this->_current_it--;
					return (*this);
				}
				
				// post-increment :
				_reverseIter	operator++(int)
				{
					_reverseIter	tmp(*this);
					
					--(this->_current_it);
					return (tmp);
				}
				//}
				
				// Decrement iterator position : {
				// post-decrement :
				_reverseIter	operator--(int)
				{
					_reverseIter	tmp(*this);
					
					++(this->_current_it);
					return (tmp);
				}
				// pre-decrement :
				_reverseIter&	operator--()
				{ 
					this->_current_it++;
					return (*this);
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
		
	};// END! _reverseIter

	// NON-MEMBER FUNCTIONS OVERLOADS

	// Relational operators :
	
	template <typename Iter>
	bool	operator == (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (_left.base() == _right.base());
	}

	template <typename Iter>
	bool	operator != (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (!(_left.base() == _right.base()));
	}

	template <typename Iter>
	bool	operator < (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (_left.base() < _right.base());
	}

	template <typename Iter>
	bool	operator > (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (_right.base() < _left.base());
	}
	
	template <typename Iter>
	bool	operator >= (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (!(_left < _right));
	}

	template <typename Iter>
	bool	operator <= (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (!(_right < _left));
	}
	
	// Function template for Addition and Substraction
	template <typename Iter>
	_reverseIter<Iter>	operator + (typename _reverseIter<Iter>::difference_type _diff, const _reverseIter<Iter> _revIt)
	{
		return (_revIt.base() - _diff);
	}

	template <typename Iter>
	typename _reverseIter<Iter>::difference_type	operator - (const _reverseIter<Iter>& _left, const _reverseIter<Iter>& _right)
	{
		return (_right.base() - _left.base());
	}

	// END! NON-MEMBER FUNCTIONS OVERLOADS
	
	// END! ------------- REVERSE_ITERATOR ------------
	
} // END! ft namespace

#endif
