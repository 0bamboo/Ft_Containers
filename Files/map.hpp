/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:00 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/04 16:30:12 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "_pair_.hpp"
# include "_RBT_.hpp"
# include "_iter_.hpp"
# include <iostream>
# include <limits>
# include <memory>

namespace ft{

	template< typename Key,
			typename T,
			typename Compare = std::less<Key>,
			typename Alloc = std::allocator<ft::pair<const Key, T> >
			>
	class map{

		public:
			
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef Compare													key_compare;
			typedef pair<const key_type, mapped_type>						value_type;
			typedef	Alloc													allocator_type;
			typedef _rbTree_<key_type, value_type, key_compare, allocator_type>		_rbTree_;
			typedef typename ft::tree_node<value_type>*						_nodePtr_;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename _rbTree_::iterator								iterator;// add const iter and const rev
			typedef typename _rbTree_::const_iterator						const_iterator;
			typedef typename _rbTree_::const_reverse_iterator				const_reverse_iterator;
			typedef typename _rbTree_::reverse_iterator						reverse_iterator;
			typedef typename _rbTree_::size_type							size_type;
			typedef typename _rbTree_::difference_type						difference_type;

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
		
		private:
			_rbTree_		_tree_;
			allocator_type	_alloc;
			key_compare		_compare;
		
		public:
			// Constructors:
			explicit	map(const key_compare& cmp = value_compare(), const allocator_type& allocator = allocator_type())
					: _tree_(value_compare(cmp), allocator), _alloc(allocator), _compare(cmp) { }
			template<typename _iter>
			map(_iter first, _iter last, const key_compare& cmp = value_compare(), const allocator_type& allocator = allocator_type()) :
			_tree_(value_compare(cmp), allocator), _alloc(allocator), _compare(cmp)
			{
				this->insert(first, last);
			}
			map(const map& obj) : _tree_(value_compare(obj._compare), _alloc(obj._alloc)), _compare(obj._compare)
			{
				*this = obj;
			}
			
			// Assignment operator:
			map&	operator = (const map& obj)
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

			~map() { }

			// Iterators:
			iterator	begin()
			{
				return (iterator(this->_tree_.begin()));
			}

			const_iterator	begin() const
			{
				return (const_iterator(this->_tree_.begin()));
			}

			iterator	end()
			{
				return (iterator(this->_tree_.end()));
			}
			
			const_iterator	end() const
			{
				return (const_iterator(this->_tree_.end()));
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
				return (std::min<size_type>(this->_alloc.max_size(), std::numeric_limits<difference_type>::max()));
			}

			// Insert methods:
			pair<iterator, bool>	insert(const value_type& _pair)
			{
				iterator	_found = this->find(_pair._first);

				if (_found == this->end())
				{
					this->_tree_._insert_(_pair);
					_found = this->find(_pair._first);
					return (pair<iterator, bool>(_found, true));
				}
				return (pair<iterator, bool>(_found, false));
			}

			iterator	insert(iterator pos, const value_type& _pair)
			{
				pos = this->find(_pair._first);
				if(pos != this->end())
					return (pos);
				this->insert(_pair);
				return (this->find(_pair._first));
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
				if (this->find((*pos)._first) != this->end())
					this->_tree_._delete_(pos._get_node_());
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
				for(;first!=last;first++)
					this->erase(first);
			}

			// Find methods :
			iterator	find(const key_type& key)
			{
				_nodePtr_ tmp = this->_tree_.find(ft::make_pair(key, mapped_type()));

				if (tmp != nullptr)
					return (iterator(tmp));
				return (this->end());
			}

			const_iterator	find(const key_type& key) const
			{
				_nodePtr_ tmp = this->_tree_.find(ft::make_pair(key, mapped_type()));

				if (tmp != nullptr)
					return (const_iteraotr(tmp));
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

			// Return the value comparison object .
			value_compare	value_comp() const
			{
				return (value_compare(this->_compare));
			}

			// Swap :
			void	swap(map& _map_)
			{
				this->_tree_.swap(_map_._tree_);
				std::swap(this->_alloc, _map_._alloc);
				std::swap(this->_compare, _map_._compare);
			}

			// Upper bound:
			iterator	upper_bound(const key_type& k)
			{
				return (this->_tree_.upper_bound(make_pair(k, mapped_type())));
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				return (this->_tree_.upper_bound(make_pair(k, mapped_type())));
			}

			// Lower bound :
			iterator	lower_bound(const key_type& k)
			{
				return (this->_tree_.lower_bound(make_pair(k, mapped_type())));
			}

			const_iterator lower_bound(const key_type& k) const
			{
				return (this->_tree_.lower_bound(make_pair(k, mapped_type())));
			}

			// return allocator type:
			allocator_type	get_allocator() const
			{
				return (this->_alloc);
			}
			
			// Equal range : get range of equal elements but since all the key are unique so the size of the range is 1 if the key exists
			pair<iterator, iterator> equal_range(const key_type& k)
			{
				return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
			
			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			// Access element :
			mapped_type&	operator[](const key_type& _key)
			{
				iterator	_found = this->find(_key);
				if (_found != this->end())
					return ((*_found)._second);
				return (*((this->insert(make_pair(_key,mapped_type())))._first))._second;
			}
			
	};// END MAP!

}; // END NAMESPACE FT!

#endif
