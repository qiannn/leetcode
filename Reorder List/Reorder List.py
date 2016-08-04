# Definition for singly-linked list.
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def reorderList(self, head):
		"""
		:type head: ListNode
		:rtype: void Do not return anything, modify head in-place instead.
		"""
		if head == None : return
		p = head

		nodelist = []
		while p != None :
			nodelist.append(p)
			p = p.next

		start ,end = 0, len(nodelist) - 1
		while start < end :
			nodelist[end - 1].next = None
			nodelist[end].next = nodelist[start].next
			nodelist[start].next = nodelist[end]
			start += 1
			end -= 1

def makelist(end, newnode):
	end.next = newnode
	return newnode

def main():
	solution = Solution()

	list = [ListNode(x) for x in range(1,10)]
	reduce(makelist, list)
	head = list[0]

	solution.reorderList(head)
	node = head
	while node != None :
		print node.val
		node = node.next

if __name__ == '__main__':
	main()