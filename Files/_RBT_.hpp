/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _RBT_.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:01:47 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/28 21:15:13 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RED-BLACK TREE.
#ifndef _RBT__HPP
#define _RBT__HPP

# include "_iter_.hpp"

# define _BLACK_ 1
# define _RED_   0

namespace ft{

	// Tree Node :
	template<typename _pairType>
	struct tree_node{
		
		typedef		_pairType					value_type;
		typedef		tree_node<_pairType>*		_nodePtr;

		value_type		_pair;   // the data of the map pair
		_nodePtr		_parent;
		_nodePtr		_left;
		_nodePtr		_right;
		bool			_color;

		tree_node(): _color(_BLACK_), _parent(nullptr), _left(nullptr), _right(nullptr) { }
		tree_node(value_type _dt): _color(_BLACK_), _pair(_dt), _parent(nullptr), _left(nullptr), _right(nullptr) { }
	};

	// Tree iterator :
	template<typename _pairType>
	class	tree_iterator
	{
		public:
			
			typedef	_pairType										iterator_type;
			typedef _pairType*										pointer;
			typedef _pairType&										reference;
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef tree_iterator<_pairType>						_self;
			typedef	typename tree_node<_pairType>::_nodePtr			_node;
		
		private:
			_node	_curr;
			
		public:
			
			tree_iterator() : _curr() { }

			tree_iterator(iterator_type iter) : _curr(iter) { }

			template<typename T>
			tree_iterator(const tree_iterator<T>& iter) : _curr(iter.base()) { }
			
			template<typename T>
			tree_iterator&	operator = (const tree_iterator<T>& iter)
			{
				this->_curr = iter.base();
				return (*this);
			}
			
			~tree_iterator() { }

			iterator_type	base() const { return (this->_curr); }

			reference	operator *( ) const { return (this->_curr->_pair); }

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
				tree_iterator	_tmp(*this);

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
				tree_iterator	_tmp(*this);

				this->_curr = prev(this->_curr);
				return (_tmp);
			}

			template<typename It>
			bool	operator == (const tree_iterator<It>& cmp)
			{
				return (this->_curr == cmp.base());
			}

			template<typename It>
			bool	operator != (const tree_iterator<It>& cmp)
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
						iterator_type	_tmp = _currNode->_parent;
						while (_tmp != nullptr && _currNode == _tmp->_right)
						{
							_currNode = _tmp;
							_tmp = _tmp->_parent;
						}
						return (_tmp);
					}
				}
			
	}; // END! TREE ITERATOR .



	// RED BLACK TREE TEMPLATE CLASS :
	
	
};


#endif
