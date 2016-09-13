#ifndef __LEETCODE_35
#define __LEETCODE_35
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	static int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		if (target < nums[0])
			return 0;
		
		for (size_t i = 0; i < nums.size(); i++)
		{
			//cout << i << endl;
			if (nums[i] == target)
				return i;
			if (i < nums.size() - 1 && target>nums[i] && target < nums[i + 1] )
				return i+1;
		}
		return nums.size();
	}
};

#endif