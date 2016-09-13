#ifndef __LEETCODE_40
#define __LEETCODE_40
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	 static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		 vector<vector<int>> res;
		 sort(candidates.begin(), candidates.end());
		 vector<int> tmp;
		 process(0, candidates, target, res, tmp);
		 return res;
	}
	 static void process(int index, const vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> & tmp)
	 {
		 //cout << "index = "<<index<<"target = " <<target<< endl;
		 if (target == 0){
			 res.push_back(tmp);
			 return;
		 }
		 for (int i = index; i < candidates.size() && target >= candidates[i]; i++){
			 if (i> index && candidates[i] == candidates[i - 1])
				 continue;
			tmp.push_back(candidates[i]);
			process(i + 1, candidates, target - candidates[i], res, tmp);
			tmp.pop_back();
			 
			
			 
		 }
		 return;

	 }

};



#endif