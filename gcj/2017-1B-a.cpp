#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int D, N;
		cin >> D >> N;
		double time = DBL_MIN;;
		for (int i = 0; i < N; ++i)
		{
			int pos, speed;
			cin >> pos >> speed;
			time = max(time, (D - pos) / (double)speed);
		}
		printf("Case #%d: %.6f\n", t, D / time);
	}
	return 0;
};