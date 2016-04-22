//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by apple on 16/1/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

vector<vector<int> > ans;

void Traversal(int depth, TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (depth >= ans.size()) {
        vector<int> level;
        ans.push_back(level);
    }
    ans[depth].push_back(root->val);
    Traversal(depth + 1, root->left);
    Traversal(depth + 1, root->right);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    Traversal(0, root);
    vector<vector<int> > reverse_answer;
    vector<vector<int> >::reverse_iterator riter = ans.rbegin();
    for (; riter != ans.rend(); riter++) {
        reverse_answer.push_back(*riter);
    }
    return reverse_answer;
}

int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    
    node1->left = node2;
    
    node2->left = node3;
    
    node3->left = node4;
    
    node4->left = node5;
    
    vector<vector<int>> ans = levelOrder(node1);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
