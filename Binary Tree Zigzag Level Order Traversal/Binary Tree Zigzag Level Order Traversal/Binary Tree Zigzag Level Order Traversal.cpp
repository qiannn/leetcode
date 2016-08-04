// Binary Tree Zigzag Level Order Traversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > vv;
		if (!root)
			return vv;
		map<int, vector<int> > levelOrder;
		helper(root, 0, levelOrder);

		auto iter = levelOrder.begin();
		for (; iter != levelOrder.end(); iter++) {
			if (iter->first % 2 != 0) {
				reverse(iter->second.begin(), iter->second.end());
			}
			vv.push_back(iter->second);
		}
		return vv;
	}


	void helper(TreeNode* root, int height, map<int, vector<int> >& levelOrder) {
		if (!root)
			return;
		levelOrder[height].push_back(root->val);

		helper(root->left, height + 1, levelOrder);
		helper(root->right, height + 1, levelOrder);
	}
};

int main()
{
    return 0;
}

