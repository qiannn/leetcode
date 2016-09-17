#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
	vector<string> findRepeatedDnaSequences(string s) 
	{
		vector<string> answer;
		if (s.size() <= 10)
			return answer;

		std::set<string> substr_set;
		std::set<string> answer_set;

		for (int i = 0; i <= s.length() - 10; ++i) 
		{
			string sub = s.substr(i, 10);
			if (substr_set.find(sub) != substr_set.end())
				answer_set.insert(sub);
			else 
				substr_set.insert(sub);
		}
		for (auto str : answer_set)
		{
			answer.push_back(str);
		}
		return answer;
	}
};

int main(int argc, char const *argv[]) 
{
	Solution s;
	vector<string> v = s.findRepeatedDnaSequences("AAAAAAAAAAAA");
	for (auto str : v) 
	{
		cout << str << endl;
	}
	return 0;
}