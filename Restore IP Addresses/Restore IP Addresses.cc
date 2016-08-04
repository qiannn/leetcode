#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> v;
		if (!(s.size() > 12 || s.size() < 4))
			divide("", s, 0, v);
		return v;
	}

	bool check(const string& s) const {
		if (s.length() > 1 && s[0] == '0') 
			return false;
		else if (std::stoi(s) < 256 && std::stoi(s) > -1) {
			return true;
		}
		return false;
	}

	void divide(const string& prestr, const string& rest, int times, vector<string>& v) {
		if (times == 3) {
			if (check(rest)) {
				string validaddress = prestr + "." + rest;
				validaddress = validaddress.substr(1);
				if (find(v.begin(), v.end(), validaddress) == v.end())
					v.push_back(validaddress);
			}
			return;
		}		
		for (int i = 1; i < 4; i++) {
			if (i < rest.size() && check(rest.substr(0, i))) {
				divide(prestr + "." + rest.substr(0, i), rest.substr(i), times + 1, v);
			}
		}			
	}
};

int main(int argc, char const *argv[]) {
	//string str = "25525511100";
	//string str = "0000";
	string str = "010010";
	Solution s;
	vector<string> ipaddress = s.restoreIpAddresses(str);
	for (int i = 0; i < ipaddress.size(); i++) {
		cout << ipaddress[i] << endl;
	}
	return 0;
}