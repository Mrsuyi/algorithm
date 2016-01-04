#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
	static bool cmp(const Interval& i1, const Interval& i2)
	{
		return i1.start < i2.start;
	}

	vector<Interval> merge(vector<Interval>& intervals)
	{
		int len = intervals.size();
		if (len == 0) return {};

		sort(intervals.begin(), intervals.end(), cmp);

		vector<Interval> ret = { intervals.front() };
		for (int i = 1; i < len; i++)
		{
			if (intervals[i].start <= ret.back().end)
			{
				ret.back().end = max(ret.back().end, intervals[i].end);
			}
			else
			{
				ret.push_back(intervals[i]);
			}
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}