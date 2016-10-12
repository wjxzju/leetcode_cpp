#ifndef __LEETCODE_84
#define __LEETCODE_84
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	static int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;

		if (heights.size() == 0)
			return maxArea;

		vector<int> copy = heights;
		copy.push_back(0);  //在原有的数组后面加个0保证最后一个元素也计算进去
		stack<int> s;
		for (size_t i = 0; i < copy.size(); i++)
		{
			
			while (!s.empty() && copy[i] <= copy[s.top()]){
				int index = s.top();
				s.pop();
				int curArea = s.empty() ? i*copy[index] : (i - s.top() - 1)*copy[index];
				//cout <<" i = "<<i<<" index = "<< index<<" "<<  curArea <<  endl;
				maxArea = max(curArea, maxArea);
			}
			
			s.push(i);
		}
		return maxArea;
	}
};


#endif