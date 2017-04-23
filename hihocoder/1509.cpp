#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<LL> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	LL res = 1;
	vector<int> divs = {0, n};
	for (int i = 59; i >= 0; --i)
	{
		LL mask = 1LL << i;
		vector<int> nxt;
		int asc = 0, eq = 0, desc = 0;
		for (int j = 0; j < divs.size() - 1; ++j)
		{
			int tend = 0;
			nxt.push_back(divs[j]);
			for (int k = divs[j] + 1; k < divs[j + 1]; ++k)
			{
				bool pre = nums[k - 1] & mask;
				bool cur = nums[k] & mask;
				if (tend == 0)
				{
					if (cur != pre)
					{
						tend = cur ? 1 : -1;
						nxt.push_back(k);
					}
				}
				else if ((tend == 1 && !cur) || (tend == -1 && cur))
				{
					cout << 0 << endl;
					return 0;
				}
			}
			if (tend == 0)
				++eq;
			else if (tend == 1)
				++asc;
			else
				++desc;
		}
		if (asc != 0 && desc != 0)
		{
			cout << 0 << endl;
			return 0;
		}
		if (asc == 0 && desc == 0)
			res *= 2;
		nxt.push_back(n);
		swap(divs, nxt);
	}
	cout << res << endl;
	
    return 0;
};