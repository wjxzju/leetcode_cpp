#ifndef __LEETCODE_20
#define __LEETCODE_20
#include <iostream>

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	static bool isValid(string s) {
		if (s.size()<2)
			return false;
		stack<char> st;
		for (int i = 0; i < s.size(); i++){
			cout << i << endl;
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')
				st.push(s[i]);
			else{
				char top = st.size() ? st.top() : '*';
				if (s[i] == '}' && top != '{')
					return false;
				if (s[i] == ']' && top != '[')
					return false;
				if (s[i] == ')' && top != '(')
					return false;
				st.pop();
			}
		}
		if (!st.empty())
			return false;
		else
			return true;
	}
};
#endif