#ifndef __LEETCODE_136
#define __LEETCODE_136
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int singleNumber(vector<int>& nums) {
		
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size(); i++)
		{
			if ((i % 2==0)&& (nums[i]!=nums[i+1])){
				return nums[i];
			}
		}
		return nums[nums.size()-1];
	}
};

#endif