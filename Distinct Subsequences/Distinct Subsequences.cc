#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int numDistinct(string s, string t) 
	{
		int ssize = s.size(), tsize = t.size();
		if (ssize < tsize)
			return 0;

		vector< vector<int> > dp(ssize + 1, vector<int>(tsize + 1, 0));
		for (int i = 0; i < ssize + 1; ++i)
		{
			dp[i][0] = 1;
		}

		for (int i = 1; i < ssize + 1; ++i)
		{
			for (int j = 1; j < tsize + 1; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1])
					dp[i][j] += dp[i -1][j - 1];
			}
		}

		return dp[ssize][tsize];
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.numDistinct("b", "a") << endl;
	return 0;
}
