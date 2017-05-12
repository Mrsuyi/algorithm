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

int M, N;
char words[12][12];
struct Trie
{
	bool is;
	int children[4];
	int fail;
	Trie()
	{
		fail = 0;
		is = false;
		memset(children, -1, sizeof(children));
	}
} tries[110];
int tot = 1;
int chr_2_int[128];

void build()
{
	// insert
	tries[0] = Trie();
	tries[0].fail = -1;
	FO (i, M)
	{
		int cur = 0;
		for (int j = 0; words[i][j] != '\0'; ++j)
		{
			int idx = chr_2_int[words[i][j]];
			if (tries[cur].children[idx] == -1)
			{
				tries[tot] = Trie();
				tries[cur].children[idx] = tot++;
			}
			cur = tries[cur].children[idx];
		}
		tries[cur].is = true;
	}
	// fail
	int que[110], l = 0, r = 1;
	que[0] = 0;
	while (l < r)
	{
		int cur = que[l++];
		FO (i, 4)
		{
			if (tries[cur].children[i] == -1)
				continue;
			if (tries[cur].is)
				tries[tries[cur].children[i]].is = true;
			int pa = cur;
			while (pa != 0)
			{
				pa = tries[pa].fail;
				if (tries[pa].children[i] != -1)
				{
					if (tries[tries[pa].children[i]].is)
						tries[tries[cur].children[i]].is = true;
					tries[tries[cur].children[i]].fail = tries[pa].children[i];
					break;
				}
			}
			que[r++] = tries[cur].children[i];
		}
	}
}

void mul(llong a[110][110], llong b[110][110])
{
	llong tmp[110][110] = {0};
	FO (i, tot) FO (j, tot) FO (k, tot)
		tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 100000;
	FO (i, tot) FO (j, tot)
		a[i][j] = tmp[i][j];
}

llong search()
{
	build();
	llong a[110][110] = {0}, b[110][110] = {0};
	FO (i, tot)
	{
		if (tries[i].is) continue; 
		FO (j, 4)
		{
			int pa = i;
			while (pa != -1)
			{
				if (tries[pa].children[j] != -1)
				{
					if (!tries[tries[pa].children[j]].is)
						++a[i][tries[pa].children[j]];
					break;
				}
				pa = tries[pa].fail;
			}
			if (pa == -1)
				++a[i][0];
		}
	}
	FO (i, tot)
		b[i][i] = 1;
	for (int i = 0; (1LL << i) <= N; ++i)
	{
		if (N & (1LL << i))
			mul(b, a);
		mul(a, a);
	}
	llong res = 0;
	FO (i, tot)
		res += b[0][i];
	return res % 100000;
}

int main()
{
	chr_2_int['A'] = 0;
	chr_2_int['C'] = 1;
	chr_2_int['G'] = 2;
	chr_2_int['T'] = 3;

	cin >> M >> N;
	FO (i, M) cin >> words[i];
	cout << search() << endl;
	system("PAUSE");
	return 0;
}