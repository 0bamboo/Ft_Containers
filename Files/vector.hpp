/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:11 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/12 19:31:38 by abdait-m         ###   ########.fr       */
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
			typedef typename 		Alloc::const_reference				const_reference;
			typedef typename 		Alloc::pointer						pointer;
			typedef typename 		Alloc::const_pointer				const_pointer;
			typedef					_vectorIter<pointer>				iterator;
			typedef					_vectorIter<const_pointer>			const_iterator;
			typedef	typename		ft::_reverseIter<iterator>			reverse_iterator;
			typedef typename		ft::_reverseIter<const_iterator>	const_reverse_iterator;
			typedef					std::ptrdiff_t						difference_type;
			typedef	typename		Alloc::size_type					size_type;
		
		private:
			size_type		_size_;
			size_type		_capacity_;
			allocator_type	_alloctype_;
			pointer			_data_;

		public:
			// Constructors
			// We use explicit keyword to prevent the implicit conversion of the compiler, means: 
			// that the compiler can use constructors callable with a single parameter to convert from one type,
			// to another in order to get the right type for a parameter
			explicit vector(const allocator_type& alloc = allocator_type()) : 
			_size_(0), _capacity_(0),_alloctype_(alloc), _data_(nullptr) { } // default constructor
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_size_(0), _capacity_(0), _alloctype_(alloc), _data_(nullptr)
			{
				this->assign(n, val);
			} // fill constructor
			
			vector(const vector& obj):_size_(0), _capacity_(obj._size_), _alloctype_(obj.get_allocator())
			{
				this->_data_ = this->_alloctype_.allocate(this->_capacity_);
				for (; this->_size_ < this->_capacity_;this->_size_++)
					this->_alloctype_.construct(&this->_data_[this->_size_], obj._data_[this->_size_]);
			} // Copy constructor
			
			template<typename _inputIter>
			vector(_inputIter _first, _inputIter _last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<_inputIter>::value, bool>::type = true) :
			_size_(0), _capacity_(0), _alloctype_(alloc), _data_(nullptr)
			{
				this->assign(_first, _last);
			} // fill constructor using iterators

			vector&	operator = (const vector& obj)
			{
				if (this != &obj)
				{
					vector	tmp(obj);
					if (this->_capacity_ > obj._capacity_)
					{
						this->_alloctype_.deallocate(this->_data_, _size_);
						this->_data_ = this->_alloctype_.allocate(this->_capacity_);
						this->_size_ = obj._size_;
						for (size_type i = 0; i < this->_size_; i++)
							this->_alloctype_.construct(&this->_data_[i], obj._data_[i]);
					}
					else
						this->swap(tmp);
				}
				return (*this);
			}

			~vector()
			{
				this->clear();
				if (this->_data_)
					this->_alloctype_.deallocate(this->_data_, this->_capacity_);
			}
			

			// Iterators: { ---------
			// Normal iterators: 
			iterator		begin() { return (iterator(this->_data_)); }
			const_iterator		begin() const { return (const_iterator(this->_data_)); }

			iterator		end() { return (iterator(this->_data_ + this->_size_)); }
			const_iterator		end() const { return (const_iterator(this->_data_ + this->_size_)); }
			
			// Reverse Iterators:
			reverse_iterator	rbegin() { return (reverse_iterator(this->end())); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->end())); }

			reverse_iterator	rend() { return (reverse_iterator(this->begin())); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(this->begin())); }
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
					pointer		_newData_ = this->_alloctype_.allocate(_newCap_);
					for (size_type i = 0; i < this->_size_; i++)
						this->_alloctype_.construct(&_newData_[i], this->_data_[i]);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity_ = _newCap_;
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
			const_reference	operator [](size_type i) const { return (this->_data_[i]); }

			reference	at(size_type i)
			{
				if (i >= this->_size_)
					throw (std::out_of_range("vector"));
				return (this->_data_[i]);
			}

			const_reference	at(size_type i) const
			{
				if (i >= this->_size_)
					throw (std::out_of_range("vector"));
				return (this->_data_[i]);
			}

			reference	front() { return (*this->_data_); }
			const_reference	front() const { return (*this->_data_); }

			reference	back() { return (*(this->_data_ + this->_size_ - 1)); }
			const_reference	back() const { return (*(this->_data_ + this->_size_ - 1)); }
			
			// ------------- }

			// Modifiers : ------------ {
			
			// Assign vector content:
			void	assign(size_type n, const value_type& val)
			{
				if (n >= this->_capacity_)
				{
					size_type	_oldC_ = this->_capacity_;
					this->_capacity_ = this->_size_ = n;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (size_type i = 0; i < this->_capacity_; ++i)
						this->_alloctype_.construct(&_newData_[i], val);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, _oldC_);
					this->_data_ = _newData_;
				}
				else
				{
					for (size_type i = 0; i < n; i++)
					{
						this->_alloctype_.destroy(&this->_data_[i]);
						this->_alloctype_.construct(&this->_data_[i], val);
					}
					this->_size_ = n;
				}
				
			}// Fill Version.
			
			template <typename _inputIter>
			void	assign(_inputIter _first, _inputIter _last,
			typename enable_if<!is_integral<_inputIter>::value, bool>::type = true)
			{
				difference_type	_length_ = _last - _first;
				// if (_length_ < 0)
				// 	return ;
				if ((size_type)_length_ >= this->_capacity_)
				{
					size_type	_oldC_ = this->_capacity_;
					this->_capacity_ = this->_size_ = _length_;
					pointer		_newData_ = this->_alloctype_.allocate(this->_capacity_);
					for (size_type i = 0; _first != _last; ++i, ++_first)
						this->_alloctype_.construct(&_newData_[i], *_first);
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, _oldC_);
					this->_data_ = _newData_;
				}
				else
				{
					for(size_type i = 0; _first < _last; ++i, ++_first)
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
				if (this->_size_ + 1 >= this->_capacity_)
				{
					size_type _newCap_ = this->_capacity_ == 0 ? 1 : this->_capacity_ * 2;
					pointer	_newData_ = this->_alloctype_.allocate(_newCap_);

					for (size_type i = 0; i < this->_size_;i++)
						this->_alloctype_.construct(&_newData_[i], this->_data_[i]);
					if (this->_size_ + 1)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity_ = _newCap_;
					this->_data_ = _newData_;
				}
				this->_alloctype_.construct(&this->_data_[this->_size_++], val);
			}

			// Delete last element :
			void	pop_back()
			{
				this->_alloctype_.destroy(&this->_data_[--this->_size_]);
			}
			
			// Destroy all the content of the vector :
			void	clear()
			{
				for(size_type i = 0; i < this->_size_; i++)
					this->_alloctype_.destroy(&this->_data_[i]);
				this->_size_ = 0;
			}

			// Insert elements : ----------- {
			
			// Fill :
			void	insert(iterator _pos, size_type _nElem, const value_type& value)
			{
				difference_type idx = _pos - this->begin();
				size_type j = 0;
				
				if (this->_size_ + _nElem >= this->_capacity_)
				{
					size_type _newCap_ = (this->_capacity_ * 2 >= this->_size_ + _nElem) ? this->_capacity_ * 2 : this->_size_ + _nElem;
					pointer	  _newData_ = this->_alloctype_.allocate(_newCap_);
					size_type _newSize_ = this->_size_ + _nElem;
					size_type i = 0;
					while (i < this->_size_)
					{
						if (i == (size_type)idx && _nElem)
						{
							this->_alloctype_.construct(&_newData_[j++], value);
							_nElem--;
						}
						else
							this->_alloctype_.construct(&_newData_[j++], this->_data_[i++]);
					}
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_size_ = _newSize_;
					this->_capacity_ = _newCap_;
					this->_data_ = _newData_;
				}
				else
				{
					this->_size_ += _nElem;
					j = this->_size_;
					while (--j >= 0)
					{
						if (j == (size_type)(idx + _nElem - 1))
						{
							this->_alloctype_.construct(&this->_data_[j], value);
							_nElem--;
						}
						else
							this->_alloctype_.construct(&this->_data_[j], this->_data_[j - _nElem]);
						if ((size_type)idx == j)
							break ;
					}
				}
			}
			
			// Single element :
			iterator	insert(iterator _pos, const value_type& value)
			{
				difference_type	idx = _pos - this->begin();
				size_type j = 0;
				if (++this->_size_ >= this->_capacity_)
				{
					size_type	_newCap_ = (this->_capacity_ * 2 >= this->_size_) ? this->_capacity_ * 2 : this->_size_;
					pointer		_newData_ = this->_alloctype_.allocate(_newCap_);
					for (size_type i = 0; i < this->_size_; i++)
					{
						if (i == (size_type)idx)
							this->_alloctype_.construct(&_newData_[i], value);
						else
							this->_alloctype_.construct(&_newData_[i], this->_data_[j++]);
					}
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity_ = _newCap_;
					this->_data_ = _newData_;
				}
				else
				{
					j = this->_size_;
					while (--j >= 0)
					{
						if (j == (size_type)idx)
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
			void	insert(iterator _pos, _inputIter _first, _inputIter _last,
			typename enable_if<!is_integral<_inputIter>::value, bool>::type = true)
			{
				difference_type idx = _pos - this->begin();
				difference_type _rangeS_ = _last - _first;
				if (_rangeS_ < 0)
					throw std::out_of_range("vector");
				size_type j = 0;
				if (this->_size_ + _rangeS_ >= this->_capacity_)
				{
					size_type _newCap_ = (this->_capacity_ * 2 >= this->_size_ + _rangeS_) ? this->_capacity_ * 2 : this->_size_ + _rangeS_;
					pointer	  _newData_ = this->_alloctype_.allocate(_newCap_);
					size_type i = 0;
					
					while (i < this->_size_)
					{
						if (i == (size_type)idx && _first != _last)
							this->_alloctype_.construct(&_newData_[j++], *_first++);
						else
							this->_alloctype_.construct(&_newData_[j++], this->_data_[i++]);
					}
					if (this->_size_)
						this->_alloctype_.deallocate(this->_data_, this->_capacity_);
					this->_capacity_ = _newCap_;
					this->_size_ += _rangeS_;
					this->_data_ = _newData_;
				}
				else
				{
					this->_size_ += _rangeS_;
					j = this->_size_;
					while (--j >= 0)
					{
						if (j == (size_type)(idx + _rangeS_ - 1))
						{
							this->_alloctype_.construct(&this->_data_[j], *--_last);
							_rangeS_--;
						}
						else
							this->_alloctype_.construct(&this->_data_[j], this->_data_[j - _rangeS_]);
						if ((size_type)idx == j)
							break ;
					}
				}
			}
			// ---------- }

			// Swap :
			void	swap(vector& _swapvec)
			{
				std::swap(this->_size_, _swapvec._size_);
				std::swap(this->_capacity_, _swapvec._capacity_);
				std::swap(this->_alloctype_, _swapvec._alloctype_);
				std::swap(this->_data_, _swapvec._data_);
			}

			// Get Allocator:
			allocator_type	get_allocator() const { return (this->_alloctype_); }

			// Erase elements : --------- {
			
			// erase a single element : 
			iterator erase(iterator _pos)
			{
				difference_type idx = _pos - this->begin();
				size_type i = 0, j = 0;
				while (i < this->_size_)
				{
					if (i == (size_type)idx)
						this->_alloctype_.destroy(&this->_data_[i++]);
					this->_alloctype_.construct(&this->_data_[j++], this->_data_[i++]);
				}
				this->_size_--;
				return (iterator(this->_data_ + idx));
			}

			// erase a range of elements :
			iterator erase(iterator _first, iterator _last)
			{
				difference_type idx = _first - this->begin();
				size_type _deleteSize_ = _last - _first;
				size_type i = 0, j = 0;
				
				while (i < this->_size_)
				{
					if ((size_type)idx == i)
					{
						for (; _first != _last; _first++)
							this->_alloctype_.destroy(&this->_data_[i++]);
					}
					this->_alloctype_.construct(&this->_data_[j++], this->_data_[i++]);
				}
				this->_size_ -= _deleteSize_;
				return (iterator(this->_data_ + idx));
			}
			// ------------}
	}; // END! Vector 

	// Non-Member functions overloads : { ------------------
	
	// Relational operators :
	template <typename _T, typename Alloc>
	bool	operator == (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (_left.size() == _right.size() && ft::equal(_left.begin(), _left.end(), _right.begin()));
	}
	
	template <typename _T, typename Alloc>
	bool	operator != (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (!(_left == _right));
	}
	
	template <typename _T, typename Alloc>
	bool	operator < (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (ft::lexicographical_compare(_left.begin(), _left.end(), _right.begin(), _right.end()));
	}
	
	template <typename _T, typename Alloc>
	bool	operator <= (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (!(_right < _left));
	}
	
	template <typename _T, typename Alloc>
	bool	operator > (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (_right < _left);
	}
	
	template <typename _T, typename Alloc>
	bool	operator >= (const vector<_T, Alloc>& _left, const vector<_T, Alloc>& _right)
	{
		return (!(_left < _right));
	}

	// Function template of Swap :
	template <typename _T, typename Alloc>
	void	swap(vector<_T, Alloc>& _a, vector<_T, Alloc>& _b)
	{
		std::swap(_a, _b);
	}
	
	// ----------------- }

} // END! ft namespace

#endif
