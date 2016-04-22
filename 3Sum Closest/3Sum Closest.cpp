#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	// using two point
	bool threeSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			int twosum = target - nums[i];
			int p = i + 1, q = nums.size() - 1;
			while (p < q) {
				if (nums[p] + nums[q] == twosum) {
					return true;
				}
				else if (nums[p] + nums[q] > twosum) {
					q--;
				}
				else {
					p++;
				}
			}
		}
		return false;
	};

    int threeSumClosest(vector<int>& nums, int target) {
        int drift = 0;
        sort(nums.begin(), nums.end());
        while(1) {
        	if (threeSum(nums, target + drift)) {
        		return target + drift;
        	}

        	if (threeSum(nums, target - drift)) {
        		return target - drift;
        	}
        	drift++;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {-1,2,1,-4};
	cout << solution.threeSumClosest(nums, 1) << endl;
	return 0;
}