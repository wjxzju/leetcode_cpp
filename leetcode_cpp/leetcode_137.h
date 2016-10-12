#ifndef __LEETCODE_137
#define __LEETCODE_137
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int singleNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size(); i++)
		{
			if ((i + 2<nums.size()) && (i % 3 == 0) && (nums[i] != nums[i + 2]) ){
				return nums[i];
			}
		}
		return nums[nums.size() - 1];
	}
};

#endif