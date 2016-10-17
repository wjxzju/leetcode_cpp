#ifndef __LEETCODE_76
#define __LEETCODE_76
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	static string minWindow(string s, string t) {
	
		unordered_map<char, int> tMap;
		for (size_t i = 0; i < t.size(); i++)
		{
			if (tMap.find(t[i]) == tMap.end())
				tMap[t[i]] = 1;
			else{
				tMap[t[i]]++;
			}
		}

		int left = 0, count = 0;
		int minLen = 0x7fffffff;
		int minStart = 0;
		for (size_t right = 0; right <s.size(); right++)
		{
			if ( tMap.find(s[right]) != tMap.end()){  //find a char in string
				tMap[s[right]]--;
				if (tMap[s[right]] >= 0)
					count++;
			}
		
			while (count == t.size()){
				if (right - left + 1 < minLen){
					minStart = left;
					minLen = right - left + 1;
				}
				if (tMap.find(s[left]) != tMap.end()){
					tMap[s[left]] ++;
					if (tMap[s[left]] > 0)
						count--;
				}
				left++;
			}
		}
		//cout << minStart << " " << minLen << endl;
		if (minLen == 0x7fffffff)
			return "";
		return s.substr(minStart, minLen);
		
	}
};


#endif