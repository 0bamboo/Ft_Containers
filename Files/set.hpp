/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:24:08 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/10 04:12:31 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

# include "_pair_.hpp"
# include "_RBT_.hpp"
# include "_iter_.hpp"
# include <iostream>
# include <limits>
# include <memory>

namespace ft{

	// set iterator:
	template<typename _pairType>
	class	S_tree_iterator
	{
		public:
			
			typedef	_pairType										iterator_type;
			typedef _pairType*										pointer;
			typedef _pairType&										reference;
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef S_tree_iterator<_pairType>						_self;
			typedef	typename tree_node<_pairType>::_nodePtr			_node;
		
		private:
			_node	_curr;
			
		public:
			
			S_tree_iterator() : _curr() { }

			S_tree_iterator(iterator_type iter) : _curr(iter) { }

			template<typename T>
			S_tree_iterator(const S_tree_iterator<T>& iter) : _curr(iter.base()) { }
			
			template<typename T>
			S_tree_iterator&	operator = (const S_tree_iterator<T>& iter)
			{
				this->_curr = iter.base();
				return (*this);
			}
			
			~S_tree_iterator() { }

			iterator_type	base() const { return (this->_curr); }

			reference	operator *( ) const { return (this->_curr->_pair.first); }

			_node	_get_node_() const { return (this->_curr); }

			pointer		operator ->() const { return (&(operator *())); }

			// Pre increment :
			_self	operator++() 
			{
				this->_curr = next(this->_curr);
				return (*this);
			}

			// Post increment :
			_self	operator++(int)
			{
				S_tree_iterator	_tmp(*this);

				this->_curr = next(this->_curr);
				return (_tmp);
			}

			_self	operator--()
			{
				this->_curr = prev(this->_curr);
				return (*this);
			}

			_self	operator--(int)
			{
				S_tree_iterator	_tmp(*this);

				this->_curr = prev(this->_curr);
				return (_tmp);
			}

			template<typename It>
			bool	operator == (const S_tree_iterator<It>& cmp)
			{
				return (this->_curr == cmp.base());
			}

			template<typename It>
			bool	operator != (const S_tree_iterator<It>& cmp)
			{
				return (this->_curr != cmp.base());
			}

			private:

				_node	prev(_node _currNode)
				{
					if (_currNode->_left != nullptr)
					{
						while (_currNode->_right != nullptr)
							_currNode = _currNode->_right;
						return (_currNode);
					}
					else
					{
						_node _tmp = _currNode->_parent;
						while (_tmp != nullptr && _currNode == _tmp->_left)
						{
							_currNode = _tmp;
							_tmp = _tmp->_parent;
						}
						return (_tmp);
					}
				}

				_node	next(_node _currNode)
				{
					if (_currNode->_right != nullptr)
					{
						while (_currNode->_left != nullptr)
							_currNode = _currNode->_left;
						return (_currNode);
					}
					else
					{
						_node	_tmp = _currNode->_parent;
						while (_tmp != nullptr && _currNode == _tmp->_right)
						{
							_currNode = _tmp;
							_tmp = _tmp->_parent;
						}
						return (_tmp);
					}
				}
			
	}; // END! TREE ITERATOR .
	
	template< typename T,
		typename Compare = std::less<T>,
		typename Alloc = std::allocator<T> >
	class set{

		public:
			
			typedef T														key_type;
			typedef Compare													key_compare;
			typedef T														value_type;
			typedef	Alloc													allocator_type;
			typedef _rbTree_<key_type, value_type, allocator_type, key_compare>		_rbTree_;
			typedef typename ft::tree_node<value_type>*						_nodePtr_;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef tree_iterator<key_type, _nodePtr_>								iterator;// add const iter and const rev
			typedef tree_iterator<const key_type, _nodePtr_>						const_iterator;
			typedef ft::_reverseIter<const_iterator>						const_reverse_iterator;
			typedef ft::_reverseIter<iterator>								reverse_iterator;
			typedef typename _rbTree_::size_type							size_type;
			typedef typename _rbTree_::difference_type						difference_type;

			// Class value_compare :
		
		private:
			_rbTree_		_tree_;
			allocator_type	_alloc;
			key_compare		_compare;
		
		public:
			// Constructors:
			explicit	set(const key_compare& cmp = key_compare(), const allocator_type& allocator = allocator_type())
					: _tree_(key_compare(cmp), allocator), _alloc(allocator), _compare(cmp) { }
			template<typename _iter>
			set(_iter first, _iter last, const key_compare& cmp = key_compare(), const allocator_type& allocator = allocator_type()) :
			_tree_(key_compare(cmp), allocator), _alloc(allocator), _compare(cmp)
			{
				this->insert(first, last);
			}
			set(const set& obj) : _tree_(key_compare(obj._compare), _alloc(obj._alloc)), _compare(obj._compare)
			{
				*this = obj;
			}
			
			// Assignment operator:
			set&	operator = (const set& obj)
			{
				if (this != &obj)
				{
					// Clear this tree then insert all the nodes in obj
					this->clear();
					this->_alloc = obj._alloc;
					this->_compare = obj._compare;
					this->insert(obj.begin(), obj.end());
				}
				return (*this);
			}

			~set() { }

			// Iterators:
			iterator	begin()
			{
				return (this->_tree_.begin());
			}

			const_iterator	begin() const
			{
				return (this->_tree_.begin());
			}

			iterator	end()
			{
				return (this->_tree_.end());
			}
			
			const_iterator	end() const
			{
				return (this->_tree_.end());
			}

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator	rend()
			{
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(this->begin));
			}

			// Empty:
			bool	empty()
			{
				return (this->size() == 0);
			}

			// Size:
			size_type	size()
			{
				return (this->_tree_.size());
			}

			// max size:
			size_type	max_size() const
			{
				return (this->_tree_.max_size());
			}

			// Insert methods:
			pair<iterator, bool>	insert(const value_type& _key)
			{
				iterator	_found = this->find(_key);

				if (_found == this->end())
				{
					this->_tree_._insert_(_key);
					_found = this->find(_key);
					return (pair<iterator, bool>(_found, true));
				}
				return (pair<iterator, bool>(_found, false));
			}

			iterator	insert(iterator pos, const value_type& _key)
			{
				pos = this->find(_key);
				if(pos != this->end())
					return (pos);
				this->insert(_key);
				return (this->find(_key));
			}

			template<typename _iter>
			void	insert(_iter first, _iter last)
			{
				for(; first!=last; first++)
					this->insert(*first);
			}

			// Clear : delete everything.
			void	clear()
			{
				this->_tree_.clear();
			}

			// Erase methods:
			void	erase(iterator pos)
			{
				if (this->find(*pos) != this->end())
					this->_tree_._delete_(*pos);
			}

			size_type	erase(const key_type& key)
			{
				iterator _found = this->find(key);
				if (_found != this->end())
				{
					this->erase(_found);
					return (1);
				}
				return (0);
			}

			void	erase(iterator first, iterator last)
			{
				while(first!=last)
					this->erase(first++);
			}

			// Find methods :
			const_iterator	find(const key_type& key) const
			{
				_nodePtr_ tmp = this->_tree_.find(key);

				if (tmp != nullptr)
					return (const_iterator(tmp));
				return (this->end());
			}

			// Count return 1 if the key exists 0 otherwise:
			size_type	count(const key_type& k) const
			{
				return(this->find(k) != this->end());
			}

			// Return key comparison object :
			key_compare	key_comp() const
			{
				return (this->_compare);
			}
			
			// Swap :
			void	swap(set& _set_)
			{
				this->_tree_.swap(_set_._tree_);
				std::swap(this->_alloc, _set_._alloc);
				std::swap(this->_compare, _set_._compare);
			}

			// Upper bound:
			const_iterator	upper_bound(const key_type& key) const
			{
				_nodePtr_	_tmp_ = this->_root_;
				_nodePtr_	_res_ = this->_endNode_;

				while(_tmp_ != nullptr)
				{
					if (this->_comp(key, _tmp_->_pair))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return const_iterator(_res_);
			}

			// Lower bound :
			const_iterator	lower_bound(const key_type& key) const
			{
				_nodePtr_	_tmp_ = this->_root_;
				_nodePtr_	_res_ = this->_endNode_;
				
				while(_tmp_ != nullptr)
				{
					if (!this->_comp(_tmp_->_pair, key))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return (const_iterator(_res_));
			}

			// return allocator type:
			allocator_type	get_allocator() const
			{
				return (this->_alloc);
			}
			
			// Equal range : get range of equal elements but, 
			//since all the key are unique so the size of the range is 1 if the key exists			
			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
			
	};// END set!
	
}// END! NAMESPACE FT

#endif
