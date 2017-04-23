#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100001;
ll a[MAXN];
ll b[MAXN];

int main()
{
	ll N, avg = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i] >> b[i];
		avg += a[i] + b[i];
	}
	avg /= 2 * N;
	ll res = 0, p = 0, q = 0;
	for (int i = 0; i < N; ++i)
	{
		p += avg - a[i];
		q += avg - b[i];
		if ((p ^ q) & (1ULL << 63))
		{
			res += min(abs(p), abs(q));
			if (abs(p) > abs(q))
			{
				p += q;
				q = 0;
			}
			else
			{
				q += p;
				p = 0;
			}
		}
		res += abs(p) + abs(q);
	}
	cout << res << endl;

	return 0;
};