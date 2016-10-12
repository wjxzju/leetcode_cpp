#ifndef __LEETCODE_205
#define __LEETCODE_205
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		if (s.size() == 0)
			return true;
		unordered_map<char, char> m1,m2;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (m1.find(s[i]) != m1.end()){
				if (m1[s[i]] != t[i])
					return false;
			}
			if (m2.find(t[i]) != m2.end()){
				if (m2[t[i]] != s[i])
					return false;
			}

			m1[s[i]] = t[i];
			m2[t[i]] = s[i];
		}
		return true;

	}
};


#endif