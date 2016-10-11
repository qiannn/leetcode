# Definition for singly-linked list.
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def reverseBetween(self, head, m, n):
		"""
		:type head: ListNode
		:type m: int
		:type n: int
		:rtype: ListNode
		"""
		phead = ListNode(0)
		phead.next = head
		count = 1

		p, q = phead, phead
		while count < m:
			p = p.next
			q = q.next
			count += 1

		q = q.next
		while count < n:
			qnext = q.next
			q.next = qnext.next

			qnext.next = p.next
			p.next = qnext
			count += 1
		return phead.next

def main():
	s = Solution()
	node1 = ListNode(1)
	node2 = ListNode(2)
	node3 = ListNode(3)
	node4 = ListNode(4)
	node5 = ListNode(5)

	node1.next = node2
	node2.next = node3
	node3.next = node4
	node4.next = node5

	newlist = s.reverseBetween(node1, 2, 4)
	while newlist:
		print newlist.val
		newlist = newlist.next


if __name__ == '__main__':
	main()