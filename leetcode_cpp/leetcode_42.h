#ifndef __LEETCODE_42
#define __LEETCODE_42
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static int trap(vector<int>& height) {
		if (height.size()<3)
			return 0;
		vector<int> container(height.size());

		int max = 0;
		for (size_t i = 0; i < height.size(); i++)
		{
			container[i] = max;
			if (height[i] > max)
				max = height[i];
		}
		max = 0;
		int res = 0;
		
		for (int i = height.size()-1; i >=0; i--)
		{
			
			if (container[i] > max)
				container[i] = max;
			if (height[i] < container[i])
			{
				res += container[i] - height[i];
				/*cout << container[i] << " " <<height[i] << endl;*/
			}
				
			if (height[i] >max)
				max = height[i];
		}
		return res;

	}
};



#endif