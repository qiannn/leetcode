# Definition for a binary tree node.
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution(object):
	def isBalanced(self, root):
		"""
		:type root: TreeNode
		:rtype: bool
		"""
		Solution.result = True
		self.DfsHelper(root)
		return Solution.result
		

	def DfsHelper(self, root):
		if root is None:
			return 0
			
		left = self.DfsHelper(root.left)
		right = self.DfsHelper(root.right)

		if abs(left - right) > 1:
			Solution.result = False

		return max(left, right) + 1

def main():
	s = Solution()
	node1 = TreeNode(1)
	node2 = TreeNode(2)
	node3 = TreeNode(3)
	node4 = TreeNode(4)
	node5 = TreeNode(5)

	node1.left = node2
	node1.right = node3

	node2.left = node4
	node4.left = node5

	print s.isBalanced(node1)

if __name__ == '__main__':
	main()