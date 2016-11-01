#ifndef __LEETCODE_14
#define __LEETCODE_14
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	static string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];
		string res = "";
		int minLen = strs[0].size();
		for (size_t i = 0; i < strs.size(); i++)
			minLen = strs[i].size() < minLen ? strs[i].size() : minLen;

		for (size_t i = 0; i < minLen; i++)
		{
			bool flag = true;
			char t = strs[0][i];
			for (size_t j = 1; j < strs.size(); j++)
			{
				if (strs[j][i] != t){
					
					flag = false;
					break;
				}
			}
			
			string s(1, t);
			if(flag) 
				res.append(s);
			else
				break;
		}
		return res;
	}
};


#endif