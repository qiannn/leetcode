#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		vector<vector<int> > answer;
		set<vector<int> > _set;
		if (nums.empty()) 
			return answer; 
		sort(nums.begin(), nums.end());
		_set.insert(nums);
		while(next_permutation(nums.begin(), nums.end()))
			_set.insert(nums);
		for (auto v : _set)
		{
			answer.push_back(v);
		}
		return answer;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v = {1,1,2};
	vector<vector<int> > answer = s.permuteUnique(v);
	for (auto v : answer)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}