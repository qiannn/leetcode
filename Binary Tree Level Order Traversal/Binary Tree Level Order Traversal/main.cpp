//
//  main.cpp
//  Binary Tree Level Order Traversal
//
//  Created by apple on 15/11/17.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};
/*
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) {
        return ans;
    }
    
    int count = 0;
    vector<int> level;
    map<int, vector<TreeNode*>> levels;
    levels[count].push_back(root);
    while (levels.find(count) != levels.end()) {
        level.clear();
        for (int i = 0; i < levels[count].size(); i++) {
            level.push_back(levels[count][i]->val);
            if (levels[count][i]->left != NULL) {
                levels[count + 1].push_back(levels[count][i]->left);
            }
            
            if (levels[count][i]->right != NULL) {
                levels[count + 1].push_back(levels[count][i]->right);
            }
        }
        ans.push_back(level);
        count ++;
    }
    
    return ans;
}
*/

vector<vector<int>> ans;
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
    return ans;
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
