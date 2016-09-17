#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        list<int> digits_list;
        int carry = 1;
        for (int i = (int)digits.size() - 1; i >= 0; i--)
        {
        	digits_list.push_front((carry + digits[i]) % 10);
        	carry = (carry + digits[i]) / 10;
        }
        if (carry)
        	digits_list.push_front(carry);

        std::vector<int> answer;
        for (auto i : digits_list) 
        {
        	answer.push_back(i);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> digits = {3, 0, 0};
	std::vector<int> v = s.plusOne(digits);
	for (auto i : v)
	{
		cout << i << endl;
	}
	return 0;
}