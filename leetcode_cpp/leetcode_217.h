#ifndef __LEETCODE_217
#define __LEETCODE_217
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> m;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) != m.end())
				return true;
			m[nums[i]] = 0;
		}
		return false;
	}
};

#endif