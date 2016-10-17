#ifndef __LEETCODE_3
#define __LEETCODE_3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	static string preprocess(const string s){
		string res = "$#";
		for (size_t i = 0; i <s.size() ; i++)
		{
			res.push_back(s[i]);
			res.push_back('#');

		}
		res.push_back('^');
		return res;

	}
	static string longestPalindrome(string s) {
		int len = s.size();
		if (len <= 1)
			return s;

		string str = preprocess(s);
		int n = str.size();

		cout << str << endl;
		vector<int> p(n, 0);

		int id = 0, mx = 0;
		for (int i = 0; i < n; i++)
		{
			p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 0;
			while (i-p[i]>=0 && i+ p[i] < n && str[i + p[i]] == str[i - p[i]]) p[i]++;
			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
		}

		int maxlen = 0, maxid =0;
		for (size_t i = 0; i < n; i++)
		{
			if (p[i] > maxlen){
				maxlen = p[i];
				maxid = i;
			}
				
		}
		cout << maxid << " " << maxlen << endl;
		return s.substr((maxid - maxlen) / 2, maxlen - 1);
	}

	//dp solution can not solve it
	static string longestPalindrome1(string s) {  
		int len = s.size();
		if (len <= 1)
			return s;

		vector<vector<int>> dp(len, vector<int>(len,0));
		int left = 0, right = 0;
		for (size_t i = 0; i < len; i++)
		{
			dp[i][i] = 1;
		}

		for (size_t i = 0; i < len - 1; i++){
			if (s[i] == s[i+1])
			{
				dp[i][i + 1] = 1;
				if (right - left + 1 < 2){
					left = i;
					right = i + 1;
				}
			}
		}

		for (int k = 2; k < len;k++)
			for (size_t  i = 0; i <len-k; i++)
			{
				if (s[i] == s[i + k] && dp[i + 1][i + k - 1] == 1)
				{
					dp[i][i + k] = 1;
					if (right - left + 1 < k + 1){
						left = i; right = i + k;
					}
				}
			}
			return s.substr(left, right-left+1);

	}
};

#endif