#ifndef __LEETCODE_36
#define __LEETCODE_36
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	static bool checkValid(vector<int>& vec, int val)
	{
		
		if (val  <0)
			return true;
		if (vec[val-1] == 1) return false;
		vec[val-1] = 1;
		return true;
	}
	static bool isValidSudoku(vector<vector<char>>& board) {
		
		vector<int> row(9,0);
		vector<int> col(9,0);
		vector<int> grid(9,0);
		for (size_t i = 0; i < 9; i++)
		{
			row.assign(9, 0);
			col.assign(9, 0);
			grid.assign(9, 0);
			//cout << row.size() << " " << col.size() << " "<<grid.size() << endl;
			for (size_t j = 0; j < 9; j++)
			{
				//cout << "i = " << i << " j = " << j << endl;
				
				if (!checkValid(row, board[i][j]-'0') || !checkValid(col, board[j][i]-'0') || !checkValid(grid, board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3]-'0'))
					return false;
			}

		}

		return true;

	}
};



#endif