
class Node:
	
	def __init__(self, value):
		self.left = None
		self.right = None
		self.data = value

def inorder(root): # left subtree -> root -> right subtree
	if root:
		inorder(root.left)
		print("data " + str(root.data))
		inorder(root.right)

def preorder(root): # root -> left subtree -> right subtree
	if root:
		print("data : " + str(root.data))
		postorder(root.left)
		postorder(root.right)

def postorder(root): # left subtree -> right subtree -> root
	if root:
		preorder(root.left)
		preorder(root.right)
		print("data : " + str(root.data))

root = Node(1)
root.left = Node(2)
root.right = Node(3)
sub_tree_left = root.left
sub_tree_right = root.right
sub_tree_left.left = Node(11)
sub_tree_left.right = Node(22)
sub_tree_left.left.left = Node(111)
sub_tree_left.left.right = Node(222)

print(" ******************************** Inorder Traversal : ********************************")
inorder(root)
print(" ******************************** Postorder Traversal : ********************************")
postorder(root)
print(" ******************************** Preorder Traversal : ********************************")
preorder(root)

