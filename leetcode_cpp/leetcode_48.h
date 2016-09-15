#ifndef __LEETCODE_48
#define __LEETCODE_48
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static void rotate(vector<vector<int>>& matrix) {
		int n = matrix[0].size();

		for (size_t i = 0; i < n/2; i++)
		{
			for (size_t j = 0; j <n-1-2*i; j++)
			{
				cout << "i = " << i << " j = " << j << endl;
				
				int t = matrix[i][i + j];
				
				matrix[i][i + j] = matrix[n - 1 - (i+j)][i];
				
				matrix[n - 1 - (i+j)][i] = matrix[n - 1 - i][n - 1 - ( i + j )];
				
				matrix[n-1-i][n - 1 - (i + j)] = matrix[i + j][n - 1 - i];
				
				matrix[i + j][n - 1 - i] = t;
			

			}

		}

		/*for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix[i].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}*/
	}
};


#endif