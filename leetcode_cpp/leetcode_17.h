#ifndef __LEETCODE_17
#define __LEETCODE_17
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	static vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.size() == 0)
			return res;
		res.push_back("");
		string names[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (size_t i = 0; i < digits.size(); i++)
		{
			vector<string> temp;
			for (size_t j = 0; j < res.size(); j++)
			{
				for (size_t t = 0; t < names[digits[i]-'0'].size(); t++)
				{
					temp.push_back(res[j] + names[digits[i] - '0'][t]);
				}
			}
			res = temp;
		}
			
		return res;
		
	}
};


#endif