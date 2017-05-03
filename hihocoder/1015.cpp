#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int search(const string& s, const string& p)
{
	vector<int> next(p.size(), 0);
	for (int i = 1; i < p.size(); ++i)
	{
		int j = i;
		do
		{
			j = next[j - 1];
			if (p[i] == p[j])
			{
				next[i] = j + 1;
				break;
			}
		}
		while (j != 0);
	}
	
	int res = 0;
	for (int i = 0, j = 0; i < s.size(); ++i)
	{
		if (s[i] == p[j])
		{
			if (j == p.size() - 1)
			{
				++res;
				goto fail;
			}
			else
				++j;
		}
		else
		{
fail:
			while (j != 0)
			{
				j = next[j - 1];
				if (s[i] == p[j])
				{
					++j;
					break;
				}
			}
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	for (int n = 0; n < N; ++n)
	{
		string s, p;
		cin >> p >> s;
		cout << search(s, p) << endl;
	}
    return 0;
};