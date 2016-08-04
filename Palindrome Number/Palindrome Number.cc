#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		unsigned long reversed = 0, ux = static_cast<unsigned long>(x);
		while (x) {
			reversed = reversed * 10 + x % 10;
			x /= 10;
		}
		return ux == reversed;
	}
};

int main(int argc, char const *argv[]) {
	Solution s;
	int x = INT_MAX;
	if (s.isPalindrome(x))
		std::cout << "yep" << std::endl;
	else 
		std::cout << "ops" << std::endl;
	return 0;
}