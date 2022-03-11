/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _RBT_.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:01:47 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/11 21:50:28 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RED-BLACK TREE.
#ifndef _RBT__HPP
#define _RBT__HPP

# include "_iter_.hpp"
# include <iostream>
# include <iomanip>
# include <limits>

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
		tree_node(value_type _dt): _pair(_dt), _parent(nullptr), _left(nullptr), _right(nullptr), _color(_RED_) { }
	};

	// Tree iterator :
	template<typename _pairType, typename _nodetype>
	class	tree_iterator
	{
		public:
			typedef _pairType										value_type;
			typedef	_nodetype										iterator_type; //tree_node<_>
			typedef _pairType*										pointer;
			typedef _pairType&										reference;
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef tree_iterator<_pairType, _nodetype>				_self;
		
		private:
			iterator_type	_curr;
			
		public:
			
			tree_iterator() : _curr() { }

			tree_iterator(iterator_type iter) : _curr(iter) { }

			template<typename T, typename N>
			tree_iterator(const tree_iterator<T, N>& iter) : _curr(iter.base()) { }
			
			template<typename T, typename N>
			tree_iterator&	operator = (const tree_iterator<T, N>& iter)
			{
				this->_curr = iter.base();
				return (*this);
			}
			
			~tree_iterator() { }

			iterator_type	base() const { return (this->_curr); }

			reference	operator *() const { return (this->_curr->_pair); }

			iterator_type	_get_node_() const { return (this->_curr); }

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

				// this->_curr = next(this->_curr);
				++(*this);
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

				--(*this);
				return (_tmp);
			}

			template<typename T,typename N>
			bool	operator == (const tree_iterator<T, N>& cmp)
			{
				return (this->_curr == cmp.base());
			}

			template<typename T, typename N>
			bool	operator != (const tree_iterator<T, N>& cmp)
			{
				return (this->_curr != cmp.base());
			}

			private:

				iterator_type	prev(iterator_type _currNode)
				{
					if (_currNode->_left != nullptr)
					{
						_currNode = _currNode->_left;
						while (_currNode->_right != nullptr)
							_currNode = _currNode->_right;
						return (_currNode);
					}
					else
					{
						iterator_type _tmp = _currNode->_parent;
						while (_tmp != nullptr && _currNode == _tmp->_left)
						{
							_currNode = _tmp;
							_tmp = _tmp->_parent;
						}
						return (_tmp);
					}
				}

				iterator_type	next(iterator_type _currNode)
				{
					if (_currNode->_right != nullptr)
					{
						_currNode = _currNode->_right;
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
	// template<typename _pairType>
	// class	tree_const_iterator
	// {
	// 	public:
			
	// 		typedef	_pairType										iterator_type;
	// 		typedef const _pairType*								pointer;
	// 		typedef const _pairType&								reference;
	// 		typedef std::bidirectional_iterator_tag					iterator_category;
	// 		typedef std::ptrdiff_t									difference_type;
	// 		typedef tree_iterator<_pairType>						_self;
	// 		typedef	typename tree_node<_pairType>::_nodePtr			_node;
		
	// 	private:
	// 		_node	_curr;
			
	// 	public:
			
	// 		tree_const_iterator() : _curr() { }

	// 		tree_const_iterator(iterator_type iter) : _curr(iter) { }

	// 		template<typename T>
	// 		tree_const_iterator(const tree_const_iterator<T>& iter) : _curr(iter.base()) { }
			
	// 		template<typename T>
	// 		tree_const_iterator&	operator = (const tree_const_iterator<T>& iter)
	// 		{
	// 			this->_curr = iter.base();
	// 			return (*this);
	// 		}
			
	// 		~tree_const_iterator() { }

	// 		iterator_type	base() const { return (this->_curr); }

	// 		reference	operator *( ) const { return (this->_curr->_pair); }

	// 		_node	_get_node_() const { return (this->_curr); }

	// 		pointer		operator ->() const { return (&(operator *())); }

	// 		// Pre increment :
	// 		_self	operator++() 
	// 		{
	// 			this->_curr = next(this->_curr);
	// 			return (*this);
	// 		}

	// 		// Post increment :
	// 		_self	operator++(int)
	// 		{
	// 			tree_const_iterator	_tmp(*this);

	// 			this->_curr = next(this->_curr);
	// 			return (_tmp);
	// 		}

	// 		_self	operator--()
	// 		{
	// 			this->_curr = prev(this->_curr);
	// 			return (*this);
	// 		}

	// 		_self	operator--(int)
	// 		{
	// 			tree_const_iterator	_tmp(*this);

	// 			this->_curr = prev(this->_curr);
	// 			return (_tmp);
	// 		}

	// 		template<typename It>
	// 		bool	operator == (const tree_const_iterator<It>& cmp)
	// 		{
	// 			return (this->_curr == cmp.base());
	// 		}

	// 		template<typename It>
	// 		bool	operator != (const tree_const_iterator<It>& cmp)
	// 		{
	// 			return (this->_curr != cmp.base());
	// 		}

	// 		private:

	// 			_node	prev(_node _currNode)
	// 			{
	// 				if (_currNode->_left != nullptr)
	// 				{
	// 					while (_currNode->_right != nullptr)
	// 						_currNode = _currNode->_right;
	// 					return (_currNode);
	// 				}
	// 				else
	// 				{
	// 					_node _tmp = _currNode->_parent;
	// 					while (_tmp != nullptr && _currNode == _tmp->_left)
	// 					{
	// 						_currNode = _tmp;
	// 						_tmp = _tmp->_parent;
	// 					}
	// 					return (_tmp);
	// 				}
	// 			}

	// 			_node	next(_node _currNode)
	// 			{
	// 				if (_currNode->_right != nullptr)
	// 				{
	// 					while (_currNode->_left != nullptr)
	// 						_currNode = _currNode->_left;
	// 					return (_currNode);
	// 				}
	// 				else
	// 				{
	// 					_node	_tmp = _currNode->_parent;
	// 					while (_tmp != nullptr && _currNode == _tmp->_right)
	// 					{
	// 						_currNode = _tmp;
	// 						_tmp = _tmp->_parent;
	// 					}
	// 					return (_tmp);
	// 				}
	// 			}
			
	// }; // END! TREE ITERATOR .



	// RED BLACK TREE TEMPLATE CLASS :
	template<typename Key, typename _pairValue, typename _Alloc,typename _Compare = std::less<_pairValue> >
	class	_rbTree_{
		
		public:
			typedef		_pairValue														_valueType;
			typedef 	struct tree_node<_pairValue>											_node;
			typedef	_node*																_nodePtr;
			typedef		Key																key_type;
			
			// for holding another allocator for the tree_node type
			typedef typename _Alloc::template rebind<tree_node<_valueType> >::other		allocator_type; 
			
			typedef typename	_Alloc::pointer											_allocPtr;
			typedef typename	_Alloc::const_pointer									_allocConstPtr;
			typedef typename	_Alloc::reference										_allocRef;
			typedef typename	_Alloc::const_reference									_allocConstRef;
			typedef		_Compare														_valueCompare;
			typedef		tree_iterator<_valueType, _nodePtr>											iterator;
			typedef		tree_iterator<const _valueType, _nodePtr>									const_iterator; // tree_iterator<const _nodePtr>
			typedef		ft::_reverseIter<iterator>										reverse_iterator;
			typedef		ft::_reverseIter<const_iterator>								const_reverse_iterator;
			typedef	size_t																size_type;
			typedef std::ptrdiff_t														difference_type;

		private:
			_nodePtr		_root_;
			_nodePtr		_endNode_;
			allocator_type	_alloc;
			_valueCompare	_comp_;
			size_type		_size;

			// Function to create new nodes :
			_nodePtr	_createNewNode_(_valueType _pair = _valueType())
			{
				_nodePtr	_new = _alloc.allocate(1);
				
				_alloc.construct(_new, _pair);
				return (_new);
			}

			// Check if the node is  a left child:
			bool	_isLeftChild_(_nodePtr _node)
			{
				// Check first if the parent exist !!
				// if (_node && _node->_parent)
				return (_node == _node->_parent->_left);
				// return false;
			}
			
			// Tree's node min and max :
			_nodePtr	_treeMinimum_(_nodePtr _node) const
			{
				while (_node->_left != nullptr)
					_node = _node->_left;
				return (_node);
			}
			_nodePtr	_treeMaximum_(_nodePtr _node) const
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
				if (_nodeY->_left != nullptr)
					_nodeY->_left->_parent = _nodeX;
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
				if (_nodeY->_right != nullptr)
					_nodeY->_right->_parent = _nodeX;
				_nodeY->_parent = _nodeX->_parent;
				if (_nodeX->_parent == nullptr)
					this->_root_ = _nodeY;
				else if (!_isLeftChild_(_nodeX))
					_nodeX->_parent->_right = _nodeY;
				else
					_nodeX->_parent->_left = _nodeY;
				_nodeY->_right = _nodeX;
				_nodeX->_parent = _nodeY;
			}

			_nodePtr	prev(_nodePtr _currNode)
			{
				if (_currNode->_left != nullptr)
					return (this->_treeMaximum_(_currNode->_left));
				_nodePtr _tmp = _currNode->_parent;
				while (_tmp != nullptr && _currNode == _tmp->_left)
				{
					_currNode = _tmp;
					_tmp = _tmp->_parent;
				}
				return (_tmp);
			}

			_nodePtr	next(_nodePtr _currNode)
			{
				if (_currNode->_right != nullptr)
					return (this->_treeMinimum_(_currNode->_right));
				_nodePtr	_tmp = _currNode->_parent;
				while (_tmp != nullptr && _currNode == _tmp->_right)
				{
					_currNode = _tmp;
					_tmp = _tmp->_parent;
				}
				return (_tmp);
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
			_rbTree_(_valueCompare compare, allocator_type allocator): _root_(nullptr), _alloc(allocator), _comp_(compare), _size(0)
			{
				this->_endNode_ = this->_createNewNode_();
			}

			_rbTree_(const _rbTree_& tree):_alloc(tree._alloc), _comp_(tree.value_comp()), _size(0)
			{
				*this = tree;
			}

			_rbTree_&	operator = (const _rbTree_&	tree)
			{
				if (this != &tree)
				{
					this->clear();
					this->_comp_ = tree.value_comp();
					this->_alloc = tree._alloc;
					iterator iter = tree.begin();
					while (iter != tree.end())
						this->_insert_(*iter++);
				}
				return (*this);
			}

			~_rbTree_()
			{
				this->clear();
				this->_alloc.destroy(this->_endNode_);
				this->_alloc.deallocate(this->_endNode_, 1);
			}
			

			// Iterators:
			iterator	begin()
			{
				if (this->_root_ != nullptr)
					return (iterator(_treeMinimum_(this->_root_)));
				return (iterator(this->_endNode_));
			}

			iterator	end()
			{
				return (iterator(this->_endNode_));
			}
			
			const_iterator	begin() const
			{
				if (this->_root_ != nullptr)
					return (const_iterator(_treeMinimum_(this->_root_)));
				return (const_iterator(this->_endNode_));
			}

			const_iterator	end() const
			{
				return (const_iterator(this->_endNode_));
			}
			
			// Tree size:
			size_type	size()
			{
				return (this->_size);
			}

			size_type	max_size() const
			{
				return (std::min<size_type>(this->_alloc.max_size(), std::numeric_limits<difference_type>::max()));
			}

			// Return compare :
			_valueCompare value_comp() const
			{
				return this->_comp_;
			}

			// Upper Bound : returns first node whose key is greater than searching key.
			iterator	upper_bound(const _valueType& key)
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

				while(_tmp_ != nullptr)
				{
					if (this->_comp_(key, _tmp_->_pair))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return iterator(_res_);				
			}
			
			const_iterator	upper_bound(const _valueType& key) const
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

				while(_tmp_ != nullptr)
				{
					if (this->_comp_(key, _tmp_->_pair))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return (const_iterator(_res_));
			}

			// Lower bound : similar with upper_bound but for the case of key = searching key lower_b returns key 
			// whereas upper return the next key (node)
			iterator	lower_bound(const _valueType& key)
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;

				while(_tmp_ != nullptr)
				{
					if (!this->_comp_(_tmp_->_pair, key))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return (iterator(_res_));
			}

			const_iterator	lower_bound(const _valueType& key) const
			{
				_nodePtr	_tmp_ = this->_root_;
				_nodePtr	_res_ = this->_endNode_;
				
				while(_tmp_ != nullptr)
				{
					if (!this->_comp_(_tmp_->_pair, key))
					{
						_res_ = _tmp_;
						_tmp_ = _tmp_->_left;
					}
					else
						_tmp_ = _tmp_->_right;
				}
				return (const_iterator(_res_));
			}

			// Swap :
			void	swap(_rbTree_& tree)
			{
				std::swap(this->_endNode_, tree._endNode_);
				std::swap(this->_root_, tree._root_);
				std::swap(this->_alloc, tree._alloc);
				std::swap(this->_comp_, tree._comp_);
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
			_nodePtr	find(const _valueType& _pair)  const
			{
				_nodePtr	_curr = this->_root_;

				while (_curr != nullptr)
				{
					if (!this->_comp_(_pair, _curr->_pair) && !this->_comp_(_curr->_pair, _pair))
						break ;
					_curr = this->_comp_(_curr->_pair, _pair) ? _curr->_right : _curr->_left;
				}
				return (_curr);
			}
	
			// Insertion method :
			void	_insert_(_valueType _pair)
			{
				_nodePtr _newNode = _createNewNode_(_pair);
				if (this->_root_ == nullptr)
				{
					this->_root_ = _newNode;
					this->_root_->_color = _BLACK_;
					this->_size++;
					this->_root_->_parent = this->_endNode_;
					this->_endNode_->_left = this->_root_;
					return ;
				}
				
				_nodePtr _tmp = this->_root_;
				_nodePtr _newNodeParent = nullptr;
				this->_endNode_->_left = nullptr;
				this->_root_->_parent = nullptr;
				while (_tmp != nullptr)
				{
					_newNodeParent = _tmp;
					if (!this->_comp_(_newNode->_pair, _tmp->_pair) && !this->_comp_(_tmp->_pair, _newNode->_pair))
						return ; // in case of duplicates
					_tmp = (this->_comp_(_newNode->_pair, _tmp->_pair) ? _tmp->_left : _tmp->_right);
					_newNode->_parent = _newNodeParent; // link the parent for the new node 
				}
				if (this->_comp_(_newNode->_pair, _newNodeParent->_pair)) // find where to put the newnode for parent's POV
					_newNodeParent->_left = _newNode;
				else
					_newNodeParent->_right = _newNode;
				_newNode->_color = _RED_;
				this->_fixAfterInsertion_(_newNode);
				this->_size++;
				this->_endNode_->_left = this->_root_;
				this->_root_->_parent = this->_endNode_;
			}

			// Balancing the tree after insertion :
			void	_fixAfterInsertion_(_nodePtr _fixingNode)
			{
				// Fixing for (red node cannot have red children):
				while (_fixingNode->_parent != nullptr && _fixingNode->_parent->_color == _RED_)
				{
					if (_isLeftChild_(_fixingNode->_parent))
					{

						_nodePtr	_parentSibling = _fixingNode->_parent->_parent->_right;
						if (_parentSibling != nullptr && _parentSibling->_color == _RED_)
						{
							// Case 1 : Parent(isLeftChild) , ParentSibling(isRed) , newNodeLocation(does not matter) {
								// Change the color of the parent and the parent's sibling to black ,
								// change the color of the grandparent to red ,
								// move the current location to the grandparent (points to the grandparent(theNewFixingNode) to continue fixing ...)
							// }
							_parentSibling->_color = _BLACK_;
							_fixingNode->_parent->_color = _BLACK_;
							_fixingNode->_parent->_parent->_color = _RED_;
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
							_fixingNode->_parent->_parent->_color = _RED_;
							this->_rightRotate_(_fixingNode->_parent->_parent);
							break ;
						}
					}
					else
					{
						// std::cout << "------------------else\n";
						_nodePtr	_parentSibling = _fixingNode->_parent->_parent->_left;
						if (_parentSibling != nullptr && _parentSibling->_color == _RED_)
						{
							// Case 4 : Parent(isRightChild) , ParentSibling(isRed) , newNodeLocation(does not matter)
								// change the color of the parent and the parent's siblings to black
								// change the color of the grandparent to red .
								// move the current location to the grandparent ... continue fixing...
							_fixingNode->_parent->_color = _BLACK_;
							_parentSibling->_color = _BLACK_;
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
							// std::cout << "tara\n";
							_fixingNode->_parent->_color = _BLACK_;
							_fixingNode->_parent->_parent->_color = _RED_;
							this->_leftRotate_(_fixingNode->_parent->_parent);
							break ;
						}
					}
				}
				this->_root_->_color = _BLACK_;
			}


			// Replace the deleting node to its replacement.
			void	_replace_(_nodePtr	_deletingNode_, _nodePtr	_replacingNode_)
			{
				if (_deletingNode_->_parent == nullptr)
					this->_root_ = _replacingNode_;
				else if (this->_isLeftChild_(_deletingNode_))
					_deletingNode_->_parent->_left = _replacingNode_;
				else
					_deletingNode_->_parent->_right = _replacingNode_;
				if (_replacingNode_ != nullptr)
					_replacingNode_->_parent = _deletingNode_->_parent;
			}
		
			// Delete :
			void	_delete_(const _valueType&	_delKey_)
			{
				_nodePtr	_deletingNode_ = nullptr;
				_nodePtr	_replacingNode_ = nullptr;
				bool		_delColor_;
				

				_deletingNode_ = this->find(_delKey_);
				if (!this->_root_ || _deletingNode_ == nullptr)
					return ;
				// std::cout << "DELETED ----[ "<< _deletingNode_->_pair.first << " ]----\n";
				// Detach the Endnode until we fix the tree.
				this->_endNode_->_left = nullptr;
				this->_root_->_parent = nullptr;
				_delColor_ = _deletingNode_->_color;
				if (_deletingNode_->_left == nullptr) // case of no children or only one right child.
				{
					_replacingNode_ = _deletingNode_->_right;
					this->_replace_(_deletingNode_, _deletingNode_->_right);
					this->_alloc.destroy(_deletingNode_);
					this->_alloc.deallocate(_deletingNode_, 1);
					if (_delColor_ == _BLACK_ && _replacingNode_ != nullptr)
						this->_fixAfterDeletion_(_replacingNode_);
				}// For case 1 and case 2 we fix if the deleting node is black.
				else if (_deletingNode_->_right == nullptr) // only one left child .
				{
					_replacingNode_ = _deletingNode_->_left;
					this->_replace_(_deletingNode_, _deletingNode_->_left);
					this->_alloc.destroy(_deletingNode_);
					this->_alloc.deallocate(_deletingNode_, 1);
					if (_delColor_ == _BLACK_ && _replacingNode_ != nullptr)
						this->_fixAfterDeletion_(_replacingNode_);
				}
				else // Case of two children. We fix if the replacing node is black.
				{
					_replacingNode_ = this->_treeMinimum_(_deletingNode_->_right);
					_delColor_ = _replacingNode_->_color;
					_nodePtr _reReplacement_ = _replacingNode_->_right;
					if (_replacingNode_->_parent != nullptr && _replacingNode_->_parent != _deletingNode_) // In case of the replacing node is not the direct child of the deleting node.parent. 
					{
						this->_replace_(_replacingNode_, _replacingNode_->_right);
						_replacingNode_->_right = _deletingNode_->_right;
						_replacingNode_->_right->_parent = _replacingNode_;
					}
					this->_replace_(_deletingNode_, _replacingNode_);
					_replacingNode_->_left = _deletingNode_->_left;
					_replacingNode_->_left->_parent = _replacingNode_;
					_replacingNode_->_color = _deletingNode_->_color;
					this->_alloc.destroy(_deletingNode_);
					this->_alloc.deallocate(_deletingNode_, 1);
					if (_delColor_ == _BLACK_ && _reReplacement_ != nullptr)
						this->_fixAfterDeletion_(_reReplacement_);
				}
				if (this->_root_ != nullptr)
				{
					this->_endNode_->_left = this->_root_;
					this->_root_->_parent = this->_endNode_;
				}
				this->_size--;
				
			}

			void	_fixAfterDeletion_(_nodePtr	_current)
			{
				while (_current != this->_root_ && _current->_color == _BLACK_)
				{
					// The fixing node is leftChild.
					if (_current != nullptr && this->_isLeftChild_(_current))
					{
						_nodePtr	_sibling_ = _current->_parent->_right;
						
						// Case 1: The siblingColor is Red, it doesn't matter the color of its children.
						if (_sibling_ != nullptr && _sibling_->_color == _RED_)
						{
							_sibling_->_color = _BLACK_;
							_current->_parent->_color = _RED_;
							this->_leftRotate_(_current->_parent);
							_sibling_ = _current->_parent->_right;
						}// Case 2: The siblingColor and the color of its children is Black.
						if (_sibling_ != nullptr && _sibling_->_color == _BLACK_
												&& _sibling_->_left->_color == _BLACK_
												&& _sibling_->_right->_color == _BLACK_)
						{
							_sibling_->_color = _RED_;
							_current = _current->_parent;
						}
						else
						{	// Case 3: The siblingColor is Black and its rightChild's color is Black leftChild(Red).
							if (_sibling_->_right->_color == _BLACK_)
							{
								_sibling_->_left->_color = _BLACK_;
								_sibling_->_color = _RED_;
								this->_rightRotate_(_sibling_);
							}
							// Case 4: The siblingColor is Black and its rightChild is Red.
							_sibling_->_color = _current->_parent->_color;
							_current->_parent->_color = _BLACK_;
							_sibling_->_right->_color = _BLACK_;
							this->_leftRotate_(_current->_parent);
							_current = this->_root_;
							// All the violated RBT properties restored.
						}
					}
					else // Fixing node is rightChild . 
					{
						_nodePtr _sibling_ = _current->_parent->_left;
						
						// Case 5: the siblingColor is Red, same thing with case 1 with small change.
						if (_sibling_ != nullptr && _sibling_->_color == _RED_)
						{
							_sibling_->_color = _BLACK_;
							_current->_parent->_color = _RED_;
							this->_rightRotate_(_current->_parent);
							_sibling_ = _current->_parent->_left;
						} // Case 6: Like Case 2.
						if (_sibling_ != nullptr && _sibling_->_color == _BLACK_
												&& _sibling_->_right->_color == _BLACK_
												&& _sibling_->_left->_color == _BLACK_)
						{
							_sibling_->_color = _RED_;
							_current = _current->_parent;
						}
						else
						{
							// Case 7: Like case 3, perform leftRot instead of rightRot.
							if (_sibling_->_left->_color == _BLACK_)
							{
								_sibling_->_right->_color = _BLACK_;
								_sibling_->_color = _RED_;
								this->_leftRotate_(_sibling_);
							}
							// Case 8: Like Case 4, peform rightRot instead of leftRot.
							_sibling_->_color = _current->_parent->_color;
							_current->_parent->_color = _BLACK_;
							_sibling_->_left->_color = _BLACK_;
							this->_rightRotate_(_current->_parent);
							_current = this->_root_;
							// All the violated RBT properties restored.
						}
					}
				}
				_current->_color = _BLACK_;
			}
			
			void __print_tree(_nodePtr node, int indent)
			{
				if (node) 
				{
					if (node->_right)
						__print_tree(node->_right, indent + 4);
					if (indent)
						std::cout << std::setw(indent) << ' ';
					if (node->_right) std::cout << " /\n" << std::setw(indent) << ' ';
					{
						std::string str = (node->_color) ? "BLACK" : "RED";
						std::cout << node->_pair.first << "|" << str << std::endl;
					}
					if (node->_pair.first)
					{
						std::cout << std::setw(indent) << ' ' << " \\\n";
						__print_tree(node->_left, indent + 4);
					}
				}
			}
			
			void __print_tree()
			{
				if (this->_root_ == nullptr)
					return ;
				__print_tree(this->_root_, 0);
			}
	}; // END RED BLACK TREE !!

	
}; // END FT NAMESPACE


#endif
