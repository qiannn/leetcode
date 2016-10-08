#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int n = matrix.size();
		for (int x = 0; x < n / 2; x++)
		{
			int len = n - x;
			for (int y = x; y < len; y++)
			{
				int x1 = x, y1 = y;
				int x2 = y, y2 = len - 1;
				int x3 = n - x1, y3 = n - y1;
				int x4 = n - x2, y4 = n - y2;

				int tmp = matrix[x1][y1];
				matrix[x1][y1] = matrix[x4][y4];
				matrix[x4][y4] = matrix[x3][y3];
				matrix[x3][y3] = matrix[x2][y2];
				matrix[x2][y2] = tmp;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix = 
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	Solution s;
	s.rotate(matrix);
	for (auto v : matrix)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}