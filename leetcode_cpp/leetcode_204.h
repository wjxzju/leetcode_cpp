#ifndef __LEETCODE_204
#define __LEETCODE_204
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	
	static int countPrimes(int n) {
		if (n < 2)
			return 0;
		vector<bool> prime(n, true);
		int res = 0;
		for (size_t i = 2; i < n; i++)
		{
			if (prime[i])
			{
				for (size_t j = 2; j*i < n; j++)
				{
					prime[j*i] = false;
				}
				res++;
			}
		}
		
		
		return res;
	}
};

#endif