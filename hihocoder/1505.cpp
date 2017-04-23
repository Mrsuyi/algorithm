#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;

unordered_map<int, ll> pair_cnts;
unordered_map<int, ll> num_cnts;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		++num_cnts[nums[i]];
		for (int j = 0; j < i; ++j)
			++pair_cnts[nums[i] + nums[j]];
	}
	ll res = 0;
	for (auto& pair : pair_cnts)
		res += pair.second * (pair.second - 1) / 2;
	for (int i = 0; i < N; ++i)
	{
		for (auto& pair : num_cnts)
		{
			ll val = pair.first;
			ll cnt = pair.second;

			if (val == nums[i])
				res -= (cnt - 1) * (cnt - 2) / 2;
			else
				res -= cnt * (cnt - 1) / 2;
		}
	}
	cout << res * 2 << endl;

	system("PAUSE");
	return 0;
}