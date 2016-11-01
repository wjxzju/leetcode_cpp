#ifndef __LEETCODE_22
#define __LEETCODE_22
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	static void process(int l, int r, string item, vector<string>& res){
		if (r < l)
			return;
		if (l == r && l == 0)
			res.push_back(item);
		if (l>0)
			process(l - 1, r, item + '(', res);
		if (r > 0)
			process(l, r-1, item + ')', res);
	}
	static vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0)
			return res;
		process(n, n, "", res);
		return res;
	}
};

#endif