class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def swapPairs(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		if head == None or head.next == None: return head
		firstnode = head
		nextnode = head.next

		firstnode.next = nextnode.next
		nextnode.next = firstnode

		firstnode.next = self.swapPairs(firstnode.next)
		return nextnode

def main():
	list = [ListNode(x) for x in xrange(10)]
	cur = list[0]
	for node in list[1:]:
		cur.next = node
		cur = node
	solution = Solution()
	p = solution.swapPairs(list[0])
	p = solution.swapPairs(ListNode(1))
	#p = list[0]
	while p != None:
		print p.val
		p = p.next

if __name__ == '__main__':
	main()