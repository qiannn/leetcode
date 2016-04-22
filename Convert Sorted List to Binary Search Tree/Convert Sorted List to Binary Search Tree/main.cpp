//
//  main.cpp
//  Convert Sorted List to Binary Search Tree
//
//  Created by apple on 15/12/3.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {};
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {};
};

vector<int> createArray(ListNode* head) {
    vector<int> v;
    while (head != NULL) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

TreeNode* toBST(vector<int>& nums, int start, int end) {
    TreeNode* root = NULL;
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    root = new TreeNode(nums[mid]);
    root->left = toBST(nums, start, mid - 1);
    root->right = toBST(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = NULL;
    root = toBST(nums, 0, nums.size() - 1);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    TreeNode* root = NULL;
    vector<int> nums;
    nums = createArray(head);
    root = sortedArrayToBST(nums);
    return root;
}

void levelTraversal(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node != NULL) {
            std::cout << node->val << std::endl;
            q.push(node->left);
            q.push(node->right);
        }
    }
}

ListNode* createList() {
    int vals[] = {1,2,3,4,5,6,7,8,9};
    ListNode* head = NULL;
    ListNode* node = NULL;
    for (int i = 0; i < 9; i ++) {
        if (i == 0) {
            head = new ListNode(vals[i]);
            node = head;
        }
        else {
            node->next = new ListNode(vals[i]);
            node = node->next;
        }
    }
    node->next = NULL;
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* root = createList();
    levelTraversal(sortedListToBST(root));
    return 0;
}
