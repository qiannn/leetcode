#include <iostream>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution solution;
	std::vector<int> nums = {1,3,2,4};
	solution.nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] <<" ";
	}
	std::cout << std::endl;
	return 0;
}