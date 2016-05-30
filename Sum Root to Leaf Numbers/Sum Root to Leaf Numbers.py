# Definition for a binary tree node.
class TreeNode(object):
	 def __init__(self, x):
		 self.val = x
		 self.left = None
		 self.right = None

class Solution(object):
	def sumNumbers(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		if root == None:
			return 0

		return self.helper(root, 0)

	def helper(self, root, valSum):
		if root == None:
			return 0
		elif root.left == None and root.right == None:
			return root.val + valSum

		valSum = (valSum + root.val) * 10
		
		return self.helper(root.left, valSum) + self.helper(root.right, valSum)


def main():
	node1 = TreeNode(1)
	node2 = TreeNode(2)
	node3 = TreeNode(3)
	node4 = TreeNode(5)

	node1.left = node2
	node1.right = node3
	node2.left = node4

	s = Solution()

	print s.sumNumbers(node1)

if __name__ == '__main__':
	main()