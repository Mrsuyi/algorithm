#include <iostream>
#include <cstring>
using namespace std;

int kinds[100010];
int counts[100010];

void solution()
{
	int res = 0;
	int N;
	cin >> N;
	memset(counts, 0, sizeof(counts));
	for (int i = 0, j = 0; j < N; ++j)
	{
		cin >> kinds[j];
		++counts[kinds[j]];
		while (counts[kinds[j]] > 1)
			--counts[kinds[i++]];
		res = std::max(res, j - i + 1);
	}
	cout << res << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		solution();
	
	return 0;
}