#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

typedef long long ll;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<double> ps(N);
	for (int i = 0; i < N; ++i)
		cin >> ps[i];
	vector<vector<double>> dp(N, vector<double>(M + 1, 0.0));
	dp[0][0] = 1.0 - ps[0];
	dp[0][1] = ps[0];
	for (int i = 1; i < N; ++i)
	{
		dp[i][0] = dp[i - 1][0] * (1 - ps[i]);
		for (int j = 1; j <= std::min(M, i + 1); ++j)
		{
			dp[i][j] = dp[i - 1][j] * (1 - ps[i]) + dp[i - 1][j - 1] * ps[i];
		}
	}
	cout << dp[N - 1][M] << endl;
	return 0;
}