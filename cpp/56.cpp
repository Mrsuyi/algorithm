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
	vector<Interval> merge(vector<Interval>& intervals)
	{
		sort(intervals.begin(), intervals.end(), cmp);

		vector<Interval> ret;
		int len = intervals.size();
		for (int i = 0; i < len;)
		{
			int bgn = intervals[i].start;
			int far = intervals[i].end;
			while (++i < len && intervals[i].start <= far)
			{
				far = max(far, intervals[i].end);
			}
			ret.push_back(Interval(bgn, far));
		}
		return ret;
	}

	static bool cmp(const Interval& i1, const Interval& i2)
	{
		return i1.start < i2.start;
	}
};

int main()
{
	while (getchar());

	return 0;
}