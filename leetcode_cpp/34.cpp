//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> searchRange(vector<int>& nums, int target) {
//	vector <int> res(2, -1);
//	for (size_t i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] == target && res[0] == -1){
//			res[0] = i;
//		}
//		
//		if (nums[i] == target && nums[i + 1] != target && i<nums.size()-1)
//			res[1] = i;
//		if (nums[i] == target && i == nums.size() - 1)
//			res[1] = i;
//	}
//
//
//	return res;
//	
//	
//}
//
//
//int main(void)
//{
//
//	vector<int> nums = { 5, 5, 7, 7, 8, 8, 10 };
//	vector<int> res = searchRange(nums, 8);
//
//	// cout
//	for (size_t i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}