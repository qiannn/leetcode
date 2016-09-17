#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int maxArea(vector<int>& height) 
	{
		int area = 0;
		int left = 0, right = height.size() - 1;

		while (left < right) 
		{
			int min = height[left] < height[right] ? height[left] : height[right];
			area = max(area, (min * (right - left)));
			if (min == height[left]) 
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		return area;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> height = {1,2,3,4};
	std::cout << s.maxArea(height) << endl;
	return 0;
}