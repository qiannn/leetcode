//
//  main.cpp
//  Populating Next Right Pointers in Each Node II
//
//  Created by apple on 16/8/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

//  Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    /*
    void connect(TreeLinkNode *root) {
        if (!root || (!root->left && !root->right))
            return;
        queue<TreeLinkNode*> q1, q2;
        q1.push(root);
        
        while(!q1.empty() || !q2.empty()) {
            queue<TreeLinkNode*>& Queue = q1.empty() ? q2 : q1;
            queue<TreeLinkNode*>& emptyQueue = q1.empty() ? q1 : q2;
            
            while (!Queue.empty()) {
                TreeLinkNode* pNode = Queue.front();
                Queue.pop();
                if (pNode->left)
                    emptyQueue.push(pNode->left);
                if (pNode->right)
                    emptyQueue.push(pNode->right);
                
                pNode->next = Queue.empty() ? NULL : Queue.front();
            }
        }
    }
    */
    
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *next = NULL;
            TreeLinkNode *prev = NULL;
            
            for (; root; root = root->next) {
                if (!next)
                    next = root->left ? root->left : root->right;
                
                if (root->left) {
                    if (prev)
                        prev->next = root->left;
                    prev = root->left;
                }
                if (root->right) {
                    if (prev)
                        prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *leftnode = new TreeLinkNode(2);
    TreeLinkNode *rightnode = new TreeLinkNode(3);
    
    root->left = leftnode;
    root->right = rightnode;
    Solution s;
    
    s.connect(root);
    
    queue<TreeLinkNode*> q;
    q.push(root);
    
    cout << leftnode->next->val << endl;
    return 0;
}
