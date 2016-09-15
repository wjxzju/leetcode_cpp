#ifndef __LEETCODE_55
#define __LEETCODE_55
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	 static bool canJump(vector<int>& nums) {
		
		 int cur = 0; 
		 int pre=0;
		 int i = 0;
		 for (; i < nums.size(); )
		 {
			 //cout << i << endl;
			 if (i>pre)
				 return false;
			 if (pre >=nums.size()-1)
				 return true;
			 while (i <= pre)
			 {
				 cur = max(cur, nums[i] + i);
				 i++;
				// cout << "cur "<< cur << endl;
			 }
			
			 pre = cur;
		 }
		 
	}
};
#endif 