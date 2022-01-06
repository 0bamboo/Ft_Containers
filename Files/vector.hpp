/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:11 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/06 17:08:11 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "_iter_.hpp"
# include "_equal_.hpp"
# include "_lexicographical_.hpp"
# include "_trait_types_.hpp"
# include <stdexcept>
# include <memory>

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
			typedef	typename		allocator_type::size_t				size_type;
		
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
			vector(_inputIter _first, _inputIter _last, const allocator_type& alloc = allocator_type())
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
					for (size_type i = 0; i < this->_size_; i++)
						this->_alloctype_.construct(&_newData_[i], this->_data_[i]);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity = _newCap_;
					this->_data_ = _newData_;
				}
			} // Requests a change in capacity.

			void	resize(size_type n, value_type val = value_type())
			{
				if (n < this->_size_)
				{
					for (size_type i = n; i < this->_size_; i++)
						this->_alloctype_.destroy(this->_data_ + i);
					this->_size_ = n;
				}
				else if (n > this->_size_)
				{
					size_type	_old_ = this->_size_;
					this->reserve(n);
					this->_size_ = n;
					for (size_type i = _old_; i < n; i++)
						this->_alloctype_.construct(&this->_data_[i], val);
				}
			} // Resize the container so that it contains n elements. 
			// --------- }

			// Element Access : ----------- {

			reference	operator [](size_type i) { return (this->_data_[i]); }
			c_reference	operator [](size_type i) const { return (this->_data_[i]); }

			reference	at(size_type i)
			{
				if (i >= this->_size_)
					throw (std::out_of_range("Vector"));
				return (this->_data_[i]);
			}

			c_reference	at(size_type i) const
			{
				if (i >= this->_size_)
					throw (std::out_of_range("Vector"));
				return (this->_data_[i]);
			}

			reference	front() { return (*this->_data_); }
			c_reference	front() const { return (*this->_data_); }

			reference	back() { return (*(this->_data_ + this->_size_ - 1)); }
			c_reference	back() const { return (*(this->_data_ + this->_size_ - 1)); }
			
			// ------------- }

			// Modifiers : ------------ {
			
			// Assign vector content:
			void	assign(size_type n, const value_type& val)
			{
				if (n == 0)
					this->clear();
				else if (n >= this->_capacity_)
				{
					size_type	_oldC_ = this->_capacity_;
					this->_capacity_ = n;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (size_type i = 0; i < this->_capacity_; ++i)
						this->_alloctype_.construct(&_newData_[i], val);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, _oldC_);
					this->_data_ = _newData_;
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						this->_alloctype_.destroy(&this->_data_[i]);
						this->_alloctype_.construct(&this->_data_[i], val);
					}
					this->_size_ = n;
				}
			}// Fill Version.
			
			template <typename _inputIter>
			void	assign(_inputIter _first, _inputIter _last)
			{
				size_type	_length_ = _last - _first;
				
				if (_length_ == 0)
					this->clear();
				else if (_length_ >= this->_capacity_)
				{
					size_type	_oldC_ = this->_capacity_;
					this->_capacity_ = _length_;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (int i = 0; _first < _last; ++i, ++_first)
						this->_alloctype_.construct(&_newData_[i], *_first);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, _oldC_);
					this->_data_ = _newData_;
				}
				else
				{
					for(int i = 0; _first < _last; ++i, ++_first)
					{
						this->_alloctype_.destroy(&this->_data_[i]);
						this->_alloctype_.construct(&this->_data_[i], *_first);
					}
					this->_size_ = _length_;
				}
			}// Range Version.
			
			
			// --------------- }

			// Add element at the end :
			void	push_back(const value_type& val)
			{
				this->reserve(this->_size_++);
				this->_alloctype_.construct(&this->_data_[this->_size_ - 1], val); 
			}

			// Delete last element :
			void	pop_back()
			{
				this->_alloctype_.destroy(&this->_data_[--this->_size_]);
			}
			
			// Destroy all the content of the vector :
			void	clear()
			{
				for(int i = 0; i < this->_size_; i++)
					this->_alloctype_.destroy(&this->_data_[i]);
				this->_size_ = 0;
			}

			// Insert elements : ----------- { 1 2 3    5    bLAST 2
			
			// Fill :
			void	insert(iterator _pos, size_type _nElem, const value_type& value)
			{
			}
			
			// Single element :
			iterator	insert(iterator _pos, const value_type& value)
			{
				difference_type	idx = _pos - this->begin();
					// if (idx < 0)
					// 	throw ()
				size_type j = 0;
				if (this->_size_++ > this->_capacity_)
				{
					size_type	_newCap_ = (this->_capacity_ * 2 >= this->_size_) ? this->_capacity_ * 2 : this->_size_;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (size_type i = 0; i < this->_size_; i++)
					{
						if (i == idx)
							this->_alloctype_.construct(&_newData_[i], value);
						else
							this->_alloctype_.construct(&_newData_[i], this->_data_[j++]);
					}
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity = _newCap_;
					this->_data_ = _newData_;
				}
				else
				{
					j = this->_size_++;
					while (j-- > 0)
					{
						if (j == idx)
						{
							this->_alloctype_.construct(&this->_data_[j], value);
							break ;
						}
						this->_alloctype_.construct(&this->_data_[j], this->_data_[j - 1]);
					}
				}
				return (iterator(this->_data_ + idx));
		
			}

			// Range :
			template <typename _inputIter>
			void	insert(iterator _pos, _inputIter _first, _inputIter _last)
			{

			}

			// ---------- }
	};
	// END! Vector 
} // END! ft namespace

#endif
