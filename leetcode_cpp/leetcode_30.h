#ifndef __LEETCODE_30
#define __LEETCODE_30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.size() == 0 || words.size() == 0){
			return res;
		}
		
		unordered_map<string, int> m1;
		for (auto a : words){
			m1[a]++;
		}

		int n = words.size();
		int len = words[0].size();
		
		for (int i = 0; i <=(int)s.size()-n*len; i++)
		{
			unordered_map<string, int> m2;
			int j = 0;
			for ( j = 0; j < n; j++)
			{
				string tmp = s.substr(i + j*len, len);
				if (m1.find(tmp) == m1.end())
					break;
				m2[tmp]++;
				if (m2[tmp] > m1[tmp])
					break;
				
			}
			if (j==n)
				res.push_back(i);
			
		}
	
		return res;

		
	}
};


#endif