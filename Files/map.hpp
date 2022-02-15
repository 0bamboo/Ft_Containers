/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:00 by abdait-m          #+#    #+#             */
/*   Updated: 2022/02/15 12:00:01 by abdait-m         ###   ########.fr       */
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
			typedef _rbTree_<value_type, key_compare, allocator_type>		_rbTree_;
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
					this->insert(obj.begin(), obj.end());
				}
				return (*this);
			}

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
				
			}

			iterator	insert(iterator pos, const value_type& _pair)
			{

			}

			template<typename _iter>
			void	insert(_iter first, _iter last)
			{
				
			}

			// Erase methods:
			void	erase(iterator pos)
			{
				// look for the pos and erase it using the method of delete of the tree
			}

			size_type	erase(const key_type& key)
			{
				
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					this->erase(first++);
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
			
			
	};

};

#endif
