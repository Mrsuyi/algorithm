#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const double PI = 3.14159265358;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;
		double res = 0;
		vector<double> dp(K + 1, 0);
		vector<pair<double, double>> vals(N);
		for (int i = 0; i < N; ++i)
			cin >> vals[i].first >> vals[i].second;
		sort(vals.begin(), vals.end());

		for (int i = 0; i < N; ++i)
		{
			double r = vals[i].first;
			double h = vals[i].second;
			vector<double> tmp = dp;
			for (int j = 1; j <= min(i + 1, K); ++j)
			{
				double cur = dp[j - 1] + 2 * r * h * PI;
				tmp[j] = max(tmp[j], cur);
				res = max(res, cur + PI * r * r);
			}
			swap(dp, tmp);
		}
		printf("Case #%d: %lf\n", t, res);
	}
	return 0;
};