# Definition for a binary tree node.
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution(object):
	def inorderTraversal(self, root):
		list = []
		self.traversal(root, list)
		return list

	def traversal(self, root, list):
		if (root == None) : return
		self.traversal(root.left, list)
		list.append(root.val)
		self.traversal(root.right, list)

def main() :
	solution = Solution()
	node1 = TreeNode(1)
	node2 = TreeNode(2)
	node3 = TreeNode(3)

	node1.left = node2
	#node2.left = node3

	print solution.inorderTraversal(node1)

if __name__ == '__main__':
	main()