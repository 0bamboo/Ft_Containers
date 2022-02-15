/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _RBT_.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:01:47 by abdait-m          #+#    #+#             */
/*   Updated: 2022/02/15 12:13:39 by abdait-m         ###   ########.fr       */
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
	
	// TREE CONST ITERATOR .
	template<typename _pairType>
	class	tree_const_iterator
	{
		public:
			
			typedef	_pairType										iterator_type;
			typedef const _pairType*								pointer;
			typedef const _pairType&								reference;
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef tree_iterator<_pairType>						_self;
			typedef	typename tree_node<_pairType>::_nodePtr			_node;
		
		private:
			_node	_curr;
			
		public:
			
			tree_const_iterator() : _curr() { }

			tree_const_iterator(iterator_type iter) : _curr(iter) { }

			template<typename T>
			tree_const_iterator(const tree_const_iterator<T>& iter) : _curr(iter.base()) { }
			
			template<typename T>
			tree_const_iterator&	operator = (const tree_const_iterator<T>& iter)
			{
				this->_curr = iter.base();
				return (*this);
			}
			
			~tree_const_iterator() { }

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
				tree_const_iterator	_tmp(*this);

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
				tree_const_iterator	_tmp(*this);

				this->_curr = prev(this->_curr);
				return (_tmp);
			}

			template<typename It>
			bool	operator == (const tree_const_iterator<It>& cmp)
			{
				return (this->_curr == cmp.base());
			}

			template<typename It>
			bool	operator != (const tree_const_iterator<It>& cmp)
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
	template<typename _pairValue, typename _Compare, typename _Alloc>
	class	_rbTree_{
		
		public:
			typedef		_pairValue														_valueType;
			typedef 	tree_node<_pairValue>*											_nodePtr;
			
			// for holding another allocator for the tree_node type
			typedef typename _Alloc::template rebind<tree_node<_valueType> >::other		allocator_type; 
			
			typedef typename	_Alloc::pointer											_allocPtr;
			typedef typename	_Alloc::const_pointer									_allocConstPtr;
			typedef typename	_Alloc::reference										_allocRef;
			typedef typename	_Alloc::const_reference									_allocConstRef;
			typedef		_Compare														_valueCompare;
			typedef		tree_iterator<_nodePtr>											iterator;
			typedef		tree_const_iterator<_nodePtr>									const_iterator; // tree_iterator<const _nodePtr>
			typedef		ft::_reverseIter<iterator>										reverse_iterator;
			typedef		ft::_reverseIter<const_iterator>								const_reverse_iterator;
			typedef	size_t																size_type;
			typedef std::ptrdiff_t														difference_type;

		private:
			_nodePtr		_root_;
			_nodePtr		_endNode_;
			allocator_type	_alloc;
			_valueCompare	_comp;
			size_type		_size;

			// Function to create new nodes :
			_nodePtr	_createNewNode(_valueType _pair)
			{
				_nodePtr	_new = _alloc.allocate(1);
				
				_alloc.construct(_new, _pair);
				return (_new);
			}

			// Check if the node is  a left child:
			bool	_isLeftChild_(_nodePtr _node)
			{
				return (_node == _node->_parent->_left);
			}
			
			// Tree's node min and max :
			_nodePtr	_treeMinimum(_nodePtr _node)
			{
				while (_node->_left != nullptr)
					_node = _node->_left;
				return (_node);
			}
			_nodePtr	_treeMaximum(_nodePtr _node)
			{
				while (_node->_right != nullptr)
					_node = _node->_right;
				return (_node);
			}

			// Rotation :

		public:

			// Constructors:
			

			// Iterators:
			iterator	begin()
			{
				if (this->_root_ != nullptr)
					return (iterator(_treeMinimum(this->_root_)));
				return (this->_endNode_);
			}

			const_iterator	begin() const
			{
				if (this->_root_ != nullptr)
					return (const_iterator(_treeMinimum(this->_root_)));
				return (this->_endNode_);
			}

			iterator	end()
			{
				return (iterator(this->_endNode_));
			}

			const_iterator	end() const
			{
				return (const_iterator(this->_endNode_));
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

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
			
			// Tree size:
			size_type	size()
			{
				return (this->_size);
			}
			
			// Find operation for the tree :
			_nodePtr	find(const _valueType& _pair)
			{
				_nodePtr	_curr = this->_root_;

				while (_curr != nullptr)
				{
					if (!this->_comp(_pair, _curr->_pair) && !this->_comp(_curr->_pair, _pair))
						break ;
					_curr = this->_comp(_pair, _curr->pair) ? _curr->left : _curr->right;
				}
				return (_curr);
			}

			// Insertion method :
			void	_insert_(const _valueType& _pair)
			{
				
			}
			
			
	};
	
};


#endif
