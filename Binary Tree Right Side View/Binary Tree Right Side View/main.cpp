//
//  main.cpp
//  Binary Tree Right Side View
//
//  Created by apple on 15/12/9.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

void deepFirstTraversal(TreeNode* root, int height, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    
    if (ans.size() < height) {
        ans.push_back(root->val);
    }
    
    deepFirstTraversal(root->right, height + 1, ans);
    deepFirstTraversal(root->left, height + 1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    deepFirstTraversal(root, 1, ans);
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> ans;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    
    node1->left = node2;
    node1->right = node3;
    node2->right = node5;
    node3->right = node4;
    
    ans = rightSideView(node1);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
