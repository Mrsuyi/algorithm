#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N, K;
map<llong, int> p2i;
const llong MOD = 2008;

struct Matrix
{
	llong m[32][32];
	
	Matrix() { memset(m, 0, sizeof(m)); }
	
	Matrix operator=(const Matrix& b)
	{
		memcpy(m, b.m, sizeof(m));
	}
	
	Matrix operator+(const Matrix& b)
	{
		Matrix res;
		FO (i, 32) FO (j, 32)
			res.m[i][j] = (m[i][j] + b.m[i][j]) % MOD;
		return res;
	}

	Matrix operator*(const Matrix& b)
	{
		Matrix res;
		FO (i, 32) FO (j, 32) FO (k, 32)
			res.m[i][j] = (res.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
		return res;
	}
	
	Matrix operator^(int k)
	{
		Matrix res, me = *this;
		FO (i, 32)
			res.m[i][i] = 1;
		for (; k; k >>= 1)
		{
			if (k & 1)
				res = res * me;
			me = me * me;
		}
		return res;
	}
	
	Matrix sum(int k)
	{
		Matrix me = *this;
		if (k <= 0)
			return Matrix();
		if (k == 1)
			return me;
		Matrix lo = me.sum(k / 2);
		Matrix mul = me ^ (k / 2 + k % 2);
		Matrix hi = lo * mul;
		Matrix res = lo + hi;
		if (k % 2)
			res = res + mul;
		return res;
	}
};

int main()
{
	while (cin >> N)
	{
		Matrix input;
		p2i.clear();
		int cnt = 0;
		FO (i, N)
		{
			llong p, q;
			cin >> p >> q;
			if (!p2i.count(p))
				p2i[p] = cnt++;
			if (!p2i.count(q))
				p2i[q] = cnt++;
			++input.m[p2i[p]][p2i[q]];
		}
		cin >> K;
		FO (i, K)
		{
			llong v1, v2, t1, t2;
			cin >> v1 >> v2 >> t1 >> t2;
			if (!p2i.count(v1) || !p2i.count(v2))
			{
				cout << 0 << endl;
				continue;
			}
			if (t1 > t2)
				swap(t1, t2);
			Matrix m1 = input.sum(t1 - 1);
			Matrix m2 = input.sum(t2);
			cout << ((((m2.m[p2i[v1]][p2i[v2]] - m1.m[p2i[v1]][p2i[v2]]) % MOD) + MOD) % MOD) << endl;
		}
	}
    return 0;
}