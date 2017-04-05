#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int P, Q, N;
	cin >> P >> Q >> N;
	double res = 0;
	for (int i = 0; i < N; ++i)
	{
		int prob = std::floor(P / std::pow(2, i));
		double prob2 = 1;
		int quests = 1;
		for (; prob < 100; ++quests)
		{
			res += prob2 * prob / 100.0 * quests;
			prob2 *= (100.0 - prob) / 100.0;
			prob += Q;
		}
		res += prob2 * quests;
	}
	printf("%.2f", res);

	return 0;
}