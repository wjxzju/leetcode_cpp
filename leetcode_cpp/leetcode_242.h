#ifndef __LEETCODE_242
#define __LEETCODE_242
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		if (s.size() == 0)
			return true;

		unordered_map<char, int> m1, m2;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (m1.find(s[i]) == m1.end()){
				m1[s[i]] = 0;
			}
			m1[s[i]]++;
		}
		
		for (size_t i = 0; i < t.size(); i++)
		{
			if (m2.find(t[i]) == m2.end()){
				m2[t[i]] = 0;
			}
			m2[t[i]]++;
		}
		for (auto ele : m1){
			if (m2[ele.first] != m1[ele.first])
				return false;
		}

		return true;


	}
};

#endif