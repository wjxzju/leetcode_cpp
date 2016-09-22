#ifndef __LEETCODE_57
#define __LEETCODE_57
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
	static vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		if (intervals.size() == 0)
		{
			res.push_back(newInterval);
			return res;
		}
		
		
		int i;
		for (i = 0; i < intervals.size() && intervals[i].end < newInterval.start; i++)
		{
			res.push_back(intervals[i]);
		}
		if (i < intervals.size())
			newInterval.start = min(intervals[i].start, newInterval.start);
		for (; i<intervals.size() && intervals[i].start <= newInterval.end; i++)
		{
			if (intervals[i].end > newInterval.end)
				newInterval.end = intervals[i].end;
		}

		res.push_back(newInterval);

		for (; i < intervals.size(); i++)
			res.push_back(intervals[i]);

		return res;
	}
};

#endif