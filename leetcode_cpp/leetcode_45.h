#ifndef __LEETCODE_45
#define __LEETCODE_45
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    
	static int jump(vector<int>& nums) {

		int cur = 0;
		int i = 0;
		int steps = 0;
		int pre = 0;
		for (; i < nums.size(); )
		{
			
			if (pre >= (nums.size() - 1))
				break;
			while (i <= pre)
			{	
				cur = max(cur, nums[i] + i);
				i++;
			}
			pre = cur;
			
			steps++;
		}
		return steps;
	}
		
	

};

#endif