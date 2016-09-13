#include <iostream>
#include <vector>
#include "leetcode_40.h"
using namespace std;

int main(void)
{
	vector<int> nums = { 10,1,2,7,6,1,5};
	vector<vector<int>> res = Solution::combinationSum2(nums, 8);

	cout << "------------------------------------------" << endl;

	for (size_t i = 0; i < res.size(); i++)
	{
		for (size_t j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}