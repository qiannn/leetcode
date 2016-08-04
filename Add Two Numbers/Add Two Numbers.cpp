#include <iostream>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode*p = l1;
		ListNode*q = l2;
		int carry = 0;
		ListNode* newlist = new ListNode(0);
		ListNode* head = newlist;
		while (p || q) {
			int val1 = p ? p->val : 0;
			int val2 = q ? q->val : 0;
			int sum = val1 + val2 + carry;
			
			std::cout << "val1:" << val1 << " " << "val2:" << val2 << std::endl;
			carry = sum > 9 ? 1 : 0;

			ListNode* newnode = new ListNode(sum % 10);
			newlist->next = newnode;
			newlist = newlist->next;
			p = p ? p->next : NULL;
			q = q ? q->next : NULL;
		}
		if (carry)
		{
			ListNode* endnode = new ListNode(1);
			newlist->next = endnode;
		}
		return head->next;
    }
};

int main(int argc, char const *argv[])
{
	ListNode* list1;
	ListNode* list2;

	ListNode* l1node1 = new ListNode(2);
	ListNode* l1node2 = new ListNode(4);
	ListNode* l1node3 = new ListNode(3);

	ListNode* l2node1 = new ListNode(5);
	ListNode* l2node2 = new ListNode(6);
	ListNode* l2node3 = new ListNode(3);
	ListNode* l2node4 = new ListNode(6);

	l1node1->next = l1node2;
	l1node2->next = l1node3;

	l2node1->next = l2node2;
	l2node2->next = l2node3;
	l2node3->next = l2node4;

	list1 = l1node1;
	list2 = l2node1;

	Solution s;
	ListNode* psum = s.addTwoNumbers(list1, list2);
	while (psum) {
		std::cout << psum->val << std::endl;
		psum = psum->next;
	}
	return 0;
}