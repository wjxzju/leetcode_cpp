#ifndef __LEETCODE_219
#define __LEETCODE_219
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) != m.end()){
				unordered_map<int, int>::iterator it = m.find(nums[i]);
				if (abs(it->second - i) <=k)
					return true;
			}
			m[nums[i]] = i;
		}
		return false;
	}
};

#endif