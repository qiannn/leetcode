//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by apple on 16/9/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m == 0 && n == 0)
			return 0.0;
		int k1 = (m + n - 1) / 2, k2 = (m + n) / 2;
		int numk1 = findKth(nums1, nums2, k1);
		int numk2 = findKth(nums1, nums2, k2);
		cout << "numk1 = " << numk1 << endl;
		cout << "numk2 = " << numk2 << endl;
		return (numk1 + numk2) / 2.0;
	}

	int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		if (m == 0)
			return nums2[k];
		if (n == 0)
			return nums1[k];

		int start1 = 0, end1 = m, start2 = 0, end2 = n;
		int mid1 = start1 + (end1 - start1) / 2;
		int mid2 = start2 + (end2 - start2) / 2;

		while (mid1 + mid2 != k) {
			if (mid1 + mid2 < k) {
				if (nums1[mid1] < nums2[mid2]) {
					start1 = mid1 + 1;
					mid1 = start1 + (end1 - start1) / 2;
				}
				else {
					start2 = mid2 + 1;
					mid2 = start2 + (end2 - start2) / 2;
				}
			}
			else {
				if (nums1[mid1] < nums2[mid2]) {
					end2 = mid2 - 1;
					mid2 = start2 + (end2 - start2) / 2;
				}
				else {
					end1 = mid1 - 1;
					mid1 = start1 + (end1 - start1) / 2;
				}
			}
		}
		cout << "k = " << k << endl;
		cout << "nums1[mid] = " << nums1[mid1] << endl;
		cout << "nums2[mid] = " << nums2[mid2] << endl;
		cout << endl;
		return std::min(nums1[mid1], nums2[mid2]);
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	Solution s;
	std::vector<int> nums1 = {1,2};
	std::vector<int> nums2 = {3,4};

	cout << s.findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}
