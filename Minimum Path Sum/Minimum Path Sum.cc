#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) {
			return 0;
		}

		int m = grid.size(), n = grid[0].size();
		vector<vector<int> > dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i || j) {
					int up_pathsum = i ? dp[i - 1][j] : INT_MAX;
					int left_pathsum = j ? dp[i][j - 1] : INT_MAX;
					dp[i][j] = grid[i][j] + min(up_pathsum, left_pathsum);	
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<vector<int> > grid = {
		{1,2,3},
	};
	int minpath = s.minPathSum(grid);
	cout << minpath << endl;
	return 0;
}