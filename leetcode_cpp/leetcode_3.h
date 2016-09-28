#ifndef __LEETCODE_3
#define __LEETCODE_3
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	static int lengthOfLongestSubstring(string s) {
		if (s == "")
			return 0;
		int index1=0;
		int index2 = 0;
		int res = 0;
		string longest = "";
		while (index1 < s.size())
		{
			size_t t = longest.find(s[index1]);
			if ( t!= string::npos )  //find the same character
			{
				index1 = t + index2 + 1;
				longest = "";
				index2 = index1;
				continue;
			}

			else{
				longest += s[index1];
				if (longest.size() > res)
					res = longest.size();
				index1 += 1;
			}


		}
		return res;

	}
};


#endif