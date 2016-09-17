#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.size() == 0)
			return NULL;

		ListNode* mergeList = new ListNode(0);
		ListNode* p = mergeList;

		for (int i = 0; i < lists.size(); ++i)
		{	
			p->next = lists[i];
			while (p->next)
			{
				p = p->next;
			}
		}
		return mergeSort(mergeList->next);
	}

	ListNode* mergeSort(ListNode* head)
	{
		if (!head)
			return NULL;
		if (!head->next)
			return head;

		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast->next)
		{
			fast = fast->next;
			if (fast->next)
				fast = fast->next;
			slow = slow->next;
		}

		ListNode* list1 = mergeSort(slow->next);
		slow->next = NULL;
		ListNode* list2 = mergeSort(head);

		return merge2Lists(list1, list2);
	}

	ListNode* merge2Lists(ListNode* list1, ListNode* list2)
	{
		if (!list1)
			return list2;
		if (!list2)
			return list1;

		ListNode* newList = new ListNode(0);
		ListNode* p = newList;
		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				p->next = list1;
				list1 = list1->next;
			}
			else
			{
				p->next = list2;
				list2 = list2->next;
			}
			p = p->next;
		}
		if (list1)
			p->next = list1;
		if (list2)
			p->next = list2;

		return newList->next;
	}

	void printList(ListNode* list)
	{
		while (list)
		{
			cout << list->val << endl;
			list = list->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	ListNode* list1 = new ListNode(1);
	ListNode* node2inlist1 = new ListNode(5);
	list1->next = node2inlist1;
	ListNode* list2 = new ListNode(2);
	ListNode* node2inlist2 = new ListNode(4);
	list2->next = node2inlist2;
	ListNode* list3 = new ListNode(3);

	vector<ListNode*> v = {list1, list2, list3};

	Solution s;

	ListNode* list = s.mergeKLists(v);
	s.printList(list);
	return 0;
}