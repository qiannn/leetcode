//
//  main.cpp
//  Path Sum II
//
//  Created by apple on 15/11/13.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

void Traversal(TreeNode* root, int sum, vector<int> prePath,
               vector<vector<int>>& answer) {
    if (root == NULL) {
        return;
    }
    
    prePath.push_back(root->val);
    if (root->left == NULL && root->right == NULL && root->val == sum) {
//        int count = 0;
//        for (int i = 0; i < prePath.size(); i++) {
//            count += prePath[i];
//        }
//        if (sum == count) {
//            answer.push_back(prePath);
//        }
        answer.push_back(prePath);
        return;
    }
    
    Traversal(root->left, sum - root->val, prePath, answer);
    Traversal(root->right, sum - root->val, prePath, answer);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> answer;
    vector<int> prePath;
    Traversal(root, sum, prePath, answer);
    return answer;
}

int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(13);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(2);
    TreeNode* node9 = new TreeNode(5);
    TreeNode* node10 = new TreeNode(1);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
//    node2->right = node5;
    
    node3->left = node5;
    node3->right = node6;
    
    node4->left = node7;
    node4->right = node8;
    
    node6->left = node9;
    node6->right = node10;
    
    vector<vector<int>> ans = pathSum(node1, 22);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
    return 0;
}
