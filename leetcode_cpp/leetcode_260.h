#ifndef __LEETCODE_260
#define __LEETCODE_260
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static vector<int> singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> res;
		int answer;
		for (size_t i = 0; i < nums.size(); i++)
		{	
			if (i == 0)
				answer = nums[i];
			else{
				answer=answer^nums[i];
				if (res.size() == 0){
					if ((i % 2) && (answer!=0)){  //find the first element
						res.push_back(nums[i - 1]);
						answer = nums[i];
					}	
				}
				else{
					if ((i % 2 == 0) && (answer != 0)){ //find the second element
						res.push_back(nums[i - 1]);
						break;
					}
				}
			}
	
		}
		if (res.size() < 2)
			res.push_back(nums[nums.size() - 1]);
		return res;
	}
};


#endif