#include <iostream>

class Solution {
public:
    int reverse(int x) {
    	if (x == 0)
    		return 0;
        bool isnegtive = x > 0 ? false : true;
        long long _x = std::abs((long long)x);
        long long answer = 0;
        while (_x) {
        	int i = _x % 10;
        	_x /= 10;
        	answer = answer * 10 + i;
        }
        if (answer > (long long)INT_MAX) {
        	return 0;
        }
        if (isnegtive) {
        	answer = -answer;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::cout << s.reverse(-2147483648) << std::endl;
	return 0;
}