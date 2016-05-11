#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string zigzag = "";
		for (int i = 0; i < numRows; ++i) {
			int firstspace, secondspace;
			int pos = i;
			int step = 0;

			firstspace = (numRows - i - 1) * 2;
			secondspace = i * 2;
			while (pos < s.length()) {
				int space = step++ % 2 ? secondspace : firstspace;
				if (space) {
					zigzag += s[pos]; 
					pos += space;
				}
			}
			step = 0;
		}
		return zigzag;
	}
};

int main(int argc, char const *argv[]) {
	Solution s;
	string str = "PAYPALISHIRING";
	cout << s.convert(str, 1) << endl;
	return 0;
}