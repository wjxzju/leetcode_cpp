#ifndef __LEETCODE_34
#define __LEETCODE_34

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	 static vector<int> searchRange(vector<int>& nums, int target) {
		vector <int> res(2, -1);
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target && res[0] == -1){
				res[0] = i;
			}

			if (nums[i] == target && nums[i + 1] != target && i<nums.size() - 1)
				res[1] = i;
			if (nums[i] == target && i == nums.size() - 1)
				res[1] = i;
		}


		return res;
	}
};
#endif