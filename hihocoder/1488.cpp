#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 20010;

ll n, m, block;
ll nums[MAXN];
ll res[MAXN];
struct Query
{
	ll l, r, idx;
} qs[MAXN];
bool operator<(const Query& lhs, const Query& rhs)
{
	ll a = lhs.l / block;
	ll b = rhs.l / block;
	return a < b || (a == b && lhs.r < rhs.r);
};
ll sums[MAXN] = {0}, cnts[MAXN] = {0};
void modify(ll* array, ll key, ll val)
{
	while (key < MAXN)
	{
		array[key] += val;
		key += key & -key;
	}
}
ll get(ll* array, ll key)
{
	ll res = 0;
	while (key)
	{
		res += array[key];
		key -= key & -key;
	}
	return res;
}

int main()
{
	ll T;
	cin >> T;
	for (ll t = 0; t < T; ++t)
	{
		memset(sums, 0, sizeof(sums));
		memset(cnts, 0, sizeof(cnts));
		cin >> n >> m;
		for (ll i = 0; i < n; ++i)
			cin >> nums[i + 1];
		for (ll i = 0; i < m; ++i)
		{
			cin >> qs[i].l >> qs[i].r;
			qs[i].idx = i;
		}
		block = sqrt(m + 0.5);
		sort(qs, qs + m);
		ll l = 1, r = 0, val = 0;
		for (ll i = 0; i < m; ++i)
		{
			while (l > qs[i].l)
			{
				--l;
				ll sum = get(sums, nums[l]);
				ll cnt = get(cnts, nums[l]);
				val += sum + (r - l + 1 - cnt) * nums[l];
				modify(sums, nums[l], nums[l]);
				modify(cnts, nums[l], 1);
			}
			while (l < qs[i].l)
			{
				ll sum = get(sums, nums[l]);
				ll cnt = get(cnts, nums[l]);
				val -= sum + (r - l + 1 - cnt) * nums[l];
				modify(sums, nums[l], -nums[l]);
				modify(cnts, nums[l], -1);
				++l;
			}
			while (r < qs[i].r)
			{
				++r;
				ll sum = get(sums, nums[r]);
				ll cnt = get(cnts, nums[r]);
				val += sum + (r - l + 1 - cnt) * nums[r];
				modify(sums, nums[r], nums[r]);
				modify(cnts, nums[r], 1);
			}
			while (r > qs[i].r)
			{
				ll sum = get(sums, nums[r]);
				ll cnt = get(cnts, nums[r]);
				val -= sum + (r - l + 1 - cnt) * nums[r];
				modify(sums, nums[r], -nums[r]);
				modify(cnts, nums[r], -1);
				--r;
			}
			res[qs[i].idx] = val;
		}
		for (ll i = 0; i < m; ++i)
			cout << res[i] << endl;
	}
	return 0;
}