#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution 
{
public:
	Solution()
	{

		numberAlphaMap['2'] = {"a", "b", "c"};
		numberAlphaMap['3'] = {"d", "e", "f"};
		numberAlphaMap['4'] = {"g", "h", "i"};
		numberAlphaMap['5'] = {"j", "k", "l"};
		numberAlphaMap['6'] = {"m", "n", "o"};
		numberAlphaMap['7'] = {"p", "q", "r", "s"};
		numberAlphaMap['8'] = {"t", "u", "v"};
		numberAlphaMap['9'] = {"w", "x", "y", "z"};
	}

	vector<string> letterCombinations(string digits) 
	{
		vector<string> answer;
		if (digits.size() == 0) 
		{
			return answer;
		}
		
		if (digits.size() == 1 && digits[0] >= '2' && digits[0] <= '9')
			return numberAlphaMap[digits[0]];

		vector<string> vs = letterCombinations(digits.substr(1));
		if (digits[0] >= '2' && digits[0] <= '9')
		{
			for (int i = 0; i < numberAlphaMap[digits[0]].size(); ++i)
			{		
				for (int j = 0; j < vs.size(); j++) 
				{
					answer.push_back(numberAlphaMap[digits[0]][i] + vs[j]);
				}
			}
		}
		else 
		{
			return vs;
		}

		return answer;
	}
private:
	std::map<char, std::vector<string> > numberAlphaMap;
};

int main(int argc, char const *argv[])
{
	Solution s;
	auto vs = s.letterCombinations("23");
	for (int i = 0; i < vs.size(); ++i)
	{
		cout << vs[i] << endl;
	}
	return 0;
}