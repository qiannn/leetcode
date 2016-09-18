#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	bool isNumber(string s) 
	{
		size_t pos1, pos2;
		pos1 = s.find_first_not_of(" ");
		if (pos1 != 0)
			s.erase(0, pos1);

		pos2 = s.find_last_not_of(" ");
		if (pos2 != s.size() - 1)
			s.erase(pos2 + 1);
		
		if (s.length() == 0)
			return false;
		
		string::const_iterator iter = s.begin();
		if (*iter == '+' || *iter == '-')
		{
			iter++;
			if (iter == s.end())
				return false;
		}

		bool hasIntNumber = false;
		while (*iter <= '9' && *iter >= '0')
		{
			iter++;
			hasIntNumber = true;
		}

		if (iter != s.end())
		{
			bool hasFloatNumber = false;
			if (*iter == '.')
			{
				iter++;

				while (*iter <= '9' && *iter >= '0')
				{
					iter++;
					hasFloatNumber = true;
				}
				if (!hasFloatNumber && !hasIntNumber)
					return false;
			}

			if (*iter == 'e' || *iter == 'E')
			{
				iter++;
				if (iter == s.end())
					return false;

				if (*iter == '+' || *iter == '-')
				{
					iter++;
					if (iter == s.end())
						return false;
				}

				bool hasNumber = false;
				while (*iter <= '9' && *iter >= '0')
				{
					iter++;
					hasNumber = true;
				}
				if (!hasNumber)
					return false;
			}
		}

		return iter == s.end();
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	if (s.isNumber("3.e1"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}