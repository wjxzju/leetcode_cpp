#ifndef __LEETCODE_56
#define __LEETCODE_56
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
	static bool comp(Interval i, Interval j)
	{
		return (i.start < j.start);
	}
		

	static vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), comp);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (size_t i = 1; i < intervals.size(); i++)
		{
			if (end < intervals[i].start)
			{
				res.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
			else{
				end = max(end, intervals[i].end);
			}
		}
		res.push_back(Interval(start, end));
		return res;
	}
};

#endif