class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return None
        if k == 0:
            return head

        p = head
        listLen = 0
        while p.next:
            p = p.next
            listLen += 1
        rightshift = listLen - k % listLen - 1
        p.next = head
        while rightshift:
            rightshift -= 1
            p = p.next
        newhead = p.next
        p.next = None
        return newhead

def main():
    pass

if __name__ == '__main__':
    main()
