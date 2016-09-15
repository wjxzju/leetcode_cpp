#ifndef __LEETCODE_54
#define __LEETCODE_54
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() == 0)
			return res;
		int m = matrix.size();
		int n = matrix[0].size();
		
		if (m<n)
		for (size_t i = 0; i < ceil(n/2.0) && i<ceil(m/2.0); i++)
		{
			int left = i, top = i;
			int right = n - 1 - i, bottom = m - 1 - i;
			int x = i, y = i;
			cout << "i = " << i << endl;
			if (left == right && top == bottom)
			{
				res.push_back(matrix[x][y]);
				return res;
			}
			else if (left == right && top != bottom)
			{
				while (1)
				{
					res.push_back(matrix[x][y]);
					if (x == bottom)
						break;
					x++;
				}
			}
			else if (left != right && top == bottom)
			{
				while (1)
				{
					res.push_back(matrix[x][y]);
					if (y == right)
						break;
					y++;
				}
			}
			else{
				
				int rotation = 0;
				while (1)
				{
					//cout << "x = " << x << " y = " << y << endl;
					res.push_back(matrix[x][y]);
					if (x == i + 1 && y == i)
						break;
					if (y == right && x == top)
						rotation = 1;
					else if (y == right && x == bottom)
						rotation = 2;
					else if (y == left && x == bottom)
						rotation = 3;
					//cout << "rotation = " << rotation << endl;
					if (rotation == 0)
						y++;
					else if (rotation == 1)
						x++;
					else if (rotation == 2)
						y--;
					else
						x--;
					
				}
				
			}

		}
		return res;
	}
};


#endif