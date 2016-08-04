#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* head, *end, *p = l1, *q = l2;
        if (p->val < q->val) {
            head = end = p;
            p = p->next;
        }
        else {
            head = end = q;
            q = q->next;
        }
        
        while (p && q) {
            if (p->val < q->val) {
                end->next = p;
                p = p->next;
            }
            else {
                end->next = q;
                q = q->next;
            }
            end = end->next;
        }
        if (p) {
            end->next = p;
        }
        if (q) {
            end->next = q;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}