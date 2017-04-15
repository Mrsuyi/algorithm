#include <iostream>
using namespace std;

typedef long long ll;

ll time(ll N, ll Q, ll cnt)
{
	ll t = 0;
	ll robots = 0;
	for (; robots < cnt; robots *= 2)
		t += Q;
	ll done = (robots - cnt) * Q;
	t += ((N - done) / cnt) + ((N - done) % cnt == 0) ? 0 : 1;
	return t;
}

int main()
{
	ll N, Q;
	cin >> N >> Q;
	ll l = 1, r = 1000000000000;
	while (true)
	{
		ll mid = l + (r - l) / 2;
		ll tl = time(N, Q, mid - 1);
		ll t = time(N, Q, mid);
		ll tr = time(N, Q, mid + 1);
		if (t >= tl && t >= tr)
		{
			cout << t << endl;
			return 0;
		}
		else if (tl <= t && t <= tr)
			l = mid;
		else if (tl >= t && t >= tr)
			r = mid;
	}
	
	return 0;
}