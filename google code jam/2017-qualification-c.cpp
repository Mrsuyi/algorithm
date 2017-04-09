#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		long long N, K;
		cin >> N >> K;
		map<long long, long long> map;
		map[N] = 1;
		int l, r;
		while (K > 0)
		{
			auto it = --map.end();
			long long len = it->first;
			long long cnt = it->second;
			map.erase(it);
			r = len / 2;
			l = r - 1 + len % 2;
			K -= cnt;
			map[l] += cnt;
			map[r] += cnt;
		}
		printf("Case #%d: %ld %ld\n", t + 1, r, l);
	}
	return 0;
}