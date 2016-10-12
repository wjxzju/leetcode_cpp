#ifndef __LEETCODE_202
#define __LEETCODE_202
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> splitNum(int n){
		string s = to_string(n);
		vector<int> res;
		for (size_t i = 0; i < s.size(); i++)
			res.push_back(s[i] - '0');
		return res;
	}
	bool isHappy(int n) {
		set<int> s;
		while (n!=1){
			s.insert(n);
			vector<int> split = splitNum(n);
			int sum = 0;
			for (size_t i = 0; i < split.size(); i++)
				sum += pow(split[i], 2);
			if (s.find(sum) != s.end())
				return false;
			n = sum;
		}
		return true;

	}
};



#endif