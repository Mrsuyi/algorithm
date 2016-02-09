#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


// hash

bool operator == (Point& a, Point& b)
{
	return a.x == b.x && a.y == b.y;
}

bool operator || (Point& a, Point& b)
{
	return a.x == b.x;
}

double operator / (Point& a, Point& b)
{
	return (double)(a.y - b.y) / (double)(a.x - b.x);
}

class Solution
{
public:
	int maxPoints(vector<Point>& points)
	{
		int len = points.size();
		int ret = len > 2 ? 2 : len;

		for (int i = 0; i < len; i++)
		{
			unordered_map<double, int> cnt;
			int same = 1, vert = 1;

			for (int j = 0; j < len; j++)
			{
				if (i == j)
				{
					continue;
				} 
				else if (points[i] == points[j])
				{
					same++;
				}
				else if (points[i] || points[j])
				{
					vert++;
				}
				else
				{
					cnt[points[i] / points[j]]++;
				}
			}

			for (auto p : cnt)
			{
				ret = max(ret, p.second + same);
			}
			ret = max(ret, vert);
			ret = max(ret, same);
		}

		return ret;
	}
};


// brute force

bool operator==(Point& a, Point& b)
{
    return a.x == b.x && a.y == b.y;
}

bool line(Point& a, Point& b, Point& c)
{
    return (a.y - b.y) * (b.x - c.x) == (b.y - c.y) * (a.x - b.x);
}

class Solution
{
public:
    int maxPoints(vector<Point>& points)
    {
        int len = points.size();
        int ret = len > 2 ? 2 : len;

        for (int i = 0; i < len; i++)
        {
            int same = 0;

            for (int j = i + 1; j < len; j++)
            {
                if (points[i] == points[j])
                {
                    same++;
                    continue;
                }
                int cnt = 2 + same;
                for (int k = j + 1; k < len; k++)
                {
                    if (line(points[i], points[j], points[k]))
                    {
                        cnt++;
                    }
                }
                ret = max(ret, cnt);
            }
            ret = max(ret, same + 1);
        }
        return ret;
    }
};



int main()
{
	Solution solution;

	while (getchar());

	return 0;
}