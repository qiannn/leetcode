class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution(object):
	def __init__(self):
		self.flag = True

	def isSymmetric(self, root):
		"""
		:type root: TreeNode
		:rtype: bool
		"""
		if (root == None):
			return False
		self.Traversal(root.left, root.right)
		return self.flag

	def Traversal(self, leftnode, rightnode):
		if (leftnode == None and rightnode == None):
			return
		elif (leftnode != None and rightnode != None):
			if (leftnode.val != rightnode.val):
				self.flag = False
			else:
				self.Traversal(leftnode.left, rightnode.right)
				self.Traversal(leftnode.right, rightnode.left)
		else :
			self.flag = False


def main():
	solution = Solution()
	node1 = TreeNode(1)

	node2 = TreeNode(2)
	node3 = TreeNode(2)

	node4 = TreeNode(3)
	node5 = TreeNode(3)

	node6 = TreeNode(1)

	node1.left = node2
	node1.right = node3

	node2.left = node4

	node3.right = node5
	node3.left = node6
	if solution.isSymmetric(node1):
		print 'yes'
	else :
		print 'ops'

if __name__ == '__main__':
	main()