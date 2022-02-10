/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbt.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:25:18 by abdait-m          #+#    #+#             */
/*   Updated: 2022/02/10 16:56:00 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# define _BLACK_ 1
# define _RED_ 2

template<typename Pair>
struct node{
	typedef	Pair		value_type;
	typedef	node<Pair>* node_ptr;
	

	value_type	_pair;
	bool		_color;
	node_ptr	_left;
	node_ptr	_parent;
	node_ptr	_right;

	node():_color(_BLACK_), _left(nullptr), _right(nullptr), _parent(nullptr) { }
	node(value_type _data):_pair(_data),_color(_BLACK_), _left(nullptr), _right(nullptr), _parent(nullptr) { }
	
};


template<typename Pair>
class rbt{

	public:
		typedef node<Pair>* node_ptr;

	private:
		node_ptr _root;
	
	public:
	/*

		**** Properties:
		[
			- Root is black 
			- New nodes are red
			- Leaf(Nulls) nodes are black
			- No two consecutive red nodes 
			- Same number of black nodes in each path
		]

		**** Rebalancing methods:
		[
			- check the color of each node : if a node violates any of the rules we manipulate the grandparent.
			- Black aunt ==> ROTATE.	[
												BLACK
												/	|
											 RED	RED
										]
										
			- Red aunt   ==> COLOR FLIP.	[
												 	 RED == (grandparent)
													/	|
									BLACK == (parent)	BLACK == (aunt)
											]
		]
		
		**** insert_method (new_node, parent_node) {
			compare the new node with the parent.
			- if the new node is less than the parent {
				- if the left child is null add the new node as a left child 
				- else return the insert method and left child as the new parent
			}
			else {
				same like left child.
			}
			after that check the color of the tree ---
			
		}

		**** check_color_method (node) {
			if (node == root)
				return
			if (!node.black && !black.parent.black) ==> Violation of two consecutive red nodes.
			{
				_correct_the_tree_(node);
			}
			check_color_method(node.parent);
		}
		**** _correct_the_tree_(node){
			
			//aunt is (grandparent.right) node.parent.parent.right
			if (node.parent.isleftchild)
			{
				// Rotate:
				if (node.parent.parent.right == nullptr && node.parent.parent.right.isblack)
					return (rotate(node));
				
				// ColorFlip:
				if (node.parent.parent.right != nullptr)
					node.parent.paernt.right.black = true;
				node.parent.parent.black = false;
				node.parent.black = true;
				return ;
			}
			// aunt is grandparent.left
			==> add code for  aunt == node.parent.parent.left
		}

		**** rotate_method(node){
			// node.isleftchild && node.parent.isleftchild == right rotation of the grandparent
			// node.isnotleftchild && node.parent.isnotleftchild == Left rotation rotation of the grandparent
			// node.isnotleftchild && node.parent.isleftchild == Left Right rotation (left rot of parent then right rot of grandparent)
			// node.isleftchild && node.parent.isnotleftchild == Right Left rotation (right rot of parent then left rot of grandparent)

			if (node.isleftchild)
			{
				if (node.parent.isleftchild)
				{
					_right_rotate_(node.parent.parent);
					// coloring then return ;
				}
				_right_left_rotation_(node.parent.parent);
				// coloring then return ;
			}
			// else handle the right child
		}

		**** _left_rotate_(gpnode){ // gpnode = grandparentnode
			Node<Pair> tempnode = gpnode.right;
			
			gpnode.right = tempnode.left;
			if (node.right != nullptr)
			{
				// update the parent
				gpnode.right.parent = gpnode;
				gpnode.right.isleft = false;
			}
			if (gpnode.parent == nullptr)
			{
				root = tempnode;
				temp.parent = nullptr;
			}
			else
			{
				tempnode.parent = gpnode.parent;
				if (gpnode.isleftchild)
				{
					tempnode.isleftchild = true;
					tempnode.parent.left = temp;
				}
				else
				{
					tempnode.isleftchild = false;
					tempnode.parent.right = tempnode;
				}
				tempnode.left = gpnode;
				node.isleftchild = true;
				gpnode.parent = temp;
			}
		}

		**** _right_rotate(gpnode){
			// same thing as leftrotate change left to right and vice versa
		}

		**** _left_right_rotate_(node)
		{
			_left_rotate_(node.left);
			return (_right_rotate_(node));
		}
		
		**** _right_left_rotate_(node)
		{
			// same thing as the prev method
		}
		
		**** delete_method
		**** rebalancing_method
	*/
};