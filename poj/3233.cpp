#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FO(i, n) for (int i = 0; i < n; ++i)
#define RFO(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const int INF = 0x07070707;

int n, k, m;
vector<int> idt;
map<int, vector<int>> exps;
map<int, vector<int>> sums;

vector<int> add(const vector<int>& a, const vector<int>& b)
{
	vector<int> res(a.size());
	FO (i, n) FO (j, n)
		res[i * n + j] = (a[i * n + j] + b[i * n + j]) % m;
	return res;
}

vector<int> mul(const vector<int>& a, const vector<int>& b)
{
	vector<int> res(a.size(), 0);
	FO (i, n) FO (j, n) FO (k, n)
		res[i * n + j] = (res[i * n + j] + a[i * n + k] * b[k * n + j]) % m;
	return res;
}

void exp(int x)
{
	if (exps[x].size() != 0)
		return;
	if (x % 2)
	{
		exp(x - 1);
		exps[x] = mul(exps[x - 1], exps[1]);
	}
	else
	{
		exp(x / 2);
		exps[x] = mul(exps[x / 2], exps[x / 2]);	
	}
}

void sum(int x)
{
	if (sums[x].size() != 0)
		return;
	if (x % 2)
	{
		sum(x - 1);
		exp(x);
		sums[x] = add(sums[x - 1], exps[x]);
	}
	else
	{
		sum(x / 2);
		exp(x / 2);
		sums[x] = mul(add(exps[x / 2], idt), sums[x / 2]);
	}
}

int main()
{
	cin >> n >> k >> m;
	exps[1] = vector<int>(n * n);
	FO (i, n) FO (j, n)
		cin >> exps[1][i * n + j];
	sums[1] = exps[1];
	// idt
	idt = vector<int>(n * n, 0);
	FO (i, n)
		idt[i * n + i] = 1;
	// calc
	sum(k);
	FO (i, n)
	{
		FO (j, n)
		{
			if (j == 0)
				cout << sums[k][i * n + j];
			else
				cout << " " << sums[k][i * n + j];
		}
		cout << endl;
	}
	return 0;
}


//
// a smarter one by constructing a special matrix
// [A 0]
// [A I]
//
#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FO(i, n) for (int i = 0; i < n; ++i)
#define RFO(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const int INF = 0x07070707;

int n, k, m;
int a[64][64] = {0};
int b[64][64] = {0};

void mul(int p[64][64], int q[64][64])
{
	int tmp[64][64] = {0};
	FO (i, 2 * n) FO (j, 2 * n) FO (k, 2 * n)
		tmp[i][j] = (tmp[i][j] + p[i][k] * q[k][j]) % m;
	memcpy(p, tmp, sizeof(tmp));
}

int main()
{
	cin >> n >> k >> m;
	FO (i, n) FO (j, n)
	{
		cin >> a[i][j];
		a[i + n][j] = a[i][j];
		a[i + n][i + n] = 1;
		b[i][i] = 1;
		b[i + n][i + n] = 1;
	}
	for (int i = 0; (1 << i) <= k; ++i)
	{
		if (k & (1 << i))
			mul(b, a);
		mul(a, a);
	}
	FO (i, n)
	{
		FO (j, n)
		{
			if (j == 0)
				cout << b[i + n][j];
			else
				cout << " " << b[i + n][j];
		}
		cout << endl;
	}
	return 0;
}