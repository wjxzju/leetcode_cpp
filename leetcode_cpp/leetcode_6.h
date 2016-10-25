#ifndef __LEETCODE_6
#define __LEETCODE_6
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	static string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int len = s.size();
		string res(len,' ');

		int index = 0;
		for (size_t i = 0; i < len; i = i+ 2*(numRows-1))
		{
			res[index++] = s[i];
		}
		for (size_t i = 1; i < numRows - 1; i++)
		{
			int inter = i * 2;
			for (size_t j = i; j < len; j = j + inter)
			{
				res[index++] = s[j];
				inter = 2 * (numRows - 1) - inter;
			}		
		}
		for (size_t i = numRows-1; i < len; i = i+2*(numRows-1))
		{
			res[index++] = s[i];

		}
		return res;
	}
};





#endif