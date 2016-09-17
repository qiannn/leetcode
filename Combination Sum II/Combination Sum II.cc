#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		vector<vector<int> > vv;
		if (candidates.size() == 0 || target <= 0)
			return vv;
		sort(candidates.begin(), candidates.end());
		vector<int> v;
		DFSHelper(candidates, target, 0, v);
		for (auto i : vset)
		{
			vv.push_back(i);
		}
		return vv;
	}

	void DFSHelper(vector<int>& candidates, int target, int start, vector<int> v)
	{
		if (target < 0)
		{
			return;
		}
		else if (target == 0)
		{
			vset.insert(v);
			return;
		}
		if (start == candidates.size())
			return;
		
		for (int i = start; i < candidates.size(); ++i)
		{
			if (i != start && candidates[i] == candidates[i - 1])
				continue;
			v.push_back(candidates[i]);
			DFSHelper(candidates, target - candidates[i], i + 1, v);
			v.pop_back();
		}
	}

private:
	set<vector<int> > vset;
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v = {10, 1, 2, 7, 6, 1, 5};
	vector<vector<int> > vv = s.combinationSum2(v, 8);
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j];
		}
		cout << endl;
	}
	return 0;
}