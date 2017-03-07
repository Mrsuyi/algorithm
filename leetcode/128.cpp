#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		unordered_map<int, int> map;
		unordered_map<int, int> weight;

		for (auto n : nums)
		{
			if (map.find(n) == map.end())
			{
				auto nmm = map.find(n - 1);
				auto npp = map.find(n + 1);

				if (nmm != map.end() && npp != map.end())
				{
					int rmm = root(map, nmm->first);
					int rpp = root(map, npp->first);

					if (weight[rmm] > weight[rpp])
					{
						weight[rmm] += weight[rpp] + 1;
						map[n] = map[rpp] = rmm;
						weight[rpp] = 0;
					}
					else
					{
						weight[rpp] += weight[rmm] + 1;
						map[n] = map[rmm] = rpp;
						weight[rmm] = 0;
					}
				}
				else if (nmm != map.end())
				{
					int r = root(map, nmm->first);
					map[n] = r;
					weight[r]++;
				}
				else if (npp != map.end())
				{
					int r = root(map, npp->first);
					map[n] = r;
					weight[r]++;
				}
				else
				{
					map[n] = n;
					weight[n] = 1;
				}
			}
		}

		int ret = 0;
		for (auto& p : weight)
		{
			ret = max(ret, p.second);
		}
		return ret;
	}

	int root(unordered_map<int, int>& map, int n)
	{
		while (map[n] != n)
		{
			n = map[n];
		}
		return n;
	}
};

int main()
{
	while (getchar());

	return 0;
}