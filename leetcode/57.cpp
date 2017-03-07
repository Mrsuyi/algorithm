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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		int len = intervals.size();
		if (len == 0) return { newInterval };

		int bgn = -1;
		int end = -1;
		int i = 0;
		while (i < len && intervals[i].end < newInterval.start) { i++; }
		bgn = i;
		while (i < len && intervals[i].start <= newInterval.end) { i++; }
		end = i;

		vector<Interval> ret;
		if (bgn == len)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		else
		{
			newInterval.start = min(newInterval.start, intervals[bgn].start);
			newInterval.end = max(newInterval.end, intervals[end - 1].end);

			vector<Interval> ret;
			ret.reserve(len - end + bgn + 1);
			ret.insert(ret.end(), intervals.begin(), intervals.begin() + bgn);
			ret.push_back(newInterval);
			ret.insert(ret.end(), intervals.begin() + end, intervals.end());

			return ret;
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}