/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:11 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/04 18:47:45 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "_iter_.hpp"
# include "_equal_.hpp"
# include "_lexicographical_.hpp"
# include "_trait_types_.hpp"
# include <stdexcept>

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
			typedef	typename		allocator_type::size_t							size_type;
		
		private:
			size_type		_size_;
			size_type		_capacity_;
			allocator_type	_alloctype_;
			pointer			_data_;

			// Reallocate:
			void	_reallocate_(size_type	_newS_)
			{
				
			}
		
		public:
			// Constructors
			explicit vector(const allocator_type& alloc = allocator_type()) : 
			_size_(0), _capacity_(0),_alloctype_(alloc), _data_(nullptr) { } // default constructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_size_(n), _capacity_(n)
			{
				// reserve
				// assign	
			} // fill constructor
			vector(const vector& obj)
			{
				if (this != &obj)
					*this = obj;
			} // Copy constructor
			template<typename _inputIter>
			vector(_inputIter first, _inputIter last, const allocator_type& alloc = allocator_type())
			{
				
			} // fill constructor using iterators

			// Iterators: { ---------
			// Normal iterators: 
			iterator		begin() { return (iterator(_data_)); }
			c_iterator		begin() const { return (c_iterator(_data_)); }

			iterator		end() { return (iterator(_data_ + this->_size_)); }
			c_iterator		end() const { return (c_iterator(_data_ + this->_size_)); }
			
			// Reverse Iterators:
			rev_iterator	rbegin() { return (rev_iterator(this->end())); }
			c_rev_iterator	rbegin() const { return (c_rev_iterator(this->end())); }

			rev_iterator	rend() { return (rev_iterator(this->begin())); }
			c_rev_iterator	rend() const { return (c_rev_iterator(this->begin())); }
			// --------- }

			// Size and capacity { --------- :
			size_type	size() const { return (this->_size_); } // the number of elements in the vector.
			size_type	capacity() const { return (this->_capacity_); } // the size of allocated storage capacity it can be equal or greater than size.
			size_type	max_size() const { return (_alloctype_.max_size()); } // Maximum size possible to allocate.
			
			bool	empty() const { return (this->_size_ == 0); } // Checks whether the vector is empty or not. 
			
			void	reserve(size_type n)
			{
				if (n > this->_capacity_)
				{
					size_type	_newCap_ = (this->_capacity_ * 2 >= n) ? this->_capacity_ * 2 : n;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (int i = 0; i < this->_size_; i++)
						this->_alloctype_.construct(_newData_, this->_data_[i]);
					this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_data_ = _newData_;
				}
			} // Requests a change in capacity.

			
			
			void	resize(size_type n, value_type val = value_type())
			{
				if (n < this->_size_)
				{
					pointer		_newD_ = this->_alloctype_.allocate(n);
					for (int i = 0; i < n; i++)
						_newD_[i] = this->_data_[i];
					this->_alloctype_.deallocate(this->_data_, this->_capacity_);
				}
			} // Resize the container so that it contains n elements. 
			// --------- }
	};
	// END! Vector 
} // END! ft namespace

#endif
