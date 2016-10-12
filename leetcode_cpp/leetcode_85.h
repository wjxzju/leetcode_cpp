#ifndef __LEETCODE_85
#define __LEETCODE_85
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
public:
	static int largestArea(vector<int>& heights) {
		int maxArea = 0;
		vector<int> copy = heights;
		copy.push_back(0);  //在原有的数组后面加个0保证最后一个元素也计算进去
		stack<int> s;
		for (size_t i = 0; i < copy.size(); i++)
		{

			while (!s.empty() && copy[i] <= copy[s.top()]){
				int index = s.top();
				s.pop();
				int curArea = s.empty() ? i*copy[index] : (i - s.top() - 1)*copy[index];
				maxArea = max(curArea, maxArea);
			}

			s.push(i);
		}
		return maxArea;
	}
	static int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0;
		if (matrix.size() == 0)
			return res;
		int h = matrix.size();
		int w = matrix[0].size();

		vector<vector<int>> height(h, vector<int>(w));

		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (matrix[i][j] == '0')
					height[i][j] = 0;
				else

					height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
			}	
			
		}
		for (size_t i = 0; i < h; i++)
		{
			int curArea = largestArea(height[i]);
			res = max(res, curArea);
		}


		return res;
		
	}
};


#endif