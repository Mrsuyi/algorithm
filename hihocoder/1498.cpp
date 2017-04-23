#include <iostream>
using namespace std;

typedef long long ll;

bool can(ll N, ll Q, ll time)
{
	for (ll i = 1, robots = 1; robots <= N; ++i, robots *= 2)
	{
		ll t = (i - 1) * Q;
		t += N / robots + (N % robots ? 1 : 0);
		if (t <= time)
			return true;
	}
	return false;
}

int main()
{
	ll N, Q;
	cin >> N >> Q;
	ll l = 1, r = N;
	while (l < r)
	{
		ll mid = l + (r - l) / 2;
		if (!can(N, Q, mid))
			l = mid + 1;
		else
			r = mid;
	}
	cout << r << endl;
	
	return 0;
}