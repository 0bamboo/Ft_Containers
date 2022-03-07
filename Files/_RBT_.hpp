/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _RBT_.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:01:47 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/07 12:52:45 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RED-BLACK TREE.
#ifndef _RBT__HPP
#define _RBT__HPP

# include "_iter_.hpp"
# include <iostream>

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
		tree_node(value_type _dt): _color(_RED_), _pair(_dt), _parent(nullptr), _left(nullptr), _right(nullptr) { }
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
			typedef	typename tree_node<_pairType>::_nodePtr			_node;// this the iterator type 
		
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

			iterator_type	base() const { return (tree_iterator(this->_curr)); }

			reference	operator *( ) const { return (this->_curr->_pair); }

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



	// RED BLACK TREE TEMPLATE CLASS :
	template<typename Key, typename _pairValue, typename _Compare, typename _Alloc>
	class	_rbTree_{
		
		public:
			typedef		_pairValue														_valueType;
			typedef 	tree_node<_pairValue>*											_nodePtr;
			typedef		Key																key_type;
			
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
			_nodePtr	_createNewNode_(_valueType _pair)
			{
				_nodePtr	_new = _alloc.allocate(1);
				
				_alloc.construct(_new, _pair);
				return (_new);
			}

			// Check if the node is  a left child:
			bool	_isLeftChild_(_nodePtr _node)
			{
				// Check first if the parent exist !!
				return (_node == _node->_parent->_left);
			}
			
			// Tree's node min and max :
			_nodePtr	_treeMinimum_(_nodePtr _node)
			{
				while (_node->_left != nullptr)
					_node = _node->_left;
				return (_node);
			}
			_nodePtr	_treeMaximum_(_nodePtr _node)
			{
				while (_node->_right != nullptr)
					_node = _node->_right;
				return (_node);
			}

			// Rotation :
			// Left rotation :
			// node.isRightChild and node.parent.isRightChild
			void	_leftRotate_(_nodePtr _nodeX) // _nodeX = grandparentnode 
			{
				_nodePtr _nodeY = _nodeX->_right;

				_nodeX->_right = _nodeY->_left; // Turn nodeY's subtree into nodeX's subtree
				if (_nodeX->_right != nullptr)
					_nodeX->_right->_parent = _nodeX;
				_nodeY->_parent = _nodeX->_parent;
				if (_nodeX->_parent == nullptr)
					this->_root_ = _nodeY; // add the end node -> to the new root
				else if (_isLeftChild_(_nodeX))
					_nodeX->_parent->_left = _nodeY;
				else
					_nodeX->_parent->_right = _nodeY;
				_nodeY->_left = _nodeX;
				_nodeX->_parent = _nodeY;
			}

			// Right rotation :
			// node.isLeftChild and node.parent.isLeftChild
			void	_rightRotate_(_nodePtr _nodeX) // _nodeX = grandparentnode
			{
				_nodePtr _nodeY = _nodeX->_left;

				_nodeX->_left = _nodeY->_right;
				if (_nodeX->_left != nullptr)
					_nodeX->_left->_parent = _nodeX;
				_nodeY->_parent = _nodeX->_parent;
				if (_nodeX->_parent == nullptr)
					this->_root = _nodeY;
				else if (_isLeftChild_(_nodeX))
					_nodeX->_parent->_left = _nodeY;
				else
					_nodeX->_parent->_right = _nodeY;
				_nodeY->_right = _nodeX;
				_nodeX->_parent = _nodeY;
			}

			_nodePtr	prev(_nodePtr _currNode)
			{
				if (_currNode->_left != nullptr)
				{
					while (_currNode->_right != nullptr)
						_currNode = _currNode->_right;
					return (_currNode);
				}
				else
				{
					_nodePtr _tmp = _currNode->_parent;
					while (_tmp != nullptr && _currNode == _tmp->_left)
					{
						_currNode = _tmp;
						_tmp = _tmp->_parent;
					}
					return (_tmp);
				}
			}

			_nodePtr	next(_nodePtr _currNode)
			{
				if (_currNode->_right != nullptr)
				{
					while (_currNode->_left != nullptr)
						_currNode = _currNode->_left;
					return (_currNode);
				}
				else
				{
					_nodePtr	_tmp = _currNode->_parent;
					while (_tmp != nullptr && _currNode == _tmp->_right)
					{
						_currNode = _tmp;
						_tmp = _tmp->_parent;
					}
					return (_tmp);
				}
			}
			void	_free_(_nodePtr _currNode_)
			{
				if (_currNode_ != nullptr)
				{
					this->_free_(_currNode_->_left);
					this->_free_(_currNode_->_right);
					this->_alloc.destroy(_currNode_);
					this->_alloc.deallocate(_currNode_, 1);
				}
			}

		public:

			// Constructors:
			_rbTree_(_valueCompare compare, allocator_type allocator): _root_(nullptr), _alloc(allocator), _comp(compare), _size(0)
			{
				// this->_endNode_ = this->_createNewNode_(bb);
			}

			_rbTree_(const _rbTree_& tree)
			{
				*this = tree;
			}

			_rbTree_&	operator = (const _rbTree_&	tree)
			{
				if (this != &tree)
				{
					this->clear();
					this->_comp = tree.value_comp();
					this->_alloc = tree._alloc;
					iterator iter = tree.begin();
					while (iter != iter.end())
						this->insert(*iter++);
				}
			}

			~_rbTree_()
			{
				this->clear();
				this->_alloc.destroy(this->_endNode_);
				this->_alloc.deallocate(this->_endNode_, 1);
			}
			

			// Iterators:
			_nodePtr	begin()
			{
				if (this->_root_ != nullptr)
					return (iterator(_treeMinimum(this->_root_)));
				return (this->_endNode_);
			}

			_nodePtr	end()
			{
				return (iterator(this->_endNode_));
			}
			
			// Tree size:
			size_type	size()
			{
				return (this->_size);
			}
			// Max size :
			size_type	max_size()
			{
				return (this->_alloc.max_size());
			}

			// Return compare :
			_valueCompare value_comp() const
			{
				return this->_comp;
			}

			// Upper Bound : returns first node whose key is greater than searching key.
			iterator	upper_bound(const key_type& key)
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

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
				return iterator(_tmp_);				
			}
			
			const_iterator	upper_bound(const key_type& key) const
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

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
				return const_iterator(_tmp_);
			}

			// Lower bound : similar with upper_bound but for the case of key = searching key lower_b returns key 
			// whereas upper return the next key (node)
			iterator	lower_bound(const key_type& key)
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

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
				return (iterator(_tmp_));
			}

			const_iterator	lower_bound(const key_type& key) const
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;
				
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
				return (const_iterator(_tmp_));
			}

			// Swap :
			void	swap(_rbTree_& tree)
			{
				std::swap(this->_endNode_, tree._endNode_);
				std::swap(this->_root_, tree._root_);
				std::swap(this->_alloc, tree._alloc);
				std::swap(this->_comp, tree._comp);
				std::swap(this->_size, tree._size);
			}

			// Clear :
			void	clear()
			{
				// delete everything ....
				this->_free_(this->_root_);
				this->_root_ = nullptr;
				this->_size = 0;
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
				_nodePtr _newNode = _createNewNode_(_pair);
				_nodePtr _tmp;
				_nodePtr _newNodeParent;

				if (this->_root_ == nullptr)
				{
					this->_root_ = _newNode;
					this->_root_->_color = _BLACK_;
					this->_size++;
					this->_parent = this->_endNode_;
					this->_endNode_->_left = this->_root_;
				}
				else
				{
					// in case of duplicates,
					if (this->find(_pair) != nullptr)
						return ;
					_tmp = this->_root_;
					while (_tmp != nullptr)
					{
						_newNodeParent = _tmp;
						_tmp = (this->_comp(_tmp->_pair, _pair) ? _tmp->_left : _tmp->_right);
					}
					_newNode->_parent = _newNodeParent; // link the parent for the new node 
					if (this->_comp(_pair, _newNodeParent->_pair)) // find where to put the newnode for parent's POV
						_newNodeParent->_left = _newNode;
					else
						_newNodeParent->_right = _newNode;
					this->_size++;
					this->_fixAfterInsertion_(_newNode);
					this->_endNode_->_left = this->_root_;
					this->_root_->_parent = this->_endNode_;
				}
			}

			// Balancing the tree after insertion :
			void	_fixAfterInsertion_(_nodePtr _fixingNode)
			{
				// Fixing for (red node cannot have red children):
				while (_fixingNode->_parent && _fixingNode->_color == _RED_)
				{
					if (_isLeftChild_(_fixingNode->_parent))
					{
						_nodePtr	_parentSibling = _fixingNode->_parent->_parent->_right;
						
						if (_parentSibling && _parentSibling->_color == _RED_)
						{
							// Case 1 : Parent(isLeftChild) , ParentSibling(isRed) , newNodeLocation(does not matter) {
								// Change the color of the parent and the parent's sibling to black ,
								// change the color of the grandparent to red ,
								// move the current location to the grandparent (points to the grandparent(theNewFixingNode) to continue fixing ...)
							// }
							_parentSibling->_color = _BLACK_;
							_fixingNode->_parent->_color = _BLACK_;
							_fixingNode->_parent->_parent = _RED_;
							_fixingNode = _fixingNode->_parent->_parent;
						}
						else
						{
							if (!_isLeftChild_(_fixingNode))
							{
								// Case 2 : Parent(isLeftChild) , ParentSibling(isBlack) , newNodeLocation(isRightChild) {
									// In this case we Perform the leftRotation on the parent (after rotation oldParent = thisParent), 
									// then we set the newFixingNode to oldParent 
									// This operation transfer Case 2 to Case 3 ...
								// }
								_fixingNode = _fixingNode->_parent;
								this->_leftRotate_(_fixingNode);
							}
							// Case 3 : Parent(isLeftChild) , ParentSibling(isBlack) , newNodeLocation(isLeftChild) {
								// Change the color of the parent to black ,
								// Change the color of the grandparent to red ,
								// Perform the rightRotation on the grandparent
							// }
							_fixingNode->_parent->_color = _BLACK_;
							_fixingNode->_parent->_parent = _RED_;
							this->_rightRotate_(_fixingNode->_parent->_parent);
							break ;
						}
					}
					else
					{
						_nodePtr	_parentSibling = _fixingNode->_parent->_parent->_left;

						if (_parentSibling && _parentSibling->_color == _RED_)
						{
							// Case 4 : Parent(isRightChild) , ParentSibling(isRed) , newNodeLocation(does not matter)
								// change the color of the parent and the parent's siblings to black
								// change the color of the grandparent to red .
								// move the current location to the grandparent ... continue fixing...
							_fixingNode->_parent = _BLACK_;
							_parentSibling = _BLACK_;
							_fixingNode->_parent->_parent->_color = _RED_;
							_fixingNode = _fixingNode->_parent->_parent;
						}
						else
						{
							if (_isLeftChild_(_fixingNode))
							{
								// Case 5 : Pa	rent(isRightChild) , ParentSibling(isBlack) , newNodeLocation(isLeftChild)
									// Perform the rightRotation on the parent (after rotation the new parent is fixingnode)
									// the fixingnode becomes the parent
									// this operation transfer case 5 to case 6.
								_fixingNode = _fixingNode->_parent;
								this->_rightRotate_(_fixingNode);
							}
							// Case 6 : Parent(isRightChild) , ParentSibling(isBlack) , newNodeLocation(isRightChild)
								// Change the color of the fixingnode's parent to black .
								// change the color of fixingnode's grandparent to red .
								// preform the leftRotation...
							_fixingNode->_parent->_color = _BLACK_;
							_fixingNode->_parent->_parent->_color = _RED_;
							this->_leftRotate_(_fixingNode->_parent->_parent);
							break ;
						}
					}
				}
				this->_root_->_color = _BLACK_;
			}


			// Transplant : if deleting node has no or only one child we use this method.
			void	_transplant_(_nodePtr	_deletingNode_, _nodePtr	_replacingNode_)
			{
				if (_deletingNode_->_parent == nullptr)
					this->_root = _replacingNode_;
				else if (this->_isLeftChild_(_deletingNode_))
					_deletingNode_->_parent->left = _replacingNode_;
				else
					_deletingNode_->_parent->_right = _replacingNode_;
				if (_replacingNode_ != nullptr)
					_replacingNode_->_parent = _deletingNode_->_parent;
			}
		
			// Delete :
			void	_delete_(_nodePtr	_deletingNode_)
			{
				(void)_deletingNode_;
			}

			/*
				void delete(value_type _data = value_type())
				{
					node_pointer _del_node;
					node_pointer _node_x;
					if (!this->_root || (_del_node = this->find(_data)) == nullptr)
						return ;
					this->_end->_left = nullptr;
					this->_root->_parent = nullptr;
					node_pointer _node_y = _del_node;
					bool _deleted_col = _node_y->_color;
					if (_del_node->_left == nullptr)
					{
						_node_x = _del_node->_right;
						this->shift(_del_node, _del_node->_right);
						_alloc.destroy(_del_node);
						_alloc.deallocate(_del_node, 1);
					}
					else if (_del_node->_right == nullptr)
					{

						_node_x = _del_node->_left;
						this->shift(_del_node, _del_node->_left);
						_alloc.destroy(_del_node);
						_alloc.deallocate(_del_node, 1);
					}
					else
					{
						_node_y = minimum(_del_node->_right);
						_deleted_col = _node_y->_color;
						_node_x = _node_y->_right;
						if (_node_y->_parent != nullptr && _node_y->_parent != _del_node)
						{
							this->shift(_node_y, _node_y->_right);
							_node_y->_right = _del_node->_right;
							_node_y->_right->_parent = _node_y;
						}
						this->shift(_del_node, _node_y);
						_node_y->_left = _del_node->_left;
						_node_y->_left->_parent = _node_y;
						_node_y->_color = _del_node->_color;
						_alloc.destroy(_del_node);
						_alloc.deallocate(_del_node, 1);
					}
					if (_deleted_col == BLACK && _node_x != nullptr)
						this->treeFixAfterRemove(_node_x);
					if (this->_root != nullptr)
					{
						this->_end->_left = this->_root;
						this->_root->_parent = this->_end;
					}
					this->_size--;
				}

				void fixdelete(node_pointer _node_x)
				{
					while (_node_x != this->_root && _node_x->_color == BLACK)
					{
						if (_node_x != nullptr && _node_x == _node_x->_parent->_left)
						{
							node_pointer _sibling = _node_x->_parent->_right;
							if (_sibling != nullptr && _sibling->_color == RED)
							{
								_sibling->_color = BLACK;
								_node_x->_parent->_color = RED;
								this->leftRotate(_node_x->_parent);
								_sibling = _node_x->_parent->_right;
							}
							if (_sibling != nullptr && _sibling->_color == BLACK
								&& _sibling->_left->_color == BLACK
								&& _sibling->_right->_color == BLACK)
							{
								_sibling->_color = RED;
								_node_x = _node_x->_parent;
							}
							else
							{
								if (_sibling->_right->_color == BLACK)
								{
									_sibling->_left->_color = BLACK;
									_sibling->_color = RED;
									this->rightRotate(_sibling);
								}
								_sibling->_color = _node_x->_parent->_color;
								_node_x->_parent->_color = BLACK;
								_sibling->_right->_color = BLACK;
								this->leftRotate(_node_x->_parent);
								_node_x = this->_root;
							}
						}
						else
						{
							node_pointer _sibling = _node_x->_parent->_left;
							if (_sibling != nullptr && _sibling->_color == RED)
							{
								_sibling->_color = BLACK;
								_node_x->_parent->_color = RED;
								this->rightRotate(_node_x->_parent);
								_sibling = _node_x->_parent->_left;
							}
							if (_sibling != nullptr && _sibling->_color == BLACK
								&& _sibling->_right->_color == BLACK
								&& _sibling->_left->_color == BLACK)
							{
								_sibling->_color = RED;
								_node_x = _node_x->_parent;
							}
							else
							{
								if (_sibling->_left->_color == BLACK)
								{
									_sibling->_right->_color = BLACK;
									_sibling->_color = RED;
									this->leftRotate(_sibling);
								}
								_sibling->_color = _node_x->_parent->_color;
								_node_x->_parent->_color = BLACK;
								_sibling->_left->_color = BLACK;
								this->rightRotate(_node_x->_parent);
								_node_x = this->_root;
							}
						}
					}
					_node_x->_color = BLACK;
				}
			};

			*/
			
	};
	
};


#endif
